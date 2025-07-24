//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Linked list to store mailing list entries */
struct MailingList {
    char name[50];
    char email[50];
    struct MailingList *next;
};

/* Function to add a new entry to the mailing list */
void add_entry(struct MailingList **head_ref, char *name, char *email) {
    struct MailingList *new_entry = (struct MailingList*) malloc(sizeof(struct MailingList));
    strcpy(new_entry->name, name);
    strcpy(new_entry->email, email);
    new_entry->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_entry;
        return;
    }

    struct MailingList *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_entry;
}

/* Function to remove an entry from the mailing list */
void remove_entry(struct MailingList **head_ref, char *email) {
    struct MailingList *temp = *head_ref, *prev;

    if (temp != NULL && strcmp(temp->email, email) == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

/* Function to print all entries in the mailing list */
void print_list(struct MailingList *head) {
    printf("Mailing List:\n");
    printf("==============\n");
    while (head != NULL) {
        printf("%s\t%s\n", head->name, head->email);
        head = head->next;
    }
}

/* Main program */
int main(void) {
    struct MailingList *head = NULL;
    char input[50];

    printf("Welcome to the mailing list manager!\n");

    while (1) {
        printf("\nPlease enter a command (add, remove, print, quit):\n");
        fgets(input, 50, stdin);
        input[strcspn(input, "\n")] = 0;

        /* Add a new entry */
        if (strcmp(input, "add") == 0) {
            char name[50], email[50];
            printf("Please enter the name:\n");
            fgets(name, 50, stdin);
            name[strcspn(name, "\n")] = 0;
            printf("Please enter the email:\n");
            fgets(email, 50, stdin);
            email[strcspn(email, "\n")] = 0;

            add_entry(&head, name, email);
            printf("Entry added!\n");
        }

        /* Remove an entry */
        else if (strcmp(input, "remove") == 0) {
            char email[50];
            printf("Please enter the email of the entry to remove:\n");
            fgets(email, 50, stdin);
            email[strcspn(email, "\n")] = 0;

            remove_entry(&head, email);
            printf("Entry removed!\n");
        }

        /* Print the list */
        else if (strcmp(input, "print") == 0) {
            print_list(head);
        }

        /* Quit the program */
        else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        /* Invalid command */
        else {
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}