//FormAI DATASET v1.0 Category: File handling ; Style: ultraprecise
#include <stdio.h>

int main() {

    // Open the file for writing
    FILE *file_pointer = fopen("example.txt", "w");

    if(file_pointer == NULL) {
        printf("Error opening file.");
        return 1;
    }

    // Write 10 lines to the file
    for(int i = 1; i <= 10; i++) {
        fprintf(file_pointer, "This is line %d.\n", i);
    }

    // Close the file
    fclose(file_pointer);

    // Open the file for reading
    file_pointer = fopen("example.txt", "r");

    if(file_pointer == NULL) {
        printf("Error opening file.");
        return 1;
    }

    // Read and print each line of the file
    char line[100];
    while(fgets(line, sizeof(line), file_pointer)) {
        printf("%s", line);
    }

    // Close the file
    fclose(file_pointer);

    return 0;
}