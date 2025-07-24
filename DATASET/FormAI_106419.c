//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 20
#define MAX_PHONE_LEN 15
#define MAX_EMAIL_LEN 30

// Define the structure for a single record in the database
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
} Record;

// Define a list of records for the database and the number of records
Record records[MAX_RECORDS];
int num_records = 0;

// Define the indexing system for the database, using arrays for each criteria
int name_index[MAX_RECORDS];
int phone_index[MAX_RECORDS];
int email_index[MAX_RECORDS];

// Define the number of records in each index
int num_name_index = 0;
int num_phone_index = 0;
int num_email_index = 0;

// Add a new record to the database and indexes
void add_record(char* name, char* phone, char* email) {
    // Create the new record and add it to the database
    Record record;
    strncpy(record.name, name, MAX_NAME_LEN);
    strncpy(record.phone, phone, MAX_PHONE_LEN);
    strncpy(record.email, email, MAX_EMAIL_LEN);
    records[num_records++] = record;

    // Update the indexes with the new record
    name_index[num_name_index++] = num_records - 1;
    phone_index[num_phone_index++] = num_records - 1;
    email_index[num_email_index++] = num_records - 1;
}

// Search for records in the database using multiple criteria
int search_records(char* name, char* phone, char* email) {
    int i, j, k;

    // Search through all the name index entries
    for (i = 0; i < num_name_index; i++) {
        Record* current = &records[name_index[i]];
        // Check if the name matches
        if (strcmp(current->name, name) == 0) {
            // Search through all the phone index entries
            for (j = 0; j < num_phone_index; j++) {
                current = &records[phone_index[j]];
                // Check if the phone matches
                if (strcmp(current->phone, phone) == 0) {
                    // Search through all the email index entries
                    for (k = 0; k < num_email_index; k++) {
                        current = &records[email_index[k]];
                        // Check if the email matches
                        if (strcmp(current->email, email) == 0) {
                            // Return the index of the matching record
                            return email_index[k];
                        }
                    }
                }
            }
        }
    }

    // No matching records were found
    return -1;
}

// Main function to add some sample records, search for them, and print the results
int main() {
    add_record("Alice", "123-456-7890", "alice@example.com");
    add_record("Bob", "234-567-8901", "bob@example.com");
    add_record("Charlie", "345-678-9012", "charlie@example.com");

    int index = search_records("Alice", "123-456-7890", "alice@example.com");
    if (index != -1) {
        printf("Found record at index %d:\n", index);
        printf("  Name: %s\n", records[index].name);
        printf("  Phone: %s\n", records[index].phone);
        printf("  Email: %s\n", records[index].email);
    } else {
        printf("No matching records found.\n");
    }

    return 0;
}