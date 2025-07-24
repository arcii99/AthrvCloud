//FormAI DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records that can be stored
#define MAX_RECORDS 1000

// Define the structure for a single record
typedef struct {
    int id;
    char name[20];
    int age;
    char city[20];
} Record;

// Define a global array to store all the records
Record all_records[MAX_RECORDS];

// Declare some helper functions
void add_record(int id, char* name, int age, char* city);
void print_records();

// Main function to test the program
int main() {
    // First add some sample records
    add_record(1, "John Smith", 25, "New York");
    add_record(2, "Jane Doe", 30, "Chicago");
    add_record(3, "Robert Johnson", 40, "Houston");
    add_record(4, "Emily Lee", 22, "San Francisco");
    add_record(5, "James Brown", 50, "Los Angeles");

    // Print all the records
    printf("All Records:\n");
    print_records();

    // Query for the records with age greater than or equal to 30
    printf("\nRecords with Age >= 30:\n");
    for(int i=0; i<MAX_RECORDS; i++) {
        if(all_records[i].id != 0 && all_records[i].age >= 30) {
            printf("%d, %s, %d, %s\n", all_records[i].id, all_records[i].name, all_records[i].age, all_records[i].city);
        }
    }

    // Query for the records with city equal to "New York"
    printf("\nRecords from New York:\n");
    for(int i=0; i<MAX_RECORDS; i++) {
        if(all_records[i].id != 0 && strcmp(all_records[i].city, "New York") == 0) {
            printf("%d, %s, %d, %s\n", all_records[i].id, all_records[i].name, all_records[i].age, all_records[i].city);
        }
    }

    // Query for the record with id equal to 4
    printf("\nRecord with ID = 4:\n");
    for(int i=0; i<MAX_RECORDS; i++) {
        if(all_records[i].id == 4) {
            printf("%d, %s, %d, %s\n", all_records[i].id, all_records[i].name, all_records[i].age, all_records[i].city);
            break;
        }
    }

    return 0;
}

// Helper function to add a record to the global array
void add_record(int id, char* name, int age, char* city) {
    // Initialize a new record structure
    Record new_record;
    new_record.id = id;
    strcpy(new_record.name, name);
    new_record.age = age;
    strcpy(new_record.city, city);

    // Add the new record to the global array
    for(int i=0; i<MAX_RECORDS; i++) {
        if(all_records[i].id == 0) {
            all_records[i] = new_record;
            break;
        }
    }
}

// Helper function to print all the records in the global array
void print_records() {
    for(int i=0; i<MAX_RECORDS; i++) {
        if(all_records[i].id != 0) {
            printf("%d, %s, %d, %s\n", all_records[i].id, all_records[i].name, all_records[i].age, all_records[i].city);
        }
    }
}