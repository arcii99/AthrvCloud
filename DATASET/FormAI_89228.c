//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define DELIMITER ","

void readCSVFile(char *fileName) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    
    fp = fopen(fileName, "r");
    
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", fileName);
        return;
    }
    
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        char *token;
        token = strtok(buffer, DELIMITER);
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, DELIMITER);
        }
        printf("\n");
    }
    
    fclose(fp);
}

int main() {
    char fileName[20];
    
    printf("Enter the name of the CSV file to be read: ");
    scanf("%s", fileName);
    
    readCSVFile(fileName);
    
    return 0;
}