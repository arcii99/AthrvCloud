//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, letters = 0, digits = 0, uppercase = 0, lowercase = 0, special = 0;
    printf("Enter a password: ");
    scanf("%s", password);
    length = strlen(password);

    // Counting the number of letters, digits, uppercase and lowercase letters, and special characters.
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digits++;
        } else if (isalpha(password[i])) {
            letters++;
            if (isupper(password[i])) {
                uppercase++;
            } else if (islower(password[i])) {
                lowercase++;
            }
        } else {
            special++;
        }
    }

    // Determining the strength of the password based on various criteria.
    if (length < 8) {
        printf("This password is too short. Please enter at least an 8 character password, Mr. Watson.\n");
    } else if (letters == 0) {
        printf("Your password needs letters, Mr. Watson. A password without letters is like a violin without strings.\n");
    } else if (digits == 0) {
        printf("A password without numbers is like a lock without a key, Mr. Watson.\n");
    } else if (uppercase == 0) {
        printf("This password could use some uppercase letters, Mr. Watson. You wouldn't go to a party dressed in just plain clothes, would you?\n");
    } else if (lowercase == 0) {
        printf("This password could use some lowercase letters, Mr. Watson. You wouldn't want to shout at everyone by using only uppercase letters, would you?\n");
    } else if (special == 0) {
        printf("This password could use some special characters, Mr. Watson. A strong password is like a puzzle that cannot be solved easily.\n");
    } else {
        printf("Well done, Mr. Watson! This password meets all the criteria of a strong password. The game is afoot!\n");
    }

    return 0;
}