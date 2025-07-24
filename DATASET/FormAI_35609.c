//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

unsigned short calculate_checksum(FILE *fp) {
    unsigned long sum = 0;
    unsigned short word;
    char buffer[BUFFER_SIZE];
    size_t count;
    while ((count = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        for (size_t i = 0; i < count; i += 2) {
            word = (buffer[i] << 8);
            if (i + 1 < count) {
                word |= buffer[i+1];
            }
            sum += word;
        }
    }
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    return (unsigned short) ~sum;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    unsigned short checksum = calculate_checksum(fp);
    fclose(fp);
    printf("Checksum: 0x%04X\n", checksum);
    return EXIT_SUCCESS;
}