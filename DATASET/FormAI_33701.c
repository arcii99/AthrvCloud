//FormAI DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>

#define MAX_SIZE 100

/* Function to perform searching */
void search(int arr[], int size, int value){
    int found_flag = 0;
    for(int i=0; i<size; i++){
        if(arr[i] == value){
            printf("Element found at index %d\n", i);
            found_flag = 1;
        }
    }
    if(!found_flag){
        printf("Element not found!\n");
    }
}

int main(){
    int arr[MAX_SIZE], size, value;

    /* Input array size */
    printf("Enter array size: ");
    scanf("%d", &size);

    /* Input array elements */
    printf("Enter array elements:\n");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    /* Input element to be searched */
    printf("Enter element to be searched: ");
    scanf("%d", &value);

    /* Perform searching */
    search(arr, size, value);

    return 0;
}