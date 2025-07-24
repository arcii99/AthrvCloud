//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i, upper, lower, digit, special;
    // Prompt user to input password
    printf("Please enter a password: ");
    fgets(password, 100, stdin);
    
    // Remove newline character from input
    length = strlen(password);
    if (password[length-1] == '\n') {
        password[length-1] = '\0';
    }
    
    // Check password strength
    upper = lower = digit = special = 0;
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper = 1;
        } else if (islower(password[i])) {
            lower = 1;
        } else if (isdigit(password[i])) {
            digit = 1;
        } else {
            special = 1;
        }
    }
    
    // Display password strength to user
    printf("Your password is ");
    if (length < 8 || !(upper && lower && digit && special)) {
        printf("weak.\n");
    } else if (length >= 8 && length < 12 && (upper || lower) && digit && special) {
        printf("moderate.\n");
    } else if (length >= 12 && (upper || lower) && digit && special) {
        printf("strong.\n");
    } else {
        printf("of unknown strength.\n");
    }
    
    return 0;
}