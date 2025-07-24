//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    unsigned char checksum = 0;
    unsigned char byte;
    while ((byte = fgetc(file)) != EOF) {
        checksum += byte;
    }

    fclose(file);

    printf("Checksum of %s: 0x%02x\n", argv[1], checksum);

    return 0;
}