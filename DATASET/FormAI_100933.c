//FormAI DATASET v1.0 Category: Memory management ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p, n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    p = (int*) malloc(n*sizeof(int));

    // Memory allocation check
    if(p == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for(i=0;i<n;i++){
        *(p+i) = i+1; // storing values at the allocated memory
    }

    printf("\nElements stored in the memory: ");
    for(i=0;i<n;i++){
        printf("%d ", *(p+i)); // printing values from the memory
    }

    // freeing the allocated memory
    free(p);

    return 0;
}