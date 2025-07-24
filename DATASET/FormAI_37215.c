//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER ','

int main() {
    FILE *fp;
    char fileName[50], line[1000];

    printf("Enter the filename: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    printf("\nFile contents:\n");

    while(fgets(line, 1000, fp)) {
        char *token = strtok(line, ",");
        while(token != NULL) {
            printf("%s", token);
            token = strtok(NULL, ",");
            if(token != NULL) {
                printf("%c", DELIMITER);
            }
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}