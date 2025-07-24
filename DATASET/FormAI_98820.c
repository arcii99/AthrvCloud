//FormAI DATASET v1.0 Category: Memory management ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

int main(){

    int *ptr;
    int lower_bound, upper_bound, sum = 0, i, n; 

    printf("Enter the value of n: ");
    scanf("%d", &n);

    //allocate memory dynamically for array
    ptr = (int*) malloc(n*sizeof(int));

    if (ptr==NULL){     //if memory allocation fails
        printf("Memory allocation failed\n");
        exit(1);
    }
    else{   //if memory allocation succeeds

        //accept the lower and upper bounds of numbers
        printf("Enter the lower bound: ");
        scanf("%d", &lower_bound);
        printf("Enter the upper bound: ");
        scanf("%d", &upper_bound);

        //generate n random integer numbers between lower_bound and upper_bound
        for(i=0; i<n; i++){
            *(ptr+i) = (rand() % (upper_bound-lower_bound+1)) + lower_bound;
            sum += *(ptr+i);
        }

        printf("The sum of %d randomly generated numbers between %d and %d is %d", n, lower_bound, upper_bound, sum);

        //free the dynamically allocated memory to avoid memory leaks
        free(ptr);
    }

    return 0;
}