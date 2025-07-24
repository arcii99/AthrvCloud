//FormAI DATASET v1.0 Category: Database simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of records in the database
#define MAX_RECORDS 1000

// define the structure for a record in the database
typedef struct {
    int id;
    char name[20];
    float salary;
} Record;

// declare the database array
Record database[MAX_RECORDS];

// declare the current number of records in the database
int num_records = 0;

// define the function for adding a record to the database
void add_record(int id, char* name, float salary) {
    // check if the database is full
    if (num_records >= MAX_RECORDS) {
        printf("Error: the database is full.\n");
        return;
    }
    
    // create a new record
    Record new_record;
    new_record.id = id;
    strcpy(new_record.name, name);
    new_record.salary = salary;
    
    // add the new record to the database
    database[num_records] = new_record;
    num_records++;
    
    // print a success message
    printf("Record added successfully.\n");
}

// define the function for deleting a record from the database
void delete_record(int id) {
    // search for the record to be deleted
    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }
    
    // check if the record was found
    if (index == -1) {
        printf("Error: no record with ID %d.\n", id);
        return;
    }
    
    // delete the record by shifting all subsequent records back by one position
    for (int i = index; i < num_records-1; i++) {
        database[i] = database[i+1];
    }
    num_records--;
    
    // print a success message
    printf("Record deleted successfully.\n");
}

// define the function for displaying all records in the database
void display_records() {
    // print the header
    printf("ID\tName\tSalary\n");
    printf("--\t----\t------\n");
    
    // loop through all records in the database and print them
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%.2f\n", database[i].id, database[i].name, database[i].salary);
    }
}

// main function
int main() {
    // print a welcome message
    printf("Welcome to the Futuristic Database Simulation!\n");
    
    // loop through the program until the user chooses to exit
    char choice;
    do {
        // print the menu
        printf("\nMENU:\n");
        printf("1. Add a record\n");
        printf("2. Delete a record\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");
        
        // get the user's choice
        printf("\nEnter your choice (1-4): ");
        scanf(" %c", &choice);
        
        // execute the appropriate function based on the user's choice
        switch (choice) {
            case '1':
                // get the record data from the user
                int id;
                char name[20];
                float salary;
                printf("\nEnter the ID: ");
                scanf("%d", &id);
                printf("Enter the name: ");
                scanf("%s", name);
                printf("Enter the salary: ");
                scanf("%f", &salary);
                
                // add the record to the database
                add_record(id, name, salary);
                break;
                
            case '2':
                // get the ID of the record to be deleted from the user
                printf("\nEnter the ID of the record to be deleted: ");
                scanf("%d", &id);
                
                // delete the record from the database
                delete_record(id);
                break;
                
            case '3':
                // display all records in the database
                display_records();
                break;
                
            case '4':
                // exit the program
                printf("\nThank you for using the Futuristic Database Simulation!\n");
                break;
                
            default:
                // print an error message for an invalid choice
                printf("\nError: invalid choice.\n");
                break;
        }
    } while (choice != '4');
    
    return 0;
}