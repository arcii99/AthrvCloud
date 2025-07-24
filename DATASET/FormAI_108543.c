//FormAI DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone_number[20];
} Contact;

int num_contacts = 0;
Contact phone_book[MAX_CONTACTS];

void add_contact() {
    if (num_contacts < MAX_CONTACTS) {
        printf("Enter name: ");
        fgets(phone_book[num_contacts].name, sizeof(phone_book[num_contacts].name), stdin);
        phone_book[num_contacts].name[strcspn(phone_book[num_contacts].name, "\n")] = '\0'; // remove trailing newline from input

        printf("Enter phone number: ");
        fgets(phone_book[num_contacts].phone_number, sizeof(phone_book[num_contacts].phone_number), stdin);
        phone_book[num_contacts].phone_number[strcspn(phone_book[num_contacts].phone_number, "\n")] = '\0'; // remove trailing newline from input

        printf("Contact added successfully.\n");

        num_contacts++;
    } else {
        printf("Phone book is full. Cannot add new contact.\n");
    }
}

void list_contacts() {
    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
    } else {
        printf("Contacts:\n");
        for (int i = 0; i < num_contacts; i++) {
            printf("%s - %s\n", phone_book[i].name, phone_book[i].phone_number);
        }
    }
}

void search_contact() {
    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
    } else {
        char search_query[50];
        printf("Enter search query: ");
        fgets(search_query, sizeof(search_query), stdin);
        search_query[strcspn(search_query, "\n")] = '\0'; // remove trailing newline from input

        printf("Search results:\n");
        int found = 0;
        for (int i = 0; i < num_contacts; i++) {
            if (strstr(phone_book[i].name, search_query) != NULL || strstr(phone_book[i].phone_number, search_query) != NULL) {
                printf("%s - %s\n", phone_book[i].name, phone_book[i].phone_number);
                found = 1;
            }
        }
        if (!found) {
            printf("No results found.\n");
        }
    }
}

void delete_contact() {
    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
    } else {
        char delete_query[50];
        printf("Enter name or phone number of contact to delete: ");
        fgets(delete_query, sizeof(delete_query), stdin);
        delete_query[strcspn(delete_query, "\n")] = '\0'; // remove trailing newline from input

        int delete_index = -1;
        for (int i = 0; i < num_contacts; i++) {
            if (strcmp(phone_book[i].name, delete_query) == 0 || strcmp(phone_book[i].phone_number, delete_query) == 0) {
                delete_index = i;
                break;
            }
        }

        if (delete_index != -1) {
            for (int i = delete_index; i < num_contacts - 1; i++) {
                phone_book[i] = phone_book[i+1];
            }
            num_contacts--;
            printf("Contact deleted successfully.\n");
        } else {
            printf("Contact not found.\n");
        }
    }
}

int main() {
    while (1) {
        printf("Phone book menu:\n");
        printf("1. Add contact\n");
        printf("2. List contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Quit\n");

        char choice_str[10];
        printf("Enter choice: ");
        fgets(choice_str, sizeof(choice_str), stdin);
        choice_str[strcspn(choice_str, "\n")] = '\0'; // remove trailing newline from input

        int choice = atoi(choice_str);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                list_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}