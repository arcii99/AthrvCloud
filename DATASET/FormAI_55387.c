//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 1024

int main() {
    char filename[MAXLINE];
    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Could not open file!");
        return 1;
    }

    char line[MAXLINE];
    char *field;
    char *rest = NULL;
    char delim[] = ",";
    int count = 0;

    while(fgets(line, MAXLINE, fp)) {
        field = strtok_r(line, delim, &rest);
        while(field) {
            printf("%s", field);
            field = strtok_r(NULL, delim, &rest);
            if(field) {
                printf(", ");
            }
            count++;
        }
        printf("\n");
    }

    fclose(fp);
    printf("Total fields: %d", count);
    return 0;
}