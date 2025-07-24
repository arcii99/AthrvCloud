//FormAI DATASET v1.0 Category: Data validation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_header(char *header) {
    printf("\n\n\n*** %s ***\n\n", header);
}

int main() {
    char name[50];
    char age[5];
    char address[100];
    char email[50];
    char phone[12];
    int is_valid = 1;

    print_header("C DATA VALIDATION SYSTEM");

    // Name Validation
    do {
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;
        
        for (int i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i]) && name[i] != ' ') {
                printf("Invalid input! Name can only contain alphabets and spaces.\n");
                is_valid = 0;
                break;
            }
        }
    } while (!is_valid);

    is_valid = 1;

    // Age Validation
    do {
        printf("Enter your age: ");
        fgets(age, sizeof(age), stdin);
        age[strcspn(age, "\n")] = 0;
        
        for (int i = 0; i < strlen(age); i++) {
            if (!isdigit(age[i])) {
                printf("Invalid input! Age can only contain numeric digits.\n");
                is_valid = 0;
                break;
            }
        }

        if (is_valid && atoi(age) < 18) {
            printf("Invalid input! Age must be at least 18 years.\n");
            is_valid = 0;
        }
    } while (!is_valid);

    is_valid = 1;

    // Address Validation
    do {
        printf("Enter your address: ");
        fgets(address, sizeof(address), stdin);
        address[strcspn(address, "\n")] = 0;

        if (strlen(address) < 10) {
            printf("Invalid input! Address must be at least 10 characters long.\n");
            is_valid = 0;
        }
    } while (!is_valid);

    is_valid = 1;

    // Email Validation
    do {
        printf("Enter your email address: ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = 0;

        int at_count = 0;
        int dot_count = 0;
        int at_index = -1;

        for (int i = 0; i < strlen(email); i++) {
            if (email[i] == '@') {
                at_count++;
                at_index = i;
            } else if (email[i] == '.') {
                dot_count++;
            }
        }

        if (at_count != 1 || dot_count < 1 || dot_count > 2 || at_index > dot_count) {
            printf("Invalid input! Enter a valid email address.\n");
            is_valid = 0;
        }
    } while (!is_valid);

    is_valid = 1;

    // Phone Validation
    do {
        printf("Enter your phone number: ");
        fgets(phone, sizeof(phone), stdin);
        phone[strcspn(phone, "\n")] = 0;

        for (int i = 0; i < strlen(phone); i++) {
            if (!isdigit(phone[i])) {
                printf("Invalid input! Phone number can only contain numeric digits.\n");
                is_valid = 0;
                break;
            }
        }

        if (is_valid && strlen(phone) != 10) {
            printf("Invalid input! Phone number must be 10 digits long.\n");
            is_valid = 0;
        }
    } while (!is_valid);

    printf("\n\n*** THANK YOU FOR PROVIDING VALID DATA! ***\n\n");

    return 0;
}