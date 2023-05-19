#include "Student_info.h"

// source file for Student_info-related functions

using std::find;
using std::istream;
using std::vector;

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

// code to read student's records
istream &read(istream &is, Student_info &s) {
  // read and store student's name, midterm and final exam grades
  is >> s.name >> s.midterm >> s.final;

  // read and store student's homework grades
  read_hw(is, s.homework);
  return is;
}

// compare student names which will be used to sort them
bool compare(const Student_info &x, const Student_info &y) {
  return x.name < y.name;
}

bool did_all_hw(const Student_info &s) {
  return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}
