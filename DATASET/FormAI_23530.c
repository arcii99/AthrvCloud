//FormAI DATASET v1.0 Category: Error handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 256

void MyError(char *errorMsg) {
    char *errBuffer = calloc(MAX_BUFFER_SIZE, sizeof(char));
    sprintf(errBuffer, "Error occurred: %s\n", errorMsg);
    fprintf(stderr, "%s", errBuffer);
    free(errBuffer);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        MyError("No file names provided!");
    }
    
    FILE *fptr = NULL;
    int i;
    for(i = 1; i < argc; i++) {
        fptr = fopen(argv[i], "r");
        if(!fptr) {
            char *errorMsg = calloc(MAX_BUFFER_SIZE, sizeof(char));
            sprintf(errorMsg, "Unable to open file: %s\nError message: %s\n", argv[i], strerror(errno));
            MyError(errorMsg);
        }
        // read content of the file
        char buffer[MAX_BUFFER_SIZE];
        while (fgets(buffer, MAX_BUFFER_SIZE, fptr)) {
            printf("%s", buffer);
        }
        fclose(fptr);
    }
    return 0;
}