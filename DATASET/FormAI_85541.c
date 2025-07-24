//FormAI DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // maximum number of records in database

// structure for storing record information
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// function prototypes
int add_record(Record* database, int num_records);
int print_records(Record* database, int num_records);
int search_record(Record* database, int num_records, int id);
int delete_record(Record* database, int num_records, int id);

int main() {
    Record database[MAX_RECORDS]; // initialize empty database array
    int num_records = 0; // initialize number of records in database to zero
    char input[50]; // string for storing user input

    printf("Welcome to the C Database Simulation!\n");

    while (1) {
        // prompt user to enter a command
        printf("\nEnter a command (add, print, search, delete, exit): ");
        fgets(input, 50, stdin);

        // remove newline character from user input
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "add") == 0) {
            // add a new record to the database
            num_records = add_record(database, num_records);
        } else if (strcmp(input, "print") == 0) {
            // print all records in the database
            print_records(database, num_records);
        } else if (strcmp(input, "search") == 0) {
            // search for a record in the database by ID
            printf("\nEnter ID to search for: ");
            fgets(input, 50, stdin);
            int id = atoi(input);
            search_record(database, num_records, id);
        } else if (strcmp(input, "delete") == 0) {
            // delete a record from the database by ID
            printf("\nEnter ID to delete: ");
            fgets(input, 50, stdin);
            int id = atoi(input);
            num_records = delete_record(database, num_records, id);
        } else if (strcmp(input, "exit") == 0) {
            // exit the program
            printf("\nGoodbye!\n");
            break;
        } else {
            // invalid command entered
            printf("\nInvalid command, please try again.\n");
        }
    }

    return 0;
}

// function to add a record to the database
int add_record(Record* database, int num_records) {
    // check if maximum number of records has been reached
    if (num_records == MAX_RECORDS) {
        printf("\nDatabase is full, cannot add new record.\n");
        return num_records;
    }

    // prompt user to enter record information
    printf("\nEnter record ID: ");
    int id;
    scanf("%d", &id);
    getchar(); // remove newline character from input buffer
    printf("Enter record name: ");
    char name[50];
    fgets(name, 50, stdin);
    printf("Enter record age: ");
    int age;
    scanf("%d", &age);
    getchar(); // remove newline character from input buffer

    // create new record and add it to the database
    Record new_record = {id, name, age};
    database[num_records] = new_record;
    num_records++;

    printf("\nRecord added successfully.\n");

    return num_records;
}

// function to print all records in the database
int print_records(Record* database, int num_records) {
    // check if database is empty
    if (num_records == 0) {
        printf("\nDatabase is empty, no records to print.\n");
        return num_records;
    }

    printf("\nDatabase contains %d record(s):\n", num_records);

    // print each record in the database
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("  ID: %d\n", database[i].id);
        printf("  Name: %s", database[i].name);
        printf("  Age: %d\n", database[i].age);
    }

    return num_records;
}

// function to search for a record in the database by ID
int search_record(Record* database, int num_records, int id) {
    // search for record with matching ID
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            printf("\nRecord found:\n");
            printf("  ID: %d\n", database[i].id);
            printf("  Name: %s", database[i].name);
            printf("  Age: %d\n", database[i].age);
            return i;
        }
    }

    // record not found
    printf("\nRecord not found.\n");
    return -1;
}

// function to delete a record from the database by ID
int delete_record(Record* database, int num_records, int id) {
    // search for record with matching ID
    int index = search_record(database, num_records, id);

    if (index == -1) {
        // record not found
        return num_records;
    } else {
        // shift all records after deleted record back one position
        for (int i = index; i < num_records - 1; i++) {
            database[i] = database[i + 1];
        }

        // reduce number of records by one
        num_records--;

        printf("\nRecord deleted successfully.\n");

        return num_records;
    }
}