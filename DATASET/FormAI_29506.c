//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 128
#define MAX_FIELDS 10

int main() {
    // Open the CSV file
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 0;
    }

    // Define variables to store the data
    char line[MAX_LINE_SIZE];
    char field[MAX_FIELDS][MAX_FIELD_SIZE];
    int num_fields = 0;

    // Read each line of the CSV file
    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Split the line into fields
        char *token = strtok(line, ",");
        num_fields = 0;
        while (token != NULL) {
            strcpy(field[num_fields], token);
            num_fields++;
            token = strtok(NULL, ",");
        }

        // Print the fields
        for (int i = 0; i < num_fields; i++) {
            printf("%s", field[i]);
            if (i < num_fields-1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    // Close the CSV file
    fclose(fp);

    return 0;
}