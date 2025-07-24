//FormAI DATASET v1.0 Category: Error handling ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

void print_error() {
    if(errno == 0) {
        printf("No error!\n");
    } else {
        printf("Error: %s\n", strerror(errno));
        errno = 0; //reset error number
    }
}

int main() {
    FILE *fp;
    fp = fopen("file_that_does_not_exist.txt", "r");
    if(fp == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char c = fgetc(fp);
    if(ferror(fp)) {
        printf("Error reading from file: %s\n", strerror(errno));
    } else {
        printf("Successfully read character %c\n", c);
    }

    if(fclose(fp) != 0) {
        printf("Error closing file: %s\n", strerror(errno));
    }

    print_error();
    return 0;
}