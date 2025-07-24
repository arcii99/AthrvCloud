//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: scalable
#include <stdio.h>
#include <string.h>

int checkLength(char *password);
int checkUpper(char *password);
int checkLower(char *password);
int checkDigit(char *password);
int checkSymbol(char * password);

int main()
{
  char password[50];

  printf("Enter password: ");
  fgets(password, 50, stdin); // Taking input using fgets to handle any whitespace characters

  int length = checkLength(password);
  int upper = checkUpper(password);
  int lower = checkLower(password);
  int digit = checkDigit(password);
  int symbol = checkSymbol(password);

  // Calculating Password Strength
  int strength = length + upper + lower + digit + symbol;
  
  printf("\nPassword Strength: %d/15\n", strength);

  if(strength >= 12)
  {
    printf("Password is Strong\n");
  }
  else if(strength >= 8)
  {
    printf("Password is Moderately Strong\n");
  }
  else
  {
    printf("Password is Weak\n");
  }

  return 0;
} 

int checkLength(char *password)
{
  int length = strlen(password);

  if(length >= 8 && length <= 15)
  {
    return 4; // Password length between 8 to 15 characters => 4 Points
  }
  else if(length > 15)
  {
    return 5; // Password length greater than 15 characters => 5 Points
  }
  else
  {
    return 0; // Password length less than 8 characters => 0 Points
  }
}

int checkUpper(char *password)
{
  int upperCount = 0;

  for(int i=0; i<strlen(password); i++)
  {
    if(password[i] >= 'A' && password[i] <= 'Z')
    {
      upperCount++;
      break; // Needed only to check the presence of atleast one uppercase letter
    }
  }

  if(upperCount > 0)
  {
    return 3; // Uppercase letter present => 3 Points
  }
  else
  {
    return 0; // Uppercase letter not present => 0 Points
  }
}

int checkLower(char *password)
{
  int lowerCount = 0;

  for(int i=0; i<strlen(password); i++)
  {
    if(password[i] >= 'a' && password[i] <= 'z')
    {
      lowerCount++;
      break; // Needed only to check the presence of atleast one lowercase letter
    }
  }

  if(lowerCount > 0)
  {
    return 3; // Lowercase letter present => 3 Points
  }
  else
  {
    return 0; // Lowercase letter not present => 0 Points
  }
}

int checkDigit(char *password)
{
  int digitCount = 0;

  for(int i=0; i<strlen(password); i++)
  {
    if(password[i] >= '0' && password[i] <= '9')
    {
      digitCount++;
      break; // Needed only to check the presence of atleast one digit
    }
  }

  if(digitCount > 0)
  {
    return 2; // Digit present => 2 Points
  }
  else
  {
    return 0; // Digit not present => 0 Points
  }
}

int checkSymbol(char *password)
{
  int symbolCount = 0;

  for(int i=0; i<strlen(password); i++)
  {
    if((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@'))
    {
      symbolCount++;
      break; // Needed only to check the presence of atleast one symbol
    }
  }

  if(symbolCount > 0)
  {
    return 3; // Symbol present => 3 Points
  }
  else
  {
    return 0; // Symbol not present => 0 Points
  }
}