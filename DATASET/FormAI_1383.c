//FormAI DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    float score;
} Record;

Record records[MAX_RECORDS];
int numRecords = 0;

void printRecords() {
    printf("Name      ID      Score\n");
    for(int i = 0; i < numRecords; i++) {
        printf("%-10s%-8d%-6.2f\n", records[i].name, records[i].id, records[i].score);
    }
}

void addRecord(char *name, int id, float score) {
    if(numRecords < MAX_RECORDS) {
        strncpy(records[numRecords].name, name, MAX_NAME_LENGTH);
        records[numRecords].id = id;
        records[numRecords].score = score;
        numRecords++;
    } else {
        printf("Database full!\n");
    }
}

void removeRecord(int id) {
    int index = -1;
    for(int i = 0; i < numRecords; i++) {
        if(records[i].id == id) {
            index = i;
            break;
        }
    }
    if(index != -1) {
        for(int i = index; i < numRecords - 1; i++) {
            records[i] = records[i + 1];
        }
        numRecords--;
    } else {
        printf("Record not found!\n");
    }
}

void updateRecord(int id, float newScore) {
    int index = -1;
    for(int i = 0; i < numRecords; i++) {
        if(records[i].id == id) {
            index = i;
            break;
        }
    }
    if(index != -1) {
        records[index].score = newScore;
    } else {
        printf("Record not found!\n");
    }
}

int main() {
    addRecord("Alice", 1001, 87.5);
    addRecord("Bob", 1002, 92.3);
    addRecord("Charlie", 1003, 78.9);

    printf("Initial Database:\n");
    printRecords();

    printf("\nRemoving record with ID 1002...\n");
    removeRecord(1002);
    printRecords();

    printf("\nAdding record for Eve...\n");
    addRecord("Eve", 1004, 95.4);
    printRecords();

    printf("\nUpdating score for Charlie...\n");
    updateRecord(1003, 81.2);
    printRecords();

    printf("\nAttempting to add record for Frank (database full)...\n");
    addRecord("Frank", 1005, 79.1);
    printRecords();

    return 0;
}