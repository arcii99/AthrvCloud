//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50

typedef struct Record {
    char name[MAX_NAME_LENGTH];
    int id;
    int age;
    float salary;
} Record;

typedef struct Index {
    int key;
    int value;
} Index;

char* getRandomName() {
    char *names[] = {"Alex", "Bridgette", "Charlie", "Diana", "Eric", "Felicia", "George", "Helen", "Isaac", "Jade"};
    return names[rand() % 10];
}

void generateRandomData(Record records[]) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        strcpy(records[i].name, getRandomName());
        records[i].id = 1000 + i;
        records[i].age = rand() % 50 + 20;
        records[i].salary = rand() % 100000;
    }
}

void printRecord(Record record) {
    printf("%d\t%s\t%d\t%.2f\n", record.id, record.name, record.age, record.salary);
}

void printIndex(Index index) {
    printf("%d\t%d\n", index.key, index.value);
}

void printRecords(Record records[], int size) {
    printf("ID\tName\tAge\tSalary\n");
    for (int i = 0; i < size; i++) {
        printRecord(records[i]);
    }
}

void printIndexes(Index indexes[], int size) {
    printf("Key\tValue\n");
    for (int i = 0; i < size; i++) {
        printIndex(indexes[i]);
    }
}

void insertionSort(Index indexes[], int size) {
    for (int i = 1; i < size; i++) {
        Index temp = indexes[i];
        int j = i - 1;
        while (j >= 0 && indexes[j].key > temp.key) {
            indexes[j + 1] = indexes[j];
            j--;
        }
        indexes[j + 1] = temp;
    }
}

int binarySearch(Record records[], int size, int id) {
    int start = 0;
    int end = size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (records[mid].id == id) {
            return mid;
        } else if (records[mid].id < id) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

void createIndex(Record records[], int size, Index indexes[]) {
    for (int i = 0; i < size; i++) {
        indexes[i].key = records[i].id;
        indexes[i].value = i;
    }
    insertionSort(indexes, size);
}

void searchRecords(Record records[], int size, Index indexes[], int num_queries, int queries[]) {
    for (int i = 0; i < num_queries; i++) {
        int index = binarySearch(records, size, queries[i]);
        if (index >= 0) {
            printf("Record Found:\n");
            printRecord(records[index]);
        } else {
            printf("Record Not Found for ID = %d\n", queries[i]);
        }
    }
}

int main() {
    srand(time(NULL));
    Record records[MAX_RECORDS];
    generateRandomData(records);
    printf("Initial Records:\n");
    printRecords(records, MAX_RECORDS);
    Index indexes[MAX_RECORDS];
    createIndex(records, MAX_RECORDS, indexes);
    printf("\nIndexes:\n");
    printIndexes(indexes, MAX_RECORDS);
    int queries[] = {1000, 1032, 1056, 1089};
    int num_queries = sizeof(queries) / sizeof(queries[0]);
    printf("\nSearching Records:\n");
    searchRecords(records, MAX_RECORDS, indexes, num_queries, queries);
    return 0;
}