//FormAI DATASET v1.0 Category: Data recovery tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    FILE *source, *destination;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;
    long long total_bytes = 0;
    int i;

    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    source = fopen(argv[1], "rb");
    if (source == NULL) {
        printf("Unable to open source file %s\n", argv[1]);
        return 2;
    }

    destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        printf("Unable to create destination file %s\n", argv[2]);
        fclose(source);
        return 3;
    }

    printf("Recovering data from %s\n", argv[1]);

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        for (i = 0; i < bytes_read; i++) {
            if (buffer[i] != 0xFF) {
                fwrite(buffer + i, 1, 1, destination);
                bytes_written = 1;
            }
            else {
                bytes_written = 0;
            }
            total_bytes += bytes_written;
        }
    }

    printf("%lld bytes of data recovered!\n", total_bytes);

    fclose(source);
    fclose(destination);

    return 0;
}