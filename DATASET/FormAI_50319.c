//FormAI DATASET v1.0 Category: File handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main() {
    // file pointer to input and output files
    FILE *in_file, *out_file;
    
    // buffer to store data being read from file
    char buffer[256];

    // open input file in read mode
    in_file = fopen("input.txt", "r");

    // check if input file was opened successfully
    if (in_file == NULL) {
        printf("Failed to open input file.\n");
        exit(-1);
    }

    // open output file in write mode
    out_file = fopen("output.txt", "w");

    // check if output file was opened successfully
    if (out_file == NULL) {
        printf("Failed to open output file.\n");
        exit(-1);
    }

    // read data from input file and write to output file
    while (fgets(buffer, sizeof(buffer), in_file)) {
        fputs(buffer, out_file);
    }

    // close input and output files
    fclose(in_file);
    fclose(out_file);

    printf("Data written to output file.\n");

    return 0;
}