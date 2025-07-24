//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: real-life
#include <stdio.h>

#define BUFFER_SIZE 1024

unsigned int calculate_checksum(char* buffer, int size) {
    unsigned int checksum = 0;
    int i;

    for (i = 0; i < size; i++) {
        checksum += buffer[i];
    }

    return checksum;
}

int main(int argc, char** argv) {
    char buffer[BUFFER_SIZE];
    int size = 0;
    unsigned int checksum;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    while (!feof(file)) {
        size += fread(buffer + size, 1, BUFFER_SIZE - size, file);
        if (size >= BUFFER_SIZE) {
            checksum += calculate_checksum(buffer, size);
            size = 0;
        }
    }

    if (size > 0) {
        checksum += calculate_checksum(buffer, size);
    }

    printf("Checksum of %s is %u\n", argv[1], checksum);

    fclose(file);
    return 0;
}