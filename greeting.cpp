#include <iostream>
#include <string>

int main() {
  // ask for the person's name
  std::cout << "Please enter your first name: ";

  // read the name
  std::string name_to_print;
  std::cin >> name_to_print;

  // build the message that we intend to write
  const std::string greeting = "Hello, " + name_to_print + "!";

  // number of blanks surrounding the greeting
  const int blanks_around_greeting = 1;

  // total number of rows to write
  const int total_rows_to_write = blanks_around_greeting * 2 + 3;

  // TODO: seperate the output from the input
  std::cout << std::endl;

  // write rows of the output
  int row_counter = 0;

  // invariant: we have written row_counter rows so far
  while (row_counter != total_rows_to_write) {
    // TODO: write a row of output
    std::cout << std::endl;
    ++row_counter;
  }

  return 0;
}
