//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BOARD_SIZE 20
#define NUM_GHOSTS 4

int score = 0;
int pacMan_x, pacMan_y;
int ghosts_x[NUM_GHOSTS], ghosts_y[NUM_GHOSTS];
int board[BOARD_SIZE][BOARD_SIZE];

pthread_mutex_t board_mutex = PTHREAD_MUTEX_INITIALIZER;

void initialize_board() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    pacMan_x = BOARD_SIZE/2;
    pacMan_y = BOARD_SIZE/2;
    board[pacMan_x][pacMan_y] = 1;
    for(int i=0; i<NUM_GHOSTS; i++) {
        ghosts_x[i] = rand() % BOARD_SIZE;
        ghosts_y[i] = rand() % BOARD_SIZE;
        board[ghosts_x[i]][ghosts_y[i]] = -1;
    }
}

void print_board() {
    system("clear");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 1) {
                printf("P ");
            }
            else if(board[i][j] == -1) {
                printf("G ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void move_pacMan(int dx, int dy) {
    int new_x = pacMan_x + dx;
    int new_y = pacMan_y + dy;
    if(new_x >= BOARD_SIZE || new_x < 0 || new_y >= BOARD_SIZE || new_y < 0) {
        return;
    }
    pthread_mutex_lock(&board_mutex); // lock mutex
    if(board[new_x][new_y] == -1) {
        printf("Game over!\n");
        exit(0);
    }
    board[pacMan_x][pacMan_y] = 0;
    pacMan_x = new_x;
    pacMan_y = new_y;
    score++;
    board[pacMan_x][pacMan_y] = 1;
    pthread_mutex_unlock(&board_mutex); // unlock mutex
}

void move_ghosts() {
    for(int i=0; i<NUM_GHOSTS; i++) {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        int new_x = ghosts_x[i] + dx;
        int new_y = ghosts_y[i] + dy;
        if(new_x >= BOARD_SIZE || new_x < 0 || new_y >= BOARD_SIZE || new_y < 0) {
            continue;
        }
        pthread_mutex_lock(&board_mutex); // lock mutex
        if(board[new_x][new_y] == 1) {
            printf("Game over!\n");
            exit(0);
        }
        board[ghosts_x[i]][ghosts_y[i]] = 0;
        ghosts_x[i] = new_x;
        ghosts_y[i] = new_y;
        board[ghosts_x[i]][ghosts_y[i]] = -1;
        pthread_mutex_unlock(&board_mutex); // unlock mutex
    }
}

void* input_thread() {
    while(1) {
        char c = getchar();
        switch(c) {
            case 'w':
                move_pacMan(-1, 0);
                break;
            case 's':
                move_pacMan(1, 0);
                break;
            case 'a':
                move_pacMan(0, -1);
                break;
            case 'd':
                move_pacMan(0, 1);
                break;
        }
    }
}

void* ghosts_thread() {
    while(1) {
        move_ghosts();
        print_board();
        usleep(500000);
    }
}

int main() {
    srand(time(NULL));
    initialize_board();
    print_board();
    pthread_t input_t, ghosts_t;
    pthread_create(&input_t, NULL, input_thread, NULL);
    pthread_create(&ghosts_t, NULL, ghosts_thread, NULL);
    pthread_join(input_t, NULL);
    pthread_join(ghosts_t, NULL);
    return 0;
}