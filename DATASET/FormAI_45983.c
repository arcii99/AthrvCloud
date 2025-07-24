//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <recovery image> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *image_file = fopen(argv[1], "rb");
    if (!image_file) {
        printf("Failed to open recovery image %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *destination_dir = argv[2];

    // Create directory if it doesn't exist
    char command[100];
    sprintf(command, "mkdir -p %s", destination_dir);
    system(command);

    unsigned char buffer[BLOCK_SIZE];
    int file_index = 0;
    FILE *dest_file = NULL;

    while (fread(buffer, BLOCK_SIZE, 1, image_file)) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            // The start of a new jpeg file
            if (dest_file) {
                fclose(dest_file);
            }

            char filename[50];
            sprintf(filename, "%s/file%d.jpg", destination_dir, file_index);
            dest_file = fopen(filename, "wb");
            if (!dest_file) {
                printf("Failed to create file %s.\n", filename);
                exit(EXIT_FAILURE);
            }

            file_index++;
        }

        // Write data to jpeg file
        if (dest_file) {
            fwrite(buffer, BLOCK_SIZE, 1, dest_file);
        }
    }

    if (dest_file) {
        fclose(dest_file);
    }

    fclose(image_file);

    return 0;
}