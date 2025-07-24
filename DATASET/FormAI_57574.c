//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void handle_error(char *message, int error_code) {
    fprintf(stderr, "%s: %s\n", message, strerror(error_code));
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (!fp) {
        handle_error("Could not open file", errno);
    }
    
    char buffer[1024];
    while (fgets(buffer, 1024, fp)) {
        printf("%s", buffer);
    }
    
    if (ferror(fp)) {
        handle_error("Error occurred while reading file", errno);
    }
    
    if (fclose(fp) != 0) {
        handle_error("Error occurred while closing file", errno);
    }
    
    return 0;
}