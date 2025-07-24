//FormAI DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <string.h>
#define MAX 100 // maximum number of phone book entries

struct PhoneBook {
    char name[50];
    char phone_number[15];
    char email[50];
};

struct PhoneBook phoneBook[MAX]; // array of phone book entries
int count = 0; // current number of phone book entries

int main() {
    int choice;
    int index;

    while(1) {
        printf("\n---PHONE BOOK MENU---\n");
        printf("1. Add new contact\n");
        printf("2. Search for contact by name\n");
        printf("3. Display all contacts\n");
        printf("4. Update contact\n");
        printf("5. Delete contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addNewContact();
                break;

            case 2:
                searchContactByName();
                break;

            case 3:
                displayAllContacts();
                break;

            case 4:
                index = searchContactByName();
                if(index != -1) {
                    updateContact(index);
                }
                break;

            case 5:
                index = searchContactByName();
                if(index != -1) {
                    deleteContact(index);
                }
                break;

            case 6:
                printf("Exiting phone book. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addNewContact() {
    if(count == MAX) {
        printf("Phone book is full. Cannot add new contact.\n");
        return;
    }

    struct PhoneBook person;

    printf("\nEnter name: ");
    fflush(stdin);
    fgets(person.name, 50, stdin);
    person.name[strcspn(person.name, "\n")] = '\0'; // remove newline

    printf("Enter phone number in format xxx-xxx-xxxx: ");
    fflush(stdin);
    fgets(person.phone_number, 15, stdin);
    person.phone_number[strcspn(person.phone_number, "\n")] = '\0'; // remove newline
    
    printf("Enter email: ");
    fflush(stdin);
    fgets(person.email, 50, stdin);
    person.email[strcspn(person.email, "\n")] = '\0'; // remove newline

    phoneBook[count++] = person;

    printf("\nContact added successfully!\n");
}

int searchContactByName() {
    char name[50];
    printf("\nEnter name to search: ");
    fflush(stdin);
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline

    int index = -1;
    for(int i = 0; i < count; i++) {
        if(strcmp(phoneBook[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("\nContact not found.\n");
    }

    return index;
}

void displayAllContacts() {
    if(count == 0) {
        printf("\nPhone book is empty.\n");
        return;
    }

    printf("\n%-20s %-15s %-20s\n", "Name", "Phone Number", "Email");
    printf("--------------------------------------------\n");

    for(int i = 0; i < count; i++) {
        printf("%-20s %-15s %-20s\n", phoneBook[i].name, phoneBook[i].phone_number, phoneBook[i].email);
    }
}

void updateContact(int index) {
    printf("\nUpdating contact...\n");

    struct PhoneBook person = phoneBook[index];

    printf("Enter phone number in format xxx-xxx-xxxx (current: %s): ", person.phone_number);
    fflush(stdin);
    fgets(person.phone_number, 15, stdin);
    person.phone_number[strcspn(person.phone_number, "\n")] = '\0'; // remove newline
    
    printf("Enter email (current: %s): ", person.email);
    fflush(stdin);
    fgets(person.email, 50, stdin);
    person.email[strcspn(person.email, "\n")] = '\0'; // remove newline

    phoneBook[index] = person;

    printf("\nContact updated successfully!\n");
}

void deleteContact(int index) {
    printf("\nDeleting contact...\n");

    struct PhoneBook person = phoneBook[index];

    printf("Are you sure you want to delete %s (y/n)? ", person.name);
    char confirm;
    scanf(" %c", &confirm);

    if(confirm == 'y') {
        for(int i = index; i < count - 1; i++) {
            phoneBook[i] = phoneBook[i+1];
        }
        count--;
        printf("\nContact deleted successfully!\n");
    }
    else {
        printf("\nDeletion cancelled.\n");
    }
}