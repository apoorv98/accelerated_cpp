#ifndef VEC_H_
#define VEC_H_

#include <memory>

using std::allocator;

template <class T> class Vec {
public:
  typedef T *iterator;
  typedef const T *const_iterator;
  typedef size_t size_type;
  typedef T value_type;

  Vec() { create(); }
  Vec(const Vec &v) { create(v.begin(), v.end()); } // copy constructor
  explicit Vec(size_type n, const T &val = T()) { create(n, val); }
  ~Vec() { uncreate(); }

  size_type size() const { return limit - data; }
  void push_back(const T &val) {
    if (avail == limit) // get space if needed
      grow();
    unchecked_append(val); // append the new element
  }

  T &operator[](size_type i) { return data[i]; }
  const T &operator[](size_type i) const { return data[i]; }
  Vec &operator=(const Vec &);

  iterator begin() { return data; }
  const_iterator begin() const { return data; }

  iterator end() { return limit; }
  const_iterator end() const { return limit; }

private:
  iterator *data;  // first element in the Vec
  iterator *avail; // pointer to (one past) the last constructed element
  iterator *limit; // one past the last element in Vec

  // facilities for memory allocation
  allocator<T> alloc; // object to handle memory allocation

  // allocate and initialize the underlying array
  void create();
  void create(size_type, const T &);
  void create(const_iterator, const_iterator);

  // destroy the elements in the array and free the memory
  void uncreate();

  // support functions for push_back
  void grow();
  void unchecked_append(const T &);
};

#endif // VEC_H_
