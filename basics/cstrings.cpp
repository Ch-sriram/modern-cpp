#include <iostream>
#include <cstring>  // for c-style string functions
#include <cctype>   // for character based functions

#include <limits>   // used to get the max() for moving the 
                    // cin stream's pointer to the latest
                    // position in the input buffer

using namespace std;

// https://www.geeksforgeeks.org/templates-cpp/
template <typename T>
void take_input(T &element) {
  cin >> element;
  // https://stackoverflow.com/a/5740111
  // Used as a workaround for also using cin.getline() along with cin formatted inputs
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// https://stackoverflow.com/a/1810295/9458784 --> parameter typing for fixed sized arrays
void compare_strings(char (&first)[40], char (&second)[40]) {
  if (strcmp(first, second) == 0) // 0 => if strings are equal
    cout << first << " and " << second << " are the same" << endl;
  else cout << first << " and " << second << " are different" << endl;
}

int main() {
  char some_string[20];
  cout << some_string << "maybe garbage" << endl; // can show a garbage value: since uninitialized or nothing

  // Initializing strings post C++11
  char first_name[20]{};
  char last_name[20]{};

  cout << "Please enter your first name: ";
  take_input(first_name);

  cout << "Please enter your last name: ";
  take_input(last_name);

  cout << "---------------------------------------------" << endl;

  cout << "Hello, " << first_name << " your first name has " << strlen(first_name) << " characters " << endl;
  cout << "and your last name, " << last_name << " has " << strlen(last_name) << " characters." << endl;

  char full_name[40]{};

  strcpy(full_name, first_name);  // copy first_name to full_name
  strcat(full_name, " "); // concatenate full_name and " "
  strcat(full_name, last_name); // concatenate full_name to full_name
  cout << "Your full name is " << full_name << endl;

  cout << "---------------------------------------------" << endl;

  // clearing an array
  memset(&full_name, 0, sizeof(full_name)); // https://stackoverflow.com/a/632865
  cout << "Enter your full name: ";
  take_input(full_name); // "Sriram Chandrabhatta" is entered

  cout << "Your full name is "<< full_name << endl;
  // "Sriram" is the output because cout is buffered on spaces by default.

  // full line inputs
  memset(&full_name, 0, sizeof(full_name));
  cout << "Enter your full name: ";
  cin.getline(full_name, 40); // will take upto 40 characters. Won't be buffered on spaces.
  cout << "Your full name is " << full_name << endl;

  cout << "---------------------------------------------" << endl;

  char temp[40];
  strcpy(temp, full_name); // copy full_name to temp
  compare_strings(temp, full_name);

  cout << "---------------------------------------------" << endl;

  for (size_t i{0}; i < strlen(full_name); ++i)
    if (isalpha(full_name[i]))
      full_name[i] = toupper(full_name[i]);
  
  cout << "Your full name is " << full_name << endl;

  cout << "---------------------------------------------" << endl;

  compare_strings(temp, full_name);

  cout << "---------------------------------------------" << endl;

  // strcmp(str1, str2): returns 0 if both str1 == str2
  //                     returns -1 if str1 < str2
  //                     returns +1 if str1 > str2
  cout << "Result of comparing " << temp << " and " << full_name << ": " << strcmp(temp, full_name) << endl;
  cout << "Result of comparing " << full_name << " and " << temp << ": " << strcmp(full_name, temp) << endl;

  return 0;
}
