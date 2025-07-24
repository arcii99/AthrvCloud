//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char buf[1024];
    unsigned int chksum = 0;
    FILE *file = fopen("example.txt", "rb");

    if (file == NULL) {
        fprintf(stderr, "Could not open file.\n");
        return EXIT_FAILURE;
    }

    size_t bytes_read;
    while ((bytes_read = fread(buf, 1, 1024, file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            chksum += buf[i];
            if (chksum > 0xFFFF) {
                // Wraparound if overflow
                chksum = (chksum & 0xFFFF) + 1;
            }
        }
    }

    fclose(file);

    printf("Checksum: %04X\n", (unsigned short)~chksum);

    return EXIT_SUCCESS;
}