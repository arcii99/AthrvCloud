//FormAI DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_ENTRIES 1000

// Define a structure to store the phone book entries
struct PhoneBookEntry {
    char name[MAX_NAME_LEN];
    char phone_number[MAX_PHONE_LEN];
};

// Declare global variables
int num_entries = 0;
struct PhoneBookEntry phone_book[MAX_ENTRIES];

// Function to add a new entry to the phone book
void add_entry() {
    // Check if there is still space in the phone book
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Phone book is full!\n");
        return;
    }

    // Prompt the user to enter the name and phone number
    printf("Enter the name: ");
    scanf("%s", phone_book[num_entries].name);
    printf("Enter the phone number: ");
    scanf("%s", phone_book[num_entries].phone_number);

    // Increment the number of entries
    num_entries++;

    printf("New entry added to the phone book!\n");
}

// Function to search for an entry in the phone book
void search_entry() {
    // Prompt the user to enter the name to search for
    char search_name[MAX_NAME_LEN];
    printf("Enter the name to search for: ");
    scanf("%s", search_name);

    // Iterate through the phone book and search for the name
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("Phone number for '%s': %s\n", search_name, phone_book[i].phone_number);
            return;
        }
    }

    printf("Entry not found in the phone book!\n");
}

// Function to print all entries in the phone book
void print_entries() {
    // Check if there are any entries in the phone book
    if (num_entries == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    // Iterate through the phone book and print each entry
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s, Phone number: %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

// Main function to run the phone book program
int main() {
    // Initialize the phone book with some sample entries
    strcpy(phone_book[0].name, "John Smith");
    strcpy(phone_book[0].phone_number, "555-1234");
    num_entries++;

    strcpy(phone_book[1].name, "Jane Doe");
    strcpy(phone_book[1].phone_number, "555-5678");
    num_entries++;

    // Loop to display the menu and process user input
    char user_choice;
    while (1) {
        printf("\n");
        printf("+=======+=======MENU=======+=======+\n");
        printf("|                                 |\n");
        printf("|         1. Add an entry         |\n");
        printf("|         2. Search for an entry  |\n");
        printf("|         3. Print all entries    |\n");
        printf("|         Q. Quit                 |\n");
        printf("|                                 |\n");
        printf("+=======+=======================+=======+\n");
        printf("Enter your choice: ");

        // Read a single character from the user
        scanf("%s", &user_choice);

        // Process the user's choice
        switch (user_choice) {
            case '1':
                add_entry();
                break;
            case '2':
                search_entry();
                break;
            case '3':
                print_entries();
                break;
            case 'Q':
            case 'q':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}