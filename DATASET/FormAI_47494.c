//FormAI DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone_number[15];
    char email[50];
} Contact;

Contact phone_book[MAX_CONTACTS];
int num_contacts = 0;

int main() {
    int choice;
    do {
        printf("\nPHONE BOOK\n");
        printf("1. Add a contact\n");
        printf("2. View all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                search_contacts();
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void add_contact() {
    Contact new_contact;

    printf("\nEnter name: ");
    scanf("%[^\n]%*c", new_contact.name);

    printf("Enter phone number: ");
    scanf("%[^\n]%*c", new_contact.phone_number);

    printf("Enter email: ");
    scanf("%[^\n]%*c", new_contact.email);

    phone_book[num_contacts++] = new_contact;

    printf("\nThe contact has been added successfully.\n");
}

void view_contacts() {
    printf("\nCONTACT LIST\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", phone_book[i].name);
        printf("Phone Number: %s\n", phone_book[i].phone_number);
        printf("Email: %s\n", phone_book[i].email);
        printf("\n");
    }
}

void search_contacts() {
    char query[50];
    int results[MAX_CONTACTS];
    int num_results = 0;

    printf("\nEnter a name to search for: ");
    scanf("%[^\n]%*c", query);

    for (int i = 0; i < num_contacts; i++) {
        if (strstr(phone_book[i].name, query) != NULL) {
            results[num_results++] = i;
        }
    }

    if (num_results == 0) {
        printf("\nNo results found.\n");
    } else {
        printf("\nSEARCH RESULTS\n");
        for (int i = 0; i < num_results; i++) {
            printf("Name: %s\n", phone_book[results[i]].name);
            printf("Phone Number: %s\n", phone_book[results[i]].phone_number);
            printf("Email: %s\n", phone_book[results[i]].email);
            printf("\n");
        }
    }
}