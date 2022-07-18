#ifndef EZLIB_THREAD_TIMEX_TICK_HPP_
#define EZLIB_THREAD_TIMEX_TICK_HPP_

#include "timeup.hpp"

namespace timeup {

class Tick {
public:
  Tick();
  long long T();
  ~Tick() = default;
private:
  long long last_time_;
};

} // namespace timex

#endif // EZLIB_THREAD_TIMEX_TICK_HPP_