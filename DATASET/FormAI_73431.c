//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define THREAD_COUNT 2

int arr[100000], key, search_index = -1;

void* search(void* thread_id){
    long tid = (long)thread_id;

    int lower_bound = tid * (100000 / THREAD_COUNT);
    int upper_bound = (tid + 1) * (100000 / THREAD_COUNT);

    for(int i = lower_bound; i < upper_bound; i++){
        if(arr[i] == key){
            search_index = i;
            pthread_exit(NULL);
        }
    }

    pthread_exit(NULL);
}

int main(){
    pthread_t threads[THREAD_COUNT];
    int thread_status;

    //Initialize the Array
    for(int i = 0; i < 100000; i++){
        arr[i] = i + 1;
    }

    //Get the Input Key from the User
    printf("Enter the Key to be Searched: ");
    scanf("%d", &key);

    //Create Threads
    for(long i = 0; i < THREAD_COUNT; i++){
        thread_status = pthread_create(&threads[i], NULL, search, (void*)i);

        if(thread_status != 0){
            printf("Error in Creating Thread %ld. Exiting...\n", i);
            exit(-1);
        }
    }

    //Wait for Threads to Complete
    for(long i = 0; i < THREAD_COUNT; i++){
        thread_status = pthread_join(threads[i], NULL);

        if(thread_status != 0){
            printf("Error in Joining Thread %ld. Exiting...\n", i);
            exit(-1);
        }
    }

    //Check if Key is Found
    if(search_index == -1){
        printf("Key Not Found in the Array.\n");
    }
    else{
        printf("Key Found at Index %d.\n", search_index);
    }

    return 0;
}