//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: safe
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32
#define SPECIAL_CHARACTERS "!@#$^&"


int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int i, upper_case_count = 0, lower_case_count = 0, digit_count = 0, special_char_count = 0;
    int password_score = 0;
    
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; //To remove the newline character from the end of the input
    
    // Check if password meets minimum length requirement
    if (strlen(password) < MIN_PASSWORD_LENGTH){
        printf("Password is too short. It must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        exit(EXIT_FAILURE);
    }
    
    // Check if password meets maximum length requirement
    if (strlen(password) > MAX_PASSWORD_LENGTH){
        printf("Password is too long. It cannot exceed %d characters.\n", MAX_PASSWORD_LENGTH);
        exit(EXIT_FAILURE);
    }
    
    for (i = 0; i < strlen(password); i++){
        char current_char = password[i];
        
        if (isupper(current_char)){
            upper_case_count++;
            password_score += 2;
        }
        else if (islower(current_char)){
            lower_case_count++;
            password_score += 2;
        }
        else if (isdigit(current_char)){
            digit_count++;
            password_score += 2;
        }
        else if (strchr(SPECIAL_CHARACTERS, current_char)){
            special_char_count++;
            password_score += 3;
        }
        else{
            password_score += 1;
        }
    }
    
    // Check for weak password
    if ((upper_case_count < 1) || (lower_case_count < 1) || (digit_count < 1)){
        printf("Weak Password. Must contain at least one uppercase letter, one lowercase letter and one digit.\n");
        exit(EXIT_FAILURE);
    }
    
    // Check for strong password
    if ((upper_case_count >= 1) && (lower_case_count >= 1) && (digit_count >= 1) && (special_char_count >= 1)){
        printf("Strong Password. Password Score: %d\n", password_score);
    }
    else{ // Medium Password
        printf("Medium Password. Password Score: %d\n", password_score);
    }
    return 0;
}