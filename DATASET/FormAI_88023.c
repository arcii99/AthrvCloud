//FormAI DATASET v1.0 Category: Data recovery tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 255
#define MAX_DATA_SIZE 1024

void recover_data(char *filename) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Failed to open file %s.\n", filename);
        return;
    }

    int file_size = 0;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    char *data = (char*) malloc(file_size * sizeof(char));
    fread(data, sizeof(char), file_size, file);
    fclose(file);

    printf("Data recovery complete. The following data was found:\n\n%s\n", data);
}

int main(int argc, char *argv[]) {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the name of the data file to recover: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);

    // strip newline character from input
    filename[strcspn(filename, "\n")] = 0;

    printf("Scanning file %s...\n", filename);
    recover_data(filename);

    return 0;
}