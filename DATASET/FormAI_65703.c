//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define SIZE 1000
#define BUCKET_SIZE 10

int arr[SIZE];

int buckets[BUCKET_SIZE][SIZE];
int bucket_sizes[BUCKET_SIZE];

pthread_mutex_t mutexes[BUCKET_SIZE];

void *sort_thread(void *bucket_num){
    int i,j,temp,n = *(int*)bucket_num;
    for(i = 0;i < bucket_sizes[n] - 1;i++){
        for(j = i+1;j < bucket_sizes[n];j++){
            if(buckets[n][i] > buckets[n][j]){
                temp = buckets[n][i];
                buckets[n][i] = buckets[n][j];
                buckets[n][j] = temp;
            }
        }
    }
}

void *combine_thread(void *arg){
    int i,j,k=0;
    for(i=0;i<BUCKET_SIZE;i++) {
        for(j = 0;j < bucket_sizes[i];j++){
            arr[k++] = buckets[i][j];
        }
    }
}

void bucket_sort(int maxval, int n){
    int i,j,k;
    int *b;
    pthread_t threads[MAX_THREADS];

    for(i=0;i<BUCKET_SIZE;i++) {
        bucket_sizes[i] = 0;
        pthread_mutex_init(&mutexes[i],NULL);
    }
    b = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++) {
        b[i] = (int)(((float)arr[i]/maxval)*BUCKET_SIZE);
        pthread_mutex_lock(&mutexes[b[i]]);
        buckets[b[i]][bucket_sizes[b[i]]++] = arr[i];
        pthread_mutex_unlock(&mutexes[b[i]]);
    }

    for(i=0; i<BUCKET_SIZE; i++){
        pthread_create(&threads[i], NULL, sort_thread, &i);
    }

    for(i=0; i<BUCKET_SIZE; i++){
        pthread_join(threads[i], NULL);
    }
        
    pthread_create(&threads[0], NULL, combine_thread, NULL);
    pthread_join(threads[0], NULL);
    free(b);
}

int main(){
    int i;
    for(i=0; i<SIZE; i++){
        arr[i] = rand() % 1000;
    }
    bucket_sort(1000, SIZE);

    printf("Sorted array:\n");
    for(i=0; i<SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}