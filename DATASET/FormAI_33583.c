//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complex
// This program checks the strength of a user-inputted password, based on a set of requirements.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
int check_length(char* password);
int check_uppercase(char* password);
int check_lowercase(char* password);
int check_special(char* password);
int check_numbers(char* password);

int main(){
    char password[100];
    int length, uppercase, lowercase, special, numbers, score;

    printf("Enter your password: ");
    fgets(password, 100, stdin);

    length = check_length(password);
    uppercase = check_uppercase(password);
    lowercase = check_lowercase(password);
    special = check_special(password);
    numbers = check_numbers(password);

    score = length + uppercase + lowercase + special + numbers;

    if(score <=5){
        printf("Your password is very weak. Please try again.\n");
    } else if(score <= 8){
        printf("Your password is weak. Please try again.\n");
    } else if(score <= 11){
        printf("Your password is decent, but could be stronger. Consider using a longer password with more special characters and numbers.\n");
    } else if(score <= 14){
        printf("Your password is strong. Keep up the good work!\n");
    } else {
        printf("Your password is very strong. Excellent job!\n");
    }

    return 0;
}

int check_length(char* password){
    int len = strlen(password) - 1;
    if(len < 8){
        printf("Your password is too short. It must be at least 8 characters long.\n");
        return 0;
    } else if(len >= 20){
        printf("Your password is too long. It must be less than 20 characters long.\n");
        return 0;
    } else {
        return 1;
    }
}

int check_uppercase(char* password){
    int i, flag = 0;
    for(i=0; password[i]!='\0'; i++){
        if(isupper(password[i])){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Your password must contain at least one uppercase letter.\n");
        return 0;
    } else {
        return 2;
    }
}

int check_lowercase(char* password){
    int i, flag = 0;
    for(i=0; password[i]!='\0'; i++){
        if(islower(password[i])){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Your password must contain at least one lowercase letter.\n");
        return 0;
    } else {
        return 2;
    }
}

int check_special(char* password){
    int i, flag = 0;
    char special_chars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', ';', ':', '<', '>', ',', '.', '/', '?'};
    for(i=0; password[i]!='\0'; i++){
        for(int j=0; j<26; j++){
            if(password[i] == special_chars[j]){
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0){
        printf("Your password must contain at least one special character.\n");
        return 0;
    } else {
        return 3;
    }
}

int check_numbers(char* password){
    int i, flag = 0;
    for(i=0; password[i]!='\0'; i++){
        if(isdigit(password[i])){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Your password must contain at least one number.\n");
        return 0;
    } else {
        return 2;
    }
}