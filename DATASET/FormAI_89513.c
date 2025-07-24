//FormAI DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void error_handling(int code) {
    switch(code) {
        case 0:
            printf("No error found! Program exiting...\n");
            exit(0);
            break;
        case 1:
            printf("Error code 1: File not found!\n");
            exit(1);
            break;
        case 2:
            printf("Error code 2: Access denied!\n");
            exit(2);
            break;
        case 3:
            printf("Error code 3: Memory allocation failed!\n");
            exit(3);
            break;
        case 4:
            printf("Error code 4: Division by zero error!\n");
            exit(4);
            break;
        case 5:
            printf("Error code 5: Invalid argument provided!\n");
            exit(5);
            break;
        default:
            printf("Error code %d: Unknown error occurred!\n", code);
            exit(code);
            break;
    }
}

int main() {
    FILE *fp;
    char *str;
    int num, *arr;
    
    // attempting to open file
    fp = fopen("non-existent-file.txt", "r");
    if(fp == NULL) {
        error_handling(1); // file not found error
    }
    
    // attempting to allocate memory
    arr = malloc(-1 * sizeof(int)); // intentionally allocating negative memory
    if(arr == NULL) {
        error_handling(3); // memory allocation error
    }
    
    // attempting to divide by 0
    num = 10 / 0;
    if(num == 0) {
        error_handling(4); // division by zero error
    }
    
    // attempting to access beyond array size
    str = "hello";
    if(str[10] != '\0') {
        error_handling(5); // invalid argument provided error
    }
    
    // no error found
    error_handling(0);
    
    return 0;
}