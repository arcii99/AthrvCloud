//FormAI DATASET v1.0 Category: Data recovery tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C Data Recovery Tool!\n");
    printf("Please enter the name of the file you wish to recover:\n");

    char filepath[100];
    scanf("%s", filepath);

    FILE* file = fopen(filepath, "r");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // Find file size
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // Allocate memory for file contents
    char* contents = (char*)malloc(size * sizeof(char));

    // Read file contents into memory
    fread(contents, sizeof(char), size, file);

    printf("File contents:\n%s\n", contents);

    // Close file and free memory
    fclose(file);
    free(contents);

    printf("File recovery successful!\n");

    return 0;
}