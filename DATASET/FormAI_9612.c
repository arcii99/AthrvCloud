//FormAI DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>

// Custom error codes
#define ERROR_SUCCESS 0
#define ERROR_INVALID_INPUT 1
#define ERROR_FILE_NOT_FOUND 2
#define ERROR_FILE_ACCESS 3

// Function prototype to read file
int read_file(char* filename);

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Invalid input arguments.\n");
        return ERROR_INVALID_INPUT;
    }

    char* filename = argv[1];
    int result = read_file(filename);
    if(result != ERROR_SUCCESS) {
        switch(result) {
            case ERROR_FILE_NOT_FOUND:
                printf("File not found: %s\n", filename);
                break;
            case ERROR_FILE_ACCESS:
                printf("Error accessing file: %s\n", filename);
                break;
            default:
                printf("Unknown error occurred.\n");
                break;
        }
    } else {
        printf("File read successfully.\n");
    }
    return ERROR_SUCCESS;
}

int read_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        return ERROR_FILE_NOT_FOUND;
    }

    char buffer[100];
    while(fgets(buffer, 100, fp)) {
        printf("%s", buffer);
    }

    if(ferror(fp)) {
        return ERROR_FILE_ACCESS;
    }

    fclose(fp);
    return ERROR_SUCCESS;
}