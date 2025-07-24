//FormAI DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct Entry {
    char key[32];
    int value;
};

struct Database {
    struct Entry entries[MAX_ENTRIES];
    int length;
};

void db_init(struct Database* db) {
    db->length = 0;
}

int db_get(struct Database* db, const char* key) {
    for (int i = 0; i < db->length; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            return db->entries[i].value;
        }
    }
    printf("Key not found in database: %s\n", key);
    return 0;
}

void db_set(struct Database* db, const char* key, int value) {
    if (db->length == MAX_ENTRIES) {
        printf("Database is full\n");
        return;
    }
    for (int i = 0; i < db->length; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            db->entries[i].value = value;
            printf("Value updated: %s = %d\n", key, value);
            return;
        }
    }
    strcpy(db->entries[db->length].key, key);
    db->entries[db->length].value = value;
    printf("New entry added: %s = %d\n", key, value);
    db->length++;
}

void db_delete(struct Database* db, const char* key) {
    for (int i = 0; i < db->length; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            db->entries[i] = db->entries[db->length - 1];
            db->length--;
            printf("Entry deleted: %s\n", key);
            return;
        }
    }
    printf("Key not found in database: %s\n", key);
}

void db_print(struct Database* db) {
    printf("Database:\n");
    for (int i = 0; i < db->length; i++) {
        printf("%s = %d\n", db->entries[i].key, db->entries[i].value);
    }
}

int main() {
    struct Database db;
    db_init(&db);

    db_set(&db, "John", 65);
    db_set(&db, "Jane", 70);
    db_set(&db, "Bob", 80);

    db_print(&db);

    db_set(&db, "Jane", 75);

    db_print(&db);

    db_delete(&db, "Bob");

    db_print(&db);

    int value = db_get(&db, "Bob");

    return 0;
}