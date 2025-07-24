//FormAI DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DB_SIZE 1000
#define MAX_NAME_SIZE 50
#define MAX_AGE 120
#define MAX_ADDRESS_SIZE 100

typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
    int age;
    char address[MAX_ADDRESS_SIZE];
} Person;

typedef struct {
    int size;
    Person data[MAX_DB_SIZE];
} Database;

void initialize_database(Database *db) {
    db->size = 0;
}

void add_person(Database *db, Person person) {
    if (db->size >= MAX_DB_SIZE) {
        printf("ERROR: database is full!\n");
        return;
    }
    db->data[db->size++] = person;
}

void print_person(Person *person) {
    printf("ID: %d\n", person->id);
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Address: %s\n", person->address);
    printf("\n");
}

void print_database(Database *db) {
    for (int i = 0; i < db->size; i++) {
        print_person(&db->data[i]);
    }
}

int main() {
    Database my_db;
    initialize_database(&my_db);
    
    Person p1 = {1, "John Smith", 25, "1234 Main St"};
    Person p2 = {2, "Jane Doe", 30, "5678 Elm St"};
    
    add_person(&my_db, p1);
    add_person(&my_db, p2);
    
    print_database(&my_db);
    
    return 0;
}