//FormAI DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {

    int x = -10;
    FILE* file;

    //open file
    file = fopen("example.txt", "r");
    if(file == NULL) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    //check if x is negative
    if(x < 0) {
        fprintf(stderr, "Error: x must be non-negative\n");
        exit(EXIT_FAILURE);
    }

    //close file
    if(fclose(file) == EOF) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    return 0;
}