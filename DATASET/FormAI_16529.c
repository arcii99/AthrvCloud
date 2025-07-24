//FormAI DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void print_error_message(int error_code) {
    switch (error_code) {
        case EACCES:
            printf("Insufficient permissions to access file.\n");
            break;
        case EIO:
            printf("Input/Output error occurred.\n");
            break;
        case ENOMEM:
            printf("Out of memory error.\n");
            break;
        default:
            printf("Unknown error occurred.\n");
            break;
    }
}

int main() {
    FILE *fp;
    char *file_name = "example.txt";
    char buffer[255];
    
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        int error_code = errno;
        print_error_message(error_code);
        exit(1);
    }
    
    while(fgets(buffer, 255, fp)) {
        printf("%s", buffer);
    }
    
    fclose(fp);
    return 0;
}