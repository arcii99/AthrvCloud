//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

void readCSVFile(char* fileName);

int main() {
    char* fileName = "./data.csv";
    
    readCSVFile(fileName);
    
    return 0;
}

void readCSVFile(char* fileName) {
    FILE* file = fopen(fileName, "r");
    char line[MAX_LINE_LENGTH];
    char* field;
    int row = 0;
    
    if(!file) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    printf("Reading file: %s\n", fileName);
    
    while(fgets(line, MAX_LINE_LENGTH, file)) {
        printf("\nRow %d:\n", ++row);
        field = strtok(line, ",");
        while(field) {
            printf("     %s\n", field);
            field = strtok(NULL, ",");
        }
    }
    
    fclose(file);
}