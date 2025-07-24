//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>

#define ARRAY_SIZE 100
#define MAX_THREADS 4

int arr[ARRAY_SIZE];

typedef struct {
    int start_index;
    int end_index;
} sort_params;

void fill_array(){
    srand(time(0));
    for(int i=0; i<ARRAY_SIZE; i++){
        arr[i] = rand()%100;
    }
}

void print_array(){
    for(int i=0; i<ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int start, int end){
    for(int i=start+1; i<=end; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=start && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(int start, int mid, int end){
    int l_size = mid-start+1;
    int r_size = end-mid;
    int left[l_size], right[r_size];
    for(int i=0; i<l_size; i++){
        left[i] = arr[start+i];
    }
    for(int i=0; i<r_size; i++){
        right[i] = arr[mid+1+i];
    }
    int i=0, j=0, k=start;
    while(i<l_size && j<r_size){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<l_size){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<r_size){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void* async_sort(void* arg){
    sort_params* params = (sort_params*) arg;
    insertion_sort(params->start_index, params->end_index);
    pthread_exit(NULL);
}

int main(){
    fill_array();
    printf("Original Array:\n");
    print_array();

    pthread_t threads[MAX_THREADS];
    sort_params params[MAX_THREADS];
    int seg_size = ARRAY_SIZE/MAX_THREADS;
    for(int i=0; i<MAX_THREADS; i++){
        int start = i*seg_size;
        int end = (i+1)*seg_size-1;
        if(i == MAX_THREADS-1){
            end = ARRAY_SIZE-1;
        }
        params[i].start_index = start;
        params[i].end_index = end;
        pthread_create(&threads[i], NULL, async_sort, (void*)&params[i]);
    }

    for(int i=0; i<MAX_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    for(int i=1; i<=MAX_THREADS; i++){
        int mid = i*seg_size-1;
        merge(0, mid, i*seg_size-1);
    }

    printf("Sorted Array:\n");
    print_array();

    return 0;
}