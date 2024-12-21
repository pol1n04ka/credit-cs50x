#include <stdio.h>
#include <math.h>

// main function for verifying card number

int CheckCreditCard(long number); // TODO

// utilities for number verification

int GetNumberLength(long number);        // done
int CheckNumberFirstDigits(long number); // done

// utilities for Luhn's algorithm

int GetLastDigit(long number);                 // done
int GetNDigit(long number, int digitPosition); // done
int GetChecksum(long number);                  // done, maybe need refactoring
int VerifyChecksum(int checksum);              // done

int main(void)
{
  long visaNumberTest = 5115800601659182;

  int isValid = CheckNumberFirstDigits(visaNumberTest);

  printf("%i\n", isValid);

  int checkSum = GetChecksum(visaNumberTest);

  printf("%i\n", VerifyChecksum(checkSum));

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
  int length = GetNumberLength(number);
  int firstDigit = GetNDigit(number, length - 1);
  int secondDigit = GetNDigit(number, length - 2);

  if (length == 16 || length == 13) // visa or mc
  {
    if (firstDigit == 4)
    {
      return 1;
    }
    else if (firstDigit == 5)
    {
      if (secondDigit >= 1 && secondDigit <= 5)
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
    if (firstDigit == 3 && (secondDigit == 4 || secondDigit == 7))
    {
      return 3;
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

// returns last digit in a number
int GetLastDigit(long number)
{
  return number % 10;
}

// returns digit from requested position in a number
// 0 is last digit, 1 is second from end and so on
int GetNDigit(long number, int digitPosition)
{
  return (number / (long)pow(10, digitPosition)) % 10;
}

int GetChecksum(long number)
{
  int length = GetNumberLength(number);
  int sumFirst = 0;
  int sumSecond = 0;
  int sumFinal;

  int currentDigit;

  for (int i = 1; i < length; i += 2)
  {
    currentDigit = GetNDigit(number, i);

    if ((currentDigit * 2) > 9)
    {
      int a = GetNDigit(currentDigit * 2, 0);
      int b = GetNDigit(currentDigit * 2, 1);

      sumFirst += a + b;
    }
    else
    {
      sumFirst += currentDigit * 2;
    }
  }

  for (int j = 0; j < length; j += 2)
  {
    currentDigit = GetNDigit(number, j);
    sumSecond += currentDigit;
  }

  sumFinal = sumFirst + sumSecond;

  return sumFinal;
}

// 0 invalid, 1 valid
int VerifyChecksum(int checksum)
{
  if (GetLastDigit(checksum) == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}