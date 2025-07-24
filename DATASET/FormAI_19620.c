//FormAI DATASET v1.0 Category: Sorting ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int left, int right);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int n, option;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nSelect the sorting algorithm:\n");
    printf("1. Quick Sort\n2. Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            quickSort(arr, 0, n-1);
            printf("\nAfter sorting using Quick Sort:\n");
            break;

        case 2:
            mergeSort(arr, 0, n-1);
            printf("\nAfter sorting using Merge Sort:\n");
            break;

        default:
            printf("\nInvalid option!");
            exit(0);
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}

void quickSort(int arr[], int left, int right) {
    if(left < right) {
        int pivot = arr[right];
        int i = left - 1;

        for(int j = left; j < right; j++) {
            if(arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i+1];
        arr[i+1] = arr[right];
        arr[right] = temp;

        int partition = i+1;

        quickSort(arr, left, partition-1);
        quickSort(arr, partition+1, right);
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++) {
        L[i] = arr[left+i];
    }

    for(int i = 0; i < n2; i++) {
        R[i] = arr[mid+1+i];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while(i < n1) {
        arr[k++] = L[i++];
    }

    while(j < n2) {
        arr[k++] = R[j++];
    }
}