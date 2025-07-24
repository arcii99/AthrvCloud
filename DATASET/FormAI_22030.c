//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMN 10
#define MAX_LENGTH 100

void print_csv(char *filename);
void parse_csv_line(char *line, char data[][MAX_LENGTH], int *column_count);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: csvreader <filename>\n");
        return 1;
    }
    
    char *filename = argv[1];
    print_csv(filename);
    
    return 0;
}

/**
 * Reads and prints the contents of a CSV file
 * @param filename The name of the file to read
 */
void print_csv(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file %s\n", filename);
        return;
    }
    
    char line[MAX_COLUMN * MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        int column_count = 0;
        char data[MAX_COLUMN][MAX_LENGTH];
        parse_csv_line(line, data, &column_count);
        
        for (int i = 0; i < column_count; i++) {
            printf("%s ", data[i]);
        }
        printf("\n");
    }
    
    fclose(file);
}

/**
 * Parses a line of CSV data and populates a 2D array with the column values
 * @param line The line of CSV data
 * @param data The 2D array to populate
 * @param column_count The number of columns parsed from the line
 */
void parse_csv_line(char *line, char data[][MAX_LENGTH], int *column_count) {
    int i = 0;
    char *start = line;
    while (*line) {
        if (*line == ',' || *line == '\n') {
            strncpy(data[*column_count], start, line - start);
            data[*column_count][line - start] = '\0';
            (*column_count)++;
            start = line + 1;
        }
        line++;
    }
    strncpy(data[*column_count], start, line - start);
    data[*column_count][line - start] = '\0';
    (*column_count)++;
}