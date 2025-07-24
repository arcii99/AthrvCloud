//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: statistical
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int num_count = 0, upper_count = 0, lower_count = 0, special_char_count = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    int password_length = strlen(password);

    for(int i = 0; i < password_length; i++) {
        if(password[i] >= '0' && password[i] <= '9') {
            num_count++;
        } else if(password[i] >= 'A' && password[i] <= 'Z') {
            upper_count++;
        } else if(password[i] >= 'a' && password[i] <= 'z') {
            lower_count++;
        } else {
            special_char_count++;
        }
    }

    printf("----------------- Statistics -----------------\n");

    printf("Password length: %d \n", password_length);
    printf("Number of digits: %d \n", num_count);
    printf("Number of uppercase characters: %d \n", upper_count);
    printf("Number of lowercase characters: %d \n", lower_count);
    printf("Number of special characters: %d \n", special_char_count);

    int score = 0;

    if(password_length >= 8) {
        score++;
    }

    if(num_count >= 2) {
        score++;
    }

    if(upper_count >= 2) {
        score++;
    }

    if(lower_count >= 2) {
        score++;
    }

    if(special_char_count >= 2) {
        score++;
    }

    printf("\n--------- Password Strength Score ---------\n");

    if(score == 5) {
        printf("Congratulations! Your password is extremely strong.\n");
    } else if(score == 4) {
        printf("Your password is very strong.\n");
    } else if(score == 3) {
        printf("Your password is strong.\n");
    } else if(score == 2) {
        printf("Your password is medium strength.\n");
    } else if(score == 1) {
        printf("Your password is weak.\n");
    } else {
        printf("Your password is very weak. Please consider changing it.\n");
    }

    return 0;
}