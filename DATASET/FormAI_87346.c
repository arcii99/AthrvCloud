//FormAI DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone_number[20];
};

int num_contacts = 0;
struct Contact contacts[MAX_CONTACTS];

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Error: Cannot add more contacts.\n");
        return;
    }
    
    struct Contact new_contact;
    
    printf("Enter name: ");
    fgets(new_contact.name, 50, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = '\0'; // removes trailing newline character
    
    printf("Enter phone number: ");
    fgets(new_contact.phone_number, 20, stdin);
    new_contact.phone_number[strcspn(new_contact.phone_number, "\n")] = '\0'; // removes trailing newline character
    
    contacts[num_contacts++] = new_contact;
    
    printf("Contact added successfully.\n");
}

void search_contact() {
    char name[50];
    printf("Enter name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0'; // removes trailing newline character
    
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Phone number: %s\n", contacts[i].phone_number);
            return;
        }
    }
    
    printf("Contact not found.\n");
}

void print_all_contacts() {
    if (num_contacts == 0) {
        printf("No contacts found.\n");
        return;
    }
    
    printf("Contacts:\n");
    
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone_number);
    }
}

int main() {
    char command[10];
    
    while (1) {
        printf("Enter command (add, search, print, exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // removes trailing newline character
        
        if (strcmp(command, "add") == 0) {
            add_contact();
        } else if (strcmp(command, "search") == 0) {
            search_contact();
        } else if (strcmp(command, "print") == 0) {
            print_all_contacts();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }
    
    printf("Exiting phone book.\n");
    
    return 0;
}