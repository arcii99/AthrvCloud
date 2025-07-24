//FormAI DATASET v1.0 Category: Benchmarking ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 10000

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubbleSort(int arr[], int n){
    int i, j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n){
    int i, j, min_index;
    for(i=0;i<n-1;i++){
        min_index=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(&arr[min_index], &arr[i]);
    }
}

void insertionSort(int arr[], int n){
    int i, j, key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low-1;
    int j;
    for(j=low;j<=high-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void printArr(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr1[ARRAY_SIZE], arr2[ARRAY_SIZE], arr3[ARRAY_SIZE], arr4[ARRAY_SIZE], arr5[ARRAY_SIZE];
    int i;
    for(i=0;i<ARRAY_SIZE;i++){
        arr1[i]=rand()%1000;
        arr2[i]=rand()%1000;
        arr3[i]=rand()%1000;
        arr4[i]=rand()%1000;
        arr5[i]=rand()%1000;
    }
    clock_t t;
    t=clock();
    bubbleSort(arr1, ARRAY_SIZE);
    t=clock()-t;
    printf("Bubble Sort: %f seconds\n", ((double)t)/CLOCKS_PER_SEC);
    t=clock();
    selectionSort(arr2, ARRAY_SIZE);
    t=clock()-t;
    printf("Selection Sort: %f seconds\n", ((double)t)/CLOCKS_PER_SEC);
    t=clock();
    insertionSort(arr3, ARRAY_SIZE);
    t=clock()-t;
    printf("Insertion Sort: %f seconds\n", ((double)t)/CLOCKS_PER_SEC);
    t=clock();
    mergeSort(arr4, 0, ARRAY_SIZE-1);
    t=clock()-t;
    printf("Merge Sort: %f seconds\n", ((double)t)/CLOCKS_PER_SEC);
    t=clock();
    quickSort(arr5, 0, ARRAY_SIZE-1);
    t=clock()-t;
    printf("Quick Sort: %f seconds\n", ((double)t)/CLOCKS_PER_SEC);
    return 0;
}