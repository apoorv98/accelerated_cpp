#include "Vec.h"

template <class T> Vec<T> &Vec<T>::operator=(const Vec &rhs) {
  // check for self-assignmen
  if (&rhs != this) {
    // free the array in left-hand side
    uncreate();

    // copy elements from right-hand side to left-hand side
    create(rhs.begin(), rhs.end());
  }
  return *this;
}
