//FormAI DATASET v1.0 Category: Data recovery tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

FILE *findFile(const char *filename, const char *mode) {
    FILE *file = NULL;
    file = fopen(filename, mode);
    if(file == NULL) {
        printf("Error: cannot open file %s\n", filename);
    }
    return file;
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Invalid usage: enter input and output file names\n");
        exit(1);
    }
    const char* in_fname = argv[1];
    const char* out_fname = argv[2];

    FILE *in_file = findFile(in_fname, "rb");
    FILE *out_file = findFile(out_fname, "wb");

    if(in_file == NULL || out_file == NULL) {
        exit(1);
    }

    char buffer[512];
    size_t bytes_read = 0;

    while((bytes_read = fread(buffer, sizeof(char), 512, in_file))) {
        fwrite(buffer, sizeof(char), bytes_read, out_file);
    }

    printf("File %s was successfully recovered to %s.\n", in_fname, out_fname);

    fclose(in_file);
    fclose(out_file);

    return 0;
}