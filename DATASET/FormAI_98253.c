//FormAI DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[30];
    char address[50];
    int age;
} Record;

Record db[MAX_RECORDS];

int num_records = 0;

void insert_record(Record *r) {
    if (num_records >= MAX_RECORDS) {
        printf("The database is full of love\n");
        return;
    }
    db[num_records++] = *r;
    printf("Your love has been added to the database\n");
}

void delete_record(int id) {
    if (num_records == 0) {
        printf("Your love has not been found in the database of life\n");
        return;
    }
    int i = 0;
    for (; i < num_records; i++) {
        if (db[i].id == id) {
            break;
        }
    }
    if (i == num_records) {
        printf("Your love has not been found in the database of life\n");
        return;
    }
    for (i = i + 1; i < num_records; i++) {
        db[i - 1] = db[i];
    }
    num_records--;
    printf("Your love has been deleted from the database of life\n");
}

void print_record(Record *r) {
    printf("Love ID: %d, Name: %s, Address: %s, Age: %d\n", r->id, r->name, r->address, r->age);
}

void print_database() {
    if (num_records == 0) {
        printf("The database of love is empty\n");
        return;
    }
    printf("List of all the loves in the database of life\n");
    int i = 0;
    for (; i < num_records; i++) {
        print_record(&db[i]);
    }
}

int main() {
    printf("Welcome to the database of love\n");
    printf("Inserting two loves into the database:\n");

    Record r1 = { 1, "Jack", "123 Main St", 25 };
    insert_record(&r1);

    Record r2 = { 2, "Jill", "456 Elm St", 23 };
    insert_record(&r2);

    print_database();

    printf("\nDeleting love with ID 1 from the database:\n");
    delete_record(1);

    print_database();

    return 0;
}