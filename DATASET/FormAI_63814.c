//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 100

int main() {
    char email[MAX_EMAIL_LENGTH + 1]; // +1 for null terminator
    int invalid_chars = 0;
    printf("Please enter a valid email address: ");
    fgets(email, MAX_EMAIL_LENGTH + 1, stdin); // read up to MAX_EMAIL_LENGTH chars
    if (email[strlen(email) - 1] == '\n') {
        email[strlen(email) - 1] = '\0'; // remove newline character
    }
    for (int i = 0; i < strlen(email); i++) {
        if (!isalnum(email[i]) && email[i] != '.' && email[i] != '@') {
            invalid_chars++;
        }
    }
    if (invalid_chars == 0) {
        printf("Valid email address: %s\n", email);
    } else {
        printf("Invalid email address: %s\n", email);
    }
    return 0;
}