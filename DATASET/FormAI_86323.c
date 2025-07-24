//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 20

int main(int argc, char const *argv[]) {

    FILE *file;
    char filename[MAX_FIELD_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *field_values[MAX_FIELDS];
    int field_count = 0;
    char *token;
    const char *delimiter = ",";
    
    printf("Enter the filename to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        exit(1);
    }

    // read each line of the file
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        field_count = 0;
        token = strtok(line, delimiter);
        
        // split line into CSV fields
        while (token != NULL && field_count < MAX_FIELDS) {
            field_values[field_count++] = token;
            token = strtok(NULL, delimiter);
        }
        
        // do something with the field values
        for (int i = 0; i < field_count; i++) {
            printf("%s\t", field_values[i]);
        }
        printf("\n");
    }

    fclose(file);

    return 0;
}