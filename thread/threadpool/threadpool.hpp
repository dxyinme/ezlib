#ifndef EZLIB_THREADPOOL_THREADPOOL_HPP_
#define EZLIB_THREADPOOL_THREADPOOL_HPP_

#include <memory>
#include <queue>
#include <condition_variable>
#include <vector>
#include <chrono>
#include <thread>

class ThTask {
public:
  ThTask();
  ThTask(int task_id);
  void Done();
  void Wait();
  virtual void TaskDo() = 0;
  void SetCommitTime();
  void SetBeginTime();
  void SetFinishTime();
  std::string WorkMessage();
  ~ThTask() = default;

private:
  std::condition_variable cv_;
  std::mutex mtx_;
  bool is_done_;
  int task_id_;
  long long begin_tms{}, finish_tms{}, commit_tms{};
};

class ThPool {
public:
  explicit ThPool(int num);
  void Commit(std::shared_ptr<ThTask> task_ptr);
  ~ThPool();

private:

  std::vector<std::thread> thp_;
  std::mutex q_mtx_;
  std::condition_variable cv_;
  std::queue<std::shared_ptr<ThTask>> task_queue_;
  bool is_done_;
};

#endif //EZLIB_THREADPOOL_THREADPOOL_HPP_