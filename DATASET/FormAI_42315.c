//FormAI DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum size for database records
#define MAX_RECORD_SIZE 100

// define maximum number of records for the database
#define MAX_NUM_RECORDS 50

// define structure to hold database records
typedef struct record_t {
    int id;
    float value1;
    float value2;
    char str[MAX_RECORD_SIZE];
} Record;

// define structure to hold database
typedef struct database_t {
    Record record_list[MAX_NUM_RECORDS];
    int num_records;
} Database;

// function to add a new record to the database
void add_record(Database *database, int id, float value1, float value2, char *str) {
    // check if database is full
    if (database->num_records >= MAX_NUM_RECORDS) {
        printf("ERROR - Maximum number of records exceeded.\n");
        return;
    }

    // create new record
    Record new_record = {
        .id = id,
        .value1 = value1,
        .value2 = value2
    };
    strncpy(new_record.str, str, MAX_RECORD_SIZE);

    // add record to database and increment number of records
    database->record_list[database->num_records++] = new_record;
}

// function to print all records in the database
void print_database(Database *database) {
    printf("ID\tValue 1\tValue 2\tString\n");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < database->num_records; i++) {
        Record record = database->record_list[i];
        printf("%d\t%.2f\t%.2f\t%s\n", record.id, record.value1, record.value2, record.str);
    }
}

int main() {
    // create new database and add some records
    Database database = {0};
    add_record(&database, 1, 10.5, 20.3, "Record 1");
    add_record(&database, 2, 15.2, 25.9, "Record 2");
    add_record(&database, 3, 8.1, 30.7, "Record 3");

    // print all records in the database
    print_database(&database);

    return 0;
}