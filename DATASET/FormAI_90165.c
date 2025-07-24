//FormAI DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_error(int error_code){
    switch(error_code){
        case 1:
            printf("Error code 1: memory allocation failed\n");
            exit(1);
            break;
        case 2:
            printf("Error code 2: file opening failed\n");
            exit(1);
            break;
        case 3:
            printf("Error code 3: division by zero\n");
            exit(1);
            break;
        default:
            printf("Unknown error occurred\n");
            exit(1);
            break;
    }
}

int main(){
    int* ptr = (int*) malloc(sizeof(int) * 100);
    if(ptr == NULL){
        handle_error(1);
    }
    
    FILE* file = fopen("non_existent_file.txt", "r");
    if(file == NULL){
        handle_error(2);
    }
    
    int a = 5, b = 0;
    if(b == 0){
        handle_error(3);
    }
    
    int result = a / b;
    printf("%d", result);
    
    free(ptr);
    fclose(file);
    
    return 0;
}