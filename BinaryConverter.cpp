/**********************************************************

   BinaryConverter.cpp

   @author Ryan Morehouse
   @license MIT

   A simple class that contains conversion calculations from
   binary to decimal and back.

   *********************************************************/

#include <vector>
#include <math.h>
#include "BinaryConverter.h"

bool BinaryConverter::is_binary(long n) {
  if (n < 0)
    return false;

  while(n > 0) {
    int digit = n %10;
    if (digit > 1)
      return false;
    n /= 10;
  }
  return true;
}

long BinaryConverter::binary_to_decimal(long bi) {
  // if bi is not binary, return -1
  if (!this->is_binary(bi))
    return -1;

  // get individual digits
  std::vector<int> digits;
  while(bi > 0) {
    // get current digit
    int digit = bi % 10;
    digits.push_back(digit);
    bi /= 10;
  }

  // convert digits to decimal place values
  long sum = 0;
  int size = digits.size();
  for(int i = 0; i < size; i++)
    sum += (digits[i] * pow(2.0, static_cast<double>(i)));

  return sum;
}

long BinaryConverter::decimal_to_binary(long de) {
  long bi = 0;
  int step = 1;
  while (de > 0) {
    int remainder = de % 2;
    bi += remainder * step;
    step *= 10;
    de /= 2;
  }
  return bi;
}
