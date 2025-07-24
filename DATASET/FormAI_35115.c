//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include<stdio.h>
#include<stdlib.h>

void error_handling(int status, char* msg) {
    if(status) {
        fprintf(stderr, "Error: %s\n",msg);
        exit(EXIT_FAILURE);
    }
}

int main() {
    int num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    error_handling(num1 <= 0 || num2 <= 0, "Invalid input. Please enter positive numbers only.");
    
    int* array = (int*)malloc((num1+num2)*sizeof(int));
    error_handling(array == NULL, "Memory allocation failed.");

    for(int i = 0; i < num1; i++) {
        printf("Enter element %d of array 1: ",i+1);
        scanf("%d",&array[i]);
    }

    for(int i = 0; i < num2; i++) {
        printf("Enter element %d of array 2: ",i+1);
        scanf("%d",&array[num1+i]);
    }

    for(int i = 0; i < num1+num2; i++) {
        printf("%d ",array[i]);
    }

    free(array);
    return 0;
}