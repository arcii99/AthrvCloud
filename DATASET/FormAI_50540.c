//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: program.exe <source_file> <destination_file>\n");

        return EXIT_FAILURE;
    }

    FILE* source = fopen(argv[1], "rb");
    FILE* destination = fopen(argv[2], "wb");

    if(!source || !destination) {
        printf("Error: Could not open files.\n");

        return EXIT_FAILURE;
    }

    char* buffer = (char*) malloc(sizeof(char) * 512);

    if(!buffer) {
        printf("Error: Could not allocate memory.\n");

        return EXIT_FAILURE;
    }

    size_t read_bytes;

    while((read_bytes = fread(buffer, sizeof(char), 512, source)) > 0) {
        fwrite(buffer, sizeof(char), read_bytes, destination);
    }

    free(buffer);
    fclose(source);
    fclose(destination);

    printf("Done.");

    return EXIT_SUCCESS;
}