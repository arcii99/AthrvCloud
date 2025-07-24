//FormAI DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

int main() {
    // Create a new database with 10 records
    Person *db = (Person*) malloc(10 * sizeof(Person));
    
    // Initialize the database
    for (int i = 0; i < 10; i++) {
        db[i].id = i+1;
        sprintf(db[i].name, "Person %d", i+1);
        db[i].age = (i+1) * 10;
    }
    
    // Print the database
    printf("Database contents:\n");
    for (int i = 0; i < 10; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db[i].id, db[i].name, db[i].age);
    }
    
    // Free the database memory
    free(db);
    
    return 0;
}