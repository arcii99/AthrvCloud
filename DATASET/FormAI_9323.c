//FormAI DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

void read_file(FILE *file_ptr, char lines[MAX_LINES][MAX_LENGTH], int *num_lines);
void remove_repeated_lines(char lines[MAX_LINES][MAX_LENGTH], int *num_lines);
void sort_lines(char lines[MAX_LINES][MAX_LENGTH], int num_lines);

int main() {
    char lines[MAX_LINES][MAX_LENGTH];
    int num_lines = 0;
    FILE *file_ptr;

    file_ptr = fopen("input.txt", "r"); // Open the file for reading

    if (file_ptr == NULL) {
        printf("Error: Could not open input file\n");
        exit(1);
    }

    read_file(file_ptr, lines, &num_lines);

    fclose(file_ptr); // Close the file

    remove_repeated_lines(lines, &num_lines);

    sort_lines(lines, num_lines);

    printf("Sorted lines with no repeated lines:\n");
    for (int i = 0; i < num_lines; i++) {
        printf("%s", lines[i]);
    }

    return 0;
}

/**
 * Reads each line from a file and stores them in an array of strings.
 * @param file_ptr pointer to a file
 * @param lines array of strings to store the lines read from the file
 * @param num_lines pointer to the number of lines read from the file
 */
void read_file(FILE *file_ptr, char lines[MAX_LINES][MAX_LENGTH], int *num_lines) {
    char line[MAX_LENGTH];

    while (fgets(line, MAX_LENGTH, file_ptr) != NULL) {
        strcpy(lines[*num_lines], line);
        (*num_lines)++;
    }
}

/**
 * Removes duplicate lines from an array of strings.
 * @param lines array of strings to remove duplicates from
 * @param num_lines pointer to the number of lines in the array
 */
void remove_repeated_lines(char lines[MAX_LINES][MAX_LENGTH], int *num_lines) {
    int i, j;

    for (i = 0; i < *num_lines; i++) {
        for (j = i+1; j < *num_lines;) {
            if (strcmp(lines[i], lines[j]) == 0) { // Found a duplicate line
                (*num_lines)--;
                strcpy(lines[j], lines[*num_lines]);
            } else {
                j++;
            }
        }
    }
}

/**
 * Sorts an array of strings in ascending order.
 * @param lines array of strings to sort
 * @param num_lines the number of lines in the array
 */
void sort_lines(char lines[MAX_LINES][MAX_LENGTH], int num_lines) {
    int i, j;
    char temp[MAX_LENGTH];

    for (i = 0; i < num_lines-1; i++) {
        for (j = i+1; j < num_lines; j++) {
            if (strcmp(lines[i], lines[j]) > 0) { // Swap lines i and j
                strcpy(temp, lines[i]);
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], temp);
            }
        }
    }
}