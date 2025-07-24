//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 20

void check_password_strength(char* password);

int main() {
    char password[MAX_LEN];
    printf("Enter your password (maximum length %d): ", MAX_LEN);
    fgets(password, MAX_LEN, stdin);
    password[strcspn(password, "\n")] = 0; //remove the trailing newline character
    
    check_password_strength(password); //call the function to check password strength
    
    return 0;
}

void check_password_strength(char* password) {
    int length = strlen(password);
    int score = 0;
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int special = 0;
    
    for(int i=0; i<length; i++) {
        //check for uppercase letters
        if(password[i] >= 'A' && password[i] <= 'Z') {
            upper = 1;
            score += 2;
        }
        //check for lowercase letters
        else if(password[i] >= 'a' && password[i] <= 'z') {
            lower = 1;
            score += 2;
        }
        //check for digits
        else if(password[i] >= '0' && password[i] <= '9') {
            digit = 1;
            score += 2;
        }
        //check for special characters
        else if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || 
                password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
            special = 1;
            score += 3;
        }
    }
    
    //check if password length is less than 8
    if(length < 8) {
        printf("Weak password - length should be at least 8 characters.\n");
        return;
    }
    //check if all types of characters are present
    else if(!upper || !lower || !digit || !special) {
        printf("Moderate password - include upper and lowercase letters, digits, and special characters.\n");
        return;
    }
    //check if score is less than 15
    else if(score < 15) {
        printf("Moderate password - include more upper and lowercase letters, digits, and special characters.\n");
        return;
    }
    else {
        printf("Strong password - score is %d.\n", score);
        return;
    }
}