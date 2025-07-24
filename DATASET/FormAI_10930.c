//FormAI DATASET v1.0 Category: Educational ; Style: synchronous
#include<stdio.h>

int main(){
    int arr[5] = {10, 20, 30, 40, 50}; //declaring array

    printf("Array elements are: ");
    for(int i=0; i < 5; i++){ //iterating through array
        printf("%d ", arr[i]); //printing each element of the array
    }

    printf("\n");

    int i = 0, sum = 0;
    while(i < 5){ //iterating through array using while loop
        sum += arr[i]; //adding each element to sum
        i++;
    }

    printf("Sum of array elements using while loop: %d\n", sum);

    i = 0; //reseting i to 0
    sum = 0; //resetting sum to 0
    do{
        sum += arr[i]; //adding each element to sum
        i++;
    }while(i < 5); //iterating through array using do while loop

    printf("Sum of array elements using do while loop: %d\n", sum);

    return 0;
}