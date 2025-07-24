//FormAI DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone_number[20];
};

void add_contact(struct contact *book, int *num_contacts);
void display_all(struct contact *book, int num_contacts);
void search_contact(struct contact *book, int num_contacts);
void delete_contact(struct contact *book, int *num_contacts);

int main() {
    struct contact phone_book[100];
    int num_contacts = 0;
    char choice[10];

    do {
        printf("\nPHONE BOOK MENU\n");
        printf("----------------\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        fgets(choice, 10, stdin);
        printf("----------------\n");

        switch(atoi(choice)) {
            case 1:
                add_contact(phone_book, &num_contacts);
                break;

            case 2:
                display_all(phone_book, num_contacts);
                break;

            case 3:
                search_contact(phone_book, num_contacts);
                break;

            case 4:
                delete_contact(phone_book, &num_contacts);
                break;

            case 5:
                printf("Exiting Phone Book...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (atoi(choice) != 5);

    return 0;
}

void add_contact(struct contact *book, int *num_contacts) {
    if (*num_contacts == 100) {
        printf("Phone book is full.\n");
        return;
    }

    struct contact new_contact;

    printf("Enter name: ");
    fgets(new_contact.name, 50, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0; // remove newline character

    printf("Enter phone number: ");
    fgets(new_contact.phone_number, 20, stdin);
    new_contact.phone_number[strcspn(new_contact.phone_number, "\n")] = 0;

    book[*num_contacts] = new_contact;
    (*num_contacts)++;

    printf("Contact added.\n");
}

void display_all(struct contact *book, int num_contacts) {
    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Your Phone Book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s\t%s\n", i+1, book[i].name, book[i].phone_number);
    }
}

void search_contact(struct contact *book, int num_contacts) {
    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char name_search[50];
    printf("Enter name to search: ");
    fgets(name_search, 50, stdin);
    name_search[strcspn(name_search, "\n")] = 0;

    int results = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(book[i].name, name_search) == 0) {
            printf("%d. %s\t%s\n", i+1, book[i].name, book[i].phone_number);
            results++;
        }
    }

    if (results == 0)
        printf("No contacts found with that name.\n");
}

void delete_contact(struct contact *book, int *num_contacts) {
    if (*num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char name_delete[50];
    printf("Enter name to delete: ");
    fgets(name_delete, 50, stdin);
    name_delete[strcspn(name_delete, "\n")] = 0;

    int index = -1;
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(book[i].name, name_delete) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1)
        printf("No contacts found with that name.\n");
    else {
        for (int i = index; i < *num_contacts-1; i++) {
            book[i] = book[i+1];
        }

        (*num_contacts)--;
        printf("Contact deleted.\n");
    }
}