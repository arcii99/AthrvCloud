//FormAI DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 20

struct email {
    char name[MAX_NAME_LENGTH];
    char email_addr[MAX_EMAIL_LENGTH];
};

struct email_list {
    struct email emails[MAX_EMAILS];
    int num_emails;
};

void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_menu() {
    printf("1. Add email\n");
    printf("2. Remove email\n");
    printf("3. View all emails\n");
    printf("4. Quit\n");
    printf("\nChoose an option (1-4):\n");
}

void add_email(struct email_list *el) {
    if (el->num_emails >= MAX_EMAILS) {
        printf("Sorry, the list is full. Cannot add more emails.\n");
        return;
    }

    printf("Enter name:\n");
    fgets(el->emails[el->num_emails].name, MAX_NAME_LENGTH, stdin);
    clear_input_buffer();
    printf("Enter email address:\n");
    fgets(el->emails[el->num_emails].email_addr, MAX_EMAIL_LENGTH, stdin);
    clear_input_buffer();
    el->num_emails++;
    printf("Email added successfully.\n");
}

void remove_email(struct email_list *el) {
    if (el->num_emails == 0) {
        printf("Sorry, the list is empty. Cannot remove any emails.\n");
        return;
    }

    printf("Enter email address to remove:\n");
    char email_addr[MAX_EMAIL_LENGTH];
    fgets(email_addr, MAX_EMAIL_LENGTH, stdin);
    clear_input_buffer();

    int email_found = 0;
    for (int i = 0; i < el->num_emails; i++) {
        if (strcmp(el->emails[i].email_addr, email_addr) == 0) {
            strcpy(el->emails[i].name, "");
            strcpy(el->emails[i].email_addr, "");
            email_found = 1;
            break;
        }
    }

    if (email_found) {
        printf("Email removed successfully.\n");
    } else {
        printf("Email not found in the list.\n");
    }
}

void view_emails(struct email_list *el) {
    if (el->num_emails == 0) {
        printf("The list is empty.\n");
        return;
    }

    printf("All emails in the list:\n");
    for (int i = 0; i < el->num_emails; i++) {
        if (strcmp(el->emails[i].name, "") != 0) {
            printf("%s: %s\n", el->emails[i].name, el->emails[i].email_addr);
        }
    }
}

int main() {
    struct email_list el;
    el.num_emails = 0;

    printf("Welcome to the post-apocalyptic mailing list manager.\n\n");

    while (1) {
        print_menu();

        int option;
        scanf("%d", &option);
        clear_input_buffer();

        switch (option) {
            case 1:
                add_email(&el);
                break;
            case 2:
                remove_email(&el);
                break;
            case 3:
                view_emails(&el);
                break;
            case 4:
                printf("Goodbye.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please enter a number from 1-4.\n");
                break;
        }
    }

    return 0;
}