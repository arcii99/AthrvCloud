//FormAI DATASET v1.0 Category: Database querying ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLS 10

typedef struct {
    char name[50];
    int age;
    double height;
} Person;

typedef struct {
    Person rows[MAX_ROWS];
    int size;
} Database;

void Database_insert(Database* db, Person p) {
    if (db->size < MAX_ROWS) {
        db->rows[db->size++] = p;
    } else {
        printf("Database is full\n");
    }
}

void Database_display(Database* db) {
    for (int i = 0; i < db->size; i++) {
        printf("Name: %s, Age: %d, Height: %.2f\n", db->rows[i].name, db->rows[i].age, db->rows[i].height);
    }
}

int Database_find_index(Database* db, char* name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->rows[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void Database_delete(Database* db, char* name) {
    int index = Database_find_index(db, name);
    if (index != -1) {
        for (int i = index; i < db->size - 1; i++) {
            db->rows[i] = db->rows[i + 1];
        }
        db->size--;
    }
}

void Database_update_age(Database* db, char* name, int age) {
    int index = Database_find_index(db, name);
    if (index != -1) {
        db->rows[index].age = age;
    }
}

int main() {
    Database db = { .size = 0 };

    Person p1 = { .name = "John", .age = 25, .height = 1.75 };
    Person p2 = { .name = "Mary", .age = 30, .height = 1.65 };
    Person p3 = { .name = "Tom", .age = 28, .height = 1.80 };
    Person p4 = { .name = "Lisa", .age = 35, .height = 1.70 };

    Database_insert(&db, p1);
    Database_insert(&db, p2);
    Database_insert(&db, p3);
    Database_insert(&db, p4);

    printf("Database:\n");
    Database_display(&db);

    printf("\nDeleting Mary from database\n");
    Database_delete(&db, "Mary");
    Database_display(&db);

    printf("\nUpdating age of John to 30\n");
    Database_update_age(&db, "John", 30);
    Database_display(&db);

    return 0;
}