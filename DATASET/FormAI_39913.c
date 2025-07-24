//FormAI DATASET v1.0 Category: Database querying ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_SIZE 100
#define MAX_RECORDS 1000

typedef struct{
    int id;
    char name[MAX_FIELD_SIZE];
    char email[MAX_FIELD_SIZE];
    int age;
} Record;

int main() {
    // Initialize an array to store all records
    Record database[MAX_RECORDS];
    memset(database, 0, sizeof(database));
    int num_records = 0;

    // Load data from database file
    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char line[MAX_FIELD_SIZE];
    while (fgets(line, MAX_FIELD_SIZE, fp) != NULL) {
        char *token = strtok(line, ",");
        database[num_records].id = atoi(token);
        token = strtok(NULL, ",");
        strncpy(database[num_records].name, token, MAX_FIELD_SIZE);
        token = strtok(NULL, ",");
        strncpy(database[num_records].email, token, MAX_FIELD_SIZE);
        token = strtok(NULL, ",");
        database[num_records].age = atoi(token);
        num_records++;
    }
    fclose(fp);

    // Query records based on user input
    char search_name[MAX_FIELD_SIZE];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    printf("\nResults for %s:\n", search_name);
    int found_records = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, search_name) == 0) {
            printf("ID: %d\nName: %s\nEmail: %s\nAge: %d\n\n", 
                    database[i].id, database[i].name, database[i].email, database[i].age);
            found_records++;
        }
    }
    if (found_records == 0) {
        printf("No records found for %s.\n", search_name);
    }

    return 0;
}