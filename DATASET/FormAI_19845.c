//FormAI DATASET v1.0 Category: Data validation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int validateData(char* name, char* phone, char* email) {
    // Validation for name
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && !isspace(name[i])) {
            printf("Invalid name! Name can only contain alphabets and spaces.\n");
            return 0;
        }
    }
    
    // Validation for phone number
    for (int i = 0; phone[i] != '\0'; i++) {
        if (!isdigit(phone[i]) && phone[i] != ' ' && phone[i] != '-') {
            printf("Invalid phone number! Phone number can only contain digits, spaces and dashes.\n");
            return 0;
        }
    }
    
    // Validation for email
    int at_count = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            at_count++;
        }
    }
    if (at_count != 1) {
        printf("Invalid email address! Email address must contain exactly one '@' character.\n");
        return 0;
    }
    
    // If all validations pass, return 1
    return 1;
}

int main() {
    char name[50], phone[15], email[50];
    
    // Get user input
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter your phone number: ");
    fgets(phone, sizeof(phone), stdin);
    printf("Enter your email address: ");
    fgets(email, sizeof(email), stdin);
    
    // Remove trailing newline characters
    name[strcspn(name, "\n")] = 0;
    phone[strcspn(phone, "\n")] = 0;
    email[strcspn(email, "\n")] = 0;
    
    // Validate user input
    if (validateData(name, phone, email)) {
        printf("Data validated successfully!\n");
    }
    
    return 0;
}