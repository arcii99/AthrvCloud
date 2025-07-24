//FormAI DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROWS 1000
#define MAX_DATA 512

typedef struct {
    int id;
    char name[MAX_DATA];
    int age;
} Person;

typedef struct {
    Person rows[MAX_ROWS];
    int last_index;
} Database;

void print_person(Person person) {
    printf("ID: %d\n", person.id);
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
}

void print_database(Database database) {
    for (int i = 0; i <= database.last_index; i++) {
        print_person(database.rows[i]);
        printf("\n");
    }
}

void add_person(Database *database, Person person) {
    database->last_index++;
    person.id = database->last_index;
    database->rows[database->last_index] = person;
}

bool delete_person(Database *database, int id) {
    for (int i = 0; i <= database->last_index; i++) {
        if (database->rows[i].id == id) {
            int length = database->last_index - i;
            memmove(&database->rows[i], &database->rows[i+1], length * sizeof(Person));
            database->last_index--;
            return true;
        }
    }
    return false;
}

void find_person(Database database, char *name) {
    for (int i = 0; i <= database.last_index; i++) {
        if (strcmp(database.rows[i].name, name) == 0) {
            print_person(database.rows[i]);
            return;
        }
    }
    printf("The person named %s was not found.\n", name);
}

int main() {
    Database database;
    database.last_index = -1;

    Person person1 = {0, "John Doe", 30};
    Person person2 = {0, "Jane Smith", 25};
    Person person3 = {0, "Bob Johnson", 40};

    add_person(&database, person1);
    add_person(&database, person2);
    add_person(&database, person3);

    printf("Initial database:\n");
    print_database(database);
    printf("\n");

    delete_person(&database, 2);

    printf("Database after deleting person with ID 2:\n");
    print_database(database);
    printf("\n");

    find_person(database, "John Doe");
    printf("\n");

    find_person(database, "Alice Brown");
    printf("\n");

    return 0;
}