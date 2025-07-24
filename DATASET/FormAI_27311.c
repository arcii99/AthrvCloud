//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define N 3 //number of disks
#define MAX_MOVES (1 << N) - 1 //maximum number of moves required to solve Tower of Hanoi

int tower[3][N]; //tower array representing three rods

//print current state of the tower
void print_tower() {
    printf("\n");
    for(int i=0; i<N; i++) {
        printf("|");
        for(int j=0; j<3; j++) {
            if(tower[j][i]) {
                printf(" %d |", tower[j][i]);
            }
            else {
                printf("   |");
            }
        }
        printf("\n");
    }
    printf("___|___|___\n");
}

//move disk from source rod to destination rod
void move_disk(int source, int destination) {
    int temp = tower[source][N-1];
    tower[source][N-1] = 0;
    for(int i=N-2; i>=0; i--) {
        if(tower[source][i]) {
            temp = tower[source][i];
            tower[source][i] = 0;
            break;
        }
    }
    for(int i=0; i<N; i++) {
        if(!tower[destination][i]) {
            tower[destination][i] = temp;
            break;
        }
    }
    usleep(1000000); //wait for 1 second
    printf("\nMove disk %d from rod %d to rod %d\n", temp, source+1, destination+1);
    print_tower();
}

//solve Tower of Hanoi problem recursively
void solve_hanoi(int n, int source, int destination, int temp) {
    if(n > 0) {
        solve_hanoi(n-1, source, temp, destination);
        move_disk(source, destination);
        solve_hanoi(n-1, temp, destination, source);
    }
}

//create threads to solve Tower of Hanoi problem iteratively
void *solve_tower(void *limit) {
    int *moves = (int*)limit;
    int count = 0;
    for(int i=0; i<N; i++) {
        if(tower[0][i]) {
            count++;
        }
    }
    while(*moves < MAX_MOVES) {
        if(count % 2 == 1) {
            if(tower[0][0] < tower[2][0]) {
                move_disk(0, 2);
                (*moves)++;
            }
            else {
                move_disk(2, 0);
                (*moves)++;
            }
        }
        else {
            if(tower[0][0] < tower[1][0]) {
                move_disk(0, 1);
                (*moves)++;
            }
            else {
                move_disk(1, 0);
                (*moves)++;
            }
        }
        count++;
    }
    return NULL;
}

int main() {
    pthread_t thread;
    int limit = 0;
    printf("Initial State:\n");
    for(int i=N-1; i>=0; i--) {
        tower[0][i] = i+1;
    }
    print_tower();
    printf("\nSolving Tower of Hanoi iteratively using multithreading...\n");
    pthread_create(&thread, NULL, solve_tower, (void*)&limit);
    solve_hanoi(N, 0, 2, 1);
    pthread_join(thread, NULL);
    printf("\nFinal State:\n");
    print_tower();
    printf("\nNumber of moves required: %d\n", limit);
    return 0;
}