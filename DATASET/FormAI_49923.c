//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

struct Record {
    int id;
    char name[50];
    int age;
};

struct Database {
    struct Record records[MAX_RECORDS];
    int num_records;
};

void save_database(struct Database db) {
    FILE *fp;
    fp = fopen("database.bin", "wb");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
    } else {
        fwrite(&db, sizeof(struct Database), 1, fp);
        fclose(fp);
        printf("Database successfully saved!\n");
    }
}

void load_database(struct Database *db) {
    FILE *fp;
    fp = fopen("database.bin", "rb");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
    } else {
        fread(db, sizeof(struct Database), 1, fp);
        fclose(fp);
        printf("Database successfully loaded!\n");
    }
}

void print_record(struct Record r) {
    printf("ID: %d\n", r.id);
    printf("Name: %s\n", r.name);
    printf("Age: %d\n", r.age);
}

void print_all_records(struct Database db) {
    if (db.num_records == 0) {
        printf("No records found.\n");
    } else {
        for (int i = 0; i < db.num_records; i++) {
            printf("Record %d:\n", i+1);
            print_record(db.records[i]);
            printf("\n");
        }
    }
}

void add_record(struct Database *db, struct Record r) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: Database is full.\n");
    } else {
        db->records[db->num_records] = r;
        db->num_records++;
        printf("Record added successfully.\n");
    }
}

void delete_record(struct Database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->num_records-1; j++) {
                db->records[j] = db->records[j+1];
            }
            db->num_records--;
            printf("Record deleted successfully.\n");
            return;
        }
    }
    printf("Error: Record with ID %d not found.\n", id);
}

int main() {
    struct Database my_db;
    my_db.num_records = 0;

    // Load the database
    load_database(&my_db);

    // Print all records
    printf("All records in the database:\n");
    print_all_records(my_db);

    // Add a record
    struct Record new_record;
    new_record.id = 11;
    strcpy(new_record.name, "John Smith");
    new_record.age = 30;
    add_record(&my_db, new_record);
    save_database(my_db);

    // Delete a record
    delete_record(&my_db, 3);
    save_database(my_db);

    // Print the updated records
    printf("All records in the database:\n");
    print_all_records(my_db);

    return 0;
}