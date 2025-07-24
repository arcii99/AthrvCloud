//FormAI DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

int main(){

    int* myNumbers = NULL;
    int numberOfElements;
    int i;

    printf("Enter the number of elements: ");
    scanf("%d", &numberOfElements);

    myNumbers = (int*)malloc(numberOfElements * sizeof(int));

    if(myNumbers == NULL){
        printf("Not enough memory to allocate!");
        exit(1);
    }

    for(i=0;i<numberOfElements;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &myNumbers[i]);
    }

    printf("Your array: [");
    for(i=0;i<numberOfElements;i++){
        printf("%d ", myNumbers[i]);
    }
    printf("]\n");

    free(myNumbers);

    return 0;
}