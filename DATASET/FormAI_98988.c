//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int length, lower, upper, number, special, score;
    printf("Enter your password to be checked:\n");
    fgets(password, sizeof(password), stdin);
    length = strlen(password) - 1;
    lower = upper = number = special = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i]))
            lower++;
        else if (isupper(password[i]))
            upper++;
        else if (isdigit(password[i]))
            number++;
        else if (ispunct(password[i]))
            special++;
    }
    score = lower + upper + number + special;
    if (length < 8) {
        printf("This password is weak, my dear friend. It's too short!\n");
        printf("I suggest you to use at least 8 characters!\n");
    }
    else if (score < 4) {
        printf("This password is weak, my dear friend. It needs more complexity!\n");
        printf("I suggest you to use upper and lower case letters, numbers, and special characters.\n");
    }
    else if (score < 8) {
        printf("This password is okay, my dear friend, but it still needs more complexity!\n");
        printf("I suggest you to use more upper and lower case letters, numbers, and special characters.\n");
    }
    else {
        printf("This password is strong, my dear friend. Congratulations!\n");
        printf("Good job to add complexity with upper and lower case letters, numbers, and special characters.\n");
    }
    return 0;
}