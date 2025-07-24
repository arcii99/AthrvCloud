//FormAI DATASET v1.0 Category: Database Indexing System ; Style: high level of detail
/* A unique C Database Indexing System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    char address[50];
    int age;
} record;

// define the maximum number of records in the database
#define MAX_RECORDS 1000

// define the indexing structure
typedef struct {
    int index;
    int id;
} index_record;

// define the maximum number of index records
#define MAX_INDEXES 1000

// initialize the database and index arrays
record database[MAX_RECORDS];
index_record index_array[MAX_INDEXES];

// function to add a new record to the database
void add_record(int id, char* name, char* address, int age) {
    // find the next available index in the database array
    int next_index = 0;
    while (database[next_index].id != 0) {
        next_index++;
        if (next_index == MAX_RECORDS) {
            printf("Error: Database is full.\n");
            return;
        }
    }

    // add the new record to the database array
    database[next_index].id = id;
    strcpy(database[next_index].name, name);
    strcpy(database[next_index].address, address);
    database[next_index].age = age;

    // add a new index record to the index array
    int next_index_record = 0;
    while (index_array[next_index_record].id != 0) {
        next_index_record++;
        if (next_index_record == MAX_INDEXES) {
            printf("Error: Index array is full.\n");
            return;
        }
    }
    index_array[next_index_record].id = id;
    index_array[next_index_record].index = next_index;

    printf("Record added successfully.\n");
}

// function to remove a record from the database
void remove_record(int id) {
    // find the index of the record in the index array
    int index_record = 0;
    while (index_array[index_record].id != id && index_array[index_record].id != 0) {
        index_record++;
        if (index_record == MAX_INDEXES) {
            printf("Error: Record not found.\n");
            return;
        }
    }
    if (index_array[index_record].id == 0) {
        printf("Error: Record not found.\n");
        return;
    }

    // remove the record from the database array
    int index = index_array[index_record].index;
    database[index].id = 0;
    index_array[index_record].id = 0;

    // shift the remaining records in the index array and update their indexes
    for (int i=index_record; i<MAX_INDEXES-1; i++) {
        index_array[i].id = index_array[i+1].id;
        if (index_array[i].id != 0) {
            index_array[i].index = index_array[i+1].index - 1;
        } else {
            index_array[i].index = 0;
        }
    }

    printf("Record removed successfully.\n");
}

// function to search for a record by ID
void search_record(int id) {
    // find the index of the record in the index array
    int index_record = 0;
    while (index_array[index_record].id != id && index_array[index_record].id != 0) {
        index_record++;
        if (index_record == MAX_INDEXES) {
            printf("Record not found.\n");
            return;
        }
    }
    if (index_array[index_record].id == 0) {
        printf("Record not found.\n");
        return;
    }

    // print out the record
    int index = index_array[index_record].index;
    printf("ID: %d\n", database[index].id);
    printf("Name: %s\n", database[index].name);
    printf("Address: %s\n", database[index].address);
    printf("Age: %d\n", database[index].age);
}

int main() {
    // initialize the database and index arrays
    for (int i=0; i<MAX_RECORDS; i++) {
        database[i].id = 0;
    }
    for (int i=0; i<MAX_INDEXES; i++) {
        index_array[i].id = 0;
    }

    // add some records to the database
    add_record(1, "Alice Smith", "123 Main St.", 25);
    add_record(2, "Bob Johnson", "456 Maple Ave.", 35);
    add_record(3, "Charlie Brown", "789 Elm St.", 45);

    // search for a record by ID
    search_record(2);

    // remove a record from the database
    remove_record(2);

    // try to search for the deleted record
    search_record(2);

    return 0;
}