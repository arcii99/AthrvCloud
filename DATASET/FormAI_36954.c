//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_LIST_SIZE 100

// Define a struct to hold an email address
typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Email;

// Define a struct to hold the mailing list
typedef struct {
    Email emails[MAX_LIST_SIZE];
    int size;
} MailingList;

// Function to add an email to the mailing list
void addEmail(MailingList *list, Email email) {
    if (list->size == MAX_LIST_SIZE) {
        printf("Error: Mailing list is full.\n");
        return;
    }
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i].email, email.email) == 0) {
            printf("Error: Email already in list.\n");
            return;
        }
    }
    list->emails[list->size] = email;
    list->size++;
}

// Function to remove an email from the mailing list
void removeEmail(MailingList *list, Email email) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i].email, email.email) == 0) {
            for (int j = i; j < list->size - 1; j++) {
                list->emails[j] = list->emails[j+1];
            }
            list->size--;
            return;
        }
    }
    printf("Error: Email not in list.\n");
}

// Function to search for an email in the mailing list
void searchEmail(MailingList *list, Email email) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i].email, email.email) == 0) {
            printf("Email found in list.\n");
            return;
        }
    }
    printf("Email not found in list.\n");
}

int main() {
    MailingList list = {.size = 0};

    // Add some initial emails to the list
    Email email1 = {.email = "john.smith@gmail.com"};
    Email email2 = {.email = "jane.doe@yahoo.com"};
    Email email3 = {.email = "jimmy.carter@gmail.com"};
    Email email4 = {.email = "betty.white@hotmail.com"};

    addEmail(&list, email1);
    addEmail(&list, email2);
    addEmail(&list, email3);
    addEmail(&list, email4);

    // Test adding a new email
    Email newEmail = {.email = "barack.obama@gmail.com"};
    addEmail(&list, newEmail);

    // Test adding a duplicate email
    Email duplicateEmail = {.email = "betty.white@hotmail.com"};
    addEmail(&list, duplicateEmail);

    // Test removing an email
    removeEmail(&list, email2);

    // Test removing a non-existent email
    Email nonExistentEmail = {.email = "donald.trump@yahoo.com"};
    removeEmail(&list, nonExistentEmail);

    // Test searching for an email
    searchEmail(&list, newEmail);

    // Test searching for a non-existent email
    searchEmail(&list, nonExistentEmail);

    return 0;
}