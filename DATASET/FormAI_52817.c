//FormAI DATASET v1.0 Category: Mailing list manager ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 100

// Struct to hold a single email address
typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Email;

// Struct to hold a single mailing list
typedef struct {
    char name[MAX_EMAIL_LENGTH];
    int size;
    Email emails[MAX_LIST_SIZE];
} MailingList;

// Global array to hold all mailing lists
MailingList mailingLists[MAX_LIST_SIZE];
int numLists = 0;

// Function to print out all mailing lists and their contents
void printLists() {
    printf("\nAll Mailing Lists:\n");
    for (int i = 0; i < numLists; i++) {
        printf("\n%s\n", mailingLists[i].name);
        printf("Size: %d\n", mailingLists[i].size);
        printf("Emails: ");
        for (int j = 0; j < mailingLists[i].size; j++) {
            printf("%s ", mailingLists[i].emails[j].email);
        }
        printf("\n");
    }
}

// Function to add an email to a mailing list
void addEmail(char email[MAX_EMAIL_LENGTH], MailingList* list) {
    if (list->size >= MAX_LIST_SIZE) {
        printf("Mailing list is full.\n");
        return;
    }
    Email newEmail;
    strcpy(newEmail.email, email);
    list->emails[list->size] = newEmail;
    list->size++;
    printf("Added email %s to %s.\n", email, list->name);
}

// Function to remove an email from a mailing list
void removeEmail(char email[MAX_EMAIL_LENGTH], MailingList* list) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(email, list->emails[i].email) == 0) {
            for (int j = i; j < list->size - 1; j++) {
                list->emails[j] = list->emails[j+1];
            }
            list->size--;
            printf("Removed email %s from %s.\n", email, list->name);
            return;
        }
    }
    printf("Email not found in %s.\n", list->name);
}

int main() {
    // Dummy data for initial testing
    MailingList list1;
    strcpy(list1.name, "list1");
    list1.size = 0;

    MailingList list2;
    strcpy(list2.name, "list2");
    list2.size = 0;

    // Add some emails to list1
    addEmail("test1@example.com", &list1);
    addEmail("test2@example.com", &list1);

    // Add some emails to list2
    addEmail("test3@example.com", &list2);
    addEmail("test1@example.com", &list2);
    addEmail("test4@example.com", &list2);

    // Add both lists to the mailingLists array
    mailingLists[0] = list1;
    mailingLists[1] = list2;
    numLists = 2;

    // Print the initial state of the mailingLists array
    printLists();

    // Test adding and removing an email from list2
    addEmail("test5@example.com", &list2);
    removeEmail("test1@example.com", &list2);
    printf("\nUpdated list2:\n");
    printLists();

    return 0;
}