//FormAI DATASET v1.0 Category: Data mining ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 1000

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please enter filename as argument.\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char *lines[MAX_NUM_LINES];
    int num_lines = 0;

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, fp)) {
        char *line = strdup(buffer);
        lines[num_lines++] = line;
    }

    fclose(fp);

    // Data mining calculation
    int sum = 0;
    for (int i = 0; i < num_lines; i++) {
        char *line = lines[i];
        int value = atoi(line);
        sum += value;
    }

    printf("Sum of all values in file: %d\n", sum);

    // Free allocated memory
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }

    return 0;
}