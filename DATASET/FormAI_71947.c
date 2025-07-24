//FormAI DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

int main() {
    FILE *fp;
    char file_name[] = "data.txt";
    char line[MAX_LINE_LENGTH];
    int num_of_lines = 0;

    // Open the file for reading
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }

    // Count the number of lines in the file
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        num_of_lines++;
    }

    // Allocate memory to hold all the lines
    char **data = (char **)malloc(num_of_lines * sizeof(char *));
    for (int i = 0; i < num_of_lines; i++) {
        data[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    // Reset file pointer to beginning of file
    rewind(fp);

    // Read the lines of the file into the data array
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        strcpy(data[i], line);
        i++;
    }

    // Close the file
    fclose(fp);

    // Print out the data that was read from the file
    for (int i = 0; i < num_of_lines; i++) {
        printf("%s", data[i]);
    }

    // Free allocated memory
    for (int i = 0; i < num_of_lines; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}