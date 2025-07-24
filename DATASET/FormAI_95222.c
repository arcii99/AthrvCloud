//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
/* Romeo and Juliet Mailing List Manager */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

struct email {
    char address[50];
    char name[50];
};

struct mailing_list {
    struct email emails[MAX_EMAILS];
    int count;
    char list_name[50];
};

// function prototypes
void add_email(struct mailing_list* list);
void remove_email(struct mailing_list* list, char* email_address);
void print_list(struct mailing_list* list);

int main() {

    // initialize mailing list
    struct mailing_list list;
    list.count = 0;

    // introduce program
    printf("Oh, my love, my soulmate. Welcome to the Romeo and Juliet Mailing List Manager.\n");
    printf("Here, we shall manage our love letters and keep our correspondence organized.\n");
    printf("May this tool bring us closer together, even when we are far apart.\n");

    // prompt user for list name
    printf("\nMy dear, what would you like to call this mailing list?: ");
    fgets(list.list_name, 50, stdin);
    strtok(list.list_name, "\n");

    // menu loop
    while (1) {
        // display menu options
        printf("\nMy love, please choose an option:\n");
        printf("1. Add email to list\n");
        printf("2. Remove email from list\n");
        printf("3. View list\n");
        printf("4. Exit program\n");

        // get user choice
        int choice;
        printf("Choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        // perform selected action
        switch (choice) {
            case 1:
                add_email(&list);
                break;
            case 2:
                printf("My love, please enter the email address you wish to remove: ");
                char email_remove[50];
                fgets(email_remove, 50, stdin);
                strtok(email_remove, "\n");
                remove_email(&list, email_remove);
                break;
            case 3:
                print_list(&list);
                break;
            case 4:
                printf("Farewell my love. May this mailing list bring us closer together.\n");
                exit(0);
            default:
                printf("My dear, that is not a valid choice. Please choose again.\n");
        }
    }

    return 0;
}

void add_email(struct mailing_list* list) {
    // check if list is full
    if (list->count >= MAX_EMAILS) {
        printf("My love, this mailing list is already at capacity. Please remove an email to add a new one.\n");
        return;
    }

    // prompt user for email address and name
    printf("My love, please enter the email address you wish to add: ");
    fgets(list->emails[list->count].address, 50, stdin);
    strtok(list->emails[list->count].address, "\n");

    printf("And what name should we associate with this address?: ");
    fgets(list->emails[list->count].name, 50, stdin);
    strtok(list->emails[list->count].name, "\n");

    // increment email count
    list->count++; 

    printf("Thank you my sweet. The email has been added to the list.\n");
}

void remove_email(struct mailing_list* list, char* email_address) {
    // find email in list
    int index = -1;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i].address, email_address) == 0) {
            index = i;
            break;
        }
    }

    // if email not found, inform user and return
    if (index == -1) {
        printf("My love, that email is not on the list.\n");
        return;
    }

    // shift emails after removed email back one position
    for (int i = index; i < list->count - 1; i++) {
        strcpy(list->emails[i].address, list->emails[i+1].address);
        strcpy(list->emails[i].name, list->emails[i+1].name);
    }

    // decrement email count
    list->count--;

    printf("The email has been removed from the list, my love.\n");
}

void print_list(struct mailing_list* list) {
    printf("\nMy love, here is the current list:\n");
    printf("List Name: %s\n", list->list_name);
    printf("Email Count: %d\n", list->count);
    printf("------------------------------\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s <%s>\n", list->emails[i].name, list->emails[i].address);
    }
}