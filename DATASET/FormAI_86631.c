//FormAI DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void print_error_msg(int err_num) {
    switch (err_num) {
        case EINVAL:
            printf("Invalid argument.\n");
            break;
        case EACCES:
            printf("Permission denied.\n");
            break;
        case ELOOP:
            printf("Too many symbolic links encountered.\n");
            break;
        default:
            printf("Unknown error occurred.\n");
            break;
    }
}

int main() {
    FILE *fp;
    errno = 0; // Reset errno to 0
    fp = fopen("non_existing_file.txt", "r");
    if(fp == NULL) {
        printf("Error: %d\n", errno);
        print_error_msg(errno);
        exit(EXIT_FAILURE); // Terminate the program with failure status
    }
    fclose(fp);
    return 0;
}