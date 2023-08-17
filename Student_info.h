#ifndef STUDENT_INFO_H_
#define STUDENT_INFO_H_

// Student_info.h header file
#include "Core.h"
#include <iostream>
#include <string>
#include <vector>

class Student_info {
public:
  // constructors and copy control
  Student_info() : cp(0) {}
  Student_info(std::istream &is) : cp(0) { read(is); }
  Student_info(const Student_info &);
  Student_info &operator=(const Student_info &);
  ~Student_info() { delete cp; }

  // operations
  std::istream &read(std::istream &);

  std::string name() const {
    if (cp)
      return cp->name();
    else
      throw std::runtime_error("uninitialized Student");
  }

  double grade() const {
    if (cp)
      return cp->grade();
    else
      throw std::runtime_error("uninitialized Student");
  }

  static bool compare(const Student_info &s1, const Student_info &s2) {
    return s1.name() < s2.name();
  }

private:
  Core *cp;
  // private:
  //   std::string n;
  //   double midterm, final;
  //   std::vector<double> homework;

  // public:
  //   Student_info();               // construct empty Student_info object
  //   Student_info(std::istream &); // construct one by reading a stream
  //   std::istream &read(std::istream &);
  //   bool valid() const { return !homework.empty(); }
  //   double grade() const;
  //   std::string name() const { return n; }
};

#endif // STUDENT_INFO_H_
