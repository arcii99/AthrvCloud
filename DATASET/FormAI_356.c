//FormAI DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

int num_contacts = 0;
Contact phone_book[MAX_CONTACTS];

void add_contact() {
    if (num_contacts == MAX_CONTACTS) {
        printf("Phone book is full\n");
        return;
    }

    printf("Enter name: ");
    fgets(phone_book[num_contacts].name, NAME_LENGTH, stdin);
    phone_book[num_contacts].name[strcspn(phone_book[num_contacts].name, "\n")] = '\0';

    printf("Enter phone number: ");
    fgets(phone_book[num_contacts].phone, PHONE_LENGTH, stdin);
    phone_book[num_contacts].phone[strcspn(phone_book[num_contacts].phone, "\n")] = '\0';

    num_contacts++;
}

void search_contact(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Phone number for %s is %s\n", name, phone_book[i].phone);
            return;
        }
    }

    printf("No contact found for %s\n", name);
}

void print_phone_book() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].phone);
    }
}

int main() {
    printf("Welcome to Curious Phone Book!\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("\t1. Add a contact\n");
        printf("\t2. Search for a phone number\n");
        printf("\t3. Print phone book\n");
        printf("\t4. Quit\n");

        char option_str[NAME_LENGTH];
        fgets(option_str, NAME_LENGTH, stdin);

        if (strcmp(option_str, "1\n") == 0) {
            add_contact();
        } else if (strcmp(option_str, "2\n") == 0) {
            printf("Enter name: ");
            char name[NAME_LENGTH];
            fgets(name, NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = '\0';
            search_contact(name);
        } else if (strcmp(option_str, "3\n") == 0) {
            print_phone_book();
        } else if (strcmp(option_str, "4\n") == 0) {
            printf("Thank you for using Curious Phone Book!\n");
            return 0;
        } else {
            printf("Invalid option\n");
        }
    }
}