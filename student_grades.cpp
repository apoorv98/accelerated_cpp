#include "Student_info.h"
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
  vector<Student_info> students, did, didnt;
  Student_info record;
  string::size_type length_of_longest_name = 0;

  // read and store all the records
  // find the length of the longest name
  while (record.read(cin)) {
    length_of_longest_name = max(length_of_longest_name, record.name().size());
    students.push_back(record);
    /*if (did_all_hw(record))
      did.push_back(record);
    else {
      didnt.push_back(record);
    }*/
  }

  /*
  // check that both groups contain data
  if (did.empty()) {
    cout << "No student did all the homework!" << endl;
    return 1;
  }
  if (didnt.empty()) {
    cout << "Every student did all the homework!" << endl;
    return 1;
  }

  // do the analyses
  write_analysis(cout, "median", median_analysis, did, didnt);
  write_analysis(cout, "average", average_analysis, did, didnt);
  write_analysis(cout, "median of homework turned in",
                 optimistic_median_analysis, did, didnt);

  */

  // alphabetize the student records
  sort(students.begin(), students.end(), compare);

  // write the names and grades
  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    // write the name, padded on the right to length_of_longest_name + 1 chars
    cout << students[i].name()
         << string(length_of_longest_name + 1 - students[i].name().size(), ' ');

    // compute and write the grade
    try {
      double final_grade = students[i].grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }

  return 0;
}
