//FormAI DATASET v1.0 Category: Phone Book ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_NAME_LENGTH 20
#define MAX_NUMBER_LENGTH 10
#define MAX_CONTACTS 100

struct contact {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_NUMBER_LENGTH];
};

struct contact phone_book[MAX_CONTACTS];

int num_contacts = 0;

void add_contact() {
    // Add a contact to the phone book
    
    if (num_contacts == MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }
    
    struct contact new_contact;
    printf("Enter contact name: ");
    fgets(new_contact.name, MAX_NAME_LENGTH, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0; // Remove newline character
    
    printf("Enter phone number: ");
    fgets(new_contact.phone_number, MAX_NUMBER_LENGTH, stdin);
    new_contact.phone_number[strcspn(new_contact.phone_number, "\n")] = 0; // Remove newline character
    
    phone_book[num_contacts] = new_contact;
    num_contacts++;
    printf("Contact added successfully.\n");
}

void search_contact() {
    // Search for a contact in the phone book
    
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search for: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove newline character
    
    int num_results = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strstr(phone_book[i].name, search_name) != NULL) {
            printf("%s: %s\n", phone_book[i].name, phone_book[i].phone_number);
            num_results++;
        }
    }
    
    if (num_results == 0) {
        printf("No contacts found.\n");
    } else {
        printf("Found %d contact(s).\n", num_results);
    }
}

void list_contacts() {
    // List all contacts in the phone book
    
    if (num_contacts == 0) {
        printf("No contacts in phone book.\n");
        return;
    }
    
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

void delete_contact() {
    // Delete a contact from the phone book
    
    char delete_name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(delete_name, MAX_NAME_LENGTH, stdin);
    delete_name[strcspn(delete_name, "\n")] = 0; // Remove newline character
    
    int delete_index = -1;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, delete_name) == 0) {
            delete_index = i;
            break;
        }
    }
    
    if (delete_index == -1) {
        printf("Contact not found.\n");
        return;
    }
    
    for (int i = delete_index; i < num_contacts - 1; i++) {
        phone_book[i] = phone_book[i+1];
    }
    
    num_contacts--;
    printf("Contact deleted successfully.\n");
}

int main() {
    char input[MAX_NAME_LENGTH];
    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. List all contacts\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        fgets(input, MAX_NAME_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character
        
        if (isdigit(input[0])) {
            int choice = atoi(input);
            switch (choice) {
                case 1:
                    add_contact();
                    break;
                case 2:
                    search_contact();
                    break;
                case 3:
                    list_contacts();
                    break;
                case 4:
                    delete_contact();
                    break;
                case 5:
                    printf("Goodbye!\n");
                    exit(0);
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        } else {
            printf("Invalid input.\n");
        }
    }
    return 0;
}