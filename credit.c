#include <stdio.h>
#include <math.h>

int CheckCreditCard(long cardNumber);
int GetLastDigit(long number);
int GetNDigit(long number, int digitPosition);

int main(void)
{
  long visaNumberTest = 4003600000070314;

  int k = 4;

  printf("%li\n", (visaNumberTest / (long)pow(10, k)) % 10);
  printf("%i\n", GetNDigit(visaNumberTest, 2));
  printf("%i\n", GetLastDigit(visaNumberTest));

  return 0;
}

int CheckCreditCard(long cardNumber)
{
  return 0;
}

int GetLastDigit(long number)
{
  return number % 10;
}

int GetNDigit(long number, int digitPosition)
{
  return (number / (long)pow(10, digitPosition)) % 10;
}