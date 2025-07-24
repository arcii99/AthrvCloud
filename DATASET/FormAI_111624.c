//FormAI DATASET v1.0 Category: Database Indexing System ; Style: excited
#include<stdio.h>
#include<string.h>

struct Database {
    char name[20];
    int age;
    char gender;
};

struct Index {
    char indexName[20];
    int position;
};

struct Index indexList[100];
int indexCount = 0;

int main() {
    struct Database records[5] = {
        {"John", 25, 'M'},
        {"Anna", 33, 'F'},
        {"Emma", 19, 'F'},
        {"Mike", 41, 'M'},
        {"Oliver", 27, 'M'}
    };

    // Creating an index for the 'name' field
    char fieldName[20] = "name";
    for (int i = 0; i < 5; i++) {
        struct Index index;
        strcpy(index.indexName, records[i].name);
        index.position = i;
        indexList[indexCount++] = index;
    }

    // Searching for all records with name 'Anna'
    for (int i = 0; i < indexCount; i++) {
        if (strcmp(indexList[i].indexName, "Anna") == 0) {
            printf("Record found at position %d\n", indexList[i].position);
            struct Database record = records[indexList[i].position];
            printf("Name: %s\nAge: %d\nGender: %c\n", record.name, record.age, record.gender);
        }
    }

    return 0;
}