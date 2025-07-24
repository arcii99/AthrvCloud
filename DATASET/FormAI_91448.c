//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF_SIZE 2048

int main(int argc, char *argv[])
{
    char *file_name = argv[1];
    FILE *fp = fopen(file_name, "rb");
    if (!fp) {
        printf("Error: Failed to open file!\n");
        return -1;
    }
    char *buf = malloc(sizeof(char) * MAX_BUF_SIZE);
    memset(buf, 0, MAX_BUF_SIZE);

    size_t read = fread(buf, sizeof(char), MAX_BUF_SIZE, fp);
    if (read == 0) {
        printf("Error: File is empty!\n");
        return -1;
    }

    // Search for metadata
    char *metadata_start = strstr(buf, "BEGIN_METADATA");
    char *metadata_end = strstr(buf, "END_METADATA");
    if (!metadata_start || !metadata_end) {
        printf("Error: Metadata not found!\n");
        return -1;
    }

    size_t metadata_len = metadata_end - metadata_start;
    char *metadata = malloc(sizeof(char) * metadata_len);
    memcpy(metadata, metadata_start, metadata_len);

    printf("Metadata: %s\n", metadata);

    fclose(fp);
    free(buf);
    free(metadata);
    return 0;
}