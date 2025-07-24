//FormAI DATASET v1.0 Category: Data recovery tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

/* Function to recover deleted files recursively */
int recover_file(const char *filename, int start_of_file, FILE *disk_image) {
    /* Open the file with the given filename */
    FILE *fp;
    char recovered_filename[strlen(filename) + 2];
    sprintf(recovered_filename, "%s_", filename);
    fp = fopen(recovered_filename, "wb");

    /* Set the offset of the file pointer to the start of the file */
    fseek(disk_image, start_of_file, SEEK_SET);

    /* Allocate memory for a buffer to read blocks of data */
    char *buffer = malloc(sizeof(char) * BLOCK_SIZE);
    if (buffer == NULL) {
        printf("Error: Failed to allocate buffer memory\n");
        return 1;
    }

    /* Read the first block of data */
    size_t size = 1;
    size_t bytes_read = BLOCK_SIZE;
    int end_of_file = start_of_file;
    while (size > 0 && bytes_read == BLOCK_SIZE) {
        bytes_read = fread(buffer, sizeof(char), BLOCK_SIZE, disk_image);
        size = fwrite(buffer, sizeof(char), bytes_read, fp);            
        end_of_file += bytes_read;
    }

    printf("Recovered file: %s\n", recovered_filename);

    /* Check for files that are split over multiple blocks */
    int next_block = start_of_file + BLOCK_SIZE;
    while (next_block < end_of_file) {
        /* Recursive call to recover the next block of data */
        recover_file(filename, next_block, disk_image);
        next_block += BLOCK_SIZE;
    }

    /* Free the memory used for the buffer and close the file*/
    free(buffer);   
    fclose(fp);

    return 0;
}

/* Main function */
int main(int argc, char *argv[]) {
    /* Check if correct number of arguments has been provided */
    if (argc != 2) {
        printf("Usage: %s <disk image file>\n", argv[0]);
        return 1;
    }

    /* Open the disk_image file for reading */
    FILE *disk_image = fopen(argv[1], "rb");

    /* Check if the file was opened successfully */
    if (disk_image == NULL) {
        printf("Error: Failed to open file %s\n", argv[1]);
        return 1;
    }

    /* Recover deleted files recursively */
    recover_file("file.txt", 0, disk_image);
    recover_file("document.pdf", 0, disk_image);
    recover_file("photo.jpg", 0, disk_image);

    /* Close the disk_image file */
    fclose(disk_image);

    return 0;
}