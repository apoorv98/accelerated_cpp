#include "Core.h"
#include "grade.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
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

int main() {
  vector<Handle<Core>> students;
  Handle<Core> record;
  char ch;
  string::size_type length_of_longest_name = 0;

  // read and store all the records
  // find the length of the longest name
  while (cin >> ch) {
    if (ch == 'U')
      record = new Core; // allocate a Core object
    else
      record = new Grad; // allocate a Grad object
    record->read(cin);   // virtual call
    length_of_longest_name = max(length_of_longest_name, record->name().size());
    students.push_back(record);
  }

  // alphabetize the student records
  sort(students.begin(), students.end(), compare_Core_handles);

  // write the names and grades
  for (vector<Handle<Core>>::size_type i = 0; i != students.size(); ++i) {
    // write the name, padded on the right to length_of_longest_name + 1 chars
    cout << students[i]->name()
         << string(length_of_longest_name + 1 - students[i]->name().size(),
                   ' ');

    // compute and write the grade
    try {
      double final_grade = students[i]->grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }

  return 0;
}
