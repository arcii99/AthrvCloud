//FormAI DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *input_file;
    char *filename = argv[1];
    char line[100];
    
    // Check if file name is provided as arg
    if (argc < 2) {
        printf("Error: File name not provided.\n");
        exit(EXIT_FAILURE);
    }
    
    // Open input file
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    // Read input file line by line
    while (fgets(line, 100, input_file) != NULL) {
        int num = atoi(line);
        
        if (num == 0) {
            if (errno == EINVAL) {
                printf("Error: Invalid number format.\n");
            } else {
                printf("Error: Number is zero.\n");
            }
            exit(EXIT_FAILURE);
        } else if (num < 0) {
            printf("Error: Cannot compute with negative numbers.\n");
            exit(EXIT_FAILURE);
        }
        
        printf("Number is %d\n", num);
    }
    
    // Close input file
    fclose(input_file);
    
    return 0;
}