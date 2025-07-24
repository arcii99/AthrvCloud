//FormAI DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ENTRIES 100 // maximum number of entries in the database
#define MAX_NAME_LENGTH 50 // maximum length of a name in the database
#define MAX_PHONE_LENGTH 20 // maximum length of a phone number in the database

// Structs
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Entry;

typedef struct {
    Entry* entries[MAX_ENTRIES];
    int count;
    int index[MAX_ENTRIES];
} Database;

// Prototypes
void initialize_database(Database* db);
void add_entry(Database* db, Entry* entry);
void print_database(Database* db);
void index_database(Database* db);
int compare_entries(const void* a, const void* b);
int binary_search(Database* db, char* name);
void search_database(Database* db, char* name);

// Main function
int main() {
    char name[MAX_NAME_LENGTH];
    Entry entry;
    Database db;
    initialize_database(&db);

    // Add entries to the database
    strcpy(entry.name, "John Smith");
    strcpy(entry.phone, "555-1234");
    add_entry(&db, &entry);

    strcpy(entry.name, "Jane Doe");
    strcpy(entry.phone, "555-5678");
    add_entry(&db, &entry);

    strcpy(entry.name, "Bob Johnson");
    strcpy(entry.phone, "555-9012");
    add_entry(&db, &entry);

    // Index the database
    index_database(&db);

    // Print the database
    printf("Database:\n");
    print_database(&db);

    // Search for an entry
    printf("Enter name to search for: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline character from input
    search_database(&db, name);

    return 0;
}

// Initializes a new database with no entries
void initialize_database(Database* db) {
    db->count = 0;
}

// Adds a new entry to the database
void add_entry(Database* db, Entry* entry) {
    Entry* new_entry = malloc(sizeof(Entry));
    strcpy(new_entry->name, entry->name);
    strcpy(new_entry->phone, entry->phone);
    db->entries[db->count] = new_entry;
    db->count++;
}

// Prints all entries in the database
void print_database(Database* db) {
    int i;
    for (i = 0; i < db->count; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, db->entries[i]->name, db->entries[i]->phone);
    }
}

// Sorts the entries in the database by name and creates an index
void index_database(Database* db) {
    int i;
    for (i = 0; i < db->count; i++) {
        db->index[i] = i;
    }
    qsort(db->index, db->count, sizeof(int), compare_entries);
}

// Compares two entries by name for sorting purposes
int compare_entries(const void* a, const void* b) {
    Entry* entry_a = *((Entry**)a);
    Entry* entry_b = *((Entry**)b);
    return strcmp(entry_a->name, entry_b->name);
}

// Searches for an entry in the database using binary search
int binary_search(Database* db, char* name) {
    int low = 0, high = db->count - 1, mid, cmp;
    while (low <= high) {
        mid = (low + high) / 2;
        cmp = strcmp(db->entries[db->index[mid]]->name, name);
        if (cmp == 0) {
            return db->index[mid];
        }
        else if (cmp < 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

// Searches for an entry in the database by name and prints its phone number
void search_database(Database* db, char* name) {
    int index = binary_search(db, name);
    if (index == -1) {
        printf("Entry not found.\n");
    }
    else {
        printf("Phone: %s\n", db->entries[index]->phone);
    }
}