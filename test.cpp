/*******************************************

   test.cpp

   @author Ryan Morehouse
   @license MIT

   A quick test of the BinaryConverter class.

   *******************************************/

#include <string>
#include <sstream>
#include <iostream>
#include "TerminalPrompt.h"
#include "BinaryConverter.h"

int main() {
  int selection = -1;
  long input = -1;
  long output = -1;
  TerminalPrompt term;
  BinaryConverter converter;

  std::ostringstream oss;
  oss << "Please select an option from the menu below:\n";
  oss << "1. Convert binary to decimal\n";
  oss << "2. Convert decimal to binary\n";
  oss << "Selection";
  std::string prompt = oss.str();
  
  while(selection == -1) {
    selection = term.get_positive_int(&prompt);
    if (selection == 0 || selection > 2) {
      std::cout << "Please select 1 or 2.\n";
      selection = -1;
    }
  }

  prompt = "Enter number to convert";
  input = term.get_positive_long(&prompt);

  switch (selection) {
    case 1:
      while(!converter.is_binary(input)) {
        prompt = "Please enter a valid binary number";
        input = term.get_positive_long(&prompt);
      }
      output = converter.binary_to_decimal(input);
      break;
    case 2:
      output = converter.decimal_to_binary(input);
      break;
  }

  std::cout << "Output: " << output << std::endl;

  return 0;
  
}
