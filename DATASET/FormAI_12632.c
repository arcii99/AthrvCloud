//FormAI DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void error_handling(int error_code) {
    switch(error_code) {
        case 1:
            printf("Error: Not enough memory\n");
            exit(EXIT_FAILURE);
            break;
        case 2:
            printf("Error: Invalid input\n");
            exit(EXIT_FAILURE);
            break;
        case 3:
            printf("Error: File not found\n");
            exit(EXIT_FAILURE);
            break;
        default:
            printf("Unknown error\n");
            exit(EXIT_FAILURE);
            break;
    }
}

int main() {
    int *ptr;
    int n;
    printf("Enter the number of elements: ");
    if(scanf("%d", &n) != 1 || n <= 0) {
        error_handling(2);
    }
    ptr = (int*)malloc(n * sizeof(int));
    if(ptr == NULL) {
        error_handling(1);
    }
    FILE *fp = fopen("file.txt", "r");
    if(fp == NULL) {
        error_handling(3);
    }
    // Do some work with the allocated memory and file
    fclose(fp);
    free(ptr);
    return 0;
}