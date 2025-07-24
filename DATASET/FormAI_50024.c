//FormAI DATASET v1.0 Category: Sorting ; Style: brave
#include<stdio.h>

//sorting function
void bubble_sort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    //declaration and initialization of an array
    int arr[10] = {5, 6, 17, 3, 25, 10, 8, 2, 14, 7};

    //calling the sorting function
    bubble_sort(arr, 10);

    //printing the sorted array
    printf("The sorted array is:\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}