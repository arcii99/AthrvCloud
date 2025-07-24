//FormAI DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[20];
    struct contact *next;
};

int main() {
    int choice;
    struct contact *head, *new_contact, *current_contact;
    head = NULL;
    
    printf("Welcome to Introspective Phone Book\n");
    
    do {
        printf("\n1. Add a new contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Adding a new contact
                new_contact = (struct contact *) malloc(sizeof(struct contact));
                printf("Enter the name: ");
                scanf("%s", new_contact->name);
                printf("Enter the phone number: ");
                scanf("%s", new_contact->phone);
                new_contact->next = head;
                head = new_contact;
                printf("Contact added successfully!\n");
                break;
            case 2:
                // Searching for a contact
                char search_name[50];
                printf("Enter the name to search: ");
                scanf("%s", search_name);
                current_contact = head;
                while(current_contact != NULL) {
                    if(strcmp(current_contact->name, search_name) == 0) {
                        printf("\nName: %s\nPhone Number: %s\n", current_contact->name, current_contact->phone);
                        break;
                    }
                    current_contact = current_contact->next;
                }
                if(current_contact == NULL) {
                    printf("\nContact not found!\n");
                }
                break;
            case 3:
                // Displaying all contacts
                current_contact = head;
                if(current_contact == NULL) {
                    printf("\nNo contacts found!\n");
                } else {
                    printf("\nList of all contacts:\n");
                    while(current_contact != NULL) {
                        printf("\nName: %s\nPhone Number: %s\n", current_contact->name, current_contact->phone);
                        current_contact = current_contact->next;
                    }
                }
                break;
            case 4:
                // Deleting a contact
                char delete_name[50];
                printf("Enter the name to delete: ");
                scanf("%s", delete_name);
                current_contact = head;
                struct contact *previous_contact = NULL;
                while(current_contact != NULL) {
                    if(strcmp(current_contact->name, delete_name) == 0) {
                        if(current_contact == head) {
                            head = current_contact->next;
                        } else {
                            previous_contact->next = current_contact->next;
                        }
                        free(current_contact);
                        printf("\nContact deleted successfully!\n");
                        break;
                    }
                    previous_contact = current_contact;
                    current_contact = current_contact->next;
                }
                if(current_contact == NULL) {
                    printf("\nContact not found!\n");
                }
                break;
            case 5:
                // Exit
                printf("Thank you for using Introspective Phone Book!\n");
                break;
            default:
                printf("Invalid input! Please try again.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}