//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#define MAXSIZE 10

/* Function to search for an element in an array */
int linear_search(int arr[], int size, int search_element) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == search_element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAXSIZE], size, search_element;
    int i, found_index;
    
    /* Input size of array */
    printf("Enter size of array: ");
    scanf("%d", &size);
    
    /* Input elements of array */
    printf("Enter %d elements in array: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    /* Input element to search in array */
    printf("Enter element to search in array: ");
    scanf("%d", &search_element);
    
    /* Call linear_search function to search for search_element in array */
    found_index = linear_search(arr, size, search_element);
    if (found_index == -1) {
        printf("%d not found in array.", search_element);
    } else {
        printf("%d found at index %d in array.", search_element, found_index);
    }
    return 0;
}