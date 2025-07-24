//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    FILE *csv_file = fopen(argv[1], "r");
    if (!csv_file) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, csv_file) != NULL) {
        // remove newline character from buffer
        buffer[strcspn(buffer, "\n")] = 0;
        
        // tokenize the buffer
        char *token = strtok(buffer, ",");
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }
    
    fclose(csv_file);
    return 0;
}