//FormAI DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>

int main() {
    // file pointer for input and output files
    FILE *input_file, *output_file;
    
    // buffer to read from input file
    char buffer[100];
    
    // opening input file
    input_file = fopen("input.txt", "r");
    
    // checking if input file could be opened
    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }
    
    // opening output file for writing
    output_file = fopen("output.txt", "w");
    
    // checking if output file could be opened
    if (output_file == NULL) {
        printf("Error opening output file\n");
        return 1;
    }
    
    // reading from input file and writing to output file
    while (fgets(buffer, sizeof(buffer), input_file)) {
        fprintf(output_file, "%s", buffer);
    }
    
    // closing input and output files
    fclose(input_file);
    fclose(output_file);
    
    printf("File handling example program completed\n");
    
    return 0;
}