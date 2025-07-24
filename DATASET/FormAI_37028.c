//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Ken Thompson
#include <stdio.h>

int checksum(char *buffer, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += buffer[i];
    }

    return sum & 0xFFFF;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: checksum <filename>\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");

    if (!fp) {
        printf("error: could not open file\n");
        return 2;
    }

    fseek(fp, 0L, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char *buffer = malloc(filesize);

    if (!buffer) {
        printf("error: out of memory\n");
        return 3;
    }

    fread(buffer, 1, filesize, fp);

    int sum = checksum(buffer, filesize);

    free(buffer);
    fclose(fp);

    printf("%s: checksum = 0x%X\n", argv[1], sum);

    return 0;
}