//FormAI DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000 // maximum number of records
#define MAX_NAME_LENGTH 50 // maximum length of name

// structure for a single record
struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
};

// structure for the indexing system
struct Index {
    char name[MAX_NAME_LENGTH];
    int start_pos;
    int num_records;
};

int main() {
    struct Record records[MAX_RECORDS]; // array to store all records
    struct Index indexes[MAX_NAME_LENGTH]; // array to store all indexes
    int num_records = 0; // number of records currently in the array
    int num_indexes = 0; // number of indexes currently in the array

    // function to add a new record to the array
    void add_record(int id, char name[MAX_NAME_LENGTH], int age) {
        struct Record record;
        record.id = id;
        strncpy(record.name, name, MAX_NAME_LENGTH);
        record.age = age;

        records[num_records] = record;
        num_records++;
    }

    // function to add a new index to the array
    void add_index(char name[MAX_NAME_LENGTH], int start_pos, int num_records) {
        struct Index index;
        strncpy(index.name, name, MAX_NAME_LENGTH);
        index.start_pos = start_pos;
        index.num_records = num_records;

        indexes[num_indexes] = index;
        num_indexes++;
    }

    // function to search for records by name
    void search_by_name(char name[MAX_NAME_LENGTH]) {
        int i, j;
        for (i = 0; i < num_indexes; i++) {
            if (strncmp(indexes[i].name, name, MAX_NAME_LENGTH) == 0) {
                for (j = indexes[i].start_pos; j < indexes[i].start_pos + indexes[i].num_records; j++) {
                    if (strncmp(records[j].name, name, MAX_NAME_LENGTH) == 0) {
                        // print out the matching record
                        printf("Record with name %s found. ID: %d, Age: %d\n", records[j].name, records[j].id, records[j].age);
                    }
                }
            }
        }
    }

    // function to print out all records in the array
    void print_all_records() {
        int i;
        for (i = 0; i < num_records; i++) {
            printf("Record #%d: ID: %d, Name: %s, Age: %d\n", i+1, records[i].id, records[i].name, records[i].age);
        }
    }

    // add some example records to the array
    add_record(1, "John Smith", 25);
    add_record(2, "Jane Doe", 30);
    add_record(3, "Alice Johnson", 45);
    add_record(4, "Bob Williams", 50);
    add_record(5, "John Doe", 35);

    // add some indexes for the names
    add_index("John", 0, 2);
    add_index("Jane", 1, 1);
    add_index("Alice", 2, 1);
    add_index("Bob", 3, 1);

    // search for some records by name
    search_by_name("John");
    search_by_name("Jane");
    search_by_name("Alice");
    search_by_name("Bob");
    search_by_name("Joe");

    // print out all records
    print_all_records();

    return 0;
}