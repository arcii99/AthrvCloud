//FormAI DATASET v1.0 Category: Data recovery tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_DATA_LENGTH 1024

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char data[MAX_DATA_LENGTH];
    int length;
} File;

typedef struct {
    File* files;
    int num_files;
} Dir;

void recover_data(Dir* directory);

int main() {
    Dir directory;
    directory.num_files = 0;
    directory.files = NULL;

    /* code to read in directory contents and populate directory struct*/

    recover_data(&directory);

    /* code to write recovered data to output files */
    
    return 0;
}

void recover_data(Dir* directory) {
    int i;
    FILE* file;
    for (i = 0; i < directory->num_files; i++) {
        file = fopen(directory->files[i].filename, "rb");
        if (file == NULL) {
            perror("Error opening file");
            continue;
        }
        fseek(file, 0, SEEK_END);
        int file_length = ftell(file);
        rewind(file);
        char file_data[file_length];
        int read_bytes = fread(file_data, sizeof(char), file_length, file);
        if (read_bytes < file_length) {
            fprintf(stderr, "Error reading file: %s\n", directory->files[i].filename);
            continue;
        }
        directory->files[i].length = read_bytes;
        memcpy(directory->files[i].data, file_data, read_bytes);
        fclose(file);
    }
}