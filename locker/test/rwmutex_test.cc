#include <gtest/gtest.h>
#include <mutex>
#include <memory>
#include <thread>
#include "rwmutex.hpp"

namespace rwmutex_test {

void ReadThread(std::shared_ptr<
                  locker::RWMutex<std::mutex>
                > lock_ptr) {
  const int N = 10000;
  for (int i = 0; i < N; i++) {
    lock_ptr->RLock();
    lock_ptr->RUnLock();
  }
}

void WriteThread(std::shared_ptr<
                  locker::RWMutex<std::mutex>
                 > lock_ptr) {
  const int N = 10000;
  for (int i = 0; i < N; i++) {
    lock_ptr->Lock();
    lock_ptr->UnLock();
  }
}

TEST(RWMutexTestCase, normal_test) {
  auto lock_ptr = std::make_shared<locker::RWMutex<std::mutex>>();
  int rth = 16;
  std::vector<std::thread> rvec;
  int wth = 1;
  std::vector<std::thread> wvec;
  for (int i = 0; i < rth; i++) {
    rvec.emplace_back(std::thread(ReadThread, lock_ptr));
  }
  for (int i = 0; i < wth; i++) {
    wvec.emplace_back(std::thread(WriteThread, lock_ptr));
  }
  for (int i = 0; i < rth; i++) {
    rvec[i].join();
  }
  for (int i = 0; i < wth; i++) {
    wvec[i].join();
  }
}

}  // namespace locker_test