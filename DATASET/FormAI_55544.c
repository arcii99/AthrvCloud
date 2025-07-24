//FormAI DATASET v1.0 Category: Data validation ; Style: creative
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 50

bool validate_name(char input[]);
bool validate_age(char input[]);
bool validate_email(char input[]);
bool validate_phone(char input[]);

int main() {
    char name[MAX_LENGTH], age[MAX_LENGTH], email[MAX_LENGTH], phone[MAX_LENGTH];
    bool valid_name, valid_age, valid_email, valid_phone;

    // Get user input
    printf("Please enter your name: ");
    fgets(name, MAX_LENGTH, stdin);

    printf("Please enter your age: ");
    fgets(age, MAX_LENGTH, stdin);

    printf("Please enter your email: ");
    fgets(email, MAX_LENGTH, stdin);

    printf("Please enter your phone number: ");
    fgets(phone, MAX_LENGTH, stdin);

    // Validate user input
    valid_name = validate_name(name);
    valid_age = validate_age(age);
    valid_email = validate_email(email);
    valid_phone = validate_phone(phone);

    // Print validation results
    if (valid_name && valid_age && valid_email && valid_phone) {
        printf("Your information has been successfully validated.\n");
    } else {
        printf("Your information could not be validated. Please check your inputs and try again.\n");
    }

    return 0;
}

bool validate_name(char input[]) {
    int i = 0;

    // Check if input is empty
    if (input[0] == '\n') {
        printf("Name cannot be empty.\n");
        return false;
    }

    // Check if input contains only letters or spaces
    while (input[i] != '\n') {
        if (!isalpha(input[i]) && !isspace(input[i])) {
            printf("Name can only contain letters or spaces.\n");
            return false;
        }
        i++;
    }

    return true;
}

bool validate_age(char input[]) {
    int i = 0;

    // Check if input is empty
    if (input[0] == '\n') {
        printf("Age cannot be empty.\n");
        return false;
    }

    // Check if input contains only digits
    while (input[i] != '\n') {
        if (!isdigit(input[i])) {
            printf("Age can only contain digits.\n");
            return false;
        }
        i++;
    }

    return true;
}

bool validate_email(char input[]) {
    int i = 0;
    bool contains_at = false;

    // Check if input is empty
    if (input[0] == '\n') {
        printf("Email cannot be empty.\n");
        return false;
    }

    // Check if input contains @ and .
    while (input[i] != '\n') {
        if (input[i] == '@') {
            contains_at = true;
        }
        if (contains_at && input[i] == '.') {
            return true;
        }
        i++;
    }

    printf("Email must be in valid format (example@example.com).\n");
    return false;
}

bool validate_phone(char input[]) {
    int i = 0;

    // Check if input is empty
    if (input[0] == '\n') {
        printf("Phone number cannot be empty.\n");
        return false;
    }

    // Check if input contains only digits and hyphens
    while (input[i] != '\n') {
        if (!isdigit(input[i]) && input[i] != '-') {
            printf("Phone number can only contain digits or hyphens.\n");
            return false;
        }
        i++;
    }

    return true;
}