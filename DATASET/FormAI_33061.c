//FormAI DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Defining structure to pass arguments to thread */
struct arg_struct {
    int row, col;
};

/* Function to print C pattern for a given row and column number */
void print_C(int row, int col) {
    /* Outer loop to traverse rows */
    for(int i=0; i<row; i++) {
        /* Inner loop to traverse columns */
        for(int j=0; j<col; j++) {
            /* Condition to print '*' character */
            if((i == 0 || i == row-1 || j == 0) && j<(col-1)) {
                printf("*");
            } 
            /* Condition to print space */
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* Function to handle thread */
void *print_C_threaded(void *arguments) {
    struct arg_struct *args = arguments;
    /* Extracting passed arguments row and col */
    int row = args->row;
    int col = args->col;
    print_C(row, col);
    pthread_exit(NULL);
}

int main() {
    int row = 10;
    int col = 10;

    /* Creating structure for thread arguments */
    struct arg_struct args = {row, col};

    /* Creating thread */
    pthread_t thread;
    int status = pthread_create(&thread, NULL, print_C_threaded, (void *)&args);

    /* Handling thread creation errors */
    if (status != 0) {
        printf("Error while creating thread\n");
        exit(EXIT_FAILURE);
    }

    /* Waiting for thread to finish */
    pthread_join(thread, NULL);

    printf("Printing C pattern using thread in a multi-threaded style is done.\n");

    return 0;
}