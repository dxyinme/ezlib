#include <sstream>
#include "thread/timeup/timeup.hpp"
#include "threadpool.hpp"

ThTask::ThTask() :
        is_done_(false), task_id_(0) {}

ThTask::ThTask(int task_id) :
        is_done_(false), task_id_(task_id) {}

void ThTask::Done() {
  is_done_ = true;
  cv_.notify_one();
}

void ThTask::Wait() {
  std::unique_lock<std::mutex> _(mtx_);
  cv_.wait(_, [&]{ return is_done_;} );
}

void ThTask::SetCommitTime() {
  commit_tms = timeup::NowMs();
}

void ThTask::SetBeginTime() {
  begin_tms = timeup::NowMs();
}

void ThTask::SetFinishTime() {
  finish_tms = timeup::NowMs();
}

std::string ThTask::WorkMessage() {
  std::stringstream ss;
  ss << "[commit time: " << commit_tms << "ms]";
  ss << "[begin time: " << begin_tms << "ms]";
  ss << "[finish time: " << finish_tms << "ms]";
  return ss.str();
}


ThPool::ThPool(int num) {
  is_done_ = false;
  for (int i = 0; i < num; i++) {
    thp_.emplace_back(std::thread([&] {
      for (;;) {
        std::unique_lock<std::mutex> _(q_mtx_);
        cv_.wait(_, [&] { return is_done_ || !task_queue_.empty();});
        if (is_done_) {
          break;
        }
        auto t_ptr = task_queue_.front();
        task_queue_.pop();
        t_ptr->SetBeginTime();
        t_ptr->TaskDo();
        t_ptr->Done();
        t_ptr->SetFinishTime();
      }
    }));
  }
}

void ThPool::Commit(std::shared_ptr<ThTask> task_ptr) {
  task_ptr->SetCommitTime();
  task_queue_.push(std::move(task_ptr));
  cv_.notify_one();
}

ThPool::~ThPool() {
  is_done_ = true;
  cv_.notify_all();
  for (auto & th : thp_) th.join();
}