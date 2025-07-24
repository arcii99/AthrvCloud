//FormAI DATASET v1.0 Category: Error handling ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>

void panic(const char* message);

int main(){

    printf("Paranoid style error handling example\n");

    int* pointer = (int*) malloc(sizeof(int));

    if(pointer == NULL){
        panic("Memory allocation failed");
    }

    int num = 0;

    printf("Enter a number: ");
    if(scanf("%d", &num) != 1){
        panic("Input not accepted");
    }

    if(num < 1 || num > 100){
        panic("Number should be between 1 and 100");
    }

    FILE* file = fopen("example.txt", "r");

    if(file == NULL){
        panic("File opening failed");
    }

    char string[100];

    if(fgets(string, 100, file) == NULL){
        panic("File reading failed");
    }

    int sum = num + *pointer;

    printf("The sum is: %d\n", sum);

    fclose(file);
    free(pointer);

    return 0;

}

void panic(const char* message){
    fprintf(stderr, "Panic: %s\n", message);
    exit(1);
}