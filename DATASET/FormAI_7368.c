//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>

#define MAX_FILENAME_LENGTH     128
#define META_DATA_LENGTH        28

void extract_metadata(char *file_name, unsigned char *metadata);

int main(int argc, char** argv) 
{
    // check command line arguments
    if (argc < 2) {
        printf("Usage: %s [file_name]\n", argv[0]);
        return -1;
    }

    // extract metadata from file
    unsigned char metadata[META_DATA_LENGTH];
    extract_metadata(argv[1], metadata);

    // parse metadata and print out information
    int offset = 0;
    int version = metadata[offset];
    offset += 2;
    int length = ntohs(*(unsigned short*)(metadata+offset));
    offset += 6;
    int sequence = ntohl(*(unsigned int*)(metadata+offset));
    offset += 4;
    unsigned char hash[16];
    memcpy(hash, metadata+offset, 16);

    printf("Version: %d\n", version);
    printf("Length: %d\n", length);
    printf("Sequence: %d\n", sequence);
    printf("Hash: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}

/* 
 * Extracts the metadata from a file
 */
void extract_metadata(char *file_name, unsigned char *metadata) 
{
    // open file
    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", file_name);
        exit(-1);
    }

    // read metadata
    if (read(fd, metadata, META_DATA_LENGTH) < 0) {
        printf("Error reading metadata from file: %s\n", file_name);
        exit(-1);
    }

    // close file
    close(fd);
}