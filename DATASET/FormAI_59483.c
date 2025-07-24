//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: single-threaded
#include <stdio.h>
#include <string.h>

int main() {

    char password[50];
    int length, hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;

    printf("Enter the Password: ");
    scanf("%s", password);

    length = strlen(password);

    for(int i = 0; i < length; i++) {

        if(password[i] >= 'a' && password[i] <= 'z') {
            hasLower = 1; 
        }
        else if(password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = 1; 
        }
        else if(password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1; 
        }
        else {
            hasSpecial = 1; 
        }
    }

    if(length < 8) { 
        printf("\nPassword is too short, it should have a minimum length of 8 characters\n");
    }
    else {
      if(hasLower && hasUpper && hasDigit && hasSpecial) {
          printf("\nThe password is Strong\n"); 
      }
      else if((hasLower || hasUpper) && hasDigit && hasSpecial) { 
          printf("\nThe password is Moderate\n"); 
      }
      else {
         printf("\nThe password is Weak\n"); 
      }
   }

   return 0;
}