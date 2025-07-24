//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10000

// Define the structure for a record in the database
typedef struct {
    int id;
    char name[20];
    int age;
    float salary;
} Record;

// Define the structure for the database index
typedef struct {
    char name[20];
    int offset;
} Index;

// Global variables for the database
Record database[MAX_RECORDS];
Index index_table[MAX_RECORDS];
int num_records = 0;
int num_indexes = 0;

// Function prototypes
void add_record(int id, char* name, int age, float salary);
void build_index(char* index_name);
int find_index(char* search_name);
void print_records();

int main() {
    // Add some sample records to the database
    add_record(1, "John", 25, 50000.0);
    add_record(2, "Mary", 30, 60000.0);
    add_record(3, "Bob", 35, 70000.0);
    add_record(4, "Alice", 40, 80000.0);
    
    // Build an index on the name field
    build_index("name");
    
    // Print all the records
    print_records();
    
    return 0;
}

// Add a record to the database
void add_record(int id, char* name, int age, float salary) {
    // Make sure there is room in the database
    if (num_records >= MAX_RECORDS) {
        printf("Error: database full\n");
        exit(1);
    }
    
    // Add the record to the database
    database[num_records].id = id;
    strcpy(database[num_records].name, name);
    database[num_records].age = age;
    database[num_records].salary = salary;
    
    // Increment the number of records in the database
    num_records++;
}

// Build an index on the specified field
void build_index(char* index_name) {
    // Make sure there is room in the index table
    if (num_indexes >= MAX_RECORDS) {
        printf("Error: index table full\n");
        exit(1);
    }
    
    // Add an index entry for each record in the database
    for (int i = 0; i < num_records; i++) {
        int offset = i * sizeof(Record);
        strcpy(index_table[i].name, database[i].name);
        index_table[i].offset = offset;
        num_indexes++;
    }
}

// Find the index of the specified name in the index table
int find_index(char* search_name) {
    for (int i = 0; i < num_indexes; i++) {
        if (strcmp(index_table[i].name, search_name) == 0) {
            return i;
        }
    }
    return -1;
}

// Print all the records in the database
void print_records() {
    for (int i = 0; i < num_records; i++) {
        printf("Record %d\n", i+1);
        printf("ID: %d\n", database[i].id);
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Salary: %.2f\n", database[i].salary);
        printf("\n");
    }
}