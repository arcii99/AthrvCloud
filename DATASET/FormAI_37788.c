//FormAI DATASET v1.0 Category: Phone Book ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 100 // Maximum entries in the phone book
#define MAX_NAME_LENGTH 50 // Maximum characters in a name
#define MAX_PHONE_LENGTH 15 // Maximum characters in a phone number

struct Entry {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

struct PhoneBook {
    struct Entry entries[MAX_ENTRIES];
    int num_entries;
};

int addEntry(struct PhoneBook *pb, char *name, char *phone);
int removeEntry(struct PhoneBook *pb, char *name);
int findEntry(struct PhoneBook *pb, char *name);
void printPhoneBook(struct PhoneBook *pb);
void clearPhoneBook(struct PhoneBook *pb);

int main(void) {
    struct PhoneBook pb;
    pb.num_entries = 0;

    // Add a few entries
    addEntry(&pb,"Alice","555-1234");
    addEntry(&pb,"Bob","555-5678");
    addEntry(&pb,"Carol","555-6789");

    // Print the phone book
    printPhoneBook(&pb);

    // Remove an entry
    removeEntry(&pb,"Bob");

    // Print the phone book again
    printPhoneBook(&pb);

    // Find an entry
    int index = findEntry(&pb,"Alice");
    if (index != -1) {
        printf("Found %s: %s\n", pb.entries[index].name, pb.entries[index].phone);
    } else {
        printf("Entry not found.\n");
    }

    // Clear the phone book
    clearPhoneBook(&pb);

    return 0;
}

// Adds a new entry to the phone book
// Returns 0 if successful, -1 if the phone book is full
int addEntry(struct PhoneBook *pb, char *name, char *phone) {
    if (pb->num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return -1;
    }

    strcpy(pb->entries[pb->num_entries].name, name);
    strcpy(pb->entries[pb->num_entries].phone, phone);
    pb->num_entries++;

    return 0;
}

// Removes an entry from the phone book
// Returns 0 if successful, -1 if the entry was not found
int removeEntry(struct PhoneBook *pb, char *name) {
    int index = findEntry(pb, name);
    if (index == -1) {
        printf("Entry not found.\n");
        return -1;
    }

    // Shift the entries after the removed entry back by one
    for (int i = index; i < pb->num_entries - 1; i++) {
        strcpy(pb->entries[i].name,pb->entries[i+1].name);
        strcpy(pb->entries[i].phone,pb->entries[i+1].phone);
    }
    pb->num_entries--;

    return 0;
}

// Finds the index of an entry in the phone book
// Returns the index if the entry is found, -1 otherwise
int findEntry(struct PhoneBook *pb, char *name) {
    for (int i = 0; i < pb->num_entries; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Prints the contents of the phone book
void printPhoneBook(struct PhoneBook *pb) {
    printf("Phone book:\n");
    for (int i = 0; i < pb->num_entries; i++) {
        printf("%s: %s\n", pb->entries[i].name, pb->entries[i].phone);
    }
}

// Clears the phone book
void clearPhoneBook(struct PhoneBook *pb) {
    pb->num_entries = 0;
}