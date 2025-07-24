//FormAI DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

#define ROW 10
#define COL 10

int board[ROW][COL];

void initialize_board() {
    srand(time(NULL));
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board() {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(board[i][j] == 0) {
                printf(". ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

bool is_alive(int row, int col) {
    int num_alive_neighbors = 0;
    // check top
    if(row > 0) {
        if(board[row-1][col] == 1) {
            num_alive_neighbors++;
        }
        if(col > 0 && board[row-1][col-1] == 1) {
            num_alive_neighbors++;
        }
        if(col < COL-1 && board[row-1][col+1] == 1) {
            num_alive_neighbors++;
        }
    }
    // check bottom
    if(row < ROW-1) {
        if(board[row+1][col] == 1) {
            num_alive_neighbors++;
        }
        if(col > 0 && board[row+1][col-1] == 1) {
            num_alive_neighbors++;
        }
        if(col < COL-1 && board[row+1][col+1] == 1) {
            num_alive_neighbors++;
        }
    }
    // check left
    if(col > 0 && board[row][col-1] == 1) {
        num_alive_neighbors++;
    }
    // check right
    if(col < COL-1 && board[row][col+1] == 1) {
        num_alive_neighbors++;
    }
    if(board[row][col] == 0 && num_alive_neighbors == 3) {
        return true;
    }
    if(board[row][col] == 1 && (num_alive_neighbors == 2 || num_alive_neighbors == 3)) {
        return true;
    }
    return false;
}

void update_board() {
    int new_board[ROW][COL];
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            new_board[i][j] = board[i][j];
        }
    }
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(is_alive(i, j)) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

void *game_loop(void *arg) {
    int *counter = (int*)arg;
    while(*counter < 10) {
        update_board();
        print_board();
        printf("\n");
        (*counter)++;
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(void) {
    initialize_board();
    print_board();
    printf("\n");
    int counter = 0;
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, game_loop, &counter);
    while(counter < 10) {
        printf("Current generation: %d\n", counter);
        sleep(2);
    }
    pthread_join(thread_id, NULL);
    return 0;
}