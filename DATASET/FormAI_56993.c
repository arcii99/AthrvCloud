//FormAI DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void handle_error(int error_code){
    switch (error_code){
        case 1:
            printf("Error: Null pointer encountered.\n");
            exit(1);
        case 2:
            printf("Error: Array index out of bounds.\n");
            exit(1);
        case 3:
            printf("Error: Division by zero.\n");
            exit(1);
        case 4:
            printf("Error: Unable to open the file.\n");
            exit(1);
        default:
            printf("Unknown error occurred.\n");
            exit(1);
    }
}

int main(){
    int *ptr = NULL;
    int arr[] = {1, 2, 3};
    int divide_by_zero = 0;
    char filename[] = "does_not_exist.txt";
    FILE *fp;

    printf("Error handling example\n");

    if(ptr == NULL){
        handle_error(1);
    }

    if(arr[3]){
        handle_error(2);
    }

    if(divide_by_zero == 0){
        handle_error(3);
    }

    fp = fopen(filename, "r");
    if(fp == NULL){
        handle_error(4);
    }

    printf("No error occurred.\n");
    return 0;
}