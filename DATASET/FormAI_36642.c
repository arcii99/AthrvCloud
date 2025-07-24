//FormAI DATASET v1.0 Category: Database querying ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 10

struct Row {
    int id;
    char name[20];
    int age;
};

typedef struct Row Row;

int main() {
    // Create an array of Row structures
    Row table[MAX_ROWS];

    // Assign values to the rows
    table[0].id = 1;
    strcpy(table[0].name, "John");
    table[0].age = 25;

    table[1].id = 2;
    strcpy(table[1].name, "Jane");
    table[1].age = 30;

    table[2].id = 3;
    strcpy(table[2].name, "Mike");
    table[2].age = 35;

    table[3].id = 4;
    strcpy(table[3].name, "Mary");
    table[3].age = 40;

    // Query the database
    int id = 2;
    char name[20];
    strcpy(name, "Mary");

    printf("Querying table for ID %d and name %s\n", id, name);

    bool found = false;
    for (int i = 0; i < MAX_ROWS; i++) {
        if (table[i].id == id && strcmp(table[i].name, name) == 0) {
            printf("Record found:\n");
            printf("ID: %d\n", table[i].id);
            printf("Name: %s\n", table[i].name);
            printf("Age: %d\n", table[i].age);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Record not found\n");
    }

    return 0;
}