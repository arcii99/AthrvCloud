//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_password_strength(char password[]) {
    int length = strlen(password);
    int uppercase_flag = 0;
    int lowercase_flag = 0;
    int digit_flag = 0;
    int special_char_flag = 0;
    int i;
    
    if (length < 8) // Password must be at least 8 characters long
        return 0;
  
    for(i = 0; i < length; i++) {
        if (isdigit(password[i])) // Checking for digit
            digit_flag = 1;
        else if (islower(password[i])) // Checking for lowercase alphabets
            lowercase_flag = 1;
        else if (isupper(password[i])) // Checking for uppercase alphabets
            uppercase_flag = 1;
        else // Anything that is not digit or alphabet is considered a special character
            special_char_flag = 1;
    }
    
    if (digit_flag == 0 || uppercase_flag == 0 || lowercase_flag == 0 || special_char_flag == 0) // If any of these flags remain 0 means we didn't get corresponding character types
        return 0;
  
    else // Otherwise, password is strong!
        return 1;
}

int main() {
    char password[50];
    int strength_result;
  
    printf("Enter password: ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\r\n")] = 0; // Remove trailing newline caused by fgets
  
    strength_result = check_password_strength(password);
  
    if (strength_result == 1)
        printf("Valid password. Your password is strong!\n");
    else
        printf("Your password is weak or invalid. Please make sure your password contains at least one uppercase letter, one lowercase letter, one digit and one special character and length should be at least 8 characters.\n");
  
    return 0;
}