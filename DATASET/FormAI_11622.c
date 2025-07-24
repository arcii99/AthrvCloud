//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_COUNT 100

char** read_csv_file(char* filename, int* field_count, int* row_count) {
    FILE* file = fopen(filename, "r");
    
    // Calculate file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char* buffer = (char*) malloc(file_size + 1);
    fread(buffer, file_size, 1, file);
    buffer[file_size] = '\0';
    
    char** rows = (char**) malloc(MAX_FIELD_COUNT * sizeof(char*));
    rows[0] = strtok(buffer, "\n");
    
    *field_count = 0;
    char* ptr = strtok(rows[0], ",");
    
    while(ptr != NULL) {
        rows[++(*field_count)] = ptr;
        ptr = strtok(NULL, ",");
    }
    
    (*row_count) = 1;
    
    while((rows[(*row_count)] = strtok(NULL, "\n")) != NULL) {
        (*row_count)++;
    }
    
    fclose(file);
    
    return rows;
}

void print_csv(char** rows, int field_count, int row_count) {
    for(int i = 0; i < row_count; i++) {
        char* row = rows[i];
        printf("%s", row);
        
        if(row[strlen(row) - 1] != '\n') {
            printf("\n");
        }
    }
}

int main() {
    int field_count, row_count;
    char** rows = read_csv_file("data.csv", &field_count, &row_count);
    print_csv(rows, field_count, row_count);
    return 0;
}