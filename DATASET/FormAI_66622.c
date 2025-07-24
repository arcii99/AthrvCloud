//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

/* Struct for database records */
typedef struct {
    int id;
    char name[20];
    int age;
} Record;

/* Struct for indexing nodes */
typedef struct node {
    int id;
    int offset;
    struct node* next;
} Node;

/* Global variables for database and index */
Record db[SIZE];
Node* index[SIZE];

/* Function to add record to database */
void addRecord(int id, char name[], int age) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (db[i].id == 0) {
            db[i].id = id;
            strcpy(db[i].name, name);
            db[i].age = age;
            break;
        }
    }
}

/* Function to create index for database */
void createIndex() {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (db[i].id != 0) {
            int indexPos = db[i].id % SIZE;
            Node* newNode = malloc(sizeof(Node));
            newNode->id = db[i].id;
            newNode->offset = i;
            newNode->next = NULL;
            if (index[indexPos] == NULL) {
                index[indexPos] = newNode;
            } else {
                Node* cur = index[indexPos];
                while (cur->next != NULL) {
                    cur = cur->next;
                }
                cur->next = newNode;
            }
        }
    }
}

/* Function to get record from database using index */
Record getRecord(int id) {
    int indexPos = id % SIZE;
    Node* cur = index[indexPos];
    while (cur != NULL) {
        if (cur->id == id) {
            int offset = cur->offset;
            Record record = db[offset];
            return record;
        }
        cur = cur->next;
    }
    /* Return empty record if not found */
    Record emptyRecord;
    emptyRecord.id = 0;
    return emptyRecord;
}

/* Testing */
int main() {
    addRecord(1, "John", 25);
    addRecord(2, "Jane", 30);
    addRecord(3, "Bob", 40);
    createIndex();
    Record rec1 = getRecord(2);
    printf("%d %s %d\n", rec1.id, rec1.name, rec1.age);
    Record rec2 = getRecord(4);
    printf("%d %s %d\n", rec2.id, rec2.name, rec2.age);
    return 0;
}