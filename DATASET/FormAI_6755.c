//FormAI DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE *file = NULL;
    char *filename = "non_existing_file.txt";
    
    if ((file = fopen(filename, "r")) == NULL) {
        if (errno == ENOENT) {
            printf("Error: File %s not found.\n", filename);
        } else if (errno == EACCES) {
            printf("Error: No permission to open file %s.\n", filename);
        } else {
            printf("Error: Failed to open file %s. Unknown error.\n", filename);
        }
        exit(EXIT_FAILURE);
    }
    
    // Do something with the file...
    
    fclose(file);
    return 0;
}