//FormAI DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *source_fp, *dest_fp;
    char source_file[BUFFER_SIZE], dest_file[BUFFER_SIZE], buffer[BUFFER_SIZE];
    time_t current_time;
    struct tm * time_info;
    char time_string[80];

    printf("Enter the source file path: ");
    fgets(source_file, BUFFER_SIZE, stdin);
    source_file[strcspn(source_file, "\n")] = '\0'; // remove newline character from input

    printf("Enter the destination file path: ");
    fgets(dest_file, BUFFER_SIZE, stdin);
    dest_file[strcspn(dest_file, "\n")] = '\0'; // remove newline character from input

    source_fp = fopen(source_file, "rb");
    if (source_fp == NULL) {
        printf("Error: Failed to open source file.\n");
        return -1;
    }

    dest_fp = fopen(dest_file, "wb");
    if (dest_fp == NULL) {
        printf("Error: Failed to create destination file.\n");
        fclose(source_fp);
        return -1;
    }

    // copy contents of source file to destination file
    while (fgets(buffer, BUFFER_SIZE, source_fp) != NULL) {
        fputs(buffer, dest_fp);
    }

    fclose(source_fp);
    fclose(dest_fp);
    printf("File copied successfully.\n");

    // append timestamp to destination file name
    current_time = time(NULL);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "_%Y%m%d-%H%M%S", time_info);
    strcat(dest_file, time_string);

    // create backup file with timestamp in filename
    source_fp = fopen(dest_file, "wb");
    dest_fp = fopen(dest_file, "ab");
    if (source_fp == NULL || dest_fp == NULL) {
        printf("Error: Failed to create backup file.\n");
        return -1;
    }

    // copy contents of original file to backup file
    source_fp = fopen(dest_file, "rb");
    while (fgets(buffer, BUFFER_SIZE, source_fp) != NULL) {
        fputs(buffer, dest_fp);
    }

    fclose(source_fp);
    fclose(dest_fp);
    printf("Backup file created successfully.\n");

    return 0;
}