//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *file_ptr;
    char *filename = "non_existent_file.txt";
    char read_buffer[256];
    
    // try to open the file
    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        fprintf(stderr, "Error: Cannot open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    
    // try to read from the file
    if (fgets(read_buffer, 256, file_ptr) == NULL) {
        fprintf(stderr, "Error: Cannot read from file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    
    // print out the contents of the file
    printf("The contents of file '%s' are: \n%s\n", filename, read_buffer);
    
    return 0;
}