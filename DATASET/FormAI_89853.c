//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

// Defining global variables
int n;
char source_rod = 'A';
char destination_rod = 'B';
char aux_rod = 'C';

// Defining the struct for the thread arguments
struct thread_args {
    int disk;
    char src_rod;
    char dest_rod;
    char aux_rod;
};

// Recursive function to move the disks from source to destination rod
void moveDisk(char fromRod, char toRod, int disk) {
    printf("Move disk %d from rod %c to rod %c\n", disk, fromRod, toRod);
    sleep(1);
}

// Asynchronous function to move the disks recursively
void *towerOfHanoi(void *args) {

    struct thread_args *threadArgs = args;
    int diskNum = threadArgs->disk;
    char fromRod = threadArgs->src_rod;
    char toRod = threadArgs->dest_rod;
    char auxRod = threadArgs->aux_rod;

    // Base Case
    if (diskNum == 1) {
        moveDisk(fromRod, toRod, diskNum);
        return NULL;
    }

    // Move the top n-1 disks from A to B using C as auxiliary
    pthread_t t1;
    struct thread_args *t1args = (struct thread_args*) malloc(sizeof(struct thread_args));
    t1args->disk = diskNum - 1;
    t1args->src_rod = fromRod;
    t1args->dest_rod = auxRod;
    t1args->aux_rod = toRod;
    pthread_create(&t1, NULL, towerOfHanoi, t1args);

    // Move the last disk from A to C
    sleep(1);

    // Move the top n-1 disks from B to C using A as auxiliary
    pthread_t t2;
    struct thread_args *t2args = (struct thread_args*) malloc(sizeof(struct thread_args));
    t2args->disk = diskNum - 1;
    t2args->src_rod = auxRod;
    t2args->dest_rod = toRod;
    t2args->aux_rod = fromRod;
    pthread_create(&t2, NULL, towerOfHanoi, t2args);

    // Wait for the threads to finish and then exit
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    free(t1args);
    free(t2args);

    return NULL;
}

int main() {

    // Get user input for the number of disks
    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Create the thread argument struct
    struct thread_args *initArgs = (struct thread_args*) malloc(sizeof(struct thread_args));
    initArgs->disk = n;
    initArgs->src_rod = source_rod;
    initArgs->dest_rod = destination_rod;
    initArgs->aux_rod = aux_rod;

    // Create the thread and execute the tower of hanoi function asynchronously
    pthread_t t;
    pthread_create(&t, NULL, towerOfHanoi, initArgs);

    // Wait for the thread to finish and then exit
    pthread_join(t, NULL);

    free(initArgs);

    return 0;
}