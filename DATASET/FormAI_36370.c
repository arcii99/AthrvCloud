//FormAI DATASET v1.0 Category: Error handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>

void errorHandler(int errorCode){
    switch(errorCode){
        case 1: printf("Error: Division by zero\n"); break;
        case 2: printf("Error: Out of memory\n"); break;
        case 3: printf("Error: File not found\n"); break;
        default: printf("Unknown error\n"); break;
    }
    exit(1);
}

int divide(int a, int b){
    if(b == 0) errorHandler(1);
    return a/b;
}

int main(){
    int *ptr = malloc(sizeof(int)*100); //try to allocate 100 integers
    if(ptr == NULL) errorHandler(2); //if memory is not allocated, throw an error
    FILE *fp = fopen("nonexistentfile.txt", "r");
    if(fp == NULL) errorHandler(3); //if file not found, throw an error
    int result = divide(5, 0); //this will also throw an error
    printf("Result: %d\n", result); //unreachable code will not be executed
    free(ptr); //free allocated memory
    fclose(fp); //close file
    return 0;
}