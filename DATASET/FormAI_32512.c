//FormAI DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50 // Maximum length of a person's name
#define MAX_NUM_LENGTH 15 // Maximum length of a person's phone number
#define CONTACTS_CAPACITY 1000 // Maximum number of contacts that can be stored

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUM_LENGTH];
} Contact;

typedef struct {
    Contact contacts[CONTACTS_CAPACITY];
    int num_contacts;
} PhoneBook;

/* Function to add a contact to the phone book */
void add_contact(PhoneBook* phone_book, char* name, char* number) {
    if (phone_book->num_contacts >= CONTACTS_CAPACITY) {
        printf("Phone book is full! Cannot add new contact.\n");
        return;
    }
    Contact new_contact;
    strncpy(new_contact.name, name, MAX_NAME_LENGTH);
    strncpy(new_contact.number, number, MAX_NUM_LENGTH);
    phone_book->contacts[phone_book->num_contacts++] = new_contact;
}

/* Function to find a contact in the phone book */
void find_contact(PhoneBook* phone_book, char* name) {
    for (int i = 0; i < phone_book->num_contacts; i++) {
        if (strcmp(phone_book->contacts[i].name, name) == 0) {
            printf("Phone number for %s: %s\n", name, phone_book->contacts[i].number);
            return;
        }
    }
    printf("Contact not found in phone book.\n");
}

/* Main function */
int main() {
    PhoneBook my_phone_book;
    my_phone_book.num_contacts = 0;

    /* Add some contacts */
    add_contact(&my_phone_book, "John Smith", "123-456-7890");
    add_contact(&my_phone_book, "Emma Johnson", "234-567-8901");
    add_contact(&my_phone_book, "David Lee", "345-678-9012");
    add_contact(&my_phone_book, "Amy Chen", "456-789-0123");

    /* Find a contact */
    find_contact(&my_phone_book, "David Lee");

    return 0;
}