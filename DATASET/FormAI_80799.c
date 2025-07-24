//FormAI DATASET v1.0 Category: Memory management ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *ptr, sum = 0;
    printf("Enter the size of an array: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int));
    if(ptr == NULL){
        printf("Memory allocation failed!");
        exit(0);
    }
    printf("Enter the elements of an array: ");
    for(int i=0; i<n; i++){
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }

    printf("The array elements are: ");
    for(int i=0; i<n; i++){
        printf("%d ", *(ptr+i));
    }

    printf("\nThe sum of array elements is: %d", sum);

    // Deallocating the memory. 
    free(ptr); 

    return 0;
}