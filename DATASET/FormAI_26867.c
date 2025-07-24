//FormAI DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define structure for storing contact information */
typedef struct phonebook {
    char name[50];
    char number[20];
} phonebook;

/* Define function for adding a new contact */
void add_contact(phonebook *pb, int *num_contacts) {
    printf("Enter a name: ");
    scanf("%s", pb[*num_contacts].name);
    printf("Enter a phone number: ");
    scanf("%s", pb[*num_contacts].number);
    (*num_contacts)++;
    printf("Contact added successfully.\n");
}

/* Define function for searching for a contact */
void search_contact(phonebook *pb, int num_contacts) {
    char name[50];
    printf("Enter a name to search for: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(pb[i].name, name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", pb[i].name, pb[i].number);
            found = 1;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

/* Define function for displaying all contacts */
void display_contacts(phonebook *pb, int num_contacts) {
    if (num_contacts == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("Name\tPhone Number\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", pb[i].name, pb[i].number);
    }
}

/* Define main function */
int main() {
    phonebook *pb = malloc(100 * sizeof(phonebook));
    int num_contacts = 0;
    int choice = 0;

    while (choice != 4) {
        printf("\nMenu\n----\n1. Add Contact\n2. Search for a Contact\n3. Display All Contacts\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact(pb, &num_contacts);
                break;
            case 2:
                search_contact(pb, num_contacts);
                break;
            case 3:
                display_contacts(pb, num_contacts);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }

    free(pb);
    return 0;
}