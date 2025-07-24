//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10

int main(int argc, const char * argv[]) {

    FILE *file = fopen("example.csv", "r");

    if (file != NULL) {

        char line[MAX_LINE_LENGTH];
        char * field;

        while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {

            field = strtok(line, ","); 
            while (field != NULL) {
                printf("%s ", field);
                field = strtok(NULL, ",");
            }
            printf("\n");
        }

        fclose(file);
        return 0;

    } else {
        printf("Could not open file.");
        return 1;
    }
}