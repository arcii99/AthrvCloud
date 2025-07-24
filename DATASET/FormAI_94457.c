//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[100];
    int age;
} entry;

typedef struct {
    int num_entries;
    entry entries[MAX_ENTRIES];
} database;

void add_entry(database *db, char *name, int age);
void index_database(database *db, char index_key);

int main() {
    database db = {0};
    add_entry(&db, "John", 25);
    add_entry(&db, "Mary", 30);
    add_entry(&db, "Bob", 24);
    
    // index the database by first letter of name
    index_database(&db, 'n');
    
    return 0;
}

void add_entry(database *db, char *name, int age) {
    entry new_entry;
    strcpy(new_entry.name, name);
    new_entry.age = age;
    db->entries[db->num_entries] = new_entry;
    db->num_entries++;
}

void index_database(database *db, char index_key) {
    int i;
    printf("Entries with key '%c':\n", index_key);
    for (i = 0; i < db->num_entries; i++) {
        if (db->entries[i].name[0] == index_key) {
            printf("%s, %d\n", db->entries[i].name, db->entries[i].age);
        }
    }
}