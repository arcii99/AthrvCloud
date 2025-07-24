//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELDS 50
#define DELIMITER ','

int main() {
    char filename[MAX_LINE_LENGTH] = "data.csv";
    FILE* fp;
    char line[MAX_LINE_LENGTH];
    char* fields[MAX_FIELDS];
    int num_fields;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        // Tokenize line by delimiter
        char* token = strtok(line, ",");
        num_fields = 0;
        while (token != NULL && num_fields < MAX_FIELDS) {
            fields[num_fields++] = token;
            token = strtok(NULL, ",");
        }

        // Process fields
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}