//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum file size to be synchronized
#define MAX_FILE_SIZE 1000

// Function to synchronize two files
void sync_files(char *file1, char *file2) {
    FILE *fp1, *fp2;
    char buffer1[MAX_FILE_SIZE + 1], buffer2[MAX_FILE_SIZE + 1];
    
    // Open files for reading and writing
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "w");
    
    if(fp1 && fp2) {
        // Read contents of file1 into buffer1
        fgets(buffer1, MAX_FILE_SIZE, fp1);
        
        // Read contents of file2 into buffer2
        fgets(buffer2, MAX_FILE_SIZE, fp2);
        
        // If contents of file1 differ from contents of file2, write to file2
        if (strcmp(buffer1,buffer2) != 0) {
            fprintf(fp2, "%s", buffer1);
        }
        
        // Close both files
        fclose(fp1);
        fclose(fp2);
        
        // Print success message
        printf("Files synchronized successfully.\n");
    } else {
        // Print error message if files cannot be opened
        printf("Unable to open files.\n");
    }
}

int main() {
    // Call the sync_files function on two sample files
    sync_files("file1.txt", "file2.txt");
    
    return 0;
}