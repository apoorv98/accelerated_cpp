#include <iostream>
#include <string>

using namespace std;

int main() {
  // ask for the person's name
  cout << "Please enter your first name: ";

  // read the name
  string name_to_print;
  cin >> name_to_print;

  // build the message that we intend to write
  const string greeting = "Hello, " + name_to_print + "!";

  // number of blanks surrounding the greeting
  const int blanks_around_greeting = 1;
  const int sides_of_greeting = 2;
  const int greeting_and_space_around_it = 3;

  // total number of rows and columns to write
  const int total_rows_to_write =
      blanks_around_greeting * sides_of_greeting + greeting_and_space_around_it;
  const string::size_type total_columns_to_write =
      greeting.size() + blanks_around_greeting * sides_of_greeting + 2;

  // write a blank line to seperate the output from the input
  cout << endl;

  // write rows of the output
  // invariant: we have written row_counter rows so far
  for (int row_counter = 0; row_counter != total_rows_to_write; ++row_counter) {
    string::size_type column_counter = 0;

    // invariant: we have written column_counter characters so far in the
    // current row
    while (column_counter != total_columns_to_write) {
      // is it time to write the greeting
      if (row_counter == blanks_around_greeting + 1 &&
          column_counter == blanks_around_greeting + 1) {
        cout << greeting;
        column_counter += greeting.size();
      } else {
        // are we on the border
        if (row_counter == 0 || row_counter == total_rows_to_write - 1 ||
            column_counter == 0 || column_counter == total_columns_to_write - 1)
          cout << "*";
        else
          cout << " ";
        ++column_counter;
      }
    }
    cout << endl;
  }
  return 0;
}
