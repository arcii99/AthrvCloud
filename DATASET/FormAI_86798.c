//FormAI DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 20

int arr[] = {2,3,4,5,7,9,11,13,15,17,18,19,20,23,25,29,30,32,33,36}; // sorted array
int n = sizeof(arr)/sizeof(arr[0]); // size of array
int key = 23; // element to be searched
int result = -1; // to store the index of the element if found

void* asyncBinarySearch(void* arg) {
    int* index = (int*) arg;
    int low = index[0];
    int high = index[1];
    int mid;
    while(low <= high) {
       mid = low + (high-low)/2;
       if(arr[mid] == key) {
           result = mid; // store the index if found
           return NULL;
       }
       else if(arr[mid] < key)
           low = mid+1;
       else
           high = mid-1;
    }
    return NULL;
}

int main() {
    pthread_t tid;
    int i,j;
    int interval = n/MAX;
    int index[MAX][2];

    // setting the intervals for each thread
    for(i=0, j=0; i<MAX; i++, j+=interval) {
        index[i][0] = j; // start index for the interval
        index[i][1] = j+interval-1; // end index for the interval
    }
    index[MAX-1][1] = n-1; // making sure the last interval covers the rest of the array 

    // creating the threads
    for(i=0; i<MAX; i++) {
        pthread_create(&tid, NULL, asyncBinarySearch, index[i]);
        printf("\nThread %d created for index %d-%d", i+1, index[i][0], index[i][1]);
        sleep(1); //wait for each thread to start before creating the next one
    }

    for(i=0; i<MAX; i++) {
        pthread_join(tid, NULL); // wait for all threads to finish executing
    }

    if(result == -1)
        printf("\nElement not found!");
    else
       printf("\nElement found at index %d.", result);
    return 0;
}