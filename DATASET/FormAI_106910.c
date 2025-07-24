//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 10

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];
    char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
    int num_fields;

    if(argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while(fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        num_fields = 0;
        
        // split the line into fields
        char *field = strtok(line, ",");
        while(field != NULL && num_fields < MAX_FIELDS) {
            strcpy(fields[num_fields++], field);
            field = strtok(NULL, ",");
        }
        
        // print the fields
        for(int i=0; i<num_fields; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}