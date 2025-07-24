//FormAI DATASET v1.0 Category: Error handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handle_error(char *error_message) {
    perror(error_message);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    
    FILE *file = fopen("nonexistent_file.txt", "r");
    if (file == NULL) {
        handle_error("Cannot open file");
    }
    
    char buffer[10];
    errno = 0;
    if (fgets(buffer, 10, file) == NULL) {
        if (errno != 0) {
            handle_error("Error while reading file");
        } else {
            handle_error("End of file reached");
        }
    }
    
    printf("Contents of file: %s", buffer);
    
    return 0;
}