//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 8   //size of percolation grid
#define THREADS 4   //number of threads to run

bool grid[SIZE][SIZE];  //percolation grid

//helper function to randomly fill the grid
void generate_grid() {
    srand(time(0));
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(rand() % 5 == 0)
                grid[i][j] = true;
            else
                grid[i][j] = false;
        }
    }
}

void* check_percolation(void* rank){
    int thread_rank = *(int*) rank;
    int start_row = (SIZE / THREADS) * thread_rank;   //start row for each thread
    int end_row = (SIZE / THREADS) * (thread_rank + 1);   //end row for each thread
    
    //check for percolation
    for(int i=start_row; i<end_row; i++){
        for(int j=0; j<SIZE; j++){
            if(grid[i][j])
                continue;
            if(i == 0)
                grid[i][j] = true;
            else{
                if(grid[i-1][j])
                    grid[i][j] = true;
                if(j > 0 && grid[i][j-1])
                    grid[i][j] = true;
                if(j < SIZE-1 && grid[i][j+1])
                    grid[i][j] = true;
            }
        }
    }
    pthread_exit(NULL);
}

//function to print the grid
void print_grid(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(grid[i][j])
                printf("x ");
            else
                printf("- ");
        }
        printf("\n");
    }
}

int main() {
    pthread_t threads[THREADS];
    int rank[THREADS];
    
    generate_grid();
    
    for(int i=0; i<THREADS; i++){
        rank[i] = i;
        pthread_create(&threads[i], NULL, check_percolation, &rank[i]);
    }
    
    for(int i=0; i<THREADS; i++)
        pthread_join(threads[i], NULL);
    
    printf("\n");
    print_grid();
    
    return 0;
}