//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void recursive_function(int *a, int size){
    if(size == 0){
        printf("Congratulations! You have successfully called a recursive function!\n");
        return;
    }
    printf("Calling the function again with size %d...\n", size-1);
    recursive_function(a, size-1);
}

int main(){
    int size = 5;
    int *a = (int*) malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
        a[i] = i;
    }
    printf("Welcome to my recursive function!\n");
    recursive_function(a, size);
    free(a);
    return 0;
}