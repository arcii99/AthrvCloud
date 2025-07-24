//FormAI DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DB_SIZE 10000
#define MAX_NAME_LEN 100
#define MAX_ADDRESS_LEN 200
#define MAX_PHONE_LEN 20

struct Contact {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char phone[MAX_PHONE_LEN];
};

struct Database {
    struct Contact contacts[MAX_DB_SIZE];
    int size;
};

// Function to add a new contact to the database
void addContact(struct Database *db, char name[], char address[], char phone[]) {
    strcpy(db->contacts[db->size].name, name);
    strcpy(db->contacts[db->size].address, address);
    strcpy(db->contacts[db->size].phone, phone);
    db->size++;
}

// Function to search for a contact in the database
void searchContact(struct Database *db, char name[]) {
    for(int i = 0; i < db->size; i++) {
        if(strcmp(db->contacts[i].name, name) == 0) {
            printf("%s\t%s\t%s\n", db->contacts[i].name, db->contacts[i].address, db->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

// Function to print all contacts in the database
void printContacts(struct Database *db) {
    for(int i = 0; i < db->size; i++) {
        printf("%s\t%s\t%s\n", db->contacts[i].name, db->contacts[i].address, db->contacts[i].phone);
    }
}

int main() {
    char choice;
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char phone[MAX_PHONE_LEN];

    // Initialize the database
    struct Database db = { .size = 0 };

    // Main menu
    do {
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Print All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Add contact
        if(choice == '1') {
            printf("Enter name, address and phone number of the contact: ");
            scanf("%s%s%s", name, address, phone);
            addContact(&db, name, address, phone);
            printf("Contact added successfully!\n");
        }

        // Search contact
        else if(choice == '2') {
            printf("Enter name of the contact to search: ");
            scanf("%s", name);
            searchContact(&db, name);
        }

        // Print all contacts
        else if(choice == '3') {
            printContacts(&db);
        }

        // Exit
        else if(choice == '4') {
            break;
        }

        // Handle invalid input
        else {
            printf("Invalid choice!\n");
        }
    } while(1);

    return 0;
}