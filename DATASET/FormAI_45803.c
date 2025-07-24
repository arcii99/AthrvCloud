//FormAI DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_CONTACTS 1000

// Structure to hold information of a contact
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

// Array of contacts
Contact contacts[MAX_CONTACTS];

// Number of contacts in the mailing list
int num_contacts = 0;

// Function to add a contact to the mailing list
void add_contact(Contact c) {
    if(num_contacts < MAX_CONTACTS) {
        // Copy the contact information to the next empty slot in the array
        strcpy(contacts[num_contacts].name, c.name);
        strcpy(contacts[num_contacts].email, c.email);
        num_contacts++;
        printf("Contact added successfully!\n");
    } else {
        printf("Mailing list is full!\n");
    }
}

// Function to remove a contact from the mailing list
void remove_contact(int index) {
    if(index >= 0 && index < num_contacts) {
        // Shift all the contacts after the specified index one position to the left
        for(int i=index; i<num_contacts-1; i++) {
            strcpy(contacts[i].name, contacts[i+1].name);
            strcpy(contacts[i].email, contacts[i+1].email);
        }
        num_contacts--;
        printf("Contact removed successfully!\n");
    } else {
        printf("Invalid index!\n");
    }
}

// Function to print all contacts in the mailing list
void print_contacts() {
    if(num_contacts > 0) {
        printf("Mailing List:\n");
        printf("===============================================\n");
        for(int i=0; i<num_contacts; i++) {
            printf("%2d. %-20s %s\n", i+1, contacts[i].name, contacts[i].email);
        }
        printf("===============================================\n");
    } else {
        printf("Mailing list is empty!\n");
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int index;
    Contact c;

    do {
        // Print menu
        printf("Mailing List Manager\n");
        printf("===============================================\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Print all contacts\n");
        printf("4. Quit\n");
        printf("===============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                strcpy(c.name, name);
                strcpy(c.email, email);
                add_contact(c);
                break;
            case 2:
                printf("Enter index of contact to remove: ");
                scanf("%d", &index);
                remove_contact(index-1);
                break;
            case 3:
                print_contacts();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 4);

    return 0;
}