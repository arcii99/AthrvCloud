//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i, upper = 0, lower = 0, digit = 0, special = 0, score = 0;

    printf("Enter a password:\n");
    fgets(password, 100, stdin); // Allow spaces in input
    
    length = strlen(password) - 1; // Exclude newline character
    
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) { // Check upper case
            upper = 1;
        } else if (islower(password[i])) { // Check lower case
            lower = 1;
        } else if (isdigit(password[i])) { // Check digit
            digit = 1;
        } else if (ispunct(password[i])) { // Check special character
            special = 1;
        }
    }

    score += length * 2; // Points for length
    score += upper * 4; // Points for upper case
    score += lower * 2; // Points for lower case
    score += digit * 3; // Points for digit
    score += special * 5; // Points for special character
    
    printf("Password strength score: %d\n", score);

    if (score >= 40) {
        printf("Password is very strong.\n");
    } else if (score >= 30) {
        printf("Password is strong.\n");
    } else if (score >= 20) {
        printf("Password is weak.\n");
    } else {
        printf("Password is very weak.\n");
    }

    return 0;
}