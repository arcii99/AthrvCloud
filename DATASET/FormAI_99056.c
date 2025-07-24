//FormAI DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename = "example.txt";
    
    fp = fopen(filename, "r");
    if(fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    printf("File opened successfully!\n");
    
    if(fclose(fp) != 0) {
        perror("Error closing file");
    }
    
    return 0;
}