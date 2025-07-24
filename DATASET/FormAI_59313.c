//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_csv(char* filename){
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char field[255];
    char line[1024];
    int num_fields = 0;
    int num_lines = 0;

    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline
        line[strcspn(line, "\n")] = 0;
        num_lines++;

        char* ptr = line;
        while (ptr) {
            // Find next comma or end of line
            char* comma = strchr(ptr, ',');
            if (comma) {
                int len = comma - ptr;
                strncpy(field, ptr, len);
                field[len] = 0;
                ptr = comma + 1;
            } else {
                strcpy(field, ptr);
                ptr = NULL;
            }
            num_fields++;
            printf("%s\n", field);
        }
    }

    printf("Read %d lines and %d fields from file: %s\n", num_lines, num_fields, filename);
    fclose(file);
}

int main(){
    parse_csv("example.csv");
    return 0;
}