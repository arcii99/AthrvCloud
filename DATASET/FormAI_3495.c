//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LOWER_ALPHA "abcdefghijklmnopqrstuvwxyz"
#define UPPER_ALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()_+[]\\;',./{}|\":<>?"

#define MAX_LEN 100

int main()
{
  char password[MAX_LEN];
  int len, has_lower, has_upper, has_digit, has_special;

  printf("Enter password: ");
  fgets(password, MAX_LEN, stdin);
  len = strlen(password);

  if (len < 8 || len > 16)
  {
    printf("Password length should be between 8 and 16 characters.\n");
    exit(0);
  }

  has_lower = has_upper = has_digit = has_special = 0;

  for (int i = 0; i < len; i++)
  {
    char c = password[i];
    if (strchr(LOWER_ALPHA, c))
      has_lower = 1;
    else if (strchr(UPPER_ALPHA, c))
      has_upper = 1;
    else if (strchr(NUMBERS, c))
      has_digit = 1;
    else if (strchr(SPECIAL_CHARS, c))
      has_special = 1;
  }

  if (!has_lower)
    printf("Password should contain at least one lowercase character.\n");
  if (!has_upper)
    printf("Password should contain at least one uppercase character.\n");
  if (!has_digit)
    printf("Password should contain at least one digit.\n");
  if (!has_special)
    printf("Password should contain at least one special character.\n");

  if (has_lower && has_upper && has_digit && has_special)
    printf("The password is strong.\n");

  return 0;
}