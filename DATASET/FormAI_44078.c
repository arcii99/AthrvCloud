//FormAI DATASET v1.0 Category: Data recovery tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./data-recovery-tool FILENAME\n");
        exit(1);
    }
    
    // Open the file
    FILE *fp = fopen(argv[1], "r+");
    if (fp == NULL) {
        printf("Unable to open file: %s\n", argv[1]);
        exit(1);
    }
    
    // Get file size
    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    // Allocate memory for data
    char *data = (char *) malloc(sizeof(char) * file_size);
    if (data == NULL) {
        printf("Error: Unable to allocate memory for data.\n");
        fclose(fp);
        exit(1);
    }
    
    // Read data from file
    int read = fread(data, sizeof(char), file_size, fp);
    if (read != file_size) {
        printf("Error: Unable to read data from file.\n");
        free(data);
        fclose(fp);
        exit(1);
    }
    
    // Attempt to recover the file by replacing NULL bytes with spaces
    int i;
    int num_null_bytes_replaced = 0;
    for (i = 0; i < file_size; i++) {
        if (data[i] == '\0') {
            data[i] = ' ';
            num_null_bytes_replaced++;
        }
    }
    
    if (num_null_bytes_replaced > 0) {
        printf("Recovered %d null bytes.\n", num_null_bytes_replaced);
        
        // Write recovered data back to file
        fseek(fp, 0L, SEEK_SET);
        int written = fwrite(data, sizeof(char), file_size, fp);
        if (written != file_size) {
            printf("Error: Failed to write recovered data back to file.\n");
        }
    } else {
        printf("No null bytes found in file. Nothing to recover.\n");
    }
    
    // Clean up
    free(data);
    fclose(fp);
    return 0;
}