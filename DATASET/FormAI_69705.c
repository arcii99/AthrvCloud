//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, j, n, max = 0;
    srand(time(NULL)); //Seed random number generator

    printf("Enter the number of rows in the array: ");
    scanf("%d", &n);
    int arr[n][n]; //Create 2D array of size n x n

    //Fill array with random integers between 0 and 99
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            arr[i][j] = rand() % 100;
        }
    }

    //Print out the array
    printf("\nArray:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", arr[i][j]);
            if(arr[i][j] > max){
                max = arr[i][j]; //Find the maximum value in the array
            }
        }
        printf("\n");
    }

    //Print out the maximum value in the array
    printf("\nMaximum value in the array: %d\n", max);

    //Print out the indices of all occurrences of the maximum value
    printf("\nIndices of all occurrences of the maximum value:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(arr[i][j] == max){
                printf("(%d,%d) ", i, j);
            }
        }
    }

    return 0;
}