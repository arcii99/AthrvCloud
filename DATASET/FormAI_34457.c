//FormAI DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_pointer;
    char filename[] = "example.txt";
    
    file_pointer = fopen(filename, "r");

    if (file_pointer == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, file_pointer) != NULL) {
        printf("%s", line);
    }

    if (ferror(file_pointer)) {
        fprintf(stderr, "Error occurred while reading file: %s\n", filename);
    }

    fclose(file_pointer);
    return 0;
}