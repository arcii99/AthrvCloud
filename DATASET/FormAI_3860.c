//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 128
#define MAX_FIELDS 10

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename.csv\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    char *fields[MAX_FIELDS];
    int num_fields;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        num_fields = 0;
        fields[num_fields] = strtok(buffer, ",");
        while (fields[num_fields] && num_fields < MAX_FIELDS - 1) {
            num_fields++;
            fields[num_fields] = strtok(NULL, ",");
        }

        for (int i = 0; i < num_fields; i++) {
            printf("%s\t", fields[i]);
        }
        printf("\n");
    }

    fclose(file);

    return 0;
}