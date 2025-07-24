//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LEN 8
#define MAX_LEN 40

int has_upper(char* password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

int has_lower(char* password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

int has_digit(char* password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

int has_symbol(char* password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

int get_strength_score(char* password) {
    int score = 0;
    if (strlen(password) >= MIN_LEN && strlen(password) <= MAX_LEN) {
        score++;
    }
    if (has_upper(password)) {
        score++;
    }
    if (has_lower(password)) {
        score++;
    }
    if (has_digit(password)) {
        score++;
    }
    if (has_symbol(password)) {
        score++;
    }
    return score;
}

void print_strength_level(int score) {
    switch (score) {
        case 1:
            printf("Your password strength level is weak.\n");
            printf("We recommend you choose a stronger password.\n");
            break;
        case 2:
            printf("Your password strength level is medium.\n");
            printf("We recommend you choose a stronger password.\n");
            break;
        case 3:
            printf("Your password strength level is good.\n");
            printf("Your password is strong enough, but you can make it even stronger.\n");
            break;
        case 4:
            printf("Your password strength level is very good!\n");
            printf("Congratulations, your password is strong enough for most purposes.\n");
            break;
        case 5:
            printf("Your password strength level is excellent!\n");
            printf("Fantastic, your password is nearly impossible to guess.\n");
            break;
        default:
            printf("Invalid score.\n");
            break;
    }
}

int main() {
    char password[MAX_LEN + 1];
    printf("Welcome to the Cyberpunk Password Strength Checker.\n");
    printf("Please enter your password (between %d and %d characters):\n", MIN_LEN, MAX_LEN);
    fgets(password, MAX_LEN + 1, stdin);
    password[strcspn(password, "\n")] = '\0';
    int score = get_strength_score(password);
    printf("\n");
    print_strength_level(score);
    return 0;
}