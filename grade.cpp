#include "grade.h"
#include "Student_info.h"
#include "median.h"
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::vector;

// code for grade(double, double, double) function
double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// code for grade(double, double, const vector<double>&) function
double grade(double midterm, double final, const vector<double> &hw) {
  if (hw.size() == 0) {
    throw domain_error("student has done no homework");
  }
  return grade(midterm, final, median(hw));
}

// calculate final grade for student
double grade(const Student_info &s) {
  return grade(s.midterm, s.final, s.homework);
}
