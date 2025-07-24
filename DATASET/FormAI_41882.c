//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char password[100];
  int length, uppercase, lowercase, digit, symbol = 0;
  
  printf("Enter password to check its strength: ");
  fgets(password, 100, stdin); // read password input from user
  
  length = strlen(password); // check the length of password
  
  for (int i = 0; i < length; i++)
  {
    if (isupper(password[i])) // check for uppercase letters
      uppercase = 1;
      
    if (islower(password[i])) // check for lowercase letters
      lowercase = 1;
      
    if (isdigit(password[i])) // check for digits
      digit = 1;
      
    if (!isalnum(password[i])) // check for symbols
      symbol = 1;
  }
  
  // check password strength conditions
  if (length < 8 || uppercase == 0 || lowercase == 0 || digit == 0 || symbol == 0)
    printf("Password is weak!\n");
  else if (length < 12 || uppercase == 1 && lowercase == 1 && digit == 1 && symbol == 1)
    printf("Password is strong!\n");
  else
    printf("Password is very strong!\n");
    
  return 0;
}