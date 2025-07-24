//FormAI DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DATABASE_ENTRIES 1000
#define MAX_STRING_LENGTH 100

typedef struct {
    int id;
    char name[MAX_STRING_LENGTH];
    int age;
    char address[MAX_STRING_LENGTH];
} Entry;

Entry database[MAX_DATABASE_ENTRIES];

bool is_database_full() {
    for (int i = 0; i < MAX_DATABASE_ENTRIES; i++) {
        if (database[i].id == 0) {
            return false;
        }
    }
    return true;
}

bool add_entry(Entry entry) {
    if (is_database_full()) {
        return false;
    }
    for (int i = 0; i < MAX_DATABASE_ENTRIES; i++) {
        if (database[i].id == entry.id) {
            return false;
        }
        if (database[i].id == 0) {
            database[i] = entry;
            return true;
        }
    }
    return false;
}

bool delete_entry(int id) {
    for (int i = 0; i < MAX_DATABASE_ENTRIES; i++) {
        if (database[i].id == id) {
            memset(&database[i], 0, sizeof(Entry));
            return true;
        }
    }
    return false;
}

void print_entry(Entry entry) {
    printf("ID: %d\n", entry.id);
    printf("Name: %s\n", entry.name);
    printf("Age: %d\n", entry.age);
    printf("Address: %s\n", entry.address);
}

void print_database() {
    for (int i = 0; i < MAX_DATABASE_ENTRIES; i++) {
        if (database[i].id != 0) {
            printf("Entry %d:\n", i+1);
            print_entry(database[i]);
            printf("\n");
        }
    }
}

int main() {
    memset(database, 0, sizeof(database));

    Entry entry1 = {1, "John Doe", 25, "123 Main St."};
    Entry entry2 = {2, "Jane Smith", 30, "456 Maple Ave."};

    add_entry(entry1);
    add_entry(entry2);

    printf("Initial database:\n");
    print_database();

    delete_entry(1);

    printf("Database after deleting entry 1:\n");
    print_database();

    Entry entry3 = {3, "Bob Johnson", 45, "789 Oak St."};

    if (add_entry(entry3)) {
        printf("Successfully added entry 3 to the database.\n");
    } else {
        printf("Could not add entry 3 to the database.\n");
    }

    printf("Final database:\n");
    print_database();

    return 0;
}