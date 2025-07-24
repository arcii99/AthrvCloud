//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_ENTRIES 1000

struct Entry {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct MailingList {
    struct Entry entries[MAX_ENTRIES];
    int size;
};

void add_entry(struct MailingList *list, char *name, char *email) {
    if (list->size < MAX_ENTRIES) {
        struct Entry *entry = &(list->entries[list->size]);
        strncpy(entry->name, name, MAX_NAME_LENGTH);
        strncpy(entry->email, email, MAX_EMAIL_LENGTH);
        list->size++;
        printf("Added entry: %s <%s>\n", name, email);
    } else {
        printf("Error: Mailing list is full\n");
    }
}

void remove_entry(struct MailingList *list, int index) {
    if (index < list->size && index >= 0) {
        int last_index = list->size - 1;
        struct Entry *entry = &(list->entries[index]);
        struct Entry *last_entry = &(list->entries[last_index]);
        memcpy(entry, last_entry, sizeof(struct Entry));
        list->size--;
        printf("Removed entry: %s <%s>\n", entry->name, entry->email);
    } else {
        printf("Error: Invalid entry index\n");
    }
}

void print_entries(struct MailingList *list) {
    printf("Mailing list entries:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d) %s <%s>\n", i, list->entries[i].name, list->entries[i].email);
    }
}

int main() {
    struct MailingList list = {0};
    
    add_entry(&list, "Alice", "alice@example.com");
    add_entry(&list, "Bob", "bob@example.com");
    add_entry(&list, "Charlie", "charlie@example.com");
    
    print_entries(&list);
    
    remove_entry(&list, 1);
    
    print_entries(&list);
    
    return 0;
}