//FormAI DATASET v1.0 Category: Sorting ; Style: scalable
#include <stdio.h>

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {23, 56, 11, 98, 77};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {4, 16, 89, 7, 40, 25};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int arr3[] = {100, 500, 230, 310, 75, 900, 50};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("Before sorting:\n");
    printArray(arr1, size1);
    printf("\n");
    
    bubbleSort(arr1, size1);
    
    printf("After sorting:\n");
    printArray(arr1, size1);
    printf("\n");
    
    printf("Before sorting:\n");
    printArray(arr2, size2);
    printf("\n");
    
    bubbleSort(arr2, size2);
    
    printf("After sorting:\n");
    printArray(arr2, size2);
    printf("\n");
    
    printf("Before sorting:\n");
    printArray(arr3, size3);
    printf("\n");
    
    bubbleSort(arr3, size3);
    
    printf("After sorting:\n");
    printArray(arr3, size3);
    printf("\n");
    
    return 0;
}