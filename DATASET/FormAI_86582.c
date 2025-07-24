//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: rigorous
#include<stdio.h>
#include<string.h>

int main() {
  char password[50];
  int length, uppercase_letters = 0, lowercase_letters = 0, digits = 0, symbols = 0, i;

  printf("Enter the password: ");
  scanf("%s", password);

  length = strlen(password);

  for(i=0;i<length;i++) {
    if(password[i]>='A' && password[i]<='Z') {
      uppercase_letters++;
    } else if(password[i]>='a' && password[i]<='z') {
      lowercase_letters++;
    } else if(password[i]>='0' && password[i]<='9') {
      digits++;
    } else {
      symbols++;
    }
  }

  if(length>=8 && uppercase_letters>=1 && lowercase_letters>=1 && digits>=1 && symbols>=1) {
    printf("Strong Password\n");
  } else if(length>=6 && uppercase_letters>=1 && lowercase_letters>=1 && digits>=1) {
    printf("Moderately Strong Password\n");
  } else {
    printf("Weak Password\n");
    if(length<8) {
      printf("Minimum length must be 8\n");
    }
    if(uppercase_letters<1) {
      printf("At least one uppercase letter is required\n");
    }
    if(lowercase_letters<1) {
      printf("At least one lowercase letter is required\n");
    }
    if(digits<1) {
      printf("At least one digit is required\n");
    }
    if(symbols<1) {
      printf("At least one symbol is required\n");
    }
  }

  return 0;
}