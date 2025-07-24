//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 20
#define MAX_ENTRIES 1000

struct MailingListEntry {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
};

struct MailingList {
    struct MailingListEntry entries[MAX_ENTRIES];
    int count;
};

void addEntry(struct MailingList *list, char *email, char *name) {
    if (list->count >= MAX_ENTRIES) {
        printf("Mailing list is full\n");
        return;
    }

    struct MailingListEntry newEntry;
    strncpy(newEntry.email, email, MAX_EMAIL_LENGTH);
    strncpy(newEntry.name, name, MAX_NAME_LENGTH);
    list->entries[list->count++] = newEntry;
}

void removeEntry(struct MailingList *list, char *email) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (strcmp(list->entries[i].email, email) == 0) {
            // Shift remaining entries left
            int j;
            for (j = i; j < list->count - 1; j++) {
                list->entries[j] = list->entries[j + 1];
            }
            list->count--;
            return;
        }
    }
    printf("Entry not found\n");
}

void printList(struct MailingList *list) {
    int i;
    for (i = 0; i < list->count; i++) {
        printf("%s <%s>\n", list->entries[i].name, list->entries[i].email);
    }
}

int main() {
    struct MailingList list;
    list.count = 0;

    while (1) {
        printf("Enter command (a: add, r: remove, p: print, q: quit): ");

        char command = getchar();
        while (getchar() != '\n'); // Clear input buffer

        switch (command) {
            case 'a': {
                char email[MAX_EMAIL_LENGTH];
                char name[MAX_NAME_LENGTH];
                printf("Enter email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                addEntry(&list, email, name);
                break;
            }
            case 'r': {
                char email[MAX_EMAIL_LENGTH];
                printf("Enter email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                removeEntry(&list, email);
                break;
            }
            case 'p': {
                printList(&list);
                break;
            }
            case 'q': {
                exit(0);
            }
            default: {
                printf("Invalid command\n");
                break;
            }
        }
    }

    return 0;
}