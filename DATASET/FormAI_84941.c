//FormAI DATASET v1.0 Category: Email Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 1000

struct Email {
    char sender[MAX_LENGTH];
    char receivers[MAX_LENGTH];
    char subject[MAX_LENGTH];
    char body[MAX_LENGTH];
};

void printMenu();
void showEmails(struct Email emails[], int numEmails);
void getEmail(struct Email emails[], int *numEmails);
void searchEmails(struct Email emails[], int numEmails);
void deleteEmail(struct Email emails[], int *numEmails);

int main() {
    struct Email emails[MAX_EMAILS];
    int numEmails = 0;
    int choice = -1;
    
    while (choice != 0) {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                getEmail(emails, &numEmails);
                break;
            case 2:
                showEmails(emails, numEmails);
                break;
            case 3:
                searchEmails(emails, numEmails);
                break;
            case 4:
                deleteEmail(emails, &numEmails);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void printMenu() {
    printf("\nEmail Client\n");
    printf("============\n");
    printf("1. Compose email\n");
    printf("2. View emails\n");
    printf("3. Search emails\n");
    printf("4. Delete email\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
}

void showEmails(struct Email emails[], int numEmails) {
    printf("\nEmails (%d)\n", numEmails);
    printf("==========\n");
    
    if (numEmails == 0) {
        printf("No emails to display.\n");
        return;
    }
    
    for (int i = 0; i < numEmails; i++) {
        printf("Email %d:\n", i+1);
        printf("From: %s\n", emails[i].sender);
        printf("To: %s\n", emails[i].receivers);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n\n", emails[i].body);
    }
}

void getEmail(struct Email emails[], int *numEmails) {
    struct Email newEmail;
    printf("\nEnter sender: ");
    scanf("%s", newEmail.sender);
    
    printf("Enter receivers: ");
    scanf("%s", newEmail.receivers);
    
    printf("Enter subject: ");
    scanf("%s", newEmail.subject);
    
    printf("Enter body: ");
    getchar(); // clear input buffer
    fgets(newEmail.body, MAX_LENGTH, stdin);
    
    if (*numEmails < MAX_EMAILS) {
        strcpy(emails[*numEmails].sender, newEmail.sender);
        strcpy(emails[*numEmails].receivers, newEmail.receivers);
        strcpy(emails[*numEmails].subject, newEmail.subject);
        strcpy(emails[*numEmails].body, newEmail.body);
        (*numEmails)++;
        printf("Email sent successfully!\n");
    } else {
        printf("Maximum number of emails reached. Email not sent.\n");
    }
}

void searchEmails(struct Email emails[], int numEmails) {
    char searchQuery[MAX_LENGTH];
    int numMatches = 0;
    
    printf("\nEnter search term: ");
    scanf("%s", searchQuery);
    
    for (int i = 0; i < numEmails; i++) {
        char *bodyPtr = strstr(emails[i].body, searchQuery);
        char *subjectPtr = strstr(emails[i].subject, searchQuery);
        
        if (bodyPtr != NULL || subjectPtr != NULL) {
            printf("Match found in email %d.\n", i+1);
            printf("From: %s\n", emails[i].sender);
            printf("To: %s\n", emails[i].receivers);
            printf("Subject: %s\n", emails[i].subject);
            printf("Body: %s\n\n", emails[i].body);
            numMatches++;
        }
    }
    
    if (numMatches == 0) {
        printf("No matches found.\n");
    } else {
        printf("%d match(es) found.\n", numMatches);
    }
}

void deleteEmail(struct Email emails[], int *numEmails) {
    int indexToDelete;
    printf("\nEnter number of email to delete: ");
    scanf("%d", &indexToDelete);
    
    if (indexToDelete < 1 || indexToDelete > *numEmails) {
        printf("Invalid index.\n");
        return;
    }
    
    for (int i = indexToDelete-1; i < *numEmails-1; i++) {
        emails[i] = emails[i+1];
    }
    
    (*numEmails)--;
    printf("Email %d deleted successfully.\n", indexToDelete);
}