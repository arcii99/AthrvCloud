//FormAI DATASET v1.0 Category: Memory management ; Style: happy
#include<stdio.h>

int main(){
    printf("Welcome to the Memory Management program!\n");

    //declaring variables and allocating memory
    int *p;
    p = (int*)malloc(sizeof(int) * 5);

    if(p == NULL){
        printf("Memory allocation failed!\n");
    }
    else{
        printf("Memory allocation successful!\n");
        printf("The address of the first memory block allocated is: %p\n", p);

        //writing values to the allocated memory
        for(int i=0; i<5; i++){
            *(p+i) = i*i;
        }
        printf("The values written to the memory blocks are: ");
        for(int i=0; i<5; i++){
            printf("%d ",*(p+i));
        }
        printf("\n");

        //reallocating memory
        p = (int*)realloc(p, sizeof(int) * 10);

        if(p == NULL){
            printf("Memory reallocation failed!\n");
        }
        else{
            printf("Memory reallocation successful!\n");
            printf("The address of the first memory block after reallocation is: %p\n", p);

            //writing values to newly allocated memory blocks
            for(int i=5; i<10; i++){
                *(p+i) = i*i;
            }
            printf("The values written to newly allocated memory blocks are: ");
            for(int i=5; i<10; i++){
                printf("%d ",*(p+i));
            }
            printf("\n");

            //freeing memory
            free(p);
            printf("Memory has been freed.\n");
        }
    }
    return 0;
}