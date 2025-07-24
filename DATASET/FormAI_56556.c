//FormAI DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for email addresses
typedef struct Email {
    char address[50];
    struct Email* next;
} Email;

// Function prototypes
void addEmail(Email** head);
void deleteEmail(Email** head, char* address);
void displayList(Email* head);

int main() {
    Email* head = NULL; // Initialize head of linked list to NULL
    int choice;

    printf("Welcome to the mailing list manager!\n");

    do {
        printf("\nMenu \n1. Add email\n2. Delete email\n3. Display list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEmail(&head);
                break;
            case 2:
                char address[50];
                printf("\nEnter the email address to delete: ");
                scanf("%s", address);
                deleteEmail(&head, address);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(choice != 4);

    // Free memory allocated for linked list
    Email* current = head;

    while(current != NULL) {
        Email* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

// Function to add an email to the linked list
void addEmail(Email** head) {
    Email* newEmail = (Email*) malloc(sizeof(Email));

    printf("\nEnter the email address: ");
    scanf("%s", newEmail->address);
    newEmail->next = NULL;

    if(*head == NULL) {
        *head = newEmail;
    } else {
        Email* current = *head;

        while(current->next != NULL) {
            current = current->next;
        }

        current->next = newEmail;
    }

    printf("\nEmail added to list!\n");
}

// Function to delete an email from the linked list
void deleteEmail(Email** head, char* address) {
    Email* current = *head;
    Email* prev = NULL;

    while(current != NULL) {
        if(strcmp(current->address, address) == 0) {
            if(prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("\nEmail deleted from list!\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("\nEmail not found in list!\n");
}

// Function to display the linked list
void displayList(Email* head) {
    if(head == NULL) {
        printf("\nMailing list is empty!\n");
    } else {
        printf("\nMailing List:\n");

        while(head != NULL) {
            printf("%s\n", head->address);
            head = head->next;
        }
    }
}