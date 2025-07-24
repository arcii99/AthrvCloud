//FormAI DATASET v1.0 Category: Error handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s FILENAME\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    FILE *fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    // read file contents and do something with it
    
    if(ferror(fp)) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if(fclose(fp) == EOF) {
        fprintf(stderr, "Error closing file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    // do other things
    
    return 0;
}