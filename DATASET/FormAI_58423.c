//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

struct Record {
    int id;
    char name[20];
    char email[30];
};

struct Index {
    int key;
    int position;
};

void printRecord(struct Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Email: %s\n", record.email);
}

int createIndex(struct Record records[], struct Index index[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        index[i].key = records[i].id;
        index[i].position = i;
    }
    return size;
}

int searchRecord(struct Record records[], struct Index index[], int size, int id) {
    int i;
    for (i = 0; i < size; i++) {
        if (index[i].key == id) {
            return index[i].position;
        }
    }
    return -1;
}

void printIndex(struct Index index[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Key: %d, Position: %d\n", index[i].key, index[i].position);
    }
}

int main() {
    struct Record records[MAX_RECORDS] = {
        {1, "John Doe", "johndoe@example.com"},
        {2, "Jane Doe", "janedoe@example.com"},
        {3, "Bob Smith", "bobsmith@example.com"},
        {4, "Alice Johnson", "alicejohnson@example.com"},
        {5, "Tom Brown", "tombrown@example.com"},
        {6, "Sam Green", "samgreen@example.com"},
        {7, "Mary Lee", "marylee@example.com"},
        {8, "David Davis", "daviddavis@example.com"},
        {9, "Patricia White", "patriciawhite@example.com"},
        {10, "Richard Black", "richardblack@example.com"}
    };
    
    struct Index index[MAX_RECORDS];
    
    int indexSize = createIndex(records, index, MAX_RECORDS);
    
    printf("Index:\n");
    printIndex(index, indexSize);
    
    int searchId = 7;
    int position = searchRecord(records, index, indexSize, searchId);
    if (position == -1) {
        printf("Record not found with ID %d", searchId);
    } else {
        printf("Record found at position %d:\n", position);
        printRecord(records[position]);
    }
    
    return 0;
}