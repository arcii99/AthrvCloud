//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX_LINE_LENGTH 1024

int main(int argc, char** argv) {

    if(argc != 2){
        printf("Please provide the CSV file name as an argument.\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Failed to open file: %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *temp;
    int row_count = 0;
    int col_count = 0;

    // Get the number of columns in the first row
    if(fgets(line, MAX_LINE_LENGTH, fp) != NULL){
        temp = strtok(line, ",");
        while(temp != NULL){
            col_count++;
            temp = strtok(NULL, ",");
        }
        row_count++;
    }

    // Read and print the rest of the rows
    while(fgets(line, MAX_LINE_LENGTH, fp) != NULL){

        temp = strtok(line, ",");
        col_count = 0;

        while(temp != NULL){
            printf("%s,", temp);
            temp = strtok(NULL, ",");
            col_count++;
        }

        printf("\n");
        row_count++;
    }

    printf("\n");

    fclose(fp);

    printf("Total number of rows: %d\n", row_count);
    printf("Total number of columns: %d\n", col_count);

    return 0;
}