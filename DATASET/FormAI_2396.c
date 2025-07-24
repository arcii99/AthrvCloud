//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of entries in the database
#define MAX_ENTRIES 100

// Define the structure of the entries in the database
typedef struct entry {
    char name[50];
    int age;
    char occupation[50];
} Entry;

// Declare an array to store the entries
Entry db[MAX_ENTRIES];

// Declare variables to keep track of the number of entries and the next available index
int num_entries = 0;
int next_index = 0;

// Declare function prototypes
void add_entry();
void view_entries();
void search_entry();

// Main function
int main() {
    int choice;

    // Print the title of the database program
    printf("Peaceful Database Program\n");
    printf("-------------------------\n");

    // Print the menu options
    while (1) {
        printf("\nMenu\n");
        printf("----\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add an entry to the database
void add_entry() {
    Entry new_entry;

    // Get the name, age, and occupation of the new entry from the user
    printf("\nEnter the name: ");
    scanf("%s", new_entry.name);
    printf("Enter the age: ");
    scanf("%d", &new_entry.age);
    printf("Enter the occupation: ");
    scanf("%s", new_entry.occupation);

    // Check if the database is already full
    if (num_entries == MAX_ENTRIES) {
        printf("\nThe database is already full. Cannot add entry.\n");
    } else {
        // Add the new entry to the database and update the number of entries and the next available index
        db[next_index] = new_entry;
        num_entries++;
        next_index++;

        printf("\nEntry added successfully.\n");
    }
}

// Function to view all entries in the database
void view_entries() {
    // Check if the database is empty
    if (num_entries == 0) {
        printf("\nThe database is empty.\n");
    } else {
        // Print the header of the table of entries
        printf("\nName\t\tAge\tOccupation\n");
        printf("--------------------------------\n");

        // Loop through the entries in the database and print each one
        for (int i = 0; i < num_entries; i++) {
            printf("%s\t\t%d\t%s\n", db[i].name, db[i].age, db[i].occupation);
        }
    }
}

// Function to search for an entry in the database
void search_entry() {
    char search_name[50];
    int found = 0;

    // Get the name of the entry to search for from the user
    printf("\nEnter the name of the entry to search for: ");
    scanf("%s", search_name);

    // Loop through the entries in the database and check if the name matches
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(db[i].name, search_name) == 0) {
            // Print the matching entry and set the found flag to 1
            printf("\nName: %s\nAge: %d\nOccupation: %s\n", db[i].name, db[i].age, db[i].occupation);
            found = 1;
            break;
        }
    }

    // Print a message if the entry was not found
    if (!found) {
        printf("\nThe entry was not found.\n");
    }
}