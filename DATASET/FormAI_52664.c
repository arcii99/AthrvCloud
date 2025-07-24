//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main() {

  char password[100];
  int i, len, digit, lowercase, uppercase, specialchar;

  printf("Enter Password: ");
  fgets(password, 100, stdin);

  len = strlen(password) - 1;

  if (len < 8) {
    printf("\nPassword is too short. It should be at least 8 characters long.\n");
    return 0;
  }

  digit = lowercase = uppercase = specialchar = 0;
  
  for(i = 0; i < len; i++) {
    if(password[i] >= '0' && password[i] <= '9')
      digit++;
    else if(password[i] >= 'a' && password[i] <= 'z')
      lowercase++;
    else if(password[i] >= 'A' && password[i] <= 'Z')
      uppercase++;
    else
      specialchar++;
  }

  if(digit >= 2 && lowercase >= 2 && uppercase >= 2 && specialchar >= 2) {
    printf("\nCongratulations! Password is Strong.\n");
    return 0;
  }

  printf("\nWeak Password. Password should contain:\n");
  printf("- At least 2 digits\n");
  printf("- At least 2 lowercase letters\n");
  printf("- At least 2 uppercase letters\n");
  printf("- At least 2 special characters (!, @, #, $, %, ^, &, *)\n");

  return 0;
}