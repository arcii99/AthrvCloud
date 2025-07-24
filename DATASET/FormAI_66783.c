//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

// Structure to represent a record in the database
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

// Function to insert a new record into the database
void insert_record(Record* database, int* num_records, char* name, char* phone) {
    if (*num_records < MAX_RECORDS) {
        // Increment number of records and update new record with ID
        (*num_records)++;
        int id = *num_records;

        // Create new record and add to database
        Record new_record = {id};
        strcpy(new_record.name, name);
        strcpy(new_record.phone, phone);
        database[id-1] = new_record;

        printf("Record added to database with ID: %d\n", id);
    } else {
        printf("Database is full\n");
    }
}

// Function to search for a record by ID
void search_record(Record* database, int num_records, int id) {
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            printf("Record found with ID %d:\n", id);
            printf("Name: %s\n", database[i].name);
            printf("Phone: %s\n", database[i].phone);
            return;
        }
    }
    printf("Record not found with ID %d\n", id);
}

// Function to print all records in the database
void print_database(Record* database, int num_records) {
    printf("Database contents:\n");
    for (int i = 0; i < num_records; i++) {
        printf("ID: %d, Name: %s, Phone: %s\n", database[i].id, database[i].name, database[i].phone);
    }
}

int main() {
    Record database[MAX_RECORDS];
    int num_records = 0;
    int choice;

    do {
        printf("1 - Add Record\n");
        printf("2 - Search Record\n");
        printf("3 - View All Records\n");
        printf("4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add new record to database
                char name[MAX_NAME_LENGTH];
                char phone[MAX_PHONE_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                insert_record(database, &num_records, name, phone);
                break;
            case 2:
                // Search for record by ID
                int id;
                printf("Enter ID to search for: ");
                scanf("%d", &id);
                search_record(database, num_records, id);
                break;
            case 3:
                // Print all records in the database
                print_database(database, num_records);
                break;
            case 4:
                // Exit program
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

    } while (choice != 4);

    return 0;
}