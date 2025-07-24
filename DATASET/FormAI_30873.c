//FormAI DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *fp;

    fp = fopen("non_existent_file.txt", "r");

    if(fp == NULL) {
        if(errno == ENOENT) {
            printf("File does not exist!\n");
        } else {
            printf("An error occurred while opening the file.\n");
        }
        exit(1);
    }

    fclose(fp);
    printf("File closed successfully.\n");
    return 0;
}