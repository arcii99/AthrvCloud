//FormAI DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing database records
typedef struct {
    int id;
    char name[20];
    int age;
} Record;

// Function to query database by name
void queryByName(Record *database, int size, char *name) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Record found with id: %d, name: %s, and age: %d\n", 
                    database[i].id, database[i].name, database[i].age);
            found = 1;
        }
    }
    if (!found) {
        printf("No records found for name: %s\n", name);
    }
}

int main() {
    // Create an array of Records to act as our database
    Record database[5] = {{1, "John", 25}, {2, "Mary", 30}, {3, "Peter", 20}, {4, "Emma", 40}, {5, "Joe", 35}};

    // Query the database by name
    queryByName(database, 5, "Peter");

    return 0;
}