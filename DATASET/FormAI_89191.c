//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include<stdio.h>
#include<time.h>

int main(){
    int arr[100000];
    int n = 100000;
    clock_t start, end;
    double time_taken;
    int i;

    //initialize array with random numbers
    for(i=0;i<n;i++)
        arr[i]=rand();

    //measure time taken to sort array using Bubble Sort
    start = clock();
    bubbleSort(arr,n);
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken by bubble sort: %lf seconds\n",time_taken);

    //initialize array with random numbers
    for(i=0;i<n;i++)
        arr[i]=rand();

    //measure time taken to sort array using Quick Sort
    start = clock();
    quickSort(arr,0,n-1);
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken by quick sort: %lf seconds\n",time_taken);

    return 0;

}

void bubbleSort(int arr[], int n){
    int i,j,temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    int j,temp;
    for(j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}