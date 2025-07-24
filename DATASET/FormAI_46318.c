//FormAI DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of a record which will be stored in our index
typedef struct Record {
    int id;
    char name[20];
    int age;
} Record;

// Defining the structure of our index 
typedef struct Index {
    int key;
    int offset;
} Index;

int main() {

    int num_records = 5;
    Record records[num_records];

    // Adding records to our database with IDs and some information
    records[0] = (Record) {1, "John Smith", 25};
    records[1] = (Record) {2, "Jane Doe", 30};
    records[2] = (Record) {3, "David Lee", 42};
    records[3] = (Record) {4, "Sarah Green", 19};
    records[4] = (Record) {5, "Tom Parker", 67};

    // Creating the index based on the IDs of the records
    Index index[num_records];
    int i;
    for (i = 0; i < num_records; i++) {
        index[i].key = records[i].id;
        index[i].offset = i * sizeof(Record);
    }

    // Printing out the index keys and offsets
    printf("Index:\n");
    for (i = 0; i < num_records; i++) {
        printf("key: %d, offset: %d\n", index[i].key, index[i].offset);
    }

    // Searching for a record based on its ID
    int search_id = 3;
    int search_offset;
    for (i = 0; i < num_records; i++) {
        if (index[i].key == search_id) {
            search_offset = index[i].offset;
            break;
        }
    }

    // Printing out the record we found
    printf("\nRecord with ID %d:\n", search_id);
    printf("ID: %d\n", records[search_offset / sizeof(Record)].id);
    printf("Name: %s\n", records[search_offset / sizeof(Record)].name);
    printf("Age: %d\n", records[search_offset / sizeof(Record)].age);

    return 0;
}