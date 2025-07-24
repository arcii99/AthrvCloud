//FormAI DATASET v1.0 Category: Error handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(){
    FILE *fp;

    fp = fopen("nonexistent.txt", "r");
    if(fp == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // rest of the program
    // ...

    if(fclose(fp) != 0){
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    return 0;
}