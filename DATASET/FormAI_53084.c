//FormAI DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 13
#define MAX_ENTRIES 100

struct PhoneBookEntry {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

struct PhoneBook {
    struct PhoneBookEntry entries[MAX_ENTRIES];
    int size;
};

void addEntry(struct PhoneBook *pb, char *name, char *phone) {
    if (pb->size < MAX_ENTRIES) {
        strncpy(pb->entries[pb->size].name, name, MAX_NAME_LENGTH);
        strncpy(pb->entries[pb->size].phone, phone, MAX_PHONE_LENGTH);
        pb->size++;
        printf("Entry added successfully!\n");
    } else {
        printf("Error: Phonebook is full!\n");
    }
}

void removeEntry(struct PhoneBook *pb, char *name) {
    int i, j;
    for (i = 0; i < pb->size; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            for (j = i; j < pb->size - 1; j++) {
                strncpy(pb->entries[j].name, pb->entries[j + 1].name, MAX_NAME_LENGTH);
                strncpy(pb->entries[j].phone, pb->entries[j + 1].phone, MAX_PHONE_LENGTH);
            }
            pb->size--;
            printf("Entry removed successfully!\n");
            return;
        }
    }
    printf("Error: Entry not found!\n");
}

void searchEntry(struct PhoneBook *pb, char *name) {
    int i;
    for (i = 0; i < pb->size; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            printf("Name: %s\n", pb->entries[i].name);
            printf("Phone: %s\n", pb->entries[i].phone);
            return;
        }
    }
    printf("Error: Entry not found!\n");
}

void printPhoneBook(struct PhoneBook *pb) {
    int i;
    for (i = 0; i < pb->size; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Name: %s\n", pb->entries[i].name);
        printf("Phone: %s\n", pb->entries[i].phone);
    }
}

int main() {
    struct PhoneBook pb;
    pb.size = 0;
    int option;
    char name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];

    do {
        printf("\n---Phone Book Menu---\n");
        printf("1. Add entry\n");
        printf("2. Remove entry\n");
        printf("3. Search entry\n");
        printf("4. Print phone book\n");
        printf("0. Exit\n");
        printf("Enter option:");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                addEntry(&pb, name, phone);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                removeEntry(&pb, name);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                searchEntry(&pb, name);
                break;
            case 4:
                printPhoneBook(&pb);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != 0);

    return 0;
}