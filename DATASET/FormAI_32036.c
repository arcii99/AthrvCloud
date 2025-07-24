//FormAI DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_ATTRIBUTES 50
#define MAX_ATTR_LENGTH 20

// data structure to store individual records
typedef struct record {
    int id;
    char attributes[MAX_ATTRIBUTES][MAX_ATTR_LENGTH];
} Record;

// data structure to store the entire dataset
typedef struct dataset {
    Record records[MAX_RECORDS];
    int numRecords;
    int numAttributes;
} Dataset;

// function to load dataset from file
Dataset loadDataset(char* filename) {
    Dataset dataset;
    FILE* fp;
    char line[1024];
    char* token;
    char* delim = ",";
    int i = 0;
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not load dataset from file '%s'\n", filename);
        exit(1);
    }
    
    // read the first line to get attribute names
    fgets(line, 1024, fp);
    token = strtok(line, delim);
    while (token != NULL) {
        strcpy(dataset.records[0].attributes[i], token);
        token = strtok(NULL, delim);
        i++;
    }
    dataset.numAttributes = i;
    dataset.numRecords = 0;
    
    // read the rest of the lines to get record data
    while (fgets(line, 1024, fp)) {
        i = 0;
        token = strtok(line, delim);
        dataset.records[dataset.numRecords].id = dataset.numRecords;
        while (token != NULL && i < dataset.numAttributes) {
            strcpy(dataset.records[dataset.numRecords].attributes[i], token);
            token = strtok(NULL, delim);
            i++;
        }
        dataset.numRecords++;
    }
    
    fclose(fp);
    return dataset;
}

// function to print the dataset
void printDataset(Dataset dataset) {
    int i, j;
    for (i = 0; i < dataset.numRecords; i++) {
        printf("%d,", dataset.records[i].id);
        for (j = 0; j < dataset.numAttributes; j++) {
            printf("%s,", dataset.records[i].attributes[j]);
        }
        printf("\n");
    }
}

// main function to load and print the dataset
int main() {
    Dataset dataset = loadDataset("example.csv");
    printDataset(dataset);
    return 0;
}