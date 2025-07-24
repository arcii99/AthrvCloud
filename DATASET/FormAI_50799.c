//FormAI DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 50
#define NAME_LENGTH 50
#define PHONE_LENGTH 20

// Define Contact structure
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

// Define PhoneBook structure
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

// Add Contact to PhoneBook
void addContact(PhoneBook* book, Contact contact) {
    if (book->count >= MAX_CONTACTS) {
        printf("Error: PhoneBook is full.\n");
        return;
    }

    book->contacts[book->count++] = contact;
}

// Find Contact in PhoneBook by name
int findContact(PhoneBook* book, char* name) {
    for (int i = 0; i < book->count; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// Remove Contact from PhoneBook by name
void removeContact(PhoneBook* book, char* name) {
    int index = findContact(book, name);

    if (index == -1) {
        printf("Error: Contact not found.\n");
        return;
    }

    for (int i = index; i < book->count - 1; i++) {
        book->contacts[i] = book->contacts[i+1];
    }

    book->count--;
}

// Print all Contacts in PhoneBook
void printPhoneBook(PhoneBook* book) {
    printf("PhoneBook:\n");
    for (int i = 0; i < book->count; i++) {
        printf("%s (%s)\n", book->contacts[i].name, book->contacts[i].phone);
    }
}

int main() {
    PhoneBook book;
    book.count = 0;

    // Add Contacts to PhoneBook
    Contact contact1 = {"John Smith", "555-1234"};
    addContact(&book, contact1);

    Contact contact2 = {"Jane Doe", "555-5678"};
    addContact(&book, contact2);

    Contact contact3 = {"Bob Johnson", "555-9012"};
    addContact(&book, contact3);

    // Print all Contacts in PhoneBook
    printPhoneBook(&book);

    // Find Contact in PhoneBook by name
    char* name = "Jane Doe";
    int index = findContact(&book, name);
    if (index != -1) {
        printf("%s's phone number is %s.\n", name, book.contacts[index].phone);
    }

    // Remove Contact from PhoneBook by name
    char* nameToRemove = "John Smith";
    removeContact(&book, nameToRemove);

    // Print all Contacts in PhoneBook again
    printPhoneBook(&book);

    return 0;
}