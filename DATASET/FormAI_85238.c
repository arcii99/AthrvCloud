//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

/* Returns the checksum of a given buffer */
byte checksum(const byte *buf, size_t buf_len) {
    byte sum = 0;
    for (size_t i = 0; i < buf_len; i++) {
        sum += buf[i];
    }
    return sum;
}

/* Main function that reads input from the user */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s string\n", argv[0]);
        exit(1);
    }

    byte *buf = (byte*)argv[1];
    size_t buf_len = strlen(argv[1]);

    byte sum = checksum(buf, buf_len);
    printf("Checksum: 0x%02x\n", sum);

    return 0;
}