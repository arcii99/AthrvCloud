//FormAI DATASET v1.0 Category: Phone Book ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 10

struct PhoneBookEntry {
    char name[MAX_NAME_LENGTH + 1];
    char phone[MAX_PHONE_LENGTH + 1];
};

struct PhoneBook {
    struct PhoneBookEntry entries[MAX_ENTRIES];
    int count;
};

void AddEntry(struct PhoneBook *phoneBook, char *name, char *phone) {
    if (phoneBook->count < MAX_ENTRIES) {
        struct PhoneBookEntry newEntry;
        strcpy(newEntry.name, name);
        strcpy(newEntry.phone, phone);
        phoneBook->entries[phoneBook->count] = newEntry;
        phoneBook->count++;
        printf("Added entry: %s - %s\n", name, phone);
    } else {
        printf("Cannot add entry. Phone book is full.\n");
    }
}

void PrintPhoneBook(struct PhoneBook *phoneBook) {
    printf("Phone book:\n");
    for (int i = 0; i < phoneBook->count; i++) {
        struct PhoneBookEntry entry = phoneBook->entries[i];
        printf("%s - %s\n", entry.name, entry.phone);
    }
}

int main() {
    struct PhoneBook phoneBook;
    phoneBook.count = 0;

    AddEntry(&phoneBook, "Jane", "1234567890");
    AddEntry(&phoneBook, "John", "0987654321");

    PrintPhoneBook(&phoneBook);

    return 0;
}