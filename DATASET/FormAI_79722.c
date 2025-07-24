//FormAI DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum size of phone book
#define MAX_BOOK_SIZE 100

// Maximum length of name and phone number
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 15

// Encrypted strings
const char *paranoid_strings[] = {
        "\x4e\x45\x56\x45\x52\x20\x54\x52\x55\x53\x54\x20\x4e\x4f\x20\x4f\x4e\x45\x20\x2d\x20\x54\x48\x45\x59\x20\x41\x52\x45\x20\x41\x46\x54\x45\x52\x20\x55\x53\x21\n",
        "\x50\x6c\x65\x61\x73\x65\x20\x65\x6e\x74\x65\x72\x20\x79\x6f\x75\x72\x20\x6e\x61\x6d\x65\x3a",
        "\x50\x6c\x65\x61\x73\x65\x20\x65\x6e\x74\x65\x72\x20\x61\x20\x76\x61\x6c\x69\x64\x20\x6e\x75\x6d\x62\x65\x72\x20\x65\x63\x68\x6f\x20\x74\x6f\x20\x63\x6f\x6e\x74\x61\x69\x6e\x20\x6f\x6e\x6c\x79\x20\x5a\x45\x52\x4f\x53\x20\x61\x6e\x64\x20\x6e\x75\x6d\x62\x65\x72\x73\x21",
        "\x51\x75\x65\x72\x79\x20\x4d\x6f\x72\x65\x20\x43\x6f\x64\x69\x6e\x67\x20\x41\x6b\x65\x72\x20\x43\x6f\x6e\x63\x65\x72\x6e\n",
        "\x54\x68\x72\x65\x61\x74\x20\x4c\x65\x76\x65\x6c\x20\x53\x65\x63\x75\x72\x69\x74\x79\x20\x41\x6c\x65\x72\x74\x21\n"
};

// Encryption key
const int paranoid_key = 13;

// Structure to store name and phone number
struct contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

// Global variables
struct contact phone_book[MAX_BOOK_SIZE];
int current_size = 0;

// Function prototypes
void display_menu();
void add_contact();
void show_contacts();
void search_contact();
void paranoid_print(const char *str);

// Main function
int main() {

    paranoid_print(paranoid_strings[0]);
    display_menu();

    while (1) {
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                show_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                paranoid_print(paranoid_strings[2]);
                exit(0);
            default:
                paranoid_print(paranoid_strings[1]);
                break;
        }

        display_menu();
    }

    return 0;
}

// Function to display menu
void display_menu() {
    paranoid_print("\nPhone Book Menu\n");
    paranoid_print("1. Add Contact\n");
    paranoid_print("2. Show Contacts\n");
    paranoid_print("3. Search Contact\n");
    paranoid_print("4. Exit\n");
}

// Function to add a contact
void add_contact() {
    if (current_size == MAX_BOOK_SIZE) {
        paranoid_print("\nPhone book is full. Cannot add any more contacts.\n");
        return;
    }

    paranoid_print("\nEnter name of contact: ");
    scanf("%s", phone_book[current_size].name);

    paranoid_print("\nEnter phone number of contact: ");
    scanf("%s", phone_book[current_size].phone);

    paranoid_print("\nContact added successfully.\n");
    current_size++;
}

// Function to show all contacts
void show_contacts() {
    if (current_size == 0) {
        paranoid_print("\nPhone book is empty.\n");
        return;
    }

    paranoid_print("\nList of contacts:\n");

    for (int i = 0; i < current_size; i++) {
        printf("Name: %s\nPhone: %s\n", phone_book[i].name, phone_book[i].phone);
    }
}

// Function to search for a contact
void search_contact() {
    if (current_size == 0) {
        paranoid_print("\nPhone book is empty.\n");
        return;
    }

    char search_name[MAX_NAME_LENGTH];
    paranoid_print("\nEnter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < current_size; i++) {
        if (strcmp(search_name, phone_book[i].name) == 0) {
            printf("Name: %s\nPhone: %s\n", phone_book[i].name, phone_book[i].phone);
            return;
        }
    }

    paranoid_print("\nNo contact found with that name.\n");
}

// Function to print an encrypted string
void paranoid_print(const char *str) {
    char c;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        c = str[i];

        if (c >= 'a' && c <= 'z') {
            c = 'A' + (c - 'a' + paranoid_key) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = 'a' + (c - 'A' + paranoid_key) % 26;
        }

        putchar(c);
    }
}