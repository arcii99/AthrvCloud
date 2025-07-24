//FormAI DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Person {
    char name[50];
    int age;
    char gender[10];
};

struct Database {
    struct Person people[MAX_RECORDS];
    int count;
};

void initialize(struct Database *db) {
    db->count = 0;
}

void add_person(struct Database *db, const char *name, int age, const char *gender) {
    if (db->count == MAX_RECORDS) {
        printf("Database is full");
        return;
    }

    struct Person person;
    strcpy(person.name, name);
    person.age = age;
    strcpy(person.gender, gender);
    db->people[db->count++] = person;
}

void print_database(struct Database *db) {
    printf("Database\n");
    printf("--------\n");
    for (int i = 0; i < db->count; i++) {
        struct Person person = db->people[i];
        printf("Name: %s\n Age: %d\n Gender: %s\n\n", person.name, person.age, person.gender);
    }
}

int main() {
    struct Database db;
    initialize(&db);

    add_person(&db, "John Doe", 32, "Male");
    add_person(&db, "Jane Smith", 28, "Female");

    print_database(&db);

    return 0;
}