//FormAI DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_ptr; // declare a file pointer
    char filename[] = "example_file.txt"; // declare the filename as a string
    
    // open file with write mode
    file_ptr = fopen(filename, "w");
    
    if (file_ptr == NULL) { // check if file is successfully opened
        printf("Unable to open file.\n");
        exit(1);
    }
    
    // write to file
    fprintf(file_ptr, "This is an example of file handling in C.\n");
    fprintf(file_ptr, "We can write to a file using fprintf.\n");
    
    // close the opened file
    fclose(file_ptr);
    
    // open the same file with read mode
    file_ptr = fopen(filename, "r");
    
    if (file_ptr == NULL) { // check if file is successfully opened
        printf("Unable to open file.\n");
        exit(1);
    }
    
    // read from file using fgets
    char line[100];
    printf("Reading from file...\n");
    while(fgets(line, 100, file_ptr) != NULL) {
        printf("%s", line);
    }
    
    // close the opened file
    fclose(file_ptr);
    
    return 0; // terminate the program
}