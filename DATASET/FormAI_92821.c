//FormAI DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#define MAX_ENTRIES 1000

struct Entry {
    int id;
    char name[50];
    char email[50];
};

struct Database {
    struct Entry entries[MAX_ENTRIES];
    int count;
};

void initialize_database(struct Database* db) {
    db->count = 0;
}

void add_entry(struct Database* db, int id, const char* name, const char* email) {
    if (db->count == MAX_ENTRIES) {
        printf("Database is full.\n");
        return;
    }

    struct Entry* entry = &db->entries[db->count];
    entry->id = id;
    snprintf(entry->name, sizeof(entry->name), "%s", name);
    snprintf(entry->email, sizeof(entry->email), "%s", email);
    db->count++;
}

void print_entries(const struct Database* db) {
    for (int i = 0; i < db->count; i++) {
        const struct Entry* entry = &db->entries[i];
        printf("ID: %d, Name: %s, Email: %s\n", entry->id, entry->name, entry->email);
    }
}

int main() {
    struct Database db;
    initialize_database(&db);

    add_entry(&db, 1, "Linus Torvalds", "linus.torvalds@gmail.com");
    add_entry(&db, 2, "Richard Stallman", "rms@gnu.org");
    add_entry(&db, 3, "Guido van Rossum", "guido@python.org");

    print_entries(&db);
    return 0;
}