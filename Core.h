#ifndef CORE_H_
#define CORE_H_

#include "Handle.h"
#include <iostream>
#include <string>
#include <vector>

class Core {
  friend class Student_info;

public:
  Core() : midterm(0), final(0) {}     // construct empty Core object
  Core(std::istream &is) { read(is); } // construct one by reading a stream
  virtual ~Core() {}
  std::string name() const { return n; }
  virtual std::istream &read(std::istream &);
  virtual double grade() const;

protected:
  std::istream &read_common(std::istream &);
  double midterm, final;
  std::vector<double> homework;
  virtual Core *clone() const { return new Core(*this); }

private:
  std::string n;
};

class Grad : public Core {
public:
  Grad() : thesis(0) {}
  Grad(std::istream &is) { read(is); }
  double grade() const;
  std::istream &read(std::istream &);

protected:
  Grad *clone() const { return new Grad(*this); }

private:
  double thesis;
};

bool compare(const Core &c1, const Core &c2) { return c1.name() < c2.name(); }

bool compare_Core_ptrs(const Core *cp1, const Core *cp2) {
  return compare(*cp1, *cp2);
}

bool compare_Core_handles(const Handle<Core> &c1, const Handle<Core> &c2) {
  return compare(*c1, *c2);
}

bool compare_grades(const Core &c1, const Core &c2) {
  return c1.grade() < c2.grade();
}

#endif // CORE_H_
