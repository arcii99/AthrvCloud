//FormAI DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct record {
    int id;
    char name[20];
    int age;
    char address[50];
} Record;

void initialize_database(Record* db) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        db[i].id = -1;
        memset(db[i].name, '\0', sizeof(db[i].name));
        db[i].age = -1;
        memset(db[i].address, '\0', sizeof(db[i].address));
    }
}

void insert_record(Record* db, int* num_records, Record new_record) {
    if (*num_records == MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (db[i].id == -1) {
            new_record.id = i;
            db[i] = new_record;
            (*num_records)++;
            printf("Record added successfully!\n");
            return;
        }
    }
}

void delete_record(Record* db, int* num_records, int id) {
    for (int i = 0; i < *num_records; i++) {
        if (db[i].id == id) {
            db[i].id = -1;
            memset(db[i].name, '\0', sizeof(db[i].name));
            db[i].age = -1;
            memset(db[i].address, '\0', sizeof(db[i].address));
            (*num_records)--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

void print_record(Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("Address: %s\n", record.address);
}

void print_database(Record* db, int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("---Record %d---\n", db[i].id);
        print_record(db[i]);
    }
}

int main() {
    Record database[MAX_RECORDS];
    int num_records = 0;
    initialize_database(database);
    char choice;
    do {
        printf("Please choose an action:\n");
        printf("1. Add record\n");
        printf("2. Delete record\n");
        printf("3. Print database\n");
        printf("4. Exit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1': {
                Record new_record;
                printf("Please enter the record information:\n");
                printf("Name: ");
                scanf(" %[^\n]s", new_record.name);
                printf("Age: ");
                scanf(" %d", &new_record.age);
                printf("Address: ");
                scanf(" %[^\n]s", new_record.address);
                insert_record(database, &num_records, new_record);
                break;
            }
            case '2': {
                int id;
                printf("Please enter the ID of the record to delete: ");
                scanf(" %d", &id);
                delete_record(database, &num_records, id);
                break;
            }
            case '3': {
                print_database(database, num_records);
                break;
            }
            case '4': {
                printf("Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid choice, please try again\n");
            }
        }
    } while (choice != '4');
    return 0;
}