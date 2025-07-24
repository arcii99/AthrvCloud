//FormAI DATASET v1.0 Category: File Backup System ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

    struct stat filestat;

    if (argc < 3) {
        printf("Error: Please provide source and destination file names\n");
        return -1;
    }

    if (stat(argv[1], &filestat) < 0) {
        printf("Error: Unable to stat file %s\n", argv[1]);
        return -1;
    }

    if (S_ISDIR(filestat.st_mode)) {
        printf("Error: Cannot copy a directory\n");
        return -1;
    }

    FILE *source_file, *destination_file;

    if ((source_file = fopen(argv[1], "r")) == NULL) {
        printf("Error: Unable to open file %s for reading\n", argv[1]);
        return -1;
    }

    if ((destination_file = fopen(argv[2], "w+")) == NULL) {
        printf("Error: Unable to open file %s for writing\n", argv[2]);
        fclose(source_file);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, destination_file);
        if (bytes_written != bytes_read) {
            printf("Error: Failed to write to file %s\n", argv[2]);
            fclose(source_file);
            fclose(destination_file);
            return -1;
        }
    }

    fclose(source_file);
    fclose(destination_file);

    printf("File %s was successfully backed up to %s\n", argv[1], argv[2]);

    return 0;
}