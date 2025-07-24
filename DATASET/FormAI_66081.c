//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

//Defining a static array of length 5
#define SIZE 5

//Defining a recursive function to take input and select largest number
void select_largest_number(int arr[], int size, int largest_num, int index) {
    
    //Base Case
    if (index == size) {
        printf("The largest number is: %d", largest_num);
        return;
    }
    
    //Recursive Case
    if (arr[index] > largest_num) {
        largest_num = arr[index];
    }
    
    //Recursive function call
    select_largest_number(arr, size, largest_num, index+1);
}

int main() {
    int arr[SIZE];
    int i;
    
    //Taking input from user
    printf("Enter %d integer numbers: ", SIZE);
    for (i=0; i<SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    
    //Calling the recursive function
    select_largest_number(arr, SIZE, arr[0], 0);

    return 0;
}