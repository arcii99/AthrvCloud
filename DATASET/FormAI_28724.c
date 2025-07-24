//FormAI DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAIL_CHARS 128

// Define the struct for each email entry
typedef struct {
    char email[MAX_EMAIL_CHARS];
    struct EmailEntry *next;
} EmailEntry;

// Define the struct for the mailing list
typedef struct {
    EmailEntry *head;
    int count;
} MailingList;

// Function to add a new email to the mailing list
void addEmail(MailingList *list, char email[]) {
    // Allocate space for the new email entry
    EmailEntry *newEmail = (EmailEntry*) malloc(sizeof(EmailEntry));
    if (newEmail == NULL) {
        printf("Error allocating memory for new email entry.\n");
        exit(1);
    }
    // Copy the email address into the new entry
    strcpy(newEmail->email, email);
    // Add the new entry to the end of the list
    if (list->head == NULL) {
        list->head = newEmail;
    } else {
        EmailEntry *currentEmail = list->head;
        while (currentEmail->next != NULL) {
            currentEmail = currentEmail->next;
        }
        currentEmail->next = newEmail;
    }
    // Increment the count of emails in the list
    list->count++;
}

// Function to remove an email from the mailing list
void removeEmail(MailingList *list, char email[]) {
    if (list->head == NULL) {
        printf("Error: Mailing list is empty.\n");
        exit(1);
    } else {
        EmailEntry *previousEmail = NULL;
        EmailEntry *currentEmail = list->head;
        while (currentEmail != NULL) {
            if (strcmp(currentEmail->email, email) == 0) {
                if (previousEmail == NULL) {
                    // The email to remove is the head of the list
                    list->head = currentEmail->next;
                } else {
                    // The email to remove is not the head of the list
                    previousEmail->next = currentEmail->next;
                }
                // Free the memory used by the email entry
                free(currentEmail);
                // Decrement the count of emails in the list
                list->count--;
                return;
            }
            previousEmail = currentEmail;
            currentEmail = currentEmail->next;
        }
        printf("Error: Email not found in mailing list.\n");
        exit(1);
    }
}

// Function to print all emails in the mailing list
void printList(MailingList *list) {
    if (list->head == NULL) {
        printf("Mailing list is empty.\n");
    } else {
        printf("Mailing list:\n");
        EmailEntry *currentEmail = list->head;
        while (currentEmail != NULL) {
            printf("- %s\n", currentEmail->email);
            currentEmail = currentEmail->next;
        }
    }
}

int main() {
    // Initialize an empty mailing list
    MailingList list = {NULL, 0};
    // Add some initial emails to the list
    addEmail(&list, "john.doe@example.com");
    addEmail(&list, "jane.doe@example.com");
    addEmail(&list, "bob.smith@example.com");
    // Print the current contents of the list
    printList(&list);
    // Remove an email from the list
    removeEmail(&list, "jane.doe@example.com");
    // Print the updated contents of the list
    printList(&list);
    // Add a new email to the list
    addEmail(&list, "alice.jones@example.com");
    // Print the updated contents of the list
    printList(&list);
    // Exit the program
    return 0;
}