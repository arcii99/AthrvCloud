//FormAI DATASET v1.0 Category: Error handling ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

void handler(int error) {
    switch(error) {
        case 0:
            printf("No errors occurred\n");
            break;
        case 1:
            printf("Error: Invalid argument\n");
            exit(1);
        case 2:
            printf("Error: File not found\n");
            exit(2);
        default:
            printf("Error: Unknown error occurred\n");
            exit(100);
    }
}

int main(int argc, char* argv[]) {
    if(argc == 1) {
        handler(1); // Invalid argument error
    }

    FILE* fp = fopen(argv[1], "r");

    if(fp == NULL) {
        handler(2); // File not found error
    }

    // Successful execution
    handler(0);

    return 0;
}