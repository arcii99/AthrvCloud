//FormAI DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>

// function to perform the Linear Search
int linear_search(int array[], int size, int element) { 
    for(int i=0;i<size;i++) {
        if(array[i] == element) 
            return i; // returning the index of the element
    }
    return -1;   // return -1 when element is not present in array
}

int main() {
    int size, element;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the elements of the array: ");
    for(int i=0;i<size;i++)
        scanf("%d", &array[i]);
    printf("Enter the element to search: ");
    scanf("%d", &element);
    int result = linear_search(array, size, element);
    if(result == -1)
        printf("%d is not present in the array.\n", element);
    else
        printf("%d is present at index %d.\n", element, result);
    return 0;
}