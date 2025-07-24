//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COL 50
#define MAX_ROW 100

typedef struct {
    size_t size;
    char* data;
} string_t;

typedef struct {
    int num_cols;
    string_t header[MAX_COL];
    string_t data[MAX_ROW][MAX_COL];
} csv_t;

string_t read_line(FILE* file);
csv_t read_csv(char* filename);

int main() {
    csv_t csv = read_csv("sample.csv");
    
    // Print column headers
    for (int i = 0; i < csv.num_cols; i++) {
        printf("%s", csv.header[i].data);
        if (i < csv.num_cols - 1) printf(",");
    }
    printf("\n");
    
    // Print data rows
    for (int i = 0; i < MAX_ROW && csv.data[i][0].size > 0; i++) {
        for (int j = 0; j < csv.num_cols; j++) {
            printf("%s", csv.data[i][j].data);
            if (j < csv.num_cols - 1) printf(",");
        }
        printf("\n");
    }
    
    return 0;
}

string_t read_line(FILE* file) {
    string_t line = {0};
    size_t len = 0;
    ssize_t read = getline(&line.data, &len, file);
    if (read == -1) {
        free(line.data);
        line.size = 0;
        return line;
    }
    line.size = read;
    if (line.data[line.size-1] == '\n') {
        line.size--;
        line.data[line.size] = 0;
    }
    return line;
}

csv_t read_csv(char* filename) {
    csv_t csv = {0};
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return csv;
    }
    // Read column headers
    string_t line = read_line(file);
    char* tok; int i = 0;
    do {
        tok = strtok(line.data, ",");
        if (tok) {
            csv.header[i].size = strlen(tok);
            csv.header[i].data = malloc(csv.header[i].size+1);
            memcpy(csv.header[i].data, tok, csv.header[i].size+1);
            i++;
        }
        line = read_line(file);
    } while (tok && i < MAX_COL);
    csv.num_cols = i;
    // Read data rows
    int j = 0;
    while (j < MAX_ROW && line.size > 0) {
        i = 0;
        do {
            if (i >= csv.num_cols) break;
            if (line.size == 0) break; // Last column empty
            csv.data[j][i].size = strlen(line.data);
            csv.data[j][i].data = malloc(csv.data[j][i].size+1);
            memcpy(csv.data[j][i].data, line.data, csv.data[j][i].size+1);
            i++;
        } while ((tok = strtok(NULL, ",")));
        j++;
        line = read_line(file);
    }
    fclose(file);
    return csv;
}