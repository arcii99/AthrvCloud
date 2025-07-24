//FormAI DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the contact structure
typedef struct {
    char name[50];
    char number[20];
    char email[50];
    char address[100];
} Contact;

// Define the contact book structure
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} ContactBook;

// Function to add a contact
void addContact(ContactBook *book, Contact contact) {
    book -> contacts[book -> count] = contact;
    book -> count++;
}

// Function to display all contacts
void displayAllContacts(ContactBook book) {
    printf("CYBERPUNK PHONE BOOK\n\n");
    printf("NAME\t\tNUMBER\t\tEMAIL\t\t\tADDRESS\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < book.count; i++) {
        printf("%s\t\t%s\t%s\t\t%s\n", book.contacts[i].name, book.contacts[i].number, book.contacts[i].email, book.contacts[i].address);
    }
}

// Main function
int main() {
    // Initialize the contact book
    ContactBook book;
    book.count = 0;

    // Add some contacts to the book
    addContact(&book, (Contact){"John Doe", "123-456-7890", "john.doe@gmail.com", "1234 Main St"});
    addContact(&book, (Contact){"Jane Smith", "987-654-3210", "jane.smith@yahoo.com", "5678 Elm St"});

    // Display all contacts
    displayAllContacts(book);

    return 0;
}