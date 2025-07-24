//FormAI DATASET v1.0 Category: Phone Book ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to hold contact information */
typedef struct {
    char name[50];
    char phone_num[20];
    char email[50];
} Contact;

/* Helper function to add a contact to the phone book */
void add_contact(Contact* contacts, int* num_contacts) {
    /* Get new contact information */
    printf("Enter contact name: ");
    getchar();
    fgets(contacts[*num_contacts].name, sizeof(contacts[*num_contacts].name), stdin);
    printf("Enter contact phone number: ");
    fgets(contacts[*num_contacts].phone_num, sizeof(contacts[*num_contacts].phone_num), stdin);
    printf("Enter contact email: ");
    fgets(contacts[*num_contacts].email, sizeof(contacts[*num_contacts].email), stdin);
    
    /* Increment number of contacts */
    *num_contacts += 1;
    
    /* Print success message */
    printf("Contact added successfully.\n");
}

/* Helper function to search for a contact in the phone book */
void search_contact(Contact* contacts, int num_contacts) {
    /* Get search query from user */
    char search[50];
    printf("Enter a search query: ");
    getchar();
    fgets(search, sizeof(search), stdin);
    
    /* Loop through all contacts and print matching ones */
    int num_matches = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strstr(contacts[i].name, search) != NULL) {
            printf("%s\n%s\n%s\n\n", contacts[i].name, contacts[i].phone_num, contacts[i].email);
            num_matches++;
        }
    }
    
    /* Print number of matches found */
    if (num_matches == 0) {
        printf("No matches found.\n");
    } else if (num_matches == 1) {
        printf("1 match found.\n");
    } else {
        printf("%d matches found.\n", num_matches);
    }
}

/* Main function to run phone book program */
int main() {
    /* Initialize empty phone book */
    Contact contacts[100];
    int num_contacts = 0;
    
    /* Loop until user chooses to exit */
    char choice = '0';
    while (choice != '3') {
        /* Print main menu */
        printf("Phone Book\n");
        printf("-----------\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        /* Perform action based on user choice */
        if (choice == '1') {
            add_contact(contacts, &num_contacts);
        } else if (choice == '2') {
            search_contact(contacts, num_contacts);
        } else if (choice == '3') {
            printf("Goodbye!\n");
        } else {
            printf("Invalid choice.\n");
        }
    }
    
    return 0;
}