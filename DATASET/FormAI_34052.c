//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include<stdio.h>  
#include<stdlib.h> 
#include<string.h>

#define MAX_BUF_SIZE 1024
#define MAX_FIELDS 100

int main()  
{ 
    FILE *fp = NULL;
    char filename[MAX_BUF_SIZE], buffer[MAX_BUF_SIZE];
    char *field[MAX_FIELDS];
    char *record = NULL;
    int col = 0, row = 0;

    printf("Enter CSV filename to read (include .csv): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("File does not exist.\n");
        exit(0);
    }

    while(fgets(buffer, MAX_BUF_SIZE, fp)) {
        record = strtok(buffer, ",");
        col = 0;
        while(record != NULL) {
            field[col++] = record;
            record = strtok(NULL, ",");
        }

        row++;

        printf("Row %d: ", row);
        for(int i = 0; i < col; i++) {
            printf("%s\t", field[i]);
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}