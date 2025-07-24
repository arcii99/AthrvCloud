//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// defining the data structure for the buckets
struct bucket{
    int* arr;
    int used;
    int size;
};

typedef struct bucket Bucket;

// function to add an element to a bucket
void add_to_bucket(Bucket* b, int ele){
    // checking if the bucket is already filled to its size
    if(b->used >= b->size){
        // doubling the size of the bucket
        b->arr = realloc(b->arr, b->size*2*sizeof(int));
        b->size *= 2;
    }
    // adding the element to the bucket
    b->arr[b->used++] = ele;
}

// function to implement the bucket sort algorithm
void bucket_sort(int arr[], int n, int m){
    // creating an array of buckets
    Bucket buckets[m];
    for(int i=0; i<m; i++){
        // initialising the size and used values of each bucket to 0
        buckets[i].size = 1;
        buckets[i].used = 0;
        // allocating memory for the array inside the bucket
        buckets[i].arr = malloc(buckets[i].size*sizeof(int));
    }
    // adding each element of the given array to a bucket
    for(int i=0; i<n; i++){
        int index = (arr[i]*m)/100;
        add_to_bucket(&buckets[index], arr[i]);
    }
    // sorting each bucket using insertion sort
    for(int i=0; i<m; i++){
        int len = buckets[i].used;
        for(int j=1; j<len; j++){
            int key = buckets[i].arr[j];
            int k = j-1;
            while(k>=0 && buckets[i].arr[k]>key){
                buckets[i].arr[k+1] = buckets[i].arr[k];
                k--;
            }
            buckets[i].arr[k+1] = key;
        }
    }
    // creating the final sorted array by concatenating all the buckets
    int index = 0;
    for(int i=0; i<m; i++){
        int len = buckets[i].used;
        for(int j=0; j<len; j++){
            arr[index++] = buckets[i].arr[j];
        }
    }
    // deallocating the memory for all the buckets
    for(int i=0; i<m; i++){
        free(buckets[i].arr);
    }
}

int main(){
    // generating a random array of integers
    srand(time(NULL));
    int n = 10;
    int arr[n];
    for(int i=0; i<n; i++){
        arr[i] = rand()%101;
    }
    // printing the unsorted array
    printf("Unsorted array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // sorting the array using bucket sort
    int m = 5;
    bucket_sort(arr, n, m);

    // printing the sorted array
    printf("Sorted array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}