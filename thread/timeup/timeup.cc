
#include "timeup.hpp"

namespace timeup {

long long NowMs() {
  using namespace std::chrono;
  auto now_ms = duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
  return now_ms;
}

} // namespace timex
