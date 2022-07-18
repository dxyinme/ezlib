#include "tick.hpp"

namespace timeup {

Tick::Tick() {
  last_time_ = NowMs();
}

long long Tick::T() {
  auto now = NowMs();
  auto ret = now - last_time_;
  last_time_ = now;
  return ret;
}

} // namespace timex
