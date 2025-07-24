//FormAI DATASET v1.0 Category: Sorting ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10 // number of integers to sort
#define THREADS 2 // number of threads to use

int arr[SIZE] = {3,6,1,8,4,2,9,7,5,0}; // array to sort
int left = 0, right = SIZE-1; // indices for quicksort
pthread_mutex_t mutex; // mutex to control access to the indices

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right){
    int pivot = arr[right];
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);
    return i+1;
}

void quicksort(int *arr, int left, int right){
    if(left < right){
        int p_index = partition(arr, left, right);
        quicksort(arr, left, p_index-1);
        quicksort(arr, p_index+1, right);
    }
}

void* sort(void* arg){
    int thread_no = *(int*)arg;
    while(true){
        pthread_mutex_lock(&mutex);
        if(left <= right){
            // critical section
            int l = left, r = right;
            left += 2; right -= 2;
            pthread_mutex_unlock(&mutex);
            quicksort(arr, l, r);
            printf("Thread %d sorted arr[%d-%d]\n", thread_no, l, r);
        }else{
            pthread_mutex_unlock(&mutex);
            break;
        }
    }
    return NULL;
}

int main(){
    pthread_t threads[THREADS];
    int thread_nos[THREADS];

    pthread_mutex_init(&mutex, NULL);

    // create threads
    for(int i = 0; i < THREADS; i++){
        thread_nos[i] = i;
        pthread_create(&threads[i], NULL, sort, &thread_nos[i]);
    }

    // join threads
    for(int i = 0; i < THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    // merge sorted subarrays
    int sub_len = SIZE/THREADS;
    for(int i = 0; i < SIZE; i += sub_len){
        int low = i, mid = i + sub_len/2, high = i + sub_len - 1;
        if(high > SIZE-1) high = SIZE-1;
        int temp[sub_len];
        int x = low, y = mid, z = 0;
        while(x < mid && y <= high){
            if(arr[x] < arr[y]){
                temp[z++] = arr[x++];
            }else{
                temp[z++] = arr[y++];
            }
        }
        while(x < mid) temp[z++] = arr[x++];
        while(y <= high) temp[z++] = arr[y++];
        for(int j = 0; j < z; j++){
            arr[low+j] = temp[j];
        }
    }

    // print sorted array
    printf("Sorted Array: ");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    pthread_mutex_destroy(&mutex);

    return 0;
}