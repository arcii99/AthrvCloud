//FormAI DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} PhoneBookEntry;

typedef struct {
    PhoneBookEntry contacts[MAX_CONTACTS];
    int numContacts;
} PhoneBook;

void addContact(PhoneBook *book, char *name, char *phone) {
    if (book->numContacts >= MAX_CONTACTS) {
        printf("Phone book is full\n");
        return;
    }
    PhoneBookEntry newContact;
    strncpy(newContact.name, name, MAX_NAME_LENGTH);
    strncpy(newContact.phone, phone, MAX_PHONE_LENGTH);
    book->contacts[book->numContacts] = newContact;
    book->numContacts++;
}

void printContacts(PhoneBook *book) {
    printf("=== Phone Book ===\n");
    for (int i = 0; i < book->numContacts; i++) {
        printf("%s: %s\n", book->contacts[i].name, book->contacts[i].phone);
    }
}

void removeContact(PhoneBook *book, char *name) {
    for (int i = 0; i < book->numContacts; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            // shift all contacts after this one back by one position
            for (int j = i; j < book->numContacts - 1; j++) {
                book->contacts[j] = book->contacts[j+1];
            }
            book->numContacts--;
            return;
        }
    }
    printf("%s not found in phone book\n", name);
}

int main() {
    PhoneBook book;
    book.numContacts = 0;

    addContact(&book, "Alice", "555-1234");
    addContact(&book, "Bob", "555-5678");
    addContact(&book, "Charlie", "555-9012");
    printContacts(&book);

    removeContact(&book, "Bob");
    printContacts(&book);

    addContact(&book, "Dave", "555-3456");
    addContact(&book, "Eve", "555-7890");
    printContacts(&book);

    return 0;
}