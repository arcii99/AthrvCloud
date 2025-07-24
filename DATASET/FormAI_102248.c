//FormAI DATASET v1.0 Category: Data validation ; Style: introspective
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char name[50], email[50], phone[15], age[4]; // Declare variables for user input 
    int valid = 1; // Set a flag for whether input is valid

    printf("Please enter your name: ");
    fgets(name, 50, stdin); // Read user input for name

    printf("Please enter your age: ");
    fgets(age, 4, stdin); // Read user input for age

    printf("Please enter your email: ");
    fgets(email, 50, stdin); // Read user input for email

    printf("Please enter your phone number (format: 555-555-5555): ");
    fgets(phone, 15, stdin); // Read user input for phone number

    // Remove newline characters from user inputs
    name[strcspn(name, "\n")] = 0;
    age[strcspn(age, "\n")] = 0;
    email[strcspn(email, "\n")] = 0;
    phone[strcspn(phone, "\n")] = 0;

    // Validate name input
    for(int i = 0; i < strlen(name); i++) {
        if(!isalpha(name[i]) && name[i] != ' ') { // Check if name contains only letters and spaces
            valid = 0; // Set flag to invalid
            printf("Invalid name input. Please enter only letters and spaces.\n");
            break;
        }
    }

    // Validate age input
    for(int i = 0; i < strlen(age); i++) {
        if(!isdigit(age[i])) { // Check if age contains only digits
            valid = 0; // Set flag to invalid
            printf("Invalid age input. Please enter only digits.\n");
            break;
        }
    }

    // Validate email input
    int at_count = 0, dot_count = 0;
    for(int i = 0; i < strlen(email); i++) {
        if(email[i] == '@') {
            at_count++;
        } else if(email[i] == '.') {
            dot_count++;
        }
    }
    if(at_count != 1 || dot_count < 1) { // Check if email contains exactly one @ symbol and at least one .
        valid = 0; // Set flag to invalid
        printf("Invalid email input. Please enter a valid email address.\n");
    }

    // Validate phone input
    if(strlen(phone) != 12 || phone[3] != '-' || phone[7] != '-') { // Check if phone input adheres to format: 555-555-5555
        valid = 0; // Set flag to invalid
        printf("Invalid phone input. Please enter a phone number in the format: 555-555-5555.\n");
    } else {
        for(int i = 0; i < strlen(phone); i++) {
            if(i != 3 && i != 7 && !isdigit(phone[i])) { // Check if phone number contains only digits and the characters '-'
                valid = 0; // Set flag to invalid
                printf("Invalid phone input. Please enter only digits and '-' characters in the format: 555-555-5555.\n");
                break;
            }
        }
    }

    // If input is valid, print a success message
    if(valid) {
        printf("Success! Your inputs are:\nName: %s\nAge: %s\nEmail: %s\nPhone: %s\n", name, age, email, phone);
    }

    return 0;
}