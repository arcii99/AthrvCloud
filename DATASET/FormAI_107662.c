//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short calc_checksum(const char *buf, size_t len)
{
    unsigned short cksum = 0;
    int i;

    for (i = 0; i < len; i++) {
        cksum += buf[i];
    }

    return cksum;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Failed to open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *buf = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&buf, &len, file)) != -1) {
        unsigned short cksum = calc_checksum(buf, strlen(buf));
        printf("%04X: %s", cksum, buf);
    }

    free(buf);
    fclose(file);
    exit(EXIT_SUCCESS);
}