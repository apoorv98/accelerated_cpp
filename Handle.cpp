#include "Handle.h"
#include <stdexcept>

using std::runtime_error;

template <class T> Handle<T> &Handle<T>::operator=(const Handle &rhs) {
  if (&rhs != this) {
    delete p;
    p = rhs.p ? rhs.p->clone() : 0;
  }
  return *this;
}

template <class T> T &Handle<T>::operator*() const {
  if (p)
    return *p;
  throw runtime_error("unbound Handle");
}

template <class T> T *Handle<T>::operator->() const {
  if (p)
    return p;
  throw runtime_error("unbound Handle");
}
