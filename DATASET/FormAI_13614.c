//FormAI DATASET v1.0 Category: Benchmarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void bubbleSort(int arr[], int size){
    int i,j;
    for(i=0; i<size-1; i++)
        for(j=0; j<size-i-1; j++)
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(i=0; i<n1; i++)
        L[i] = arr[l+i];
    for(j=0; j<n2; j++)
        R[j] = arr[m+1+j];
    i=0; j=0; k=l;
    while(i<n1 && j<n2){
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
    while(i<n1){
        arr[k] = L[i];
        i++; k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    clock_t start, end;
    int arr[10000], size=10000, i, j, k;
    for(i=0; i<size; i++)
        arr[i] = rand() % 10000;
    start = clock();
    bubbleSort(arr,size);
    end = clock();
    printf("Time taken by Bubble Sort: %ld\n", end-start);
    for(i=0; i<size; i++)
        arr[i] = rand() % 10000;
    start = clock();
    mergeSort(arr,0,size-1);
    end = clock();
    printf("Time taken by Merge Sort: %ld\n", end-start);
    return 0;
}