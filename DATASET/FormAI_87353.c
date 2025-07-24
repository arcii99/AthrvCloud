//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char file_name[MAX_LINE_LENGTH], line[MAX_LINE_LENGTH], *token;
    FILE *file;
    int line_num = 0;

    printf("Enter CSV file name: ");
    scanf("%s", file_name);

    file = fopen(file_name, "r");
    if (!file) {
        printf("Error opening file: %s\n", file_name);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        line_num++;
        printf("Line %d:\n", line_num);

        token = strtok(line, ",");
        while (token != NULL) {
            printf("    %s\n", token);
            token = strtok(NULL, ",");
        }
    }

    fclose(file);
    return 0;
}