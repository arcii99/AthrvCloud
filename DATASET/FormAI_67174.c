//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 2048

/**
 * This program extracts metadata from a C source file and outputs it to the console.
 * Metadata includes: number of functions, number of lines of code, and number of comments.
 */

int count_functions(char *buffer);
int count_lines_of_code(char *buffer);
int count_comments(char *buffer);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [source_file]\n", argv[0]);
        return 1;
    }
    
    FILE *fp;
    char buffer[BUFFER_SIZE];
    
    // Attempt to open the source file
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Error: cannot open file %s\n", argv[1]);
        return 1;
    }
    
    // Read the source file into a buffer
    fread(buffer, sizeof(char), BUFFER_SIZE, fp);
    
    // Count the number of functions, lines of code, and comments
    int num_functions = count_functions(buffer);
    int num_lines_of_code = count_lines_of_code(buffer);
    int num_comments = count_comments(buffer);
    
    // Output the metadata to the console
    printf("Number of functions: %d\n", num_functions);
    printf("Number of lines of code: %d\n", num_lines_of_code);
    printf("Number of comments: %d\n", num_comments);
    
    // Close the file and exit
    fclose(fp);
    return 0;
}

int count_functions(char *buffer) {
    int count = 0;
    char *ptr = buffer;
    
    // Loop through the buffer, searching for function declarations
    while ((ptr = strstr(ptr, "function ")) != NULL) {
        count++;
        ptr += strlen("function ");
    }
    
    return count;
}

int count_lines_of_code(char *buffer) {
    int count = 0;
    char *ptr = buffer;
    char *line_start;
    char *line_end;
    
    // Loop through the buffer, searching for newline characters
    while ((line_end = strchr(ptr, '\n')) != NULL) {
        line_start = ptr;
        ptr = line_end + 1;
        
        // Check if the line contains code
        while (*line_start == ' ' || *line_start == '\t') {
            line_start++;
        }
        if (*line_start != '\n' && *line_start != '\0') {
            count++;
        }
    }
    
    return count;
}

int count_comments(char *buffer) {
    int count = 0;
    char *ptr = buffer;
    
    // Loop through the buffer, searching for comment symbols
    while ((ptr = strstr(ptr, "//")) != NULL) {
        count++;
        ptr += strlen("//");
    }
    
    return count;
}