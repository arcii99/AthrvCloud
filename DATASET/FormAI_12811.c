//FormAI DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 50
#define MAX_STRING_SIZE 100

typedef struct {
    int id;
    char name[MAX_STRING_SIZE];
    int age;
} Record;

int main() {
    Record database[MAX_RECORDS];
    int num_records = 0;

    // Add records to the database
    Record new_record = {1, "John Doe", 25};
    database[num_records++] = new_record;

    new_record = (Record) {2, "Jane Smith", 28};
    database[num_records++] = new_record;

    new_record = (Record) {3, "Bob Johnson", 30};
    database[num_records++] = new_record;

    new_record = (Record) {4, "Alice Brown", 27};
    database[num_records++] = new_record;

    // Create indexing system based on name
    char index[MAX_RECORDS][MAX_STRING_SIZE];
    int num_keys = 0;

    // Add index keys
    for (int i = 0; i < num_records; i++) {
        Record record = database[i];

        // Check if record name is already indexed
        int found = 0;
        for (int j = 0; j < num_keys; j++) {
            if (strcmp(record.name, index[j]) == 0) {
                found = 1;
                break;
            }
        }

        // If not found, add to index
        if (!found) {
            strcpy(index[num_keys++], record.name);
        }
    }

    // Print records by name
    printf("Records sorted by name:\n");
    for (int i = 0; i < num_keys; i++) {
        printf("%s:\n", index[i]);
        for (int j = 0; j < num_records; j++) {
            Record record = database[j];
            if (strcmp(record.name, index[i]) == 0) {
                printf("\tID: %d\n", record.id);
                printf("\tAge: %d\n", record.age);
            }
        }
        printf("\n");
    }

    return 0;
}