//FormAI DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Define the maximum length of strings */
#define MAX_STR_LEN 50

/* Define the maximum number of records */
#define MAX_RECORDS 100

/* Define the structure of a record */
struct Record {
    int id;
    char name[MAX_STR_LEN];
    int age;
    char gender[MAX_STR_LEN];
    float salary;
};

/* Define the database */
struct Record database[MAX_RECORDS];

/* Define the number of records currently in the database */
int num_records = 0;

/* Function to add a record to the database */
void add_record(int id, char name[], int age, char gender[], float salary) {
    /* Check if the database is full */
    if (num_records >= MAX_RECORDS) {
        printf("Error: Database is full!\n");
        return;
    }
    
    /* Create the new record */
    struct Record new_record;
    new_record.id = id;
    strncpy(new_record.name, name, MAX_STR_LEN);
    new_record.age = age;
    strncpy(new_record.gender, gender, MAX_STR_LEN);
    new_record.salary = salary;
    
    /* Add the new record to the database */
    database[num_records] = new_record;
    num_records++;
    
    printf("Record added successfully!\n");
}

/* Function to print a record */
void print_record(struct Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("Gender: %s\n", record.gender);
    printf("Salary: %.2f\n", record.salary);
}

/* Function to find a record by its ID */
int find_record_by_id(int id) {
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            return i; /* Return the index of the record */
        }
    }
    return -1; /* Record not found */
}

/* Function to query the database */
void query_database() {
    int choice;
    int id;
    char name[MAX_STR_LEN];
    int age;
    char gender[MAX_STR_LEN];
    float salary;
    int index;
    bool found_records = false; /* Flag to indicate whether or not any records were found */
    
    do {
        /* Print the menu */
        printf("Select query type:\n");
        printf("1. Query by ID\n");
        printf("2. Query by name\n");
        printf("3. Query by age\n");
        printf("4. Query by gender\n");
        printf("5. Query by salary\n");
        printf("6. Exit\n");
        
        /* Get user input */
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: /* Query by ID */
                printf("Enter ID to search for: ");
                scanf("%d", &id);
                index = find_record_by_id(id);
                if (index == -1) {
                    printf("Record with ID %d not found!\n", id);
                } else {
                    found_records = true;
                    printf("Record found:\n");
                    print_record(database[index]);
                }
                break;
            case 2: /* Query by name */
                printf("Enter name to search for: ");
                scanf("%s", name);
                found_records = false;
                for (int i = 0; i < num_records; i++) {
                    if (strcmp(database[i].name, name) == 0) {
                        found_records = true;
                        print_record(database[i]);
                    }
                }
                if (!found_records) {
                    printf("No records found!\n");
                }
                break;
            case 3: /* Query by age */
                printf("Enter age to search for: ");
                scanf("%d", &age);
                found_records = false;
                for (int i = 0; i < num_records; i++) {
                    if (database[i].age == age) {
                        found_records = true;
                        print_record(database[i]);
                    }
                }
                if (!found_records) {
                    printf("No records found!\n");
                }
                break;
            case 4: /* Query by gender */
                printf("Enter gender to search for: ");
                scanf("%s", gender);
                found_records = false;
                for (int i = 0; i < num_records; i++) {
                    if (strcmp(database[i].gender, gender) == 0) {
                        found_records = true;
                        print_record(database[i]);
                    }
                }
                if (!found_records) {
                    printf("No records found!\n");
                }
                break;
            case 5: /* Query by salary */
                printf("Enter salary to search for: ");
                scanf("%f", &salary);
                found_records = false;
                for (int i = 0; i < num_records; i++) {
                    if (database[i].salary == salary) {
                        found_records = true;
                        print_record(database[i]);
                    }
                }
                if (!found_records) {
                    printf("No records found!\n");
                }
                break;
            case 6: /* Exit */
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 6); /* Continue until user chooses to exit */
}

/* Main function */
int main() {
    /* Add some test records to the database */
    add_record(1, "John Smith", 30, "Male", 50000.0);
    add_record(2, "Jane Doe", 25, "Female", 60000.0);
    add_record(3, "Bob Johnson", 45, "Male", 75000.0);
    add_record(4, "Alice Lee", 28, "Female", 55000.0);
    
    /* Query the database */
    query_database();
    
    return 0;
}