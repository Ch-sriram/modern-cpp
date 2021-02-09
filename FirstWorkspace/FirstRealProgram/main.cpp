#include <iostream>

int main() {
  std::cout << "Enter your favourite number b/w 1 & 100: "; // << : insertion operator
  int favourite_number;
  std::cin >> favourite_number; // >> : extraction operator
  std::cout << "Your favourite number is: " << favourite_number << std::endl; // std::endl flushes the buffer and prints a new line.
  return 0;
}
