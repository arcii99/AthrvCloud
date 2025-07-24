//FormAI DATASET v1.0 Category: Database querying ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for database entry
typedef struct {
    int id;
    char name[50];
    char address[100];
    int age;
} Entry;

// function to print out an entry
void print_entry(Entry e) {
    printf("ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Address: %s\n", e.address);
    printf("Age: %d\n\n", e.age);
}

// recursive function to query the database
void query_database(Entry *db, int start, int end, char *field, char *value) {
    // base case: no more entries to check
    if (start > end) {
        printf("No entries found.\n");
        return;
    }
    
    // check if current entry matches the query
    Entry e = db[start];
    if (strcmp(field, "id") == 0 && e.id == atoi(value)) {
        print_entry(e);
    } else if (strcmp(field, "name") == 0 && strcmp(e.name, value) == 0) {
        print_entry(e);
    } else if (strcmp(field, "address") == 0 && strcmp(e.address, value) == 0) {
        print_entry(e);
    } else if (strcmp(field, "age") == 0 && e.age == atoi(value)) {
        print_entry(e);
    }
    
    // recursive case: check the next entry
    query_database(db, start+1, end, field, value);
}

int main() {
    // create test database entries
    Entry db[5] = {
        {.id=1, .name="John Smith", .address="123 Main St", .age=25},
        {.id=2, .name="Jane Doe", .address="456 Elm St", .age=30},
        {.id=3, .name="Bob Johnson", .address="789 Oak St", .age=40},
        {.id=4, .name="Lisa White", .address="321 Pine St", .age=45},
        {.id=5, .name="Joe Brown", .address="654 Maple St", .age=50}
    };
    
    // query the database for entries with ID = 3
    printf("Querying for ID = 3:\n");
    query_database(db, 0, 4, "id", "3");
    
    // query the database for entries with name = "Lisa White"
    printf("\nQuerying for name = \"Lisa White\":\n");
    query_database(db, 0, 4, "name", "Lisa White");
    
    // query the database for entries with age = 30
    printf("\nQuerying for age = 30:\n");
    query_database(db, 0, 4, "age", "30");
    
    return 0;
}