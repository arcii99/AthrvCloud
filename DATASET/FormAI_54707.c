//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_PER_LINE 1024
#define MAX_FIELDS_PER_LINE 100

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");

    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    char buffer[MAX_CHARS_PER_LINE];
    char *fields[MAX_FIELDS_PER_LINE];

    while (fgets(buffer, MAX_CHARS_PER_LINE, file)) {
        int fieldCount = 0;
        fields[fieldCount++] = strtok(buffer, ",");
        
        while (fieldCount < MAX_FIELDS_PER_LINE && (fields[fieldCount] = strtok(NULL, ","))) {
            fieldCount++;
        }

        // Do something with the fields
        // For example, print them to the console
        for (int i = 0; i < fieldCount; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}