/**********************************************************

   BinaryConverter.h

   @author Ryan Morehouse
   @license MIT

   A simple class that contains conversion calculations from
   binary to decimal and back.

   *********************************************************/

#ifndef BINARYCONVERTER_H
#define BINARYCONVERTER_H

class BinaryConverter {
  public:
    bool is_binary(long n);
    long binary_to_decimal(long bi);
    long decimal_to_binary(long de);
};

#endif
