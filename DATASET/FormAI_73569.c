//FormAI DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max number of records and max length of string fields
#define MAX_RECORDS 1000
#define MAX_NAME_LEN 50
#define MAX_ADDRESS_LEN 100

// Struct to hold a single record
typedef struct Record {
    int id;
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
} Record;

// Struct to hold the index of records based on name field
typedef struct Index {
    char name[MAX_NAME_LEN];
    int* record_ids;
    int num_records;
} Index;

// Function to add a record to the database
void add_record(Record* database, Index* index, int* num_records) {
    // Create a new record with id equal to current number of records + 1
    Record new_record;
    new_record.id = *num_records + 1;

    // Get name and address from user
    printf("Enter name: ");
    fgets(new_record.name, MAX_NAME_LEN, stdin);
    printf("Enter address: ");
    fgets(new_record.address, MAX_ADDRESS_LEN, stdin);

    // Remove newline character from end of strings
    new_record.name[strcspn(new_record.name, "\n")] = '\0';
    new_record.address[strcspn(new_record.address, "\n")] = '\0';

    // Add record to database
    database[*num_records] = new_record;
    
    // Update index
    int found = 0;
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(index[i].name, new_record.name) == 0) {
            // Add new record id to existing index entry
            index[i].record_ids[index[i].num_records] = new_record.id;
            index[i].num_records++;
            found = 1;
        }
    }
    if (!found) {
        // Create new index entry for name
        Index new_index_entry;
        strcpy(new_index_entry.name, new_record.name);
        new_index_entry.record_ids = (int*) malloc(sizeof(int) * MAX_RECORDS);
        new_index_entry.record_ids[0] = new_record.id;
        new_index_entry.num_records = 1;
        // Find next available index spot and add new entry
        for (int i = 0; i < MAX_RECORDS; i++) {
            if (index[i].record_ids == NULL) {
                index[i] = new_index_entry;
                break;
            }
        }
    }

    // Increment number of records in database
    (*num_records)++;
}

int main() {
    // Initialize database and index
    Record database[MAX_RECORDS];
    Index index[MAX_RECORDS];
    for (int i = 0; i < MAX_RECORDS; i++) {
        index[i].record_ids = NULL;
    }
    int num_records = 0;

    // Main loop for handling user input
    while (1) {
        // Print menu and get user choice
        printf("\nDatabase Indexing System\n");
        printf("1. Add record\n");
        printf("2. Search by name\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character left in input buffer

        // Handle user choice
        switch (choice) {
            case 1:
                add_record(database, index, &num_records);
                break;
            case 2: {
                // Get name to search for
                char search_name[MAX_NAME_LEN];
                printf("Enter name to search for: ");
                fgets(search_name, MAX_NAME_LEN, stdin);
                search_name[strcspn(search_name, "\n")] = '\0';

                // Search index for matching name
                int found = 0;
                for (int i = 0; i < MAX_RECORDS; i++) {
                    if (index[i].record_ids != NULL && strcmp(index[i].name, search_name) == 0) {
                        // Print all records with matching name
                        printf("Records with name '%s':\n", search_name);
                        for (int j = 0; j < index[i].num_records; j++) {
                            int record_id = index[i].record_ids[j];
                            Record record = database[record_id - 1];
                            printf("ID: %d, Name: %s, Address: %s\n", record.id, record.name, record.address);
                        }
                        found = 1;
                    }
                }
                if (!found) {
                    printf("No records found with name '%s'\n", search_name);
                }
                break;
            }
            case 3:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}