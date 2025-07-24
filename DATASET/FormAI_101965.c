//FormAI DATASET v1.0 Category: Sorting ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

//Function to perform Merge Sort
void merge(int arr[],int low,int mid,int high){
    int i,j,k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1],R[n2];

    for(i=0;i < n1; i++)
        L[i] = arr[low + i];

    for(j=0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i=0;
    j=0;
    k=low;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int low,int high){
    if(low < high){
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is : ");
    printArray(arr,n);

    mergeSort(arr,0,n-1);

    printf("\nSorted array is : ");
    printArray(arr,n);

    return 0;
}