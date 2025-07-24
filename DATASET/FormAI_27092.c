//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of email addresses
#define MAX_EMAILS 100

// Maximum length of an email address
#define MAX_EMAIL_LENGTH 50

// Mailing list structure
struct MailingList {
    char emails[MAX_EMAILS][MAX_EMAIL_LENGTH];
    int count;
};

// Function to add an email to the mailing list
void add_email(struct MailingList *list, char *email) {
    if (list->count >= MAX_EMAILS) {
        printf("Error: Mailing list is full\n");
        return;
    }
    strcpy(list->emails[list->count], email);
    list->count++;
    printf("Added email: %s\n", email);
}

// Function to remove an email from the mailing list
void remove_email(struct MailingList *list, char *email) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            int j;
            for (j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Removed email: %s\n", email);
            return;
        }
    }
    printf("Error: Email not found in mailing list\n");
}

// Function to print the mailing list
void print_list(struct MailingList *list) {
    int i;
    printf("Mailing List:\n");
    for (i = 0; i < list->count; i++) {
        printf("%s\n", list->emails[i]);
    }
}

int main() {
    // Initialize mailing list
    struct MailingList list;
    list.count = 0;

    // Add some initial emails
    add_email(&list, "john@example.com");
    add_email(&list, "jane@example.com");
    add_email(&list, "bob@example.com");

    // Print the mailing list
    print_list(&list);

    // Remove one of the emails
    remove_email(&list, "jane@example.com");

    // Print the mailing list again
    print_list(&list);

    return 0;
}