//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_VIRUS_SIGNATURE_LEN 1024

void scan_file(char *filename, char *virus_signatures) {
    FILE *fileptr;
    unsigned char buffer[MAX_VIRUS_SIGNATURE_LEN];
    size_t bytes_read;
    size_t virus_signature_len = strlen(virus_signatures);

    fileptr = fopen(filename, "rb");
    if (fileptr == NULL) {
        printf("Unable to open file: %s\n", filename);
        return;
    }

    while ((bytes_read = fread(buffer, 1, virus_signature_len, fileptr)) > 0) {
        if (memcmp(buffer, virus_signatures, bytes_read) == 0) {
            printf("Virus detected in file: %s\n", filename);
            fclose(fileptr);
            return;
        }
    }

    printf("File is virus free: %s\n", filename);
    fclose(fileptr);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <file_name> <virus_signatures>\n", argv[0]);
        return 1;
    }

    char filename[MAX_FILENAME_LEN];
    strncpy(filename, argv[1], MAX_FILENAME_LEN);
    filename[MAX_FILENAME_LEN-1] = '\0';

    char virus_signatures[MAX_VIRUS_SIGNATURE_LEN];
    strncpy(virus_signatures, argv[2], MAX_VIRUS_SIGNATURE_LEN);
    virus_signatures[MAX_VIRUS_SIGNATURE_LEN-1] = '\0';

    scan_file(filename, virus_signatures);

    return 0;
}