//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

int main(int argc, char *argv[]) {
    
    // Ensure that a filename argument is provided
    if (argc != 2) {
        printf("Please provide a filename as an argument.\n");
        return 1;
    }
    
    // Open the CSV file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Unable to open file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    char *field[MAX_NUM_FIELDS];
    int num_fields;
    int i, j;

    // Read each line of the file
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        line_count++;
        num_fields = 0;

        // Split the line on commas
        field[num_fields] = strtok(line, ",");
        while (field[num_fields] && num_fields < MAX_NUM_FIELDS) {
            num_fields++;
            field[num_fields] = strtok(NULL, ",");
        }

        // Trim whitespace from each field
        for (i = 0; i < num_fields; i++) {
            j = 0;
            while (field[i][j] && (field[i][j] == ' ' || field[i][j] == '\t' || field[i][j] == '\n')) {
                j++;
            }
            memmove(field[i], field[i] + j, strlen(field[i]) - j + 1);
            for (j = strlen(field[i]) - 1; j >= 0 && (field[i][j] == ' ' || field[i][j] == '\t' || field[i][j] == '\n'); j--);
            field[i][j + 1] = '\0';
        }

        // Print the row
        printf("Row %d: ", line_count);
        for (i = 0; i < num_fields; i++) {
            printf("%s", field[i]);
            if (i < num_fields - 1) {
                printf(", ");
            }
        }
        printf("\n");       
    }    

    // Close the file
    fclose(file);
    return 0;
}