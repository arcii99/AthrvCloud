//FormAI DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR_LEN 50
#define MAX_NUM_RECORDS 100

/* Struct definition for our records */
typedef struct Record {
    char name[MAX_STR_LEN];
    int age;
    float salary;
} Record;

/* Struct for our database with indexing mechanism */
typedef struct Database {
    Record records[MAX_NUM_RECORDS];
    int index[MAX_NUM_RECORDS];
    int num_records;
} Database;

/* Function declarations */
void add_record(Database* db, char name[], int age, float salary);
void print_record(Record record);
void print_database(Database db);
void index_database(Database* db);

/* Main function */
int main() {
    Database my_database;
    my_database.num_records = 0;

    // Add some sample records to our database
    add_record(&my_database, "Alice", 24, 75000);
    add_record(&my_database, "Bob", 32, 85000);
    add_record(&my_database, "Charlie", 28, 65000);

    // Index the database for faster search
    index_database(&my_database);

    // Print the contents of our database
    print_database(my_database);

    return 0;
}

/* Function to add a record to our database */
void add_record(Database* db, char name[], int age, float salary) {
    Record new_record;

    // Copy the values into our new record
    strcpy(new_record.name, name);
    new_record.age = age;
    new_record.salary = salary;

    // Add the new record to our database array
    db->records[db->num_records] = new_record;
    db->num_records++;
}

/* Function to print a single record */
void print_record(Record record) {
    printf("%s, %d years old, earns $%.2f per year\n", record.name, record.age, record.salary);
}

/* Function to print our entire database */
void print_database(Database db) {
    printf("Record\tName\tAge\tSalary\n");

    for (int i = 0; i < db.num_records; i++) {
        printf("%d\t", i+1);
        print_record(db.records[db.index[i]]);
    }
}

/* Function to index our database */
void index_database(Database* db) {
    // Fill the index array with 0 to N-1 for the initial values
    for (int i = 0; i < db->num_records; i++) {
        db->index[i] = i;
    }

    // Bubble sort our index array by name
    bool swapped;
    int temp_index;
    do {
        swapped = false;
        for (int i = 0; i < db->num_records - 1; i++) {
            if (strcmp(db->records[db->index[i]].name, db->records[db->index[i+1]].name) > 0) {
                temp_index = db->index[i];
                db->index[i] = db->index[i+1];
                db->index[i+1] = temp_index;
                swapped = true;
            }
        }
    } while (swapped);
}