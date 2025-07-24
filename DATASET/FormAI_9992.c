//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
    if(argc != 2) { // Ensure file path is provided
        printf("Usage: %s <file path>\n", argv[0]);
        return 1;
    }

    char file_path[100];
    strcpy(file_path, argv[1]);

    // Open file in read-only mode
    FILE *fp = fopen(file_path, "r");

    if(fp == NULL) { // Error handling
        printf("Error opening file!\n");
        return 1;
    }

    long long int total_size = 0;
    char buf[1024];
    const char delim[2] = " ";
    char *token;

    while(fgets(buf, 1024, fp)) { // Read file line by line
        token = strtok(buf, delim); // Get size of file in bytes
        total_size += atoll(token);
    }

    printf("Total disk space used by %s = %lld bytes.\n", argv[1], total_size);

    return 0;
}