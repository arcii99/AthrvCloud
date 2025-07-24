//FormAI DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a data-entry in the database
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

// A structure to represent the database
typedef struct {
    int size;
    Person *data;
} Database;

// A function to create a new person entry and return it
Person create_person(int id, char* name, int age) {
    Person new_person;
    new_person.id = id;
    strcpy(new_person.name, name);
    new_person.age = age;
    return new_person;
}

// A function to create a new database and return it
Database create_database(int size) {
    Database new_database;
    new_database.size = size;
    new_database.data = (Person *) malloc(size*sizeof(Person));
    return new_database;
}

// A function to insert a person into the database
void insert_into_database(Database *db, Person person) {
    if (db->data == NULL) {
        printf("Database is uninitialized!\n");
        return;
    }
    int i;
    for (i = 0; i < db->size; i++) {
        if (db->data[i].id == 0) {
            db->data[i] = person;
            return;
        }
    }
    printf("Database is full!\n");
}

// A function to delete a person from the database
void delete_from_database(Database *db, int id) {
    if (db->data == NULL) {
        printf("Database is uninitialized!\n");
        return;
    }
    int i;
    for (i = 0; i < db->size; i++) {
        if (db->data[i].id == id) {
            db->data[i].id = 0;
            memset(db->data[i].name, 0, sizeof(db->data[i].name));
            db->data[i].age = 0;
            return;
        }
    }
    printf("Person not found in database!\n");
}

// A function to find a person with a given id in the database
Person* find_in_database(Database *db, int id) {
    if (db->data == NULL) {
        printf("Database is uninitialized!\n");
        return NULL;
    }
    int i;
    for (i = 0; i < db->size; i++) {
        if (db->data[i].id == id) {
            return &(db->data[i]);
        }
    }
    printf("Person not found in database!\n");
    return NULL;
}

// A function to print the entire database
void print_database(Database *db) {
    if (db->data == NULL) {
        printf("Database is uninitialized!\n");
        return;
    }
    int i;
    for (i = 0; i < db->size; i++) {
        if (db->data[i].id != 0) {
            printf("ID: %d\n", db->data[i].id);
            printf("Name: %s\n", db->data[i].name);
            printf("Age: %d\n\n", db->data[i].age);
        }
    }
}

// The main function of the program
int main() {

    // Create a new database with a size of 5
    Database db = create_database(5);

    // Insert some new persons into the database
    insert_into_database(&db, create_person(1, "John", 25));
    insert_into_database(&db, create_person(2, "Jane", 30));
    insert_into_database(&db, create_person(3, "Bob", 20));

    // Print the entire database
    printf("Database after initial insertions:\n");
    print_database(&db);

    // Find a person with id 2 and change their name and age
    Person *p = find_in_database(&db, 2);
    if (p != NULL) {
        strcpy(p->name, "Janet");
        p->age = 35;
    }

    // Delete the person with id 3 and insert a new person with id 4
    delete_from_database(&db, 3);
    insert_into_database(&db, create_person(4, "Sarah", 28));

    // Print the entire database
    printf("Database after modifications:\n");
    print_database(&db);

    // Free the memory used by the database
    free(db.data);

    return 0;
}