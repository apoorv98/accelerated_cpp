#ifndef PTR_H_
#define PTR_H_

#include "Vec.h"
#include <stdexcept>

using std::size_t;

template <class T> class Ptr {
public:
  // new member to copy the object conditionally when needed
  void make_unique() {
    if (*refptr != 1) {
      --*refptr;
      refptr = new size_t(1);
      p = p ? clone(p) : 0;
    }
  }
  // manage reference count as well as pointer
  Ptr() : refptr(new size_t(1), p(0)) {}
  Ptr(T *t) : refptr(new size_t(1)), p(t) {}
  Ptr(const Ptr &h) : refptr(h, refptr), p(h.p) { ++*refptr; }

  Ptr &operator=(const Ptr &);
  ~Ptr();

  operator bool() const { return p; }
  T &operator*() const {
    if (p)
      return *p;
    throw std::runtime_error("unbound Ptr");
  }

  T *operator->() const {
    if (p)
      return p;
    throw std::runtime_error("unbound Ptr");
  }

private:
  T *p;
  size_t *refptr;
};

template <class T> T *clone(const T *tp) { return tp->clone(); }

#endif // PTR_H_
