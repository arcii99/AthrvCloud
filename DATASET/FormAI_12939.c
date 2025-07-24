//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 128
#define MAX_FIELDS 64

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    char *fields[MAX_FIELDS];
    int num_fields;

    FILE *fp;
    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        num_fields = 0;
        char *token = strtok(line, ",");
        while (token != NULL && num_fields < MAX_FIELDS) {
            fields[num_fields++] = token;
            token = strtok(NULL, ",");
        }

        for (int i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n"); 
    }

    fclose(fp);

    return 0;
}