//FormAI DATASET v1.0 Category: Sorting ; Style: statistical
//PROGRAM TO SORT AN ARRAY OF INTEGERS USING BUBBLE SORT TECHNIQUE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0)); //SEEDING RANDOM NUMBER GENERATOR WITH TIME

    int arr[100], n, i, j;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    //POPULATING ARRAY WITH RANDOM NUMBERS
    for(i=0;i<n;i++){
        arr[i] = rand()%100; //GENERATING NUMBERS BETWEEN 0 and 99
    }

    printf("\nUNSORTED ARRAY:\n");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]); //DISPLAYING THE UN-SORTED ARRAY
    }

    //BUBBLE SORT IMPLEMENTATION
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\n\nSORTED ARRAY:\n");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]); //DISPLAYING THE SORTED ARRAY
    }

    printf("\n\n");
    return 0; //PROGRAM TERMINATES SUCCESSFULLY
}