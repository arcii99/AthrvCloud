//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>

int main()
{
  // password strength variables
  int length = 0, uppercase = 0, lowercase = 0, digits = 0, symbols = 0;

  char password[50];

  // get user input for password
  printf("Enter password: ");
  scanf("%s", password);

  length = strlen(password);

  // check for password length
  if (length < 8)
  {
    printf("Password is too short!\n");
    return 0;
  }

  // check for uppercase, lowercase letters, digits and symbols
  for (int i = 0; i < length; i++)
  {
    if (password[i] >= 'A' && password[i] <= 'Z')
      uppercase = 1;
    else if (password[i] >= 'a' && password[i] <= 'z')
      lowercase = 1;
    else if (password[i] >= '0' && password[i] <= '9')
      digits = 1;
    else
      symbols = 1;
  }

  // check if the password contains required criteria
  if (uppercase == 1 && lowercase == 1 && digits == 1 && symbols == 1)
  {
    printf("Password is strong!\n");
  }
  else
  {
    printf("Password is not strong enough!\n");
  }

  return 0;
}