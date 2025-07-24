//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

// Step 1: Implement the modular logic to calculate the checksum
BYTE calc_checksum(BYTE* data, size_t len) {
    BYTE sum = 0;
    for (int i = 0; i < len; i++) {
        sum += data[i];
    }
    return ~sum + 1;
}

// Step 2: Implement the main function to accept input and print output
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Step 3: Open the file and read the contents
    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: Failed to open file '%s'\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t len = ftell(file);
    fseek(file, 0, SEEK_SET);

    BYTE* data = (BYTE*) malloc(len * sizeof(BYTE));
    if (!data) {
        printf("Error: Failed to allocate memory for data\n");
        fclose(file);
        return 1;
    }

    if (fread(data, sizeof(BYTE), len, file) != len) {
        printf("Error: Failed to read file '%s'\n", argv[1]);
        fclose(file);
        free(data);
        return 1;
    }

    fclose(file);

    // Step 4: Calculate the checksum and print the output
    BYTE checksum = calc_checksum(data, len);

    printf("Checksum for file '%s': 0x%02X\n", argv[1], checksum);

    free(data);
    return 0;
}