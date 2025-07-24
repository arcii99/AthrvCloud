//FormAI DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>

int main() {
    //declaring an array to sort
    int arr[] = {3, 8, 2, 11, 7, 9};

    //calculating the length of the array using sizeof() function
    int arr_length = sizeof(arr)/sizeof(arr[0]);

    //printing the array before sorting
    printf("The array before sorting is:\n");
    for(int i=0; i<arr_length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //sorting the array using selection sort technique
    for(int i=0; i<arr_length-1; i++) {
        int min_idx = i;
        for(int j=i+1; j<arr_length; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
     }

     //printing the array after sorting
     printf("The array after sorting is:\n");
     for(int i=0; i<arr_length; i++) {
        printf("%d ", arr[i]);
     }
     printf("\n");

     return 0;
}