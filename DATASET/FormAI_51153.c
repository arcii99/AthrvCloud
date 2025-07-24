//FormAI DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./program <filename>\n");
        return 1;
    }
    
    char *filename = argv[1];
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return errno;
    }
    
    char buffer[1024];
    while (fgets(buffer, 1024, file)) {
        // do something with the line
    }
    
    if (!feof(file)) {
        perror("Error reading file");
        return errno;
    }
    
    if (fclose(file) != 0) {
        perror("Error closing file");
        return errno;
    }
    
    return 0;
}