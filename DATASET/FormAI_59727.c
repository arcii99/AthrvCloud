//FormAI DATASET v1.0 Category: Phone Book ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000

// Define a structure for holding contact details
typedef struct contact {
    char name[30];
    char phone_number[15];
} contact_t;

// Define a structure for holding multiple contacts
typedef struct phone_book {
    int num_contacts;
    contact_t contacts[MAX_CONTACTS];
} phone_book_t;

// Function to add a new contact to the phone book
void add_contact(phone_book_t* book, char* name, char* phone_number) {
    if (book->num_contacts >= MAX_CONTACTS) {
        printf("ERROR: Phone book is full!\n");
        return;
    }

    contact_t new_contact;
    strcpy(new_contact.name, name);
    strcpy(new_contact.phone_number, phone_number);

    book->contacts[book->num_contacts] = new_contact;
    book->num_contacts++;

    printf("Added new contact: %s - %s\n", name, phone_number);
}

// Function to find a contact in the phone book by name
contact_t* find_contact(phone_book_t* book, char* name) {
    int i;
    for (i = 0; i < book->num_contacts; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            return &book->contacts[i];
        }
    }

    printf("Contact not found: %s\n", name);
    return NULL;
}

int main() {
    // Connect to distributed database server
    // ...

    // Create a new phone book
    phone_book_t my_phone_book;
    my_phone_book.num_contacts = 0;

    // Add some contacts
    add_contact(&my_phone_book, "John Smith", "555-1234");
    add_contact(&my_phone_book, "Jane Doe", "555-5678");

    // Find a contact
    contact_t* contact = find_contact(&my_phone_book, "John Smith");
    if (contact) {
        printf("Found contact: %s - %s\n", contact->name, contact->phone_number);
    }

    // Disconnect from distributed database server
    // ...

    return 0;
}