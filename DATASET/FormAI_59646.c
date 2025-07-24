//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 50

typedef struct {
    int id;
    char name[50];
    int age;
    char country[50];
} Player;

typedef struct {
    int num_rows;
    int num_cols;
    char col_names[MAX_COLS][50];
    Player data[MAX_ROWS];
} CSV;

// Split a line into an array of strings based on a delimiter
void split_line(char *line, char *delim, char **values, int max_vals) {
    int i = 0;
    char *token = strtok(line, delim);
    while (token && i < max_vals) {
        values[i++] = token;
        token = strtok(NULL, delim);
    }
}

// Parse a CSV file and return the data as a CSV struct
CSV read_csv(char *file) {
    FILE *fp = fopen(file, "r");
    if (!fp) {
        printf("Error: Could not open file \"%s\"\n", file);
        exit(1);
    }

    char line[1024];
    char *values[MAX_COLS];
    CSV csv;
    csv.num_cols = 0;
    csv.num_rows = 0;

    // Parse CSV header
    if (fgets(line, 1024, fp)) {
        split_line(line, ",", csv.col_names, MAX_COLS);
        csv.num_cols = strlen(line) - strlen(strrchr(line, ','));
        if (csv.col_names[csv.num_cols - 1][strlen(csv.col_names[csv.num_cols - 1]) - 1] == '\r') {
            csv.col_names[csv.num_cols - 1][strlen(csv.col_names[csv.num_cols - 1]) - 1] = '\0';
        }
    }

    // Parse CSV data
    while (fgets(line, 1024, fp) && csv.num_rows < MAX_ROWS) {
        split_line(line, ",", values, MAX_COLS);
        csv.data[csv.num_rows].id = atoi(values[0]);
        strcpy(csv.data[csv.num_rows].name, values[1]);
        csv.data[csv.num_rows].age = atoi(values[2]);
        strcpy(csv.data[csv.num_rows].country, values[3]);
        csv.num_rows++;
    }

    fclose(fp);
    return csv;
}

// Print CSV data to console
void print_csv(CSV csv) {
    printf("%-5s %-20s %-5s %-20s\n", csv.col_names[0], csv.col_names[1], csv.col_names[2], csv.col_names[3]);
    for (int i = 0; i < csv.num_rows; i++) {
        printf("%-5d %-20s %-5d %-20s\n", csv.data[i].id, csv.data[i].name, csv.data[i].age, csv.data[i].country);
    }
}

// Main function
int main() {
    CSV csv = read_csv("players.csv");
    print_csv(csv);
    return 0;
}