//FormAI DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000 //maximum number of records that can be indexed
#define MAX_STRING_LENGTH 50 //maximum length of strings in the data structure

typedef struct {
    int id;
    char name[MAX_STRING_LENGTH];
    int age;
    float salary;
} Record; //structure representing a single record in the database

typedef struct {
    int key;
    int index; //index of the record in the array
} Index; //structure representing a single index in the indexing system

typedef struct {
    Index indexes[MAX_RECORDS];
    int count; //number of indexes in the system
} IndexSystem; //structure representing a collection of indexes

//function to insert a new index into the system
void insert_index(IndexSystem *system, int key, int index) {
    Index new_index;
    new_index.key = key;
    new_index.index = index;
    
    //find the position to insert the new index in the system, so that the array remains sorted by key
    int i;
    for(i = 0; i < system->count && system->indexes[i].key <= key; i++);
    
    //shift all elements to the right of the insertion position to make room for the new index
    for(int j = system->count; j > i; j--)
        system->indexes[j] = system->indexes[j-1];
    
    //insert the new index into the system
    system->indexes[i] = new_index;
    system->count++;
}

//function to search the indexing system for a record with a given key
int search_index(IndexSystem *system, int key) {
    //perform binary search on the array of indexes
    int low = 0, high = system->count-1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(system->indexes[mid].key == key)
            return system->indexes[mid].index; //return the index of the record with the given key
        else if(system->indexes[mid].key < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; //indicates that no record with the given key was found in the system
}

int main() {
    //initialize some sample records
    Record records[] = {
        {1001, "John Smith", 32, 50000},
        {1010, "Jane Doe", 45, 75000},
        {1015, "Bob Johnson", 28, 40000},
        {1022, "Mary Williams", 36, 60000},
        {1030, "Peter Brown", 50, 80000}
    };
    
    int num_records = sizeof(records) / sizeof(Record);
    
    //initialize the indexing system
    IndexSystem system;
    system.count = 0;
    
    //populate the indexing system with keys and indexes to the records
    for(int i = 0; i < num_records; i++) {
        int key = records[i].id; //use the record ID as the key for indexing
        insert_index(&system, key, i);
    }
    
    //testing the indexing system
    int search_key = 1015;
    int record_index = search_index(&system, search_key);
    if(record_index != -1) {
        printf("Record with ID %d found at index %d.\n", search_key, record_index);
        Record matching_record = records[record_index];
        printf("Details: Name = %s, Age = %d, Salary = %.2f", matching_record.name, matching_record.age, matching_record.salary);
    } else {
        printf("No record with ID %d found.\n", search_key);
    }
    
    return 0;
}