//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main() {
  char password[100];
  int length, score = 0;
  
  printf("Enter your password: ");
  scanf("%s", password);
  
  length = strlen(password);
  
  for(int i = 0; i < length; i++) {
    // Case 1: Add points for uppercase characters
    score += (password[i] >= 65 && password[i] <= 90) ? 2 : 0;
  
    // Case 2: Add points for lowercase characters
    score += (password[i] >= 97 && password[i] <= 122) ? 1 : 0;
  
    // Case 3: Add points for digits
    score += (password[i] >= 48 && password[i] <= 57) ? 1 : 0;
  
    // Case 4: Add points for special characters
    score += (password[i] >= 32 && password[i] <= 47) ? 3 : 0;
    score += (password[i] >= 58 && password[i] <= 64) ? 3 : 0;
    score += (password[i] >= 91 && password[i] <= 96) ? 3 : 0;
    score += (password[i] >= 123 && password[i] <= 126) ? 3 : 0;
  }
  
  // Determine the strength of the password
  if(score < 5)
    printf("The password is weak");
  else if(score < 10)
    printf("The password is moderate");
  else if(score < 15)
    printf("The password is strong");
  else
    printf("The password is very strong");
  
  return 0;
}