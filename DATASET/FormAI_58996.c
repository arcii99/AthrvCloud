//FormAI DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct PhoneBookEntry {
    char name[50];
    char phone_number[15];
};

struct PhoneBookEntry phone_book[MAX_ENTRIES];
int current_entry = 0;

void add_entry() {
    if (current_entry == MAX_ENTRIES) {
        printf("Phone book is full. Cannot add any more entries.\n");
        return;
    }

    struct PhoneBookEntry new_entry;
    printf("Enter name: ");
    fgets(new_entry.name, 50, stdin);
    new_entry.name[strcspn(new_entry.name, "\n")] = 0; // remove newline character
    printf("Enter phone number: ");
    fgets(new_entry.phone_number, 15, stdin);
    new_entry.phone_number[strcspn(new_entry.phone_number, "\n")] = 0; // remove newline character

    phone_book[current_entry] = new_entry;
    current_entry++;

    printf("Entry added successfully.\n");
}

void display_phone_book() {
    if (current_entry == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Name\t\t\tPhone number\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < current_entry; i++) {
        printf("%-20s %-15s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

void search_entry() {
    if (current_entry == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char name_to_search[50];
    printf("Enter name to search: ");
    fgets(name_to_search, 50, stdin);
    name_to_search[strcspn(name_to_search, "\n")] = 0; // remove newline character

    for (int i = 0; i < current_entry; i++) {
        if (strcasecmp(name_to_search, phone_book[i].name) == 0) {
            printf("Name\t\t\tPhone number\n");
            printf("-------------------------------------------------\n");
            printf("%-20s %-15s\n", phone_book[i].name, phone_book[i].phone_number);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add new entry\n");
        printf("2. Display phone book\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                add_entry();
                break;

            case 2:
                display_phone_book();
                break;

            case 3:
                search_entry();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}