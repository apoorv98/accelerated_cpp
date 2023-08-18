#include "Ref_handle.h"

template <class T>
Ref_handle<T> &Ref_handle<T>::operator=(const Ref_handle &rhs) {
  ++*rhs.refptr;
  // free the left-hand side, destroying pointers if appropriate
  if (--*refptr == 0) {
    delete refptr;
    delete p;
  }

  // copy in values from the right-hand side
  refptr = rhs.refptr;
  p = rhs.p;
  return *this;
}

template <class T> Ref_handle<T>::~Ref_handle() {
  if (--*refptr == 0) {
    delete refptr;
    delete p;
  }
}
