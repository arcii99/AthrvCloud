//FormAI DATASET v1.0 Category: Phone Book ; Style: Alan Touring
// C Phone Book Example Program in Alan Turing Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[10];
};

int main() {
    int choice, i, n, found = 0;
    struct Contact *contacts;

    printf("\n\t\t ----- PHONE BOOK -----\n");

    // Get number of contacts
    printf("\nEnter the number of contacts: ");
    scanf("%d", &n);

    // Allocate memory for contacts
    contacts = (struct Contact*) malloc(n * sizeof(struct Contact));

    // Get contact data
    for(i=0; i<n; i++) {
        printf("\nContact %d\n", i+1);
        printf("Name: ");
        scanf("%s", contacts[i].name);
        printf("Phone Number: ");
        scanf("%s", contacts[i].phone);
    }

    // Menu
    while(1) {
        printf("\n\t\t ----- MENU -----\n");
        printf("1. Search by Name\n");
        printf("2. Search by Phone Number\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Search by Name
                char name[50];
                printf("\nEnter the name: ");
                scanf("%s", name);

                printf("\nContacts with name %s:\n", name);
                for(i=0; i<n; i++) {
                    if(strcmp(contacts[i].name, name) == 0) {
                        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
                        found = 1;
                    } 
                }

                if(found == 0) {
                    printf("No contacts found with name %s\n", name);
                }
                found = 0;
                break;
            
            case 2: // Search by Phone Number
                char phone[10];
                printf("\nEnter the phone number: ");
                scanf("%s", phone);

                printf("\nContacts with phone number %s:\n", phone);
                for(i=0; i<n; i++) {
                    if(strcmp(contacts[i].phone, phone) == 0) {
                        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
                        found = 1;
                    } 
                }

                if(found == 0) {
                    printf("No contacts found with phone number %s\n", phone);
                }
                found = 0;
                break;

            case 3: // Display All Contacts
                printf("\nAll Contacts:\n");
                for(i=0; i<n; i++) {
                    printf("%s: %s\n", contacts[i].name, contacts[i].phone);
                }
                break;
                
            case 4: // Exit
                free(contacts);
                printf("\nThank you for using Phone Book Program!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}