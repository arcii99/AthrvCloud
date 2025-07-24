//FormAI DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *file = fopen("nonexistent_file.txt", "r");
    
    if (file == NULL) {
        if (errno == ENOENT) {
            printf("The specified file does not exist.\n");
        } else if (errno == EACCES) {
            printf("Permission denied.\n");
        } else {
            printf("An unknown error occurred.\n");
        }
        
        return EXIT_FAILURE;
    }
    
    char buffer[1];
    
    if (fread(buffer, 1, 1, file) != 1) {
        if (feof(file) != 0) {
            printf("End of file reached.\n");
        } else if (ferror(file) != 0) {
            printf("An error occurred while reading the file.\n");
        }
        
        fclose(file);
        return EXIT_FAILURE;
    }
    
    fclose(file);
    printf("Successfully read the first byte of the file.\n");
    
    return EXIT_SUCCESS;
}