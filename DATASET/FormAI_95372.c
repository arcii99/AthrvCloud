//FormAI DATASET v1.0 Category: Mailing list manager ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAILS 1000 // Maximum number of emails that can be stored in the mailing list
#define MAX_NAME_LENGTH 50 // Maximum length of name of person
#define MAX_EMAIL_LENGTH 50 // Maximum length of email address

// Struct for storing the name and email of a person
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Person;

// Struct for storing the mailing list
typedef struct {
    Person emails[MAX_EMAILS];
    int count;
} MailingList;

// Function to add a person to the mailing list
void add_person(MailingList *list, char *name, char *email) {
    if (list->count < MAX_EMAILS) {
        strcpy(list->emails[list->count].name, name);
        strcpy(list->emails[list->count].email, email);
        list->count++;
    }
    else {
        printf("Error: Maximum number of emails reached.\n");
    }
}

// Function to print all the people in the mailing list
void print_mailing_list(MailingList list) {
    printf("--- Mailing List ---\n");
    for (int i = 0; i < list.count; i++) {
        printf("%s: %s\n", list.emails[i].name, list.emails[i].email);
    }
    printf("--------------------\n");
}

int main() {
    MailingList list;
    list.count = 0;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int choice = 0;

    // Loop for adding people to the mailing list
    while (choice != 2) {
        printf("1. Add person\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // To clear input buffer
        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character from name
                printf("Enter email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character from email
                add_person(&list, name, email);
                break;
            case 2:
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    // Print the mailing list
    print_mailing_list(list);

    return 0;
}