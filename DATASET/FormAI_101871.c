//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_NODES 10

int graph[MAX_NODES][MAX_NODES];

void* printGraph(void *tid){
    int id = *(int*)tid;
    printf("\nGraph representation from thread %d:\n", id);
    for(int i=0;i<MAX_NODES;i++){
        for(int j=0;j<MAX_NODES;j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    pthread_exit(NULL);
}

void* modifyGraph(void *row){
    int r = *(int*)row;
    for(int i=0;i<MAX_NODES;i++){
        graph[r][i] = (graph[r][i]==1)?0:1;
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];
    int rows[MAX_THREADS];
    int rc;
    
    //initialize graph
    for(int i=0;i<MAX_NODES;i++){
        for(int j=0;j<MAX_NODES;j++){
            if(i==j) graph[i][j] = 0;
            else if(i%2==0 && j%2==1) graph[i][j] = 1;
            else graph[i][j] = 0;
        }
    }

    //create threads to print graph
    for(int i=0;i<MAX_THREADS/2;i++){
        ids[i] = i;
        rc = pthread_create(&threads[i], NULL, printGraph, (void *)&ids[i]);
        if(rc){
            printf("Error creating thread %d", i);
            exit(-1);
        }
    }

    //create threads to modify graph
    for(int i=MAX_THREADS/2;i<MAX_THREADS;i++){
        rows[i] = i - MAX_THREADS/2;
        rc = pthread_create(&threads[i], NULL, modifyGraph, (void *)&rows[i]);
        if(rc){
            printf("Error creating thread %d", i);
            exit(-1);
        }
    }

    //wait for all threads to complete
    for(int i=0;i<MAX_THREADS;i++){
        pthread_join(threads[i], NULL);
    }

    printf("\nModified graph:\n");
    for(int i=0;i<MAX_NODES;i++){
        for(int j=0;j<MAX_NODES;j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}