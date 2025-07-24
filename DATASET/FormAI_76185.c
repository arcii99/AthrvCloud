//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50

struct email {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

void display_menu();
void add_email(struct email*, int*);
void remove_email(struct email*, int*);
void search_email(struct email*, int*);
void display_list(struct email*, int*);
void clear_list(struct email*, int*);

int main() {
    struct email email_list[MAX_EMAILS];
    int num_emails = 0;
    char choice;

    while (1) {
        display_menu();
        printf("\nEnter choice: ");
        choice = getchar();
        fflush(stdin);

        switch (tolower(choice)) {
            case 'a':
                add_email(email_list, &num_emails);
                break;
            case 'r':
                remove_email(email_list, &num_emails);
                break;
            case 's':
                search_email(email_list, &num_emails);
                break;
            case 'd':
                display_list(email_list, &num_emails);
                break;
            case 'c':
                clear_list(email_list, &num_emails);
                break;
            case 'q':
                printf("Quitting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }

    }

    return 0;
}

void display_menu() {
    printf("\n---MAILING LIST MANAGER---\n");
    printf("A - Add email\n");
    printf("R - Remove email\n");
    printf("S - Search email\n");
    printf("D - Display list\n");
    printf("C - Clear list\n");
    printf("Q - Quit\n");
}

void add_email(struct email *email_list, int *num_emails) {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    printf("Enter name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter email address: ");
    fgets(email, MAX_EMAIL_LEN, stdin);
    email[strcspn(email, "\n")] = '\0';

    strcpy(email_list[*num_emails].name, name);
    strcpy(email_list[*num_emails].email, email);

    printf("Email added.\n");
    (*num_emails)++;
}

void remove_email(struct email *email_list, int *num_emails) {
    char email[MAX_EMAIL_LEN];
    int i, j, found = 0;

    printf("Enter email address to remove: ");
    fgets(email, MAX_EMAIL_LEN, stdin);
    email[strcspn(email, "\n")] = '\0';

    for (i = 0; i < *num_emails; i++) {
        if (strcmp(email_list[i].email, email) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Removing email: %s\n", email_list[i].email);
        for (j = i; j < *num_emails-1; j++) {
            strcpy(email_list[j].name, email_list[j+1].name);
            strcpy(email_list[j].email, email_list[j+1].email);
        }
        (*num_emails)--;
    } else {
        printf("Email not found.\n");
    }
}

void search_email(struct email *email_list, int *num_emails) {
    char email[MAX_EMAIL_LEN];
    int i, found = 0;

    printf("Enter email address to search: ");
    fgets(email, MAX_EMAIL_LEN, stdin);
    email[strcspn(email, "\n")] = '\0';

    for (i = 0; i < *num_emails; i++) {
        if (strcmp(email_list[i].email, email) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Name: %s\n", email_list[i].name);
        printf("Email: %s\n", email_list[i].email);
    } else {
        printf("Email not found.\n");
    }
}

void display_list(struct email *email_list, int *num_emails) {
    int i;

    if (*num_emails == 0) {
        printf("No emails in list.\n");
    } else {
        printf("NAME\t\t\tEMAIL\n");
        printf("----------------------------------------\n");
        for (i = 0; i < *num_emails; i++) {
            printf("%s\t\t%s\n", email_list[i].name, email_list[i].email);
        }
    }
}

void clear_list(struct email *email_list, int *num_emails) {
    char confirmation;

    printf("Are you sure you want to clear the list? (Y/N) ");
    confirmation = getchar();
    fflush(stdin);

    if (tolower(confirmation) == 'y') {
        *num_emails = 0;
        printf("List cleared.\n");
    } else {
        printf("List not cleared.\n");
    }
}