//FormAI DATASET v1.0 Category: Data validation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 256

typedef struct {
    char firstName[MAX_STRING_SIZE];
    char lastName[MAX_STRING_SIZE];
    char email[MAX_STRING_SIZE];
    char phoneNumber[MAX_STRING_SIZE];
} User;

bool isValidEmail(char* email) {
    // Check for "@" symbol and at least one "."
    int countAtSymbol = 0;
    int countDotSymbol = 0;
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            countAtSymbol++;
        }
        else if (email[i] == '.') {
            countDotSymbol++;
        }
    }
    if (countAtSymbol == 1 && countDotSymbol > 0) {
        return true;
    }
    else {
        return false;
    }
}

bool isValidPhoneNumber(char* phoneNumber) {
    // Check for 10 digits and optional "-"'s, "(", and ")"
    int countDigits = 0;
    for (int i = 0; i < strlen(phoneNumber); i++) {
        if (isdigit(phoneNumber[i])) {
            countDigits++;
        }
        else if (phoneNumber[i] != '-' && phoneNumber[i] != '(' && phoneNumber[i] != ')') {
            return false;
        }
    }
    if (countDigits == 10) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    User user;
    printf("Enter first name: ");
    fgets(user.firstName, MAX_STRING_SIZE, stdin);
    user.firstName[strcspn(user.firstName, "\n")] = '\0';
    printf("Enter last name: ");
    fgets(user.lastName, MAX_STRING_SIZE, stdin);
    user.lastName[strcspn(user.lastName, "\n")] = '\0';

    // Validate email
    bool isValid = false;
    while (!isValid) {
        printf("Enter email: ");
        fgets(user.email, MAX_STRING_SIZE, stdin);
        user.email[strcspn(user.email, "\n")] = '\0';
        if (isValidEmail(user.email)) {
            isValid = true;
        }
        else {
            printf("Invalid email! Must contain '@' and at least one '.'\n");
        }
    }

    // Validate phone number
    isValid = false;
    while (!isValid) {
        printf("Enter phone number (format: xxx-xxx-xxxx): ");
        fgets(user.phoneNumber, MAX_STRING_SIZE, stdin);
        user.phoneNumber[strcspn(user.phoneNumber, "\n")] = '\0';
        if (isValidPhoneNumber(user.phoneNumber)) {
            isValid = true;
        }
        else {
            printf("Invalid phone number! Must contain 10 digits and optional '-''s, '(', and ')'\n");
        }
    }

    printf("\nUser information:\n");
    printf("First name: %s\n", user.firstName);
    printf("Last name: %s\n", user.lastName);
    printf("Email: %s\n", user.email);
    printf("Phone number: %s\n", user.phoneNumber);

    return 0;
}