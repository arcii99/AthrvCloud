//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 1000

// Struct to hold a person's name and email
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Person;

// Struct to hold a mailing list
typedef struct {
    int size;
    Person people[MAX_LIST_SIZE];
} MailingList;

void add_person(MailingList* list) {
    // Check if there's room to add another person
    if (list->size >= MAX_LIST_SIZE) {
        printf("Sorry, the mailing list is full.\n");
        return;
    }

    // Get the person's name
    printf("Enter the person's name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    // Get the person's email
    printf("Enter the person's email: ");
    char email[MAX_EMAIL_LENGTH];
    scanf("%s", email);

    // Add the person to the mailing list
    strcpy(list->people[list->size].name, name);
    strcpy(list->people[list->size].email, email);
    list->size++;

    printf("Added %s (%s) to the mailing list.\n", name, email);
}

void print_list(MailingList list) {
    printf("Mailing List:\n");

    for (int i = 0; i < list.size; i++) {
        printf("- %s (%s)\n", list.people[i].name, list.people[i].email);
    }
}

int main() {
    // Create an empty mailing list
    MailingList list = { .size = 0 };

    // Main loop to process user input
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a person to the mailing list\n");
        printf("2. View the mailing list\n");
        printf("3. Quit\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_person(&list);
                break;

            case 2:
                print_list(list);
                break;

            case 3:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}