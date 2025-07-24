//FormAI DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(){
    FILE *fp;
    fp = fopen("nonexistentfile.txt", "r");
    if(fp == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int num = 10;
    if(num < 20){
        errno = 22;
        perror("Error occurred");
        exit(EXIT_FAILURE);
    }

    return 0;
}