//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15

void sanitizeName(char* input, char* output);
void sanitizeEmail(char* input, char* output);
void sanitizePhone(char* input, char* output);

int main() {
    char input[MAX_INPUT_LENGTH];
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    // Prompt user to enter name, email, and phone number
    printf("Please enter your name: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitizeName(input, name);

    printf("Please enter your email: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitizeEmail(input, email);

    printf("Please enter your phone number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitizePhone(input, phone);

    // Print sanitized input
    printf("Sanitized input:\nName: %s\nEmail: %s\nPhone: %s", name, email, phone);

    return 0;
}

void sanitizeName(char* input, char* output) {
    int i, j = 0;

    for (i = 0; input[i] != '\0' && j < MAX_NAME_LENGTH-1; i++) {
        if (isalpha(input[i]) || isspace(input[i])) {
            output[j] = input[i];
            j++;
        }
    }

    // Add null terminator
    output[j] = '\0';
}

void sanitizeEmail(char* input, char* output) {
    int i, j = 0;

    for (i = 0; input[i] != '\0' && j < MAX_EMAIL_LENGTH-1; i++) {
        if (isalnum(input[i]) || input[i] == '@' || input[i] == '.') {
            output[j] = input[i];
            j++;
        }
    }

    // Add null terminator
    output[j] = '\0';
}

void sanitizePhone(char* input, char* output) {
    int i, j = 0;

    for (i = 0; input[i] != '\0' && j < MAX_PHONE_LENGTH-1; i++) {
        if (isdigit(input[i])) {
            output[j] = input[i];
            j++;
        }
    }

    // Add null terminator
    output[j] = '\0';
}