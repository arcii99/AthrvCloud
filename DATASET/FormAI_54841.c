//FormAI DATASET v1.0 Category: Sorting ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void curious_sort(int *arr, int n){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                printf("Hmm, interesting... swapping %d and %d\n", arr[i], arr[j]);
            }
        }
    }
}

int main(){
    int arr[10] = {10, 7, 9, 5, 2, 1, 8, 6, 4, 3};
    printf("Original array: ");
    print_array(arr, 10);
    curious_sort(arr, 10);
    printf("Sorted array: ");
    print_array(arr, 10);
    printf("This sorting algorithm seems to be a bit curious, but it gets the job done!\n");
    return 0;
}