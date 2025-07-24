//FormAI DATASET v1.0 Category: File Backup System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 4096 /* Buffer size as 4KB */

int main(int argc, char *argv[]) {
    char *src_file, *dst_file;
    FILE *src, *dst; /* Pointers for source and destination file */
    char buf[BUF_SIZE];
    size_t n;

    /* Check if correct number of arguments is given */
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <Source file> <Destination file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Assign arguments to variables */
    src_file = argv[1];
    dst_file = argv[2];

    /* Open source file and check for errors */
    src = fopen(src_file, "rb");
    if (src == NULL) {
        fprintf(stderr, "Error: %s could not be opened\n", src_file);
        return EXIT_FAILURE;
    }

    /* Open destination file and check for errors, only for first time backup */
    if (access(dst_file, F_OK) != 0) {
        dst = fopen(dst_file, "wb");
        if (dst == NULL) {
            fprintf(stderr, "Error: %s could not be created\n", dst_file);
            fclose(src);
            return EXIT_FAILURE;
        }
    }
    /* Open destination file in append mode thereafter */
    else {
        dst = fopen(dst_file, "ab");
    }

    /* Copy file contents */
    while ((n = fread(buf, 1, BUF_SIZE, src)) != 0) {
        if (fwrite(buf, 1, n, dst) != n) {
            fprintf(stderr, "Error: Could not write to %s\n", dst_file);
            fclose(src);
            fclose(dst);
            return EXIT_FAILURE;
        }
    }

    /* Close file pointers */
    fclose(src);
    fclose(dst);

    printf("Backup completed!\n");

    return EXIT_SUCCESS;
}