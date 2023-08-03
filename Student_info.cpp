#include "Student_info.h"

// source file for Student_info-related functions
#include <algorithm>

using std::find;
using std::istream;
using std::vector;

Student_info::Student_info() : midterm(0), final(0) {}

Student_info::Student_info(istream &is) { read(is); }

istream &Student_info::read(istream &in) {
  in >> n >> midterm >> final;
  read_hw(in, homework);
  return in;
}

double Student_info::grade() const { return ::grade(midterm, final, homework); }

// code for read_hw(istream&, vector<double>&) function
istream &read_hw(istream &in, vector<double> &hw) {
  if (in) {
    // get rid of previous contents
    hw.clear();

    // read homework grades
    double x;
    while (in >> x)
      hw.push_back(x);

    // clear the stream so that input will work for the next student
    in.clear();
  }
  return in;
}

// compare student names which will be used to sort them
bool compare(const Student_info &x, const Student_info &y) {
  return x.name() < y.name();
}

/*
bool did_all_hw(const Student_info &s) {
  return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}
*/
