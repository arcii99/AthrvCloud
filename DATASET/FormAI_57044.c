//FormAI DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

struct StudentRecord {
    int id;
    char name[30];
    float gpa;
};

struct Database {
    struct StudentRecord records[MAX_RECORDS];
    int size;
};

void initialize_database(struct Database* database);
void insert_record(struct Database* database, struct StudentRecord record);
void delete_record(struct Database* database, int id);
void search_records(struct Database* database, char* query);
void print_database(struct Database database);

int main() {
    struct Database database;
    initialize_database(&database);

    struct StudentRecord record1 = { 1, "John Smith", 3.5 };
    struct StudentRecord record2 = { 2, "Jane Doe", 3.8 };
    struct StudentRecord record3 = { 3, "Bob Johnson", 3.2 };

    insert_record(&database, record1);
    insert_record(&database, record2);
    insert_record(&database, record3);

    printf("Initial database:\n");
    print_database(database);

    delete_record(&database, 2);

    printf("\nDatabase after deleting record with id = 2:\n");
    print_database(database);

    search_records(&database, "Smith");

    return 0;
}

void initialize_database(struct Database* database) {
    database->size = 0;
}

void insert_record(struct Database* database, struct StudentRecord record) {
    if (database->size >= MAX_RECORDS) {
        printf("Error: database is full\n");
        return;
    }
    database->records[database->size] = record;
    database->size++;
}

void delete_record(struct Database* database, int id) {
    for (int i = 0; i < database->size; i++) {
        if (database->records[i].id == id) {
            memmove(&database->records[i], &database->records[i+1], sizeof(struct StudentRecord)*(database->size-i-1));
            database->size--;
            return;
        }
    }
    printf("Error: record with id=%d not found\n", id);
}

void search_records(struct Database* database, char* query) {
    printf("\nSearch results for \"%s\":\n", query);
    for (int i = 0; i < database->size; i++) {
        if (strstr(database->records[i].name, query)) {
            printf("%d\t%s\t%g\n", database->records[i].id, database->records[i].name, database->records[i].gpa);
        }
    }
}

void print_database(struct Database database) {
    printf("ID\tName\tGPA\n");
    for (int i = 0; i < database.size; i++) {
        printf("%d\t%s\t%g\n", database.records[i].id, database.records[i].name, database.records[i].gpa);
    }
}