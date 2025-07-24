//FormAI DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int* ptr;
    int n, i, sum = 0;

    //taking input from user
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // allocating memory to the pointer
    ptr = (int*) calloc(n, sizeof(int)); 

    //taking random input for the array created using random number generator
    srand(time(0));
    for(i=0; i<n; i++){
        ptr[i] = rand()%100;
    }

    printf("The array is: ");
    for(i=0; i<n; i++){
        printf("%d ", ptr[i]);
        sum += ptr[i];
    }

    printf("\nSum of the array is %d.\n", sum);

    //deallocating memory
    free(ptr); 

    return 0;
}