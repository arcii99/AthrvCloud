//FormAI DATASET v1.0 Category: Database querying ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_BIRTHDAY_LENGTH 11

#define MAX_CONTACTS 1000

struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char birthday[MAX_BIRTHDAY_LENGTH];
};

void trimWhitespace(char *s) {
    char *p = s;
    int l = strlen(p);

    while (isspace(p[l - 1])) p[--l] = 0;
    while (*p && isspace(*p)) ++p, --l;

    memmove(s, p, l + 1);
}

bool isValidPhone(char *phone) {
    for (int i = 0; i < strlen(phone); i++) {
        if ((phone[i] < '0' || phone[i] > '9') && phone[i] != '-') {
            return false;
        }
    }
    return true;
}

bool isValidBirthday(char *birthday) {
    for (int i = 0; i < strlen(birthday); i++) {
        if ((birthday[i] < '0' || birthday[i] > '9') && birthday[i] != '-') {
            return false;
        }
    }
    return true;
}

void addContact(struct Contact *contacts, int *numContacts) {
    struct Contact contact;

    printf("Enter name: ");
    fgets(contact.name, MAX_NAME_LENGTH, stdin);
    trimWhitespace(contact.name);

    printf("Enter phone number: ");
    fgets(contact.phone, MAX_PHONE_LENGTH, stdin);
    trimWhitespace(contact.phone);
    while (!isValidPhone(contact.phone)) {
        printf("Invalid phone number, try again: ");
        fgets(contact.phone, MAX_PHONE_LENGTH, stdin);
        trimWhitespace(contact.phone);
    }

    printf("Enter birthday (YYYY-MM-DD): ");
    fgets(contact.birthday, MAX_BIRTHDAY_LENGTH, stdin);
    trimWhitespace(contact.birthday);
    while (!isValidBirthday(contact.birthday)) {
        printf("Invalid birthday, try again: ");
        fgets(contact.birthday, MAX_BIRTHDAY_LENGTH, stdin);
        trimWhitespace(contact.birthday);
    }

    contacts[*numContacts] = contact;
    (*numContacts)++;
}

void printContact(struct Contact contact) {
    printf("Name: %s\n", contact.name);
    printf("Phone: %s\n", contact.phone);
    printf("Birthday: %s\n", contact.birthday);
}

void searchContacts(struct Contact *contacts, int numContacts) {
    char searchTerm[MAX_NAME_LENGTH];
    printf("Enter search term: ");
    fgets(searchTerm, MAX_NAME_LENGTH, stdin);
    trimWhitespace(searchTerm);

    bool foundMatch = false;

    for (int i = 0; i < numContacts; i++) {
        if (strstr(contacts[i].name, searchTerm) != NULL) {
            foundMatch = true;
            printContact(contacts[i]);
            printf("\n");
        }
    }

    if (!foundMatch) {
        printf("No results found.\n");
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;

    while (true) {
        printf("\n");
        printf("1. Add contact\n");
        printf("2. Search contacts\n");
        printf("3. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        char choiceStr[10];
        fgets(choiceStr, 10, stdin);

        int choice = atoi(choiceStr);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                searchContacts(contacts, numContacts);
                break;
            case 3:
                printf("Bye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}