//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_FIELD_SIZE 20
#define MAX_FIELDS 10

int main() {

    FILE *csv_file;
    char buffer[MAX_BUFFER_SIZE];
    char *fields[MAX_FIELDS];
    int i, j, num_fields;

    csv_file = fopen("example.csv", "r");

    if (csv_file == NULL) {
        printf("Could not open file!");
        exit(1);
    }

    while (fgets(buffer, MAX_BUFFER_SIZE, csv_file)) {
        num_fields = 0;
        fields[num_fields] = strtok(buffer, ",");
        while (fields[num_fields] != NULL && num_fields < MAX_FIELDS) {
            num_fields++;
            fields[num_fields] = strtok(NULL, ",");
        }
        if (num_fields > MAX_FIELDS) {
            printf("Too many fields in row\n");
            continue;
        }
        for (i = 0; i < num_fields; i++) {
            for (j = 0; fields[i][j] != '\0'; j++) {
                if (fields[i][j] == '\n') {
                    fields[i][j] = '\0';
                    break;
                }
            }
            printf("%s,", fields[i]);
        }
        printf("\n");
    }

    fclose(csv_file);

    return 0;
}