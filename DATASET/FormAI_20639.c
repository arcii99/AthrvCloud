//FormAI DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10

/* Define the database entry structure */
struct entry {
    int id;
    char name[20];
    int age;
};

/* Define the global database array */
struct entry database[MAX_ENTRIES];

/* Define the function to add a new entry to the database */
int add_entry(int id, char* name, int age) {
    int i;
    for(i = 0; i < MAX_ENTRIES; i++) {
        if(database[i].id == 0) {
            database[i].id = id;
            strcpy(database[i].name, name);
            database[i].age = age;
            return 1;
        }
    }
    return 0;
}

/* Define the function to search for an entry by ID and print it */
int search_entry(int id) {
    int i;
    for(i = 0; i < MAX_ENTRIES; i++) {
        if(database[i].id == id) {
            printf("ID: %d\nName: %s\nAge: %d\n", database[i].id, database[i].name, database[i].age);
            return 1;
        }
    }
    return 0;
}

/* Define the main function to test the database */
int main() {
    /* Add some entries to the database */
    add_entry(1, "John", 25);
    add_entry(2, "Alice", 30);
    add_entry(3, "Bob", 40);
    
    /* Search for an entry by ID */
    int id = 2;
    printf("Searching for entry with ID %d...\n", id);
    int found = search_entry(id);
    if(!found) {
        printf("Entry with ID %d not found.\n", id);
    }
    
    /* Add another entry to the database */
    add_entry(4, "Mary", 20);
    
    /* Print all entries in the database */
    int i;
    printf("Database entries:\n");
    for(i = 0; i < MAX_ENTRIES; i++) {
        if(database[i].id != 0) {
            printf("ID: %d\nName: %s\nAge: %d\n", database[i].id, database[i].name, database[i].age);
        }
    }
    
    return 0;
}