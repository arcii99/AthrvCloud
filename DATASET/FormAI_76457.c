//FormAI DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Structure to hold a record
typedef struct{
    int id;
    char name[20];
    int age;
}Record;

// Structure to hold an index entry
typedef struct{
    char name[20];
    int offset;
}Index;

void createIndex(char* filename, Index* index, int* numEntries){
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    Record record;
    int i = 0;
    while(fread(&record, sizeof(Record), 1, fp)){
        // Add index entry
        strcpy(index[i].name, record.name);
        index[i].offset = i;
        i++;
    }

    *numEntries = i;

    fclose(fp);
}

int compare(const void* a, const void* b){
    Index* indexA = (Index*)a;
    Index* indexB = (Index*)b;
    return strcmp(indexA->name, indexB->name);
}

void searchRecord(char* filename, int id){
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    Record record;
    while(fread(&record, sizeof(Record), 1, fp)){
        if(record.id == id){
            // Print record details
            printf("Record Found:\n");
            printf("ID: %d\n", record.id);
            printf("Name: %s\n", record.name);
            printf("Age: %d\n", record.age);
            break;
        }
    }

    fclose(fp);
}

int main(){
    // Create records
    Record records[MAX_RECORDS];
    for(int i=0; i<MAX_RECORDS; i++){
        records[i].id = i+1;
        sprintf(records[i].name, "Name%d", i+1);
        records[i].age = rand() % 50 + 18; // Age between 18 and 68
    }

    // Write records to file
    FILE* fp = fopen("records.dat", "wb");
    if(fp == NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    for(int i=0; i<MAX_RECORDS; i++){
        fwrite(&records[i], sizeof(Record), 1, fp);
    }

    fclose(fp);

    // Create index
    Index index[MAX_RECORDS];
    int numEntries;
    createIndex("records.dat", index, &numEntries);

    // Sort index
    qsort(index, numEntries, sizeof(Index), compare);

    // Search for record
    searchRecord("records.dat", 50);

    return 0;
}