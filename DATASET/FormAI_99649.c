//FormAI DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main(){
    int* ptr;
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    if(ptr == NULL){
        printf("Memory Allocation Failed!\n");
        exit(0);
    }

    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d", ptr+i);
    }

    printf("The elements are: ");

    for(i=0;i<n;i++){
        printf("%d ", *(ptr+i));
    }

    free(ptr); 
    return 0;
}