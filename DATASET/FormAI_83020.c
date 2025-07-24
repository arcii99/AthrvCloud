//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
  char password[50];
  int length, hasUpperCase=0, hasLowerCase=0, hasDigit=0, hasSpecialChar=0, strengthScore=0;
  
  printf(" Please enter a password to check its strength (must be at least 8 characters long):\n");
  scanf("%s", password);
  
  length = strlen(password);
  
  if (length < 8) {
    printf(" Password must be at least 8 characters long.\n");
    return 0;
  }
  
  for (int i=0; i<length; i++) {
    char currentChar = password[i];
    
    if (isupper(currentChar)) hasUpperCase = 1;
    else if (islower(currentChar)) hasLowerCase = 1;
    else if (isdigit(currentChar)) hasDigit = 1;
    else hasSpecialChar = 1;
  }
  
  strengthScore = hasUpperCase + hasLowerCase + hasDigit + hasSpecialChar;
  
  if (strengthScore < 3) printf(" Password is weak.\n");
  else if (strengthScore == 3) printf(" Password is moderate.\n");
  else printf(" Password is strong.\n");

  return 0;
}