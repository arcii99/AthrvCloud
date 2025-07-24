//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8

void clear_input_buffer() {
    while(getchar() != '\n');
}

int is_upper_case(char c) {
    return c >= 'A' && c <= 'Z';
}

int is_lower_case(char c) {
    return c >= 'a' && c <= 'z';
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_special_char(char c) {
    return !is_lower_case(c) && !is_upper_case(c) && !is_digit(c);
}

int check_password_strength(char *password) {
    int length = strlen(password);
    int score = 0;
    int has_upper_case = 0;
    int has_lower_case = 0;
    int has_digit = 0;
    int has_special_char = 0;

    for(int i = 0; i < length; i++) {
        if(is_upper_case(password[i])) {
            has_upper_case = 1;
        }
        else if(is_lower_case(password[i])) {
            has_lower_case = 1;
        }
        else if(is_digit(password[i])) {
            has_digit = 1;
        }
        else if(is_special_char(password[i])) {
            has_special_char = 1;
        }
    }

    if(has_upper_case) {
        score++;
    }
    else {
        printf("Password must contain at least one upper case letter.\n");
    }

    if(has_lower_case) {
        score++;
    }
    else {
        printf("Password must contain at least one lower case letter.\n");
    }

    if(has_digit) {
        score++;
    }
    else {
        printf("Password must contain at least one digit.\n");
    }

    if(has_special_char) {
        score++;
    }
    else {
        printf("Password must contain at least one special character.\n");
    }

    if(length >= MIN_LENGTH) {
        score++;
    }
    else {
        printf("Password must be at least %d characters long.\n", MIN_LENGTH);
    }

    return score;
}

void print_strength_message(int score) {
    printf("Password strength: ");

    switch(score) {
        case 0:
        case 1:
            printf("Very weak");
            break;
        case 2:
            printf("Weak");
            break;
        case 3:
            printf("Moderate");
            break;
        case 4:
            printf("Strong");
            break;
        case 5:
            printf("Very strong");
            break;
        default:
            printf("Invalid score");
            break;
    }

    printf("\n");
}

int main() {
    char password[100];

    printf("Enter password: ");
    fgets(password, 100, stdin);

    // Remove newline character from password
    password[strcspn(password, "\n")] = '\0';

    int score = check_password_strength(password);

    if(score < 5) {
        printf("Password is not strong enough. Please try again.\n");
        main();
    }
    else {
        print_strength_message(score);
    }

    return 0;
}