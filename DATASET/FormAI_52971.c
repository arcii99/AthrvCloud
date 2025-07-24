//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_FIELDS 128
#define DELIMITER ","

int main(int argc, char *argv[]) {
    FILE *csv_file;
    char line[MAX_LINE];
    char *field[MAX_FIELDS];
    int num_fields;
    
    if (argc < 2) {
        printf("Usage: %s <csv_file_path>\n", argv[0]);
        return 1;
    }

    csv_file = fopen(argv[1], "r");
    if (!csv_file) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE, csv_file)) {
        num_fields = 0;
        field[num_fields] = strtok(line, DELIMITER);
        while (field[num_fields] && num_fields < MAX_FIELDS) {
            num_fields++;
            field[num_fields] = strtok(NULL, DELIMITER);
        }
        
        // Print the fields
        for (int i = 0; i < num_fields; i++) {
            printf("%s\t", field[i]);
        }
        printf("\n");
    }

    fclose(csv_file);
    return 0;
}