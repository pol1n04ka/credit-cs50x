#include <stdio.h>
#include <math.h>

// main function for verification card number
int CheckCreditCard(long number); // TODO

// utilities for number verification
int CheckNumberLength(long number);                  // done
int CheckNumberFirstDigits(long number, int length); // TODO

// utilities for Luhn's algorithm
int GetLastDigit(long number);                 // done
int GetNDigit(long number, int digitPosition); // done
int GetChecksum(long number);                  // TODO

int main(void)
{
  long visaNumberTest = 4003600000070314;
  long randomNumber = 45645;

  int k = 4;

  printf("%li\n", (visaNumberTest / (long)pow(10, k)) % 10);
  printf("%i\n", GetNDigit(visaNumberTest, 2));
  printf("%i\n", GetLastDigit(visaNumberTest));

  return 0;
}

int CheckCreditCard(long number)
{
  return 0;
}

int CheckNumberLength(long number)
{
  int length;
  if (number == 0)
  {
    length = 1;
  }
  else
  {
    if (number < 0)
      number = -number;
    length = (int)log10(number) + 1;
  }

  return length;
}

int CheckNumberFirstDigits(long number, int length)
{
}

int GetLastDigit(long number)
{
  return number % 10;
}

// get digit from requested position in a number
// 0 is last digit, 1 is second from end and so on
int GetNDigit(long number, int digitPosition)
{
  return (number / (long)pow(10, digitPosition)) % 10;
}

int GetChecksum(long number)
{
}