//FormAI DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000
#define MAX_VAL 100

int array[SIZE];
int temp[SIZE];

void fill_array() {
    srand((unsigned int)time(NULL));
    for(int i=0; i<SIZE; i++) {
        array[i] = rand() % MAX_VAL;
    }
}

void print_array() {
    for(int i=0; i<SIZE; i++) {
        printf("%d ",array[i]);
    }
    printf("\n");
}

void merge_sort(int low, int high) {
    if(low>=high) return;
    int mid = (low+high)/2;
    merge_sort(low, mid);
    merge_sort(mid+1, high);
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high) {
        if(array[i]<array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }
    while(i<=mid) {
        temp[k++] = array[i++];
    }
    while(j<=high) {
        temp[k++] = array[j++];
    }
    for(int i=low; i<=high; i++) {
        array[i] = temp[i];
    }
}

int main() {
    fill_array();
    clock_t start = clock();
    merge_sort(0, SIZE-1);
    clock_t end = clock();
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken for sorting %d integers: %f seconds\n",SIZE,time_taken);
    return 0;
}