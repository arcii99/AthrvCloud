//FormAI DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Define the structure of a database record
struct Record {
    int id;
    char name[20];
    int age;
    float gpa;
};

// Define the structure of the database
struct Database {
    struct Record records[MAX_RECORDS];
    int num_records;
};

// Function declarations
void initialize_database(struct Database *);
void add_record(struct Database *, struct Record);
void delete_record(struct Database *, int);
void print_database(struct Database);
int search_database(struct Database, int);
void sort_database(struct Database *);

// Main function
int main() {
    // Initialize the database
    struct Database db;
    initialize_database(&db);

    // Add some test records
    struct Record r1 = {1, "Alice", 20, 3.5};
    struct Record r2 = {2, "Bob", 21, 3.7};
    struct Record r3 = {3, "Charlie", 19, 3.9};
    add_record(&db, r1);
    add_record(&db, r2);
    add_record(&db, r3);

    // Print the database
    printf("Initial database:\n");
    print_database(db);

    // Search for a record by ID
    int id_to_search = 2;
    int index = search_database(db, id_to_search);
    if (index != -1) {
        printf("Found record with ID %d:\n", id_to_search);
        printf("Name: %s\n", db.records[index].name);
        printf("Age: %d\n", db.records[index].age);
        printf("GPA: %.2f\n", db.records[index].gpa);
    }
    else {
        printf("Record with ID %d not found.\n", id_to_search);
    }

    // Sort the database by ID
    sort_database(&db);
    printf("Sorted database:\n");
    print_database(db);

    // Delete a record by ID
    int id_to_delete = 1;
    delete_record(&db, id_to_delete);
    printf("After deleting record with ID %d:\n", id_to_delete);
    print_database(db);

    return 0;
}

// Initialize the database
void initialize_database(struct Database *db) {
    db->num_records = 0;
}

// Add a record to the database
void add_record(struct Database *db, struct Record r) {
    db->records[db->num_records] = r;
    db->num_records++;
}

// Delete a record from the database
void delete_record(struct Database *db, int id) {
    int index = search_database(*db, id);
    if (index != -1) {
        for (int i = index; i < db->num_records - 1; i++) {
            db->records[i] = db->records[i+1];
        }
        db->num_records--;
    }
}

// Print the contents of the database
void print_database(struct Database db) {
    for (int i = 0; i < db.num_records; i++) {
        printf("Record %d:\n", i+1);
        printf("ID: %d\n", db.records[i].id);
        printf("Name: %s\n", db.records[i].name);
        printf("Age: %d\n", db.records[i].age);
        printf("GPA: %.2f\n", db.records[i].gpa);
    }
}

// Search for a record by ID
int search_database(struct Database db, int id) {
    for (int i = 0; i < db.num_records; i++) {
        if (db.records[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Sort the database by ID
void sort_database(struct Database *db) {
    for (int i = 0; i < db->num_records - 1; i++) {
        for (int j = i + 1; j < db->num_records; j++) {
            if (db->records[i].id > db->records[j].id) {
                struct Record temp = db->records[i];
                db->records[i] = db->records[j];
                db->records[j] = temp;
            }
        }
    }
}