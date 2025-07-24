//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

//Declare the database structure
struct database {
    int id;
    char name[20];
    char city[20];
    float temperature;
};

// Define the function to initialize the database
void init_database(struct database *db) {
    db->id = 0;
    strcpy(db->name, "");
    strcpy(db->city, "");
    db->temperature = 0.0;
}

// Define the function to insert a record into the database
void insert_record(struct database *db, int id, char *name, char *city, float temperature) {
    db->id = id;
    strcpy(db->name, name);
    strcpy(db->city, city);
    db->temperature = temperature;
}

// Define the function to print a record from the database
void print_record(struct database *db) {
    printf("ID: %d\n", db->id);
    printf("Name: %s\n", db->name);
    printf("City: %s\n", db->city);
    printf("Temperature: %.2f\n\n", db->temperature);
}

int main() {
    // Declare and initialize the database
    struct database db;
    init_database(&db);

    // Insert records into the database
    insert_record(&db, 1, "John", "New York", 25.5);
    insert_record(&db, 2, "Jane", "Los Angeles", 28.3);
    insert_record(&db, 3, "Bob", "Chicago", 23.8);

    // Print the records in the database
    printf("Database Records:\n");
    print_record(&db);

    // Update the temperature of a record
    db.temperature = 30.1;

    // Print the records in the database again
    printf("Updated Database Records:\n");
    print_record(&db);

    // Exit the program
    return 0;
}