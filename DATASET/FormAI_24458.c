//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FIELDS 20
#define MAX_FIELD_LEN 100

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    char filename[MAX_FIELD_LEN];
    strncpy(filename, argv[1], MAX_FIELD_LEN);

    FILE *csv_file = fopen(filename, "r");
    if (!csv_file) {
        printf("Error: Could not open file %s\n", filename);
        return 2;
    }

    char line[MAX_FIELDS*MAX_FIELD_LEN];
    char *field_ptrs[MAX_FIELDS];
    char *token;
    int num_fields;
    char delim[] = ",\n";

    while (fgets(line, MAX_FIELDS*MAX_FIELD_LEN, csv_file)) {
        num_fields = 0;

        token = strtok(line, delim);
        while (token != NULL && num_fields < MAX_FIELDS) {
            field_ptrs[num_fields] = token;
            num_fields++;
            token = strtok(NULL, delim);
        }

        if (num_fields > 0) {
            printf("Record:\n");
            for (int i = 0; i < num_fields; i++) {
                printf("\tField #%d: %s\n", i+1, field_ptrs[i]);
            }
        }
    }

    fclose(csv_file);
    return 0;
}