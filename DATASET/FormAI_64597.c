//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Romeo and Juliet
/* 
In fair C code, where we lay our scene,
From ancient grudge break to new mutiny,
Where civil blood makes civil hands unclean.

From forth the fatal loins of these two foes
A pair of star-cross'd lovers take their life;
Whole misadventured piteous overthrows
Do with their death bury their parents' strife.

The performance-critical component's task at hand,
Is to sort large arrays with efficiency grand.
To quicken the process, we'll use quicksort,
A method swift and efficient, we'll resort.

The function we use is recursive in nature,
With partitioning done to suit, with care.
The pivot element we'll choose at random,
To ensure the array is sorted in tandem.

We'll call the function to sort the array,
From start to end, we'll let it sway.
Quicksort will do its job with speed,
And with our array, we'll surely succeed.

The code below is all you'll need,
To sort an array, with quickness and heed.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int arr[1000000];
    int n;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}