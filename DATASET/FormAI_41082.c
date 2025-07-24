//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct record {
    char name[20];
    int age;
    char occupation[20];
};

int main() {
    FILE *fp;
    char filename[20];
    printf("Enter the CSV filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    int count = 0;
    char buffer[100];
    char *token;
    struct record records[50];
    fgets(buffer, 100, fp); // skip header line
    while (fgets(buffer, 100, fp)) {
        token = strtok(buffer, ",");
        strcpy(records[count].name, token);
        token = strtok(NULL, ",");
        records[count].age = atoi(token);
        token = strtok(NULL, ",");
        strcpy(records[count].occupation, token);
        count++;
    }
    fclose(fp);
    printf("CSV file read successfully!\n");
    printf("Records:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\nAge: %d\nOccupation: %s\n", 
               records[i].name, records[i].age, records[i].occupation);
    }
    return 0;
}