#ifndef GRADE_H_
#define GRADE_H_

// grade.h
#include "Student_info.h"
#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double> &);
double grade(const Student_info &);

#endif // GRADE_H_
