//FormAI DATASET v1.0 Category: Database querying ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the database records
typedef struct Record {
    int id;
    char name[50];
    int age;
    char address[100];
} Record;

// Declare the global array to hold the database records
Record database[100];

// Declare the function to read the database from a binary file
void readDatabase() {
    FILE *fp = fopen("database.bin", "rb");
    int numRecords = 0;
    while (fread(&database[numRecords], sizeof(Record), 1, fp) == 1) {
        numRecords++;
    }
    fclose(fp);
}

// Declare the function to search for a record by name and print it
void searchByName(char *name) {
    int found = 0;
    for (int i = 0; i < 100; i++) {
        if (strcmp(database[i].name, name) == 0) {
            found = 1;
            printf("Record found:\n");
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Address: %s\n", database[i].address);
            break;
        }
    }
    if (!found) {
        printf("Record not found\n");
    }
}

// Declare the function to search for a record by age and print it
void searchByAge(int age) {
    int found = 0;
    for (int i = 0; i < 100; i++) {
        if (database[i].age == age) {
            found = 1;
            printf("Record found:\n");
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Address: %s\n", database[i].address);
            break;
        }
    }
    if (!found) {
        printf("Record not found\n");
    }
}

int main() {
    readDatabase();

    // Example usage: search for a record by name
    char *name = "Claude Shannon";
    searchByName(name);

    // Example usage: search for a record by age
    int age = 40;
    searchByAge(age);

    return 0;
}