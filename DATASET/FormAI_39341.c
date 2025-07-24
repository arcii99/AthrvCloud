//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_EMAIL_LEN 50
#define MAX_ENTRIES 100

// Define a struct to hold email addresses
typedef struct {
    char email[MAX_EMAIL_LEN];
} email_t;

// Define a struct to hold the mailing list
typedef struct {
    email_t emails[MAX_ENTRIES];
    int count;
} mailing_list_t;

// Function to add an email to the mailing list
void add_email(mailing_list_t* list, char* email) {
    if (list->count >= MAX_ENTRIES) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    // Create a new email entry and copy the email address
    email_t new_email;
    strncpy(new_email.email, email, MAX_EMAIL_LEN);

    // Add the new entry to the mailing list
    list->emails[list->count] = new_email;
    list->count++;

    printf("Added email: %s\n", email);
}

// Function to print the current mailing list
void print_list(mailing_list_t* list) {
    printf("Current mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i+1, list->emails[i].email);
    }
}

int main() {
    mailing_list_t list;
    list.count = 0;

    // Add some sample emails
    add_email(&list, "jane.doe@example.com");
    add_email(&list, "john.doe@example.com");
    add_email(&list, "foo@example.com");
    add_email(&list, "bar@example.com");

    print_list(&list);

    return 0;
}