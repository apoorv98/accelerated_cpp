#ifndef GRADE_H_
#define GRADE_H_

// grade.h
#include "Student_info.h"
#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double> &);
double grade(const Student_info &);
double average_grade(const Student_info &);
double grade_aux(const Student_info &);
double median_analysis(const std::vector<Student_info> &);
double average_analysis(const std::vector<Student_info> &);
void write_analysis(std::ostream &, const std::string &,
                    double analysis(const std::vector<Student_info> &),
                    const std::vector<Student_info> &,
                    const std::vector<Student_info> &);

#endif // GRADE_H_
