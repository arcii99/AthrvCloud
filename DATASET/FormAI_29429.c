//FormAI DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_NUMBERS 5

// Structure for storing contact information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS][11];
    int num_numbers;
} contact;

// Function to add a new contact
void add_contact(contact *book, int *num_contacts) {
    contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter number (up to %d numbers, end with '0'): ", MAX_NUMBERS);
    int num_numbers = 0;
    while (num_numbers < MAX_NUMBERS) {
        char num_str[11];
        scanf("%s", num_str);
        if (strcmp(num_str, "0") == 0) {
            break;
        }
        strcpy(new_contact.numbers[num_numbers], num_str);
        num_numbers++;
    }
    new_contact.num_numbers = num_numbers;
    book[*num_contacts] = new_contact;
    (*num_contacts)++;
}

// Function to display all contacts
void display_contacts(contact *book, int num_contacts) {
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s", book[i].name);
        for (int j = 0; j < book[i].num_numbers; j++) {
            printf(" %s", book[i].numbers[j]);
        }
        printf("\n");
    }
}

// Function to search for a contact by name
void search_contact(contact *book, int num_contacts) {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search for: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(book[i].name, search_name) == 0) {
            printf("%s", book[i].name);
            for (int j = 0; j < book[i].num_numbers; j++) {
                printf(" %s", book[i].numbers[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

// Main program
int main() {
    contact book[100];
    int num_contacts = 0;
    while (1) {
        printf("Select an option:\n");
        printf("1. Add new contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_contact(book, &num_contacts);
                break;
            case 2:
                display_contacts(book, num_contacts);
                break;
            case 3:
                search_contact(book, num_contacts);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
}