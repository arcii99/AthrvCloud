//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>

// function to implement linear search algorithm
int linear_search(int array[], int n, int x){
    for (int i = 0; i < n; i++){
        if (array[i] == x){
            return i; // return index of the element if found
        }
    }
    return -1; // return -1 if element is not found
}

int main(){
    int n, array[100], x, result;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    
    printf("Enter the elements in the array:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    
    printf("Enter element to be searched: ");
    scanf("%d", &x);

    result = linear_search(array, n, x); // call the linear search function
    
    if (result == -1){
        printf("Element not found in the array!\n");
    }
    else {
        printf("Element found at index %d in the array!\n", result);
    }

    return 0;
}