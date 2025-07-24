//FormAI DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 20
#define MAX_VALUES 20

typedef struct indexed_database {
    int num_of_keys;
    int num_of_values;
    char keys[MAX_KEYS][50];
    char values[MAX_VALUES][50];
    int index[MAX_KEYS][MAX_VALUES];
} IndexedDatabase;

void insert(IndexedDatabase* database, char* key, char* value) {
    int i;
    for (i = 0; i < database->num_of_keys; i++) {
        if (strcmp(database->keys[i], key) == 0) {
            // Key already exists, so just add the value to the corresponding index
            strcpy(database->values[database->num_of_values], value);
            database->index[i][database->num_of_values] = database->num_of_values;
            database->num_of_values++;
            return;
        }
    }

    // Key doesn't exist, so insert it along with the value
    strcpy(database->keys[database->num_of_keys], key);
    strcpy(database->values[database->num_of_values], value);
    database->index[database->num_of_keys][database->num_of_values] = database->num_of_values;
    database->num_of_keys++;
    database->num_of_values++;
}

void print(IndexedDatabase* database, char* key) {
    int i, j;
    for (i = 0; i < database->num_of_keys; i++) {
        if (strcmp(database->keys[i], key) == 0) {
            printf("Values of key \"%s\":\n", key);
            for (j = 0; j < database->num_of_values; j++) {
                int index = database->index[i][j];
                if (index != -1) {
                    printf("%s\n", database->values[index]);
                }
            }
            return;
        }
    }
    printf("Key \"%s\" not found.\n", key);
}

int main() {
    IndexedDatabase db;
    db.num_of_keys = 0;
    db.num_of_values = 0;
    int i, j;
    for (i = 0; i < MAX_KEYS; i++) {
        strcpy(db.keys[i], "");
        for (j = 0; j < MAX_VALUES; j++) {
            strcpy(db.values[j], "");
            db.index[i][j] = -1;
        }
    }

    insert(&db, "fruit", "apple");
    insert(&db, "fruit", "banana");
    insert(&db, "vegetable", "carrot");
    insert(&db, "fruit", "orange");
    insert(&db, "meat", "beef");
    insert(&db, "meat", "chicken");
    insert(&db, "vegetable", "broccoli");
    insert(&db, "meat", "pork");

    print(&db, "fruit");
    printf("\n");
    print(&db, "vegetable");
    printf("\n");
    print(&db, "meat");

    return 0;
}