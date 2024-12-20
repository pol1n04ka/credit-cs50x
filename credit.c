#include <stdio.h>
#include <math.h>

// main function for verification card number
int CheckCreditCard(long number); // TODO

// utilities for number verification
int GetNumberLength(long number);        // done
int CheckNumberFirstDigits(long number); // done

// utilities for Luhn's algorithm
int GetLastDigit(long number);                 // done
int GetNDigit(long number, int digitPosition); // done
int GetChecksum(long number);                  // TODO

int main(void)
{
  long visaNumberTest = 370360000000031;

  int isValid = CheckNumberFirstDigits(visaNumberTest);

  printf("%i\n", isValid);

  return 0;
}

int CheckCreditCard(long number)
{
  return 0;
}

int GetNumberLength(long number)
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

// 0 invalid, 1 visa, 2 mc, 3 amex
int CheckNumberFirstDigits(long number)
{
  int cardType = 0;
  int length = GetNumberLength(number);
  int firstDigit;
  int secondDigit;

  if (length == 16) // visa or mc
  {
    firstDigit = GetNDigit(number, 15);
    secondDigit = GetNDigit(number, 14);
    if (firstDigit == 4)
    {
      return 1;
    }
    else if (firstDigit == 5)
    {
      if (secondDigit == 1 || secondDigit == 2 || secondDigit == 3 || secondDigit == 4 || secondDigit == 5)
      {
        return 2;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else if (length == 15) // amex
  {
    firstDigit = GetNDigit(number, 14);
    secondDigit = GetNDigit(number, 13);
    if (firstDigit == 3 && (secondDigit == 4 || secondDigit == 7))
    {
      return 3;
    }
    else
    {
      return 0;
    }
  }
  else if (length == 13) // visa or mc
  {
    firstDigit = GetNDigit(number, 12);
    secondDigit = GetNDigit(number, 11);
    if (firstDigit == 4)
    {
      return 1;
    }
    else if (firstDigit == 5)
    {
      if (secondDigit == 1 || secondDigit == 2 || secondDigit == 3 || secondDigit == 4 || secondDigit == 5)
      {
        return 2;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }
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