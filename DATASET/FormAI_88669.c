//FormAI DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *arr, int n){
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (*(arr+j) > *(arr+j+1)) {
                temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
}

void printArray(int *arr, int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int size = 10;
    int arr[size];

    for(int i=0;i<size;i++){
        int num = (rand() % (100 - 1 + 1)) + 1;
        *(arr+i) = num;
    }

    printf("Array before sorting: ");
    printArray(arr,size);

    bubbleSort(arr,size);

    printf("Array after sorting: ");
    printArray(arr,size);
    
    return 0;
}