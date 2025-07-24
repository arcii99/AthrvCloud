//FormAI DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_INDEX 26

// structure for storing record data
typedef struct Record {
    char name[50];
    int id;
    char address[100];
    char phone[20];
} Record;

// structure for storing index data
typedef struct Index {
    char key;
    int count;
    int offset[MAX_RECORDS];
} Index;

// function for adding a record to the database
void add_record(FILE* fp, Record* rec, Index* index) {
    // write record data to file
    fseek(fp, 0, SEEK_END);
    fwrite(rec, sizeof(Record), 1, fp);
    
    // update index data
    int key_index = rec->name[0] - 'A';
    index[key_index].offset[index[key_index].count] = ftell(fp) - sizeof(Record);
    index[key_index].count++;
}

// function for searching for records in the database
void search_records(FILE* fp, Index* index, char* name) {
    int key_index = name[0] - 'A';
    
    // check if there are any records with matching first letter
    if (index[key_index].count == 0) {
        printf("No records found.\n");
        return;
    }
    
    // search for matching records
    int num_matches = 0;
    for (int i = 0; i < index[key_index].count; i++) {
        fseek(fp, index[key_index].offset[i], SEEK_SET);
        Record rec;
        fread(&rec, sizeof(Record), 1, fp);
        if (strcmp(rec.name, name) == 0) {
            printf("Record found:\n");
            printf("Name: %s\n", rec.name);
            printf("ID: %d\n", rec.id);
            printf("Address: %s\n", rec.address);
            printf("Phone: %s\n", rec.phone);
            num_matches++;
        }
    }
    
    // print message if no matches found
    if (num_matches == 0) {
        printf("No records found.\n");
    }
}

int main() {
    FILE* fp;
    fp = fopen("database.bin", "wb+");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    
    // initialize index data
    Index index[MAX_INDEX];
    for (int i = 0; i < MAX_INDEX; i++) {
        index[i].key = 'A' + i;
        index[i].count = 0;
    }
    
    // add some sample records to the database
    Record rec1 = {"Alice Smith", 1001, "123 Main St", "555-1234"};
    add_record(fp, &rec1, index);
    Record rec2 = {"Bob Johnson", 1002, "456 Oak St", "555-5678"};
    add_record(fp, &rec2, index);
    Record rec3 = {"Cathy Davis", 1003, "789 Elm St", "555-9012"};
    add_record(fp, &rec3, index);
    Record rec4 = {"David Lee", 1004, "246 Pine St", "555-3456"};
    add_record(fp, &rec4, index);
    
    // search for a record
    search_records(fp, index, "Bob Johnson");
    
    fclose(fp);
    return 0;
}