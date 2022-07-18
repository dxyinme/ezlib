#include "threadpool.hpp"
#include <iostream>
#include "thread/timeup/tick.hpp"
#include <unistd.h>

namespace threadpool_test {

class CalcTask : public ThTask {
public:
  int a{}, b{}, mod{};
  int ret{};
  CalcTask(int id) :
    ThTask(id) {}
  void TaskDo() override {
    int s = 1;
    for (int i = 0; i < b; i ++) {
      s = s * a % mod;
    }
    ret = s;
  }
};

void RunThread(ThPool & thpool) {
  const int N = 4;
  const int BMAX = 10000000;
  std::vector<std::shared_ptr<CalcTask>> ptr_v;
  for (int i = 0; i < N; i++) {
    auto now_ptr = std::make_shared<CalcTask>(i);
    now_ptr->a = i;
    now_ptr->b = BMAX;
    now_ptr->mod = 1e4 + 7;
    ptr_v.emplace_back(now_ptr);
    thpool.Commit(ptr_v.back());
  }
  for (int i = 0; i < N; i++) {
    ptr_v[i]->Wait();
  }
}

}  // namespace threadpool_test

int main(int argc, char ** argv) {
  ThPool th4(4);
  ThPool th1(1);
  timeup::Tick tick;
  threadpool_test::RunThread(th4);
  std::cout << "4thread:" << tick.T() << "ms" << std::endl;
  threadpool_test::RunThread(th1);
  std::cout << "1thread:" << tick.T() << "ms" << std::endl;
  return 0;
}