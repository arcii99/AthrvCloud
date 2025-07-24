//FormAI DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROW 10
#define COL 10

// Global variable to hold the pattern
char pattern[][COL] = { 
    {'*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' '},
    {'*', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*'}
};

// Global variables to keep track of printing positions and direction
int current_row, current_col;
int dir_row, dir_col;

// Thread function to print the pattern
void *print_pattern(void* arg) {
    int i;
    
    // Loop through the pattern and print each character
    for (i = 0; i < ROW * COL; i++) {
        printf("%c", pattern[current_row][current_col]);
        fflush(stdout);
        
        // Move the printing position based on direction
        current_row += dir_row;
        current_col += dir_col;
        
        // If the printing position is out of range, change direction
        if (current_row < 0 || current_row == ROW || current_col < 0 || current_col == COL) {
            current_row -= dir_row;
            current_col -= dir_col;
            if (dir_row == 0) {
                dir_row = dir_col;
                dir_col = 0;
            } else {
                dir_col = -dir_row;
                dir_row = 0;
            }
            current_row += dir_row;
            current_col += dir_col;
        }
        
        // Sleep for some time to create a slow printing effect
        usleep(50000);
    }
    
    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;
    int i, j;
    
    // Initialize variables
    current_row = 0;
    current_col = 0;
    dir_row = 0;
    dir_col = 1;
    
    // Create the thread to print the pattern
    if (pthread_create(&tid, NULL, &print_pattern, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        exit(1);
    }
    
    // Wait for the thread to finish before exiting
    pthread_join(tid, NULL);
    
    return 0;
}