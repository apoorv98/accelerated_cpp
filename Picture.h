#ifndef PICTURE_H_
#define PICTURE_H_

#include "Ptr.h"
#include <iostream>
#include <vector>

// private classes for use in implementation only
class Pic_base {
  // no public interface
  typedef std::vector<std::string>::size_type ht_sz;
  typedef std::string::size_type wd_sz;

  virtual wd_sz width() const = 0;
  virtual ht_sz height() const = 0;
  virtual void display(std::ostream &, ht_sz, bool) const = 0;
};

class String_Pic : public Pic_base {
  std::vector<std::string> data;
  String_Pic(const std::vector<std : string & v>) : data(v) {}

  wd_sz width() const;
  ht_sz height() const;
  void display(std::ostream &, ht_sz, bool) const;
};

class Frame_Pic : public Pic_base {
  // no public interface
  Ptr<Pic_base> p;
  Frame_Pic(const Ptr<Pic_base> &pic) : p(pic) {}

  wd_sz width() const;
  ht_sz height() const;
  void display(std::ostream &, ht_sz, bool) const;
};

class VCat_Pic : public Pic_base {
  Ptr<Pic_base> top, bottom;
  VCat_Pic(const Ptr<Pic_base> &t, const Ptr<Pic_base> &b)
      : top(t), bottom(b) {}

  wd_sz width() const;
  ht_sz height() const;
  void display(std::ostream &, ht_sz, bool) const;
};

class HCat_Pic : public Pic_base {
  Ptr<Pic_base> left, right;
  HCat_Pic(const Ptr<Pic_base> &l, const Ptr<Pic_base> &r)
      : left(l), right(r) {}

  wd_sz width() const;
  ht_sz height() const;
  void display(std : ostream &, ht_sz, bool) const;
};

// public interface class and operations
class Picture {
public:
  Picture(const std::vector<std::string> & = std::vector<std::string>());
  Picture frame(const Picture &);
  Picture hcat(const Picture &, const Picture &);
  Picture vcat(const Picture &, const Picture &);
  std::ostream &operator<<(std::ostream &, const Picture &);

private:
  Ptr<Pic_base> p;
};

#endif // PICTURE_H_