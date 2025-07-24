//FormAI DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 100
#define MAX_PHONE_NUM_LEN 20

struct contact {
    char name[MAX_NAME_LEN];
    char phone_number[MAX_PHONE_NUM_LEN];
};

struct phone_book {
    int num_contacts;
    struct contact contacts[MAX_CONTACTS];
};

// Function to print the main menu of the phone book program
void print_menu() {
    printf("\nWelcome to the Phone Book Program\n");
    printf("=================================\n\n");
    printf("1. View Contacts\n");
    printf("2. Add Contact\n");
    printf("3. Delete Contact\n");
    printf("4. Search Contact\n");
    printf("5. Exit\n");
}

// Function to add a contact to the phone book
void add_contact(struct phone_book *book) {
    if (book->num_contacts == MAX_CONTACTS) {
        printf("The phone book is full.\n");
        return;
    }
    
    printf("Enter the name of the new contact: ");
    fgets(book->contacts[book->num_contacts].name, MAX_NAME_LEN, stdin);
    book->contacts[book->num_contacts].name[strlen(book->contacts[book->num_contacts].name)-1] = '\0';
    
    printf("Enter the phone number of the new contact: ");
    fgets(book->contacts[book->num_contacts].phone_number, MAX_PHONE_NUM_LEN, stdin);
    book->contacts[book->num_contacts].phone_number[strlen(book->contacts[book->num_contacts].phone_number)-1] = '\0';
    
    book->num_contacts++;
    
    printf("The new contact has been added to the phone book.\n");
}

// Function to delete a contact from the phone book
void delete_contact(struct phone_book *book) {
    char name[MAX_NAME_LEN];
    int i, j, found = 0;
    
    printf("Enter the name of the contact you want to delete: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strlen(name)-1] = '\0';
    
    for (i = 0; i < book->num_contacts; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        for (j = i; j < book->num_contacts - 1; j++) {
            strcpy(book->contacts[j].name, book->contacts[j+1].name);
            strcpy(book->contacts[j].phone_number, book->contacts[j+1].phone_number);
        }
        book->num_contacts--;
        printf("The contact has been deleted from the phone book.\n");
    } else {
        printf("The contact was not found in the phone book.\n");
    }
}

// Function to search for a contact in the phone book
void search_contact(struct phone_book *book) {
    char name[MAX_NAME_LEN];
    int i, found = 0;
    
    printf("Enter the name of the contact you want to search for: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strlen(name)-1] = '\0';
    
    for (i = 0; i < book->num_contacts; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("Name: %s\nPhone number: %s\n", book->contacts[i].name, book->contacts[i].phone_number);
    } else {
        printf("The contact was not found in the phone book.\n");
    }
}

// Function to view all contacts in the phone book
void view_contacts(struct phone_book *book) {
    int i;
    
    if (book->num_contacts == 0) {
        printf("The phone book is empty.\n");
        return;
    }
    
    printf("Name\t\tPhone Number\n");
    printf("=================================\n");
    for (i = 0; i < book->num_contacts; i++) {
        printf("%s\t\t%s\n", book->contacts[i].name, book->contacts[i].phone_number);
    }
}

int main() {
    struct phone_book book = {0};
    int choice;
 
    while (1) {
        print_menu();
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                view_contacts(&book);
                break;
            case 2:
                add_contact(&book);
                break;
            case 3:
                delete_contact(&book);
                break;
            case 4:
                search_contact(&book);
                break;
            case 5:
                printf("Thank you for using the Phone Book Program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}