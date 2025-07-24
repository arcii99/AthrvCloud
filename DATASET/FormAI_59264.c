//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

int main() {
    char filename[100];
    printf("Enter the CSV file name: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_SIZE];
    int row_count = 0;
    int column_count = 0;
    while (fgets(line, MAX_LINE_SIZE, file)) {
        column_count = 0;
        row_count++;

        // Parse the line
        char* token = strtok(line, ",");
        while (token != NULL) {
            printf("%s ", token);
            column_count++;
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    printf("%d rows and %d columns\n", row_count, column_count);

    fclose(file);

    return 0;
}