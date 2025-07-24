//FormAI DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_pointer;
    char file_name[] = "example.txt";

    file_pointer = fopen(file_name, "r");
    
    if (file_pointer == NULL) {
        fprintf(stderr, "Error: failed to open file %s\n", file_name);
        exit(1);
    }
    
    // rest of the program goes here

    fclose(file_pointer);
    
    return 0;
}