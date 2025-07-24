//FormAI DATASET v1.0 Category: Memory management ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

int main(){
    int* ptr;
    int n, i, sum = 0;

    //get number of elements from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    //memory allocation using malloc()
    ptr = (int*)malloc(n * sizeof(int));

    //if memory allocation fails
    if(ptr == NULL){
        printf("Memory allocation failed");
        exit(0);
    }

    //get elements from user
    printf("Enter the elements: ");
    for(i=0; i<n; i++){
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }

    //display the sum of the elements
    printf("Sum of the elements is: %d", sum);

    //free the allocated memory
    free(ptr);

    return 0;
}