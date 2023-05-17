#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

// keeping all of student's data together
struct Student_info {
  string name;
  double midterm, final;
  vector<double> homework;
};

// code for median function
double median(vector<double> vec) {
  typedef vector<double>::size_type vec_sz;

  vec_sz size = vec.size();
  if (size == 0)
    throw domain_error("median of an empty vector");

  sort(vec.begin(), vec.end());

  vec_sz mid = size / 2;

  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

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

int main() {
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  // read and store all the records
  // find the length of the longest name
  while (read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  // sort students by passing compare() as predicate
  sort(students.begin(), students.end(), compare);

  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    // write the name, padded on the right to maxlen + 1 chars
    cout << students[i].name
         << string(maxlen + 1 - students[i].name.size(), ' ');

    // compute and write the grade
    try {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }

  return 0;
}
