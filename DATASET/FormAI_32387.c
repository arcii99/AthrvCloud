//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_NUM_FIELDS 64

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Invalid number of command line arguments\n");
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    char *field_ptrs[MAX_NUM_FIELDS];
    int num_fields;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Remove newline character from end of line
        line[strcspn(line, "\r\n")] = '\0';

        // Skip empty lines
        if (strlen(line) == 0) continue;

        // Split line into fields
        num_fields = 0;
        char *pch = strtok(line, ",");
        while (pch != NULL && num_fields < MAX_NUM_FIELDS) {
            if (strlen(pch) > MAX_FIELD_LENGTH) {
                fprintf(stderr, "Error: Field length exceeds maximum limit\n");
                exit(EXIT_FAILURE);
            }
            field_ptrs[num_fields++] = pch;
            pch = strtok(NULL, ",");
        }

        // Process fields
        for (int i = 0; i < num_fields; i++) {
            printf("%s", field_ptrs[i]);
            if (i < num_fields - 1) printf(",");
            else printf("\n");
        }
    }

    fclose(fp);
    exit(EXIT_SUCCESS);
}