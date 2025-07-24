//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20      // Maximum length of names
#define MAX_EMAIL_LENGTH 50     // Maximum length of email addresses
#define MAX_LIST_SIZE 100       // Maximum number of entries in the mailing list

// Define a struct to represent a person in the mailing list
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Person;

// Declare a global array to hold the mailing list
Person mailing_list[MAX_LIST_SIZE];

// Declare a global variable to keep track of the size of the mailing list
int mailing_list_size = 0;

// Function to add a person to the mailing list
void add_person(char* name, char* email) {
    // Check if the mailing list is already full
    if (mailing_list_size >= MAX_LIST_SIZE) {
        printf("Error: Mailing list is full!\n");
        return;
    }

    // Create a new Person object and add it to the mailing list
    Person new_person;
    strcpy(new_person.name, name);
    strcpy(new_person.email, email);
    mailing_list[mailing_list_size] = new_person;

    // Increment the size of the mailing list
    mailing_list_size++;

    printf("Added %s to the mailing list.\n", name);
}

// Function to remove a person from the mailing list
void remove_person(char* name) {
    // Find the index of the person in the mailing list
    int index = -1;
    for (int i = 0; i < mailing_list_size; i++) {
        if (strcmp(mailing_list[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the person was found, remove them from the mailing list
    if (index >= 0) {
        for (int i = index; i < mailing_list_size - 1; i++) {
            mailing_list[i] = mailing_list[i+1];
        }
        mailing_list_size--;

        printf("Removed %s from the mailing list.\n", name);
    } else {
        printf("Error: Could not find person.\n");
    }
}

// Function to print the entire mailing list
void print_list() {
    printf("Mailing List:\n");
    for (int i = 0; i < mailing_list_size; i++) {
        printf("%s <%s>\n", mailing_list[i].name, mailing_list[i].email);
    }
}

int main() {
    // Demonstrate the mailing list manager
    add_person("John Doe", "johndoe@example.com");
    add_person("Jane Smith", "janesmith@example.com");
    add_person("Bob Johnson", "bobjohnson@example.com");
    print_list();
    remove_person("Jane Smith");
    print_list();

    return 0;
}