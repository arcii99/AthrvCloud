//FormAI DATASET v1.0 Category: Database simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 30
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

void add_record(Database* db, char* name, char* phone) {
    if (db->num_records < MAX_RECORDS) {
        strcpy(db->records[db->num_records].name, name);
        strcpy(db->records[db->num_records].phone, phone);
        db->num_records++;
    } else {
        printf("Error: database is full.\n");
    }
}

bool delete_record(Database* db, int index) {
    if (index >= 0 && index < db->num_records) {
        for (int i = index; i < db->num_records - 1; i++) {
            db->records[i] = db->records[i + 1];
        }
        db->num_records--;
        return true;
    } else {
        printf("Error: invalid index.\n");
        return false;
    }
}

int find_record(Database* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void print_record(Record* record) {
    printf("Name: %s\nPhone: %s\n", record->name, record->phone);
}

void print_database(Database* db) {
    if (db->num_records == 0) {
        printf("Database is empty.\n");
    } else {
        for (int i = 0; i < db->num_records; i++) {
            printf("Record %d:\n", i + 1);
            print_record(&db->records[i]);
        }
    }
}

int main() {
    Database db = {0};
    char command;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int index;

    do {
        printf("Enter a command (a: add, d: delete, f: find, p: print, q: quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'a':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                add_record(&db, name, phone);
                break;
            case 'd':
                printf("Enter index: ");
                scanf("%d", &index);
                delete_record(&db, index - 1);
                break;
            case 'f':
                printf("Enter name: ");
                scanf("%s", name);
                index = find_record(&db, name);
                if (index == -1) {
                    printf("Record not found.\n");
                } else {
                    printf("Record found at index %d:\n", index + 1);
                    print_record(&db.records[index]);
                }
                break;
            case 'p':
                print_database(&db);
                break;
            case 'q':
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    } while (command != 'q');

    return 0;
}