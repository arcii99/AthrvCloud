//FormAI DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100 // Maximum allowed length of file name
#define MAX_BUFFER_SIZE 1024 // Maximum size of buffer to use for copying files 

int main(int argc, char* argv[]) {
    char src_file[MAX_FILE_NAME_SIZE]; // Variable to hold source file name
    char dst_file[MAX_FILE_NAME_SIZE]; // Variable to hold destination file name
    char buffer[MAX_BUFFER_SIZE]; // Buffer to copy contents of files
    
    // Check if user entered correct number of arguments
    if (argc != 3) {
        printf("Usage: %s \n", argv[0]);
        printf("Example: %s source_file destination_file\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // Copy source and destination file names from command line arguments
    strncpy(src_file, argv[1], MAX_FILE_NAME_SIZE);
    strncpy(dst_file, argv[2], MAX_FILE_NAME_SIZE);
    
    // Open source file with read permission
    FILE* src_fp = fopen(src_file, "r");
    if (src_fp == NULL) {
        printf("Error: Could not open source file.\n");
        return EXIT_FAILURE;
    }
    
    // Open destination file with write permission
    FILE* dst_fp = fopen(dst_file, "w");
    if (dst_fp == NULL) {
        printf("Error: Could not open destination file.\n");
        return EXIT_FAILURE;
    }
    
    // Copy contents of source file to destination file using buffer
    while (fgets(buffer, MAX_BUFFER_SIZE, src_fp)) {
        fputs(buffer, dst_fp);
    }
    
    // Close both file pointers
    fclose(src_fp);
    fclose(dst_fp);
    
    printf("File backup successful!\n");
    return EXIT_SUCCESS;
}