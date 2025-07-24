//FormAI DATASET v1.0 Category: Database simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 50
#define MAX_NAME_LENGTH 20
#define MAX_ID_LENGTH 10

typedef struct {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
} Record;

typedef struct {
    Record table[MAX_TABLE_SIZE];
    int num_records;
} Database;

void createRecord(Database *db, char *id, char *name) {
    if (db->num_records >= MAX_TABLE_SIZE) {
        printf("[ERROR] Database is full.\n");
        exit(1);
    }
    if (strlen(id) >= MAX_ID_LENGTH) {
        printf("[ERROR] ID length is too long.\n");
        exit(1);
    }
    if (strlen(name) >= MAX_NAME_LENGTH) {
        printf("[ERROR] Name length is too long.\n");
        exit(1);
    }
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->table[i].id, id) == 0) {
            printf("[ERROR] ID already exists.\n");
            exit(1);
        }
    }
    strcpy(db->table[db->num_records].id, id);
    strcpy(db->table[db->num_records].name, name);
    db->num_records++;
}

void deleteRecord(Database *db, char *id) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->table[i].id, id) == 0) {
            db->num_records--;
            for (int j = i; j < db->num_records; j++) {
                strcpy(db->table[j].id, db->table[j+1].id);
                strcpy(db->table[j].name, db->table[j+1].name);
            }
            printf("Record with ID %s deleted.\n", id);
            return;
        }
    }
    printf("[ERROR] Record with ID %s not found.\n", id);
}

Record *searchRecord(Database *db, char *id) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->table[i].id, id) == 0) {
            return &db->table[i];
        }
    }
    printf("[ERROR] Record with ID %s not found.\n", id);
    exit(1);
}

int main() {
    Database my_database = {0};
    createRecord(&my_database, "001", "Alice");
    createRecord(&my_database, "002", "Bob");
    createRecord(&my_database, "003", "Charlie");
    
    Record *record;
    record = searchRecord(&my_database, "002");
    printf("Record found: %s, %s\n", record->id, record->name);
    
    deleteRecord(&my_database, "002");
    
    record = searchRecord(&my_database, "002");

    return 0;
}