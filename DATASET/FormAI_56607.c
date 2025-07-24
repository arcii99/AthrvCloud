//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("ERROR: Must provide a filename to calculate checksum.\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "rb"); // Open file in binary mode
    if (!file) {
        printf("ERROR: Failed to open file %s.\n", argv[1]);
        return 1;
    }

    unsigned int checksum = 0;
    char buffer[1024];
    size_t numRead;

    while ((numRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < numRead; i++) {
            checksum += buffer[i];
        }
    }

    printf("Checksum of file %s is %u.\n", argv[1], checksum);

    fclose(file);
    return 0;
}