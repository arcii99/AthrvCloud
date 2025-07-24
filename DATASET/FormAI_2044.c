//FormAI DATASET v1.0 Category: Benchmarking ; Style: systematic
#include<stdio.h>
#include<time.h>

#define MAX 1000000
#define N 10

int main(){
    int arr[MAX];
    double elapsed_time, start_time, end_time;

    // code to generate random numbers in array
    srand(time(NULL));
    for(int i=0; i<MAX; i++){
        arr[i] = rand() % MAX;
    }

    // bubble sort
    printf("Bubble Sort:\n");
    start_time = clock();
    for(int i=0; i<MAX-1; i++){
        for(int j=0; j<MAX-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end_time = clock();
    elapsed_time = (double)(end_time-start_time) / CLOCKS_PER_SEC;
    printf("Time taken to sort using bubble sort: %lf seconds\n",elapsed_time);

    // selection sort
    printf("\nSelection Sort:\n");
    start_time = clock();
    for(int i=0; i<MAX-1; i++){
        int min_index = i;
        for(int j=i+1; j<MAX; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    end_time = clock();
    elapsed_time = (double)(end_time-start_time) / CLOCKS_PER_SEC;
    printf("Time taken to sort using selection sort: %lf seconds\n",elapsed_time);

    // insertion sort
    printf("\nInsertion Sort:\n");
    start_time = clock();
    for(int i=1; i<MAX; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    end_time = clock();
    elapsed_time = (double)(end_time-start_time) / CLOCKS_PER_SEC;
    printf("Time taken to sort using insertion sort: %lf seconds\n",elapsed_time);

    // quick sort
    printf("\nQuick Sort:\n");
    start_time = clock();
    quick_sort(arr, 0, MAX-1);
    end_time = clock();
    elapsed_time = (double)(end_time-start_time) / CLOCKS_PER_SEC;
    printf("Time taken to sort using quick sort: %lf seconds\n",elapsed_time);

    // print top N elements of sorted array
    printf("\nTop %d elements of sorted array:\n", N);
    for(int i=0; i<N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void quick_sort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<=high-1; j++){
        if(arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}