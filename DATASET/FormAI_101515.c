//FormAI DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
    char file_name[MAX_SIZE], buffer[MAX_SIZE];
    FILE *fp;
    int bytes_read = 0, total_bytes = 0;

    printf("Enter the name of the file to recover: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("File not found!");
        return 1;
    }

    // Get the size of the file
    fseek(fp, 0L, SEEK_END);
    total_bytes = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Create a new file to write recovered data
    char new_file_name[MAX_SIZE];
    sprintf(new_file_name, "recovered_%s", file_name);
    FILE *new_fp = fopen(new_file_name, "wb");

    // Read data from file in chunks of 512 bytes
    while ((bytes_read = fread(buffer, 512, 1, fp)) > 0) {
        // Check if the chunk is all zeros, which means it was deleted
        if (memcmp(buffer, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16) == 0) {
            printf("Found deleted data!\n");
            // Write recovered data to file
            fwrite(buffer, 512, 1, new_fp);
        }
    }

    fclose(fp);
    fclose(new_fp);

    printf("Data recovery complete!\n");
    return 0;
}