//FormAI DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Define a structure to represent a person
typedef struct person {
    char name[30];
    int age;
    double height;
} Person;

// Define a structure to represent the database
typedef struct database {
    Person people[MAX_SIZE];
    int size;
} Database;

// Function to add a person to the database
void add_person(Database* db, Person p) {
    if (db->size >= MAX_SIZE) {
        printf("Database is full!\n");
        return;
    }
    db->people[db->size++] = p;
    printf("Person added successfully!\n");
}

// Function to print all people in the database
void print_database(Database* db) {
    printf("Name\tAge\tHeight\n");
    for (int i = 0; i < db->size; i++) {
        printf("%s\t%d\t%.2lf\n", db->people[i].name, db->people[i].age, db->people[i].height);
    }
}

// Function to calculate the average age and height of people in the database
void calculate_average(Database* db, double* avg_age, double* avg_height) {
    double sum_age = 0, sum_height = 0;
    for (int i = 0; i < db->size; i++) {
        sum_age += db->people[i].age;
        sum_height += db->people[i].height;
    }
    *avg_age = sum_age / db->size;
    *avg_height = sum_height / db->size;
}

int main() {
    Database db;
    db.size = 0;
    double avg_age, avg_height;

    // Add some people to the database
    add_person(&db, (Person){"John", 30, 1.8});
    add_person(&db, (Person){"Mary", 25, 1.6});
    add_person(&db, (Person){"Tom", 40, 1.75});

    // Print the database
    print_database(&db);

    // Calculate the average age and height of people in the database
    calculate_average(&db, &avg_age, &avg_height);
    printf("Average age: %.2lf\n", avg_age);
    printf("Average height: %.2lf\n", avg_height);

    return 0;
}