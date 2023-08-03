#ifndef STUDENT_INFO_H_
#define STUDENT_INFO_H_

// Student_info.h header file
#include <iostream>
#include <string>
#include <vector>

class Student_info {
private:
  std::string n;
  double midterm, final;
  std::vector<double> homework;

public:
  Student_info();               // construct empty Student_info object
  Student_info(std::istream &); // construct one by reading a stream
  std::istream &read(std::istream &);
  bool valid() const { return !homework.empty(); }
  double grade() const;
  std::string name() const { return n; }
};

bool compare(const Student_info &, const Student_info &);

#endif // STUDENT_INFO_H_
