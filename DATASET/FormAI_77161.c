//FormAI DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATABASE_SIZE 50

typedef struct {
    int id;
    char name[50];
    int age;
    char address[100];
} Person;

typedef struct {
    Person entries[MAX_DATABASE_SIZE];
    int size;
} Database;

void printPerson(Person person) {
    printf("ID: %d\n", person.id);
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Address: %s\n", person.address);
}

void printDatabase(Database database) {
    printf("Database size: %d\n", database.size);
    for (int i = 0; i < database.size; i++) {
        printf("Entry %d:\n", i+1);
        printPerson(database.entries[i]);
    }
}

void addEntry(Database* database, Person person) {
    if (database->size < MAX_DATABASE_SIZE) {
        database->entries[database->size] = person;
        database->size++;
    } else {
        printf("Database is full.\n");
    }
}

Person createPerson(int id, char* name, int age, char* address) {
    Person person;
    person.id = id;
    strcpy(person.name, name);
    person.age = age;
    strcpy(person.address, address);
    return person;
}

void initializeDatabase(Database* database) {
    database->size = 0;
}

int main() {
    Database database;
    initializeDatabase(&database);

    addEntry(&database, createPerson(1, "John", 25, "123 Main St"));
    addEntry(&database, createPerson(2, "Jane", 35, "456 Elm St"));
    addEntry(&database, createPerson(3, "Bob", 45, "789 Maple St"));

    printDatabase(database);

    return 0;
}