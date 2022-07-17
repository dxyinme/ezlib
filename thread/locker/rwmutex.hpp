#ifndef EZLIB_THREAD_LOCKER_RWMUTEX_HPP_
#define EZLIB_THREAD_LOCKER_RWMUTEX_HPP_

#include <atomic>
#include <mutex>

namespace locker {

template <typename Mutex>
class RWMutex {
public:
  RWMutex();

  void RLock();

  void RUnLock();

  void Lock();

  void UnLock();

  ~RWMutex() = default;
private:
  Mutex r_mu_;
  Mutex w_mu_;
  int reader_;
};


template<typename Mutex>
RWMutex<Mutex>::RWMutex() {
  reader_ = 0;
}

template<typename Mutex>
void RWMutex<Mutex>::RLock() {
  r_mu_.lock();
  if (++reader_ == 1) {
    w_mu_.lock();
  }
  r_mu_.unlock();
}
template<typename Mutex>
void RWMutex<Mutex>::RUnLock() {
  r_mu_.lock();
  if (--reader_ == 0) {
    w_mu_.unlock();
  }
  r_mu_.unlock();
}
template<typename Mutex>
void RWMutex<Mutex>::Lock() {
  w_mu_.lock();
}
template<typename Mutex>
void RWMutex<Mutex>::UnLock() {
  w_mu_.unlock();
}

} // namespace locker


#endif  // EZLIB_THREAD_LOCKER_RWMUTEX_HPP_