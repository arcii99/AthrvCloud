//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Ken Thompson Password Checker */
/* This program checks the strength of a password */

int main() 
{
  char password[100];
  int length, num_count = 0, up_count = 0, low_count = 0, spec_count = 0, strength, i;

  printf("Enter your password: ");
  fgets(password, 100, stdin);

  length = strlen(password) - 1;

  for (i = 0; i < length; i++)
  {
    if (isdigit(password[i]))
    {
      num_count++;
    }
    else if (isupper(password[i]))
    {
      up_count++;
    }
    else if (islower(password[i]))
    {
      low_count++;
    }
    else
    {
      spec_count++;
    }
  }

  if (length < 8)
  {
    printf("Password strength is weak: %d characters\n", length);
    strength = 1;
  }
  else if (length < 12 && num_count > 0 && (up_count > 0 || low_count > 0) && spec_count > 0)
  {
    printf("Password strength is moderate: %d characters, contains numbers, letters, and special characters\n", length);
    strength = 2;
  }
  else if (length >= 12 && num_count > 0 && up_count > 0 && low_count > 0 && spec_count > 0) 
  {
    printf("Password strength is strong: %d characters, contains numbers, upper and lowercase letters, and special characters\n", length);
    strength = 3;
  } 
  else 
  {
    printf("Password strength is weak: %d characters\n", length);
    strength = 1;
  }

  if (strength == 1)
  {
    printf("Improvement needed on password strength - please consider a longer password with a mix of letters, numbers, and special characters.\n");
  }
  else if (strength == 2)
  {
    printf("Consider adding uppercase letters and/or increasing password length.\n");
  }
  else if (strength == 3)
  {
    printf("Great job on creating a strong password!\n");
  }

  return 0;
}