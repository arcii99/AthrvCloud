//FormAI DATASET v1.0 Category: Data recovery tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

void recover_data(char *filename, unsigned int start_index, unsigned int length)
{
    FILE *fp;
    char data[MAX_FILE_SIZE];
    unsigned int i;

    fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Unable to open file.\n");
        return;
    }

    fseek(fp, start_index, SEEK_SET);
    fread(data, length, 1, fp);

    for (i = 0; i < length; i++) {
        if ((i+1) % 16 == 0) {
            printf("\n");
        }
        printf("%02X ", data[i]);
    }

    fclose(fp);
}

int main(int argc, char **argv)
{
    char *filename;
    unsigned int start_index, length;

    if (argc < 4) {
        printf("Usage: %s <filename> <start_index> <length>\n", argv[0]);
        return -1;
    }

    filename = argv[1];
    start_index = atoi(argv[2]);
    length = atoi(argv[3]);

    recover_data(filename, start_index, length);

    return 0;
}