//FormAI DATASET v1.0 Category: Data validation ; Style: bold
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NAME_LENGTH 20
#define EMAIL_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

bool is_valid_name(char *name) {
    int len = strlen(name);
    if (len > NAME_LENGTH - 1 || len < 3) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool is_valid_email(char *email) {
    int len = strlen(email);
    if (len > EMAIL_LENGTH - 1) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha(email[i]) && !isdigit(email[i]) && email[i] != '@' && email[i] != '.' && email[i] != '_') {
            return false;
        }
    }
    return true;
}

bool is_valid_phone(char *phone) {
    int len = strlen(phone);
    if (len != PHONE_LENGTH - 1) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(phone[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    Contact c;
    printf("Enter contact name: ");
    fgets(c.name, NAME_LENGTH, stdin);
    c.name[strcspn(c.name, "\n")] = '\0';

    while (!is_valid_name(c.name)) {
        printf("Invalid name. Name must be between 3 and 20 characters and contain only letters and spaces.\n");
        printf("Enter contact name: ");
        fgets(c.name, NAME_LENGTH, stdin);
        c.name[strcspn(c.name, "\n")] = '\0';
    }

    printf("Enter contact email: ");
    fgets(c.email, EMAIL_LENGTH, stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    while (!is_valid_email(c.email)) {
        printf("Invalid email. Email must be less than 50 characters and contain only letters, digits, @, ., and _.\n");
        printf("Enter contact email: ");
        fgets(c.email, EMAIL_LENGTH, stdin);
        c.email[strcspn(c.email, "\n")] = '\0';
    }

    printf("Enter contact phone: ");
    fgets(c.phone, PHONE_LENGTH, stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    while (!is_valid_phone(c.phone)) {
        printf("Invalid phone. Phone must be 14 digits long and contain only digits.\n");
        printf("Enter contact phone: ");
        fgets(c.phone, PHONE_LENGTH, stdin);
        c.phone[strcspn(c.phone, "\n")] = '\0';
    }

    printf("Contact added successfully!\n");
    printf("Name: %s\nEmail: %s\nPhone: %s\n", c.name, c.email, c.phone);

    return 0;
}