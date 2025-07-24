//FormAI DATASET v1.0 Category: Sorting ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    printf("Welcome to the Random Number Sorting program!\n");
    printf("How many random numbers would you like to generate? : ");

    int num, i, j, temp;

    srand(time(0));

    //Checking for user input
    if(scanf("%d", &num) != 1){
        printf("Invalid input! Please enter a number.\n");
        return 0;
    }

    //Creating an array of random numbers
    int arr[num];
    for(i = 0; i < num; i++){
        arr[i] = rand()%100;
    }

    printf("\nGenerating random numbers...\n\n");
    for(i = 0; i < num; i++){
        printf("%d ", arr[i]);
    }

    //Sorting the array in descending order
    for(i = 0; i < num-1; i++){
        for(j = i+1; j < num; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\n\nSorting the random numbers in descending order...\n\n");
    for(i = 0; i < num; i++){
        printf("%d ", arr[i]);
    }

    printf("\n\nThank you for using the Random Number Sorting program!\n");

    return 0;
}