#include "Core.h"
#include <iostream>
#include <string>

using std::istream;
using std::string;

double Core::grade() const { return ::grade(midterm, final, homework); }

istream &Core::read_common(istream &in) {
  // read and store student's name and exam grades
  in >> n >> midterm >> final;
  return in;
}

istream &Core::read(istream &in) {
  read_common(in);
  read_hw(in, homework);
  return in;
}

istream Grad::read(istream &in) {
  read_common(in);
  in >> thesis;
  read_hw(in, homework);
  return in;
}

double Grad::grade() const { return min(Core::grade(), thesis); }
