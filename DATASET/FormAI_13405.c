//FormAI DATASET v1.0 Category: Sorting ; Style: introspective
#include<stdio.h>

void introspective_sort(int arr[], int left, int right, int maxdepth);

void quicksort(int arr[], int left, int right);

void swap(int *x, int *y);

int median_of_three(int arr[], int left, int right);

int main(){
    int arr[10] = {1,3,5,7,9,2,4,6,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Apply introspective sort on the array
    introspective_sort(arr, 0, n-1, 2);

    // Print the sorted array
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void introspective_sort(int arr[], int left, int right, int maxdepth){
    int n = right - left + 1;

    // Check if we have partitioned small enough to use Insertion Sort
    if(n <= 16){
        for(int i=left+1; i<=right; i++){
            int key = arr[i];
            int j = i-1;

            while(j>=left && arr[j] > key){
                arr[j+1] = arr[j];
                j = j-1;
            }

            arr[j+1] = key;
        }
    }
    // If not, use Quick Sort or Heap Sort based on maxdepth
    else{
        if(maxdepth == 0){
            heap_sort(arr, left, right);
        }
        else{
            int pivot = median_of_three(arr, left, right);
            swap(&arr[pivot], &arr[right]);

            int k = partition(arr, left, right);

            introspective_sort(arr, left, k-1, maxdepth-1);
            introspective_sort(arr, k+1, right, maxdepth-1);
        }
    }
}

void quicksort(int arr[], int left, int right){
    if(left < right){
        int pivot = partition(arr, left, right);

        quicksort(arr, left, pivot-1);
        quicksort(arr, pivot+1, right);
    }
}

int partition(int arr[], int left, int right){
    int pivot = arr[right];
    int i = left - 1;

    for(int j=left; j<=right-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[right]);

    return i+1;
}

void heap_sort(int arr[], int left, int right){
    // TODO: Implement heap sort
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int median_of_three(int arr[], int left, int right){
    int center = (left + right) / 2;

    if(arr[center] < arr[left]){
        swap(&arr[left], &arr[center]);
    }

    if(arr[right] < arr[left]){
        swap(&arr[left], &arr[right]);
    }

    if(arr[right] < arr[center]){
        swap(&arr[center], &arr[right]);
    }

    return center;
}