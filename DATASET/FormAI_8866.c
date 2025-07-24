//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdint.h>

/* Virus signatures */
const uint8_t signature1[] = {0x12, 0x34, 0x56};
const uint8_t signature2[] = {0xde, 0xad, 0xbe, 0xef};

/* Scan function */
void scan_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return;
    }

    uint8_t buffer[1024];
    size_t bytes_read;
    size_t offset = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            if (offset + i + sizeof(signature1) <= sizeof(buffer)
                && memcmp(buffer + i, signature1, sizeof(signature1)) == 0) {
                printf("Virus signature found at offset %zu in file %s.\n",
                    offset + i, filename);
            }

            if (offset + i + sizeof(signature2) <= sizeof(buffer)
                && memcmp(buffer + i, signature2, sizeof(signature2)) == 0) {
                printf("Virus signature found at offset %zu in file %s.\n",
                    offset + i, filename);
            }
        }

        offset += bytes_read;
    }

    fclose(fp);
}

/* Main function */
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename> ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        scan_file(argv[i]);
    }

    return 0;
}