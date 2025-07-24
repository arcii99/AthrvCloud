//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>

#define BLOCK_SIZE 512

typedef struct {
    uint32_t sum1;
    uint32_t sum2;
    char *buffer;
    size_t length;
} ChecksumData;

void *calculate_checksum(void *arg) {
    ChecksumData *data = (ChecksumData *) arg;
    uint32_t sum1 = data->sum1;
    uint32_t sum2 = data->sum2;
    char *buffer = data->buffer;
    size_t length = data->length;

    for (size_t i = 0; i < length; i++) {
        sum1 = (sum1 + buffer[i]) % 65521;
        sum2 = (sum2 + sum1) % 65521;
    }

    data->sum1 = sum1;
    data->sum2 = sum2;
    return NULL;
}

bool calculate_file_checksum(char *filename, uint32_t *checksum1, uint32_t *checksum2) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return false;
    }

    uint32_t sum1 = 0;
    uint32_t sum2 = 0;

    char buffer[BLOCK_SIZE];
    size_t bytes_read = 0;
    ChecksumData data;
    data.sum1 = sum1;
    data.sum2 = sum2;

    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, file))) {
        data.buffer = buffer;
        data.length = bytes_read;

        pthread_t thread;
        pthread_create(&thread, NULL, calculate_checksum, (void *) &data);

        pthread_join(thread, NULL);

        sum1 = data.sum1;
        sum2 = data.sum2;
    }

    fclose(file);

    *checksum1 = sum1;
    *checksum2 = sum2;
    return true;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    uint32_t checksum1 = 0;
    uint32_t checksum2 = 0;

    if (calculate_file_checksum(argv[1], &checksum1, &checksum2)) {
        printf("Checksum1: %u\nChecksum2: %u\n", checksum1, checksum2);
        return 0;
    } else {
        printf("Failed to calculate checksum\n");
        return 1;
    }
}