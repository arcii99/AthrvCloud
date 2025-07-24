//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int check_uppercase(char password[]);
int check_lowercase(char password[]);
int check_digit(char password[]);
int check_special(char password[]);
int calc_score(char password[]);
void print_strength(int score);

int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    int score = calc_score(password);
    printf("Password strength: ");
    print_strength(score);
    return 0;
}

int check_uppercase(char password[]) {
    int length = strlen(password);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            count++;
        }
    }
    return count;
}

int check_lowercase(char password[]) {
    int length = strlen(password);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            count++;
        }
    }
    return count;
}

int check_digit(char password[]) {
    int length = strlen(password);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            count++;
        }
    }
    return count;
}

int check_special(char password[]) {
    int length = strlen(password);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            count++;
        }
    }
    return count;
}

int calc_score(char password[]) {
    int upper = check_uppercase(password);
    int lower = check_lowercase(password);
    int digit = check_digit(password);
    int special = check_special(password);
    double length = strlen(password);
    double score = (upper/length)*25 + (lower/length)*25 + (digit/length)*25 + (special/length)*25;
    score = round(score);
    return (int)score;
}

void print_strength(int score) {
    if (score >= 80) {
        printf("Strong\n");
    } else if (score >= 60) {
        printf("Moderate\n");
    } else {
        printf("Weak\n");
    }
}