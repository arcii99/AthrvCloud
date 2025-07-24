//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_ROWS 100

int read_csv(char *filename, int *cols, int *rows, char content[MAX_ROWS][MAX_COLS][100]) {
    FILE *csv_file = fopen(filename, "r");
    if (csv_file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }
    char line[500];
    int i = 0, j = 0;
    while (fgets(line, sizeof(line), csv_file) != NULL) {
        char *tok = strtok(line, ",");
        j = 0;
        while (tok != NULL) {
            strcpy(content[i][j], tok);
            tok = strtok(NULL, ",");
            j++;
        }
        i++;
    }
    *cols = j;
    *rows = i;
    fclose(csv_file);
    return 0;
}

int main() {
    char content[MAX_ROWS][MAX_COLS][100];
    int cols, rows;
    int status = read_csv("example.csv", &cols, &rows, content);
    if (status == 0) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%s\t", content[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}