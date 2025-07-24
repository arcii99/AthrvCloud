//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// struct used to pass arguments to threads
struct move_args {
    int disc_num;
    char start_peg;
    char end_peg;
    char temp_peg;
};

// function that performs the Tower of Hanoi algorithm
void move(int disc_num, char start_peg, char end_peg, char temp_peg) {
    if (disc_num == 0) {
        return;
    }
    move(disc_num-1, start_peg, temp_peg, end_peg);
    printf("Move disc %d from %c to %c\n", disc_num, start_peg, end_peg);
    move(disc_num-1, temp_peg, end_peg, start_peg);
}

// thread function that calls the move function
void *thread_move(void *arguments) {
    struct move_args *args = (struct move_args *) arguments;
    move(args->disc_num, args->start_peg, args->end_peg, args->temp_peg);
    pthread_exit(NULL);
}

int main() {
    int disc_num = 3;  // number of discs to move
    pthread_t thread;  // thread object

    // create thread arguments
    struct move_args args;
    args.disc_num = disc_num;
    args.start_peg = 'A';
    args.end_peg = 'C';
    args.temp_peg = 'B';

    // start thread
    if (pthread_create(&thread, NULL, thread_move, (void *) &args)) {
        fprintf(stderr, "Error creating thread\n");
        exit(1);
    }

    // join thread
    if (pthread_join(thread, NULL)){
        fprintf(stderr, "Error joining thread\n");
        exit(1);
    }

    return 0;
}