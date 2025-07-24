//FormAI DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <string.h>

#define MAX 50 // Maximum number of contacts that can be stored in the phone book

// Structure of contact information
struct contact {
    char name[20];
    long int phone;
};

// Function prototypes
int menu();
int addContact(struct contact list[], int count);
void viewContacts(struct contact list[], int count);
int searchContact(struct contact list[], int count, char name[]);
int deleteContact(struct contact list[], int count, char name[]);

int main() {
    struct contact phoneBook[MAX]; // Array of contacts in the phone book
    int choice, count = 0; // count keeps track of the number of contacts in the phone book
    
    printf("\n\n===== Phone Book =====\n");
    
    do {
        choice = menu();
        switch(choice) {
            case 1:
                count = addContact(phoneBook, count);
                break;
            case 2:
                viewContacts(phoneBook, count);
                break;
            case 3:
                char name[20];
                printf("\nEnter name to search: ");
                scanf("%s", name);
                searchContact(phoneBook, count, name);
                break;
            case 4:
                char nameToDel[20];
                printf("\nEnter name to delete: ");
                scanf("%s", nameToDel);
                count = deleteContact(phoneBook, count, nameToDel);
                break;
            case 0:
                printf("\nThank you for using Phone Book!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
        
    } while(choice != 0);
    
    return 0;
}

// Function to display menu and return user choice
int menu() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("0. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add contact to phone book
int addContact(struct contact list[], int count) {
    if(count >= MAX) {
        printf("\nPhone book is full. Cannot add more contacts.\n");
    } else {
        printf("\nEnter details of contact %d:\n", count+1);
        printf("Name: ");
        scanf("%s", list[count].name);
        printf("Phone: ");
        scanf("%ld", &list[count].phone);
        count++;
    }
    return count;
}

// Function to display all contacts in the phone book
void viewContacts(struct contact list[], int count) {
    printf("\nContacts:\n");
    printf("#\tName\tPhone\n");
    for(int i=0; i<count; i++) {
        printf("%d\t%s\t%ld\n", i+1, list[i].name, list[i].phone);
    }
}

// Function to search for a contact in the phone book
int searchContact(struct contact list[], int count, char name[]) {
    int index = -1;
    for(int i=0; i<count; i++) {
        if(strcmp(list[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nContact not found.\n");
    } else {
        printf("\nContact found at index %d:\n", index+1);
        printf("\tName: %s\n", list[index].name);
        printf("\tPhone: %ld\n", list[index].phone);
    }
    return index;
}

// Function to delete a contact from the phone book
int deleteContact(struct contact list[], int count, char name[]) {
    int index = searchContact(list, count, name); // First we search for the contact
    if(index == -1) {
        printf("\nContact not found. No changes made.\n");
    } else {
        // Shift all contacts to the left of the index to fill in the gap
        for(int i=index; i<count-1; i++) {
            strcpy(list[i].name, list[i+1].name);
            list[i].phone = list[i+1].phone;
        }
        count--; // Decrement the number of contacts in the phone book
        printf("\nContact deleted successfully.\n");
    }
    return count;
}