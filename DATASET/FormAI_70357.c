//FormAI DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15

typedef struct contact {
    char name[MAX_NAME_LEN];
    char phone_num[MAX_NUM_LEN];
    struct contact *next;
} Contact;

Contact *add_contact(Contact *list);
Contact *delete_contact(Contact *list, char *name);
void search_contact(Contact *list, char *name);
void print_list(Contact *list);
void free_list(Contact *list);

int main(void) {
    Contact *list = NULL;
    int choice;
    char name[MAX_NAME_LEN];

    do {
        printf("\n\nPhone Book\n");
        printf("1 - Add Contact\n");
        printf("2 - Delete Contact\n");
        printf("3 - Search Contact\n");
        printf("4 - Print Phone Book\n");
        printf("5 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                list = add_contact(list);
                break;
            case 2:
                printf("Enter the name of the contact to delete: ");
                scanf("%s", name);
                list = delete_contact(list, name);
                break;
            case 3:
                printf("Enter the name of the contact to search: ");
                scanf("%s", name);
                search_contact(list, name);
                break;
            case 4:
                print_list(list);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 5);

    free_list(list);

    return 0;
}

Contact *add_contact(Contact *list) {
    Contact *new_contact = malloc(sizeof(Contact));

    printf("Enter the name of the contact: ");
    scanf("%s", new_contact->name);

    printf("Enter the phone number of the contact: ");
    scanf("%s", new_contact->phone_num);

    new_contact->next = list;
    list = new_contact;

    printf("Contact added successfully!\n");

    return list;
}

Contact *delete_contact(Contact *list, char *name) {
    Contact *curr_contact = list;
    Contact *prev_contact = NULL;

    while(curr_contact != NULL) {
        if(strcmp(curr_contact->name, name) == 0) {
            if(prev_contact == NULL) {
                list = curr_contact->next;
            } else {
                prev_contact->next = curr_contact->next;
            }

            free(curr_contact);
            printf("Contact deleted successfully!\n");

            return list;
        }

        prev_contact = curr_contact;
        curr_contact = curr_contact->next;
    }

    printf("Contact not found!\n");
    return list;
}

void search_contact(Contact *list, char *name) {
    Contact *curr_contact = list;

    while(curr_contact != NULL) {
        if(strcmp(curr_contact->name, name) == 0) {
            printf("%s - %s\n", curr_contact->name, curr_contact->phone_num);
            return;
        }

        curr_contact = curr_contact->next;
    }

    printf("Contact not found!\n");
}

void print_list(Contact *list) {
    Contact *curr_contact = list;

    printf("\nPhone Book:\n");

    while(curr_contact != NULL) {
        printf("%s - %s\n", curr_contact->name, curr_contact->phone_num);
        curr_contact = curr_contact->next;
    }
}

void free_list(Contact *list) {
    Contact *curr_contact = list;
    Contact *next_contact;

    while(curr_contact != NULL) {
        next_contact = curr_contact->next;
        free(curr_contact);
        curr_contact = next_contact;
    }
}