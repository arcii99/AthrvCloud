//FormAI DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LEN 100
#define MAX_NAME_LEN 50
#define MAX_LIST_LEN 100

// Struct representing an email recipient
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Recipient;

// Struct representing an email mailing list
typedef struct {
    char name[MAX_NAME_LEN];
    Recipient recipients[MAX_LIST_LEN];
    int num_recipients;
} MailingList;

// Function that prompts user for information about a new recipient and adds them to a mailing list
void add_recipient_to_list(MailingList* list) {
    Recipient new_recipient;
    printf("Enter recipient name: ");
    fgets(new_recipient.name, MAX_NAME_LEN, stdin);
    printf("Enter recipient email: ");
    fgets(new_recipient.email, MAX_EMAIL_LEN, stdin);
    list->recipients[list->num_recipients++] = new_recipient;
    printf("Recipient added to list.\n");
}

// Function that prompts user for information about an existing recipient and removes them from a mailing list
void remove_recipient_from_list(MailingList* list) {
    char search_name[MAX_NAME_LEN];
    printf("Enter name of recipient to remove: ");
    fgets(search_name, MAX_NAME_LEN, stdin);
    int found_index = -1;
    for (int i = 0; i < list->num_recipients; i++) {
        if (strcmp(list->recipients[i].name, search_name) == 0) {
            found_index = i;
            break;
        }
    }
    if (found_index == -1) {
        printf("Recipient not found in list.\n");
    } else {
        for (int i = found_index; i < (list->num_recipients - 1); i++) {
            list->recipients[i] = list->recipients[i+1];
        }
        list->num_recipients--;
        printf("Recipient removed from list.\n");
    }
}

// Function that prints out the contents of a mailing list
void view_mailing_list(MailingList* list) {
    printf("Mailing list: %s\n", list->name);
    printf("Recipients:\n");
    for (int i = 0; i < list->num_recipients; i++) {
        printf("%s (%s)\n", list->recipients[i].name, list->recipients[i].email);
    }
}

// Main function that creates and manages mailing lists
int main() {
    MailingList my_list;
    printf("Enter name for new mailing list: ");
    fgets(my_list.name, MAX_NAME_LEN, stdin);
    my_list.num_recipients = 0;
    int choice = -1;
    while (choice != 0) {
        printf("What would you like to do?\n");
        printf("1. Add recipient to list\n");
        printf("2. Remove recipient from list\n");
        printf("3. View mailing list\n");
        printf("0. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character left in input stream by scanf
        switch (choice) {
            case 1:
                add_recipient_to_list(&my_list);
                break;
            case 2:
                remove_recipient_from_list(&my_list);
                break;
            case 3:
                view_mailing_list(&my_list);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    printf("Exiting...\n");
    return 0;
}