//FormAI DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 20

struct Record {
    int id; 
    char name[MAX_NAME_LENGTH]; 
    int age; 
};

int num_records = 0; 
struct Record records[MAX_RECORDS]; 

void add_record(int id, char* name, int age) {
    if (num_records < MAX_RECORDS) {
        records[num_records].id = id; 
        strncpy(records[num_records].name, name, MAX_NAME_LENGTH);
        records[num_records].name[MAX_NAME_LENGTH - 1] = '\0'; // ensure null termination
        records[num_records].age = age; 
        num_records++; 
    } else {
        printf("Error: Maximum number of records reached."); 
    }
}

struct Record* search_record(int id) {
    for (int i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            return &records[i]; 
        }
    }
    return NULL; 
}

int main() {
    add_record(1, "Alice", 25); 
    add_record(2, "Bob", 30); 
    add_record(3, "Charlie", 20); 

    printf("Search for record with ID 2:\n"); 
    struct Record* r = search_record(2); 
    if (r != NULL) {
        printf("Record found: id=%d, name=%s, age=%d\n", r->id, r->name, r->age); 
    } else {
        printf("Record not found.\n"); 
    }

    return 0; 
}