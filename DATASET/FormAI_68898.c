//FormAI DATASET v1.0 Category: Data validation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15

// Structure for storing user information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} user_info;

// Function prototypes
bool validate_name(char *name);
bool validate_email(char *email);
bool validate_phone(char *phone);

int main() {
    user_info user;

    // Ask user for name
    printf("Enter your name: ");
    fgets(user.name, MAX_NAME_LENGTH, stdin);

    // Remove trailing newline from name
    user.name[strcspn(user.name, "\n")] = 0;

    // Ask user for email
    printf("Enter your email: ");
    fgets(user.email, MAX_EMAIL_LENGTH, stdin);

    // Remove trailing newline from email
    user.email[strcspn(user.email, "\n")] = 0;

    // Ask user for phone number
    printf("Enter your phone number: ");
    fgets(user.phone, MAX_PHONE_LENGTH, stdin);

    // Remove trailing newline from phone number
    user.phone[strcspn(user.phone, "\n")] = 0;

    // Validate user input
    validate_name(user.name);
    validate_email(user.email);
    validate_phone(user.phone);

    return 0;
}

// Function to validate user name
bool validate_name(char *name) {
    int len = strlen(name);

    // Check if name length is valid
    if (len < 2 || len > MAX_NAME_LENGTH - 1) {
        printf("Invalid name length\n");
        return false;
    }

    // Check if name contains only alphabets
    for (int i = 0; i < len; i++) {
        if (!isalpha(name[i])) {
            printf("Name must contain only alphabets\n");
            return false;
        }
    }

    printf("Name is valid: %s\n", name);
    return true;
}

// Function to validate user email
bool validate_email(char *email) {
    int len = strlen(email);

    // Check if email length is valid
    if (len < 5 || len > MAX_EMAIL_LENGTH - 1) {
        printf("Invalid email length\n");
        return false;
    }

    // Check if email contains @ and .
    int at_count = 0, dot_count = 0;
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            at_count++;
        } else if (email[i] == '.') {
            dot_count++;
        }
    }
    if (at_count != 1 || dot_count < 1) {
        printf("Invalid email format\n");
        return false;
    }

    printf("Email is valid: %s\n", email);
    return true;
}

// Function to validate user phone number
bool validate_phone(char *phone) {
    int len = strlen(phone);

    // Check if phone number length is valid
    if (len != 10 && len != 13) {
        printf("Invalid phone number length\n");
        return false;
    }

    // Check if phone number contains only digits
    for (int i = 0; i < len; i++) {
        if (!isdigit(phone[i])) {
            printf("Phone number must contain only digits\n");
            return false;
        }
    }

    printf("Phone number is valid: %s\n", phone);
    return true;
}