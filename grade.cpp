#include "grade.h"
#include "Student_info.h"
#include "average.h"
#include "median.h"
#include "optimistic_median.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::endl;
using std::list;
using std::ostream;
using std::string;
using std::transform;
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

// predicate to determine whether a student failed
bool fgrade(const Student_info &s) { return grade(s) < 60; }

// separate passing and failing student records
list<Student_info> extract_fails(list<Student_info> &students) {
  list<Student_info> fail;
  list<Student_info>::iterator iter = students.begin();

  while (iter != students.end()) {
    if (fgrade(*iter)) {
      fail.push_back(*iter);
      iter = students.erase(iter);
    } else
      ++iter;
  }
  return fail;
}

double grade_aux(const Student_info &s) {
  try {
    return grade(s);
  } catch (domain_error) {
    return grade(s.midterm, s.final, 0);
  }
}

double average_grade(const Student_info &s) {
  return grade(s.midterm, s.final, average(s.homework));
}

double median_analysis(const vector<Student_info> &students) {
  vector<double> grades;

  transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
  return median(grades);
}

double average_analysis(const vector<Student_info> &students) {
  vector<double> grades;

  transform(students.begin(), students.end(), back_inserter(grades),
            average_grade);
  return median(grades);
}

double optimistic_median_analysis(const vector<Student_info> &students) {
  vector<double> grades;

  transform(students.begin(), students.end(), back_inserter(grades),
            optimistic_median);
  return median(grades);
}

void write_analysis(ostream &out, const string &name,
                    double analysis(const vector<Student_info> &),
                    const vector<Student_info> &did,
                    const vector<Student_info> &didnt) {
  out << name << ":median(did) = " << analysis(did)
      << ", median(didnt) = " << analysis(didnt) << endl;
}
