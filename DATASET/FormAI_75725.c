//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// size of game board
#define ROW 10 
#define COL 10 

// number of enemies to be killed for victory
#define ENEMIES_NEEDED ((ROW-2) * (COL-2))

// game board
char board[ROW][COL];

// player position
int player_pos = COL/2;

// player lives
int player_lives = 3;

// enemy position and state
typedef struct {
    int row;
    int col;
    int alive;
} enemy_t;

enemy_t enemies[ROW-2][COL-2];

// lock for updating player position
pthread_mutex_t player_lock = PTHREAD_MUTEX_INITIALIZER;

// lock for updating enemy position
pthread_mutex_t enemy_lock = PTHREAD_MUTEX_INITIALIZER;

// function to print game board
void print_board() {
    system("clear");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}

// function to update board with player and enemy positions
void update_board() {
    // clear board
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            board[i][j] = ' ';
    // update player position
    pthread_mutex_lock(&player_lock);
    board[ROW-1][player_pos] = 'P';
    pthread_mutex_unlock(&player_lock);
    // update enemy positions
    pthread_mutex_lock(&enemy_lock);
    for (int i = 0; i < ROW-2; i++)
        for (int j = 0; j < COL-2; j++)
            if (enemies[i][j].alive)
                board[enemies[i][j].row][enemies[i][j].col] = 'E';
    pthread_mutex_unlock(&enemy_lock);
    // print updated board
    print_board();
}

// function to move player left
void move_left() {
    pthread_mutex_lock(&player_lock);
    if (player_pos > 0)
        player_pos--;
    pthread_mutex_unlock(&player_lock);
}

// function to move player right
void move_right() {
    pthread_mutex_lock(&player_lock);
    if (player_pos < COL-1)
        player_pos++;
    pthread_mutex_unlock(&player_lock);
}

// function for enemy thread
void *enemy_thread(void *arg) {
    int row = *((int *)arg);
    int alive = COL-2;
    while (alive) {
        // wait for random amount of time
        sleep(rand() % 3 + 1);
        // update enemy position
        pthread_mutex_lock(&enemy_lock);
        int col = rand() % (COL-2);
        if (enemies[row][col].alive) {
            enemies[row][col].alive = 0;
            alive--;
        }
        pthread_mutex_unlock(&enemy_lock);
        // update board
        update_board();
    }
    return NULL;
}

int main() {
    // initialize board
    for (int i = 0; i < ROW; i++) {
        board[i][0] = '|';
        board[i][COL-1] = '|';
    }
    for (int i = 0; i < COL; i++) {
        board[0][i] = '-';
        board[ROW-1][i] = '-';
    }
    board[ROW-1][COL/2] = 'P';
    // create enemy threads
    pthread_t enemy_threads[ROW-2];
    for (int i = 0; i < ROW-2; i++) {
        int *row = (int *)malloc(sizeof(int));
        *row = i+1;
        pthread_create(&enemy_threads[i], NULL, enemy_thread, (void *)row);
        for (int j = 0; j < COL-2; j++)
            enemies[i][j].row = i+1, enemies[i][j].col = j+1, enemies[i][j].alive = 1;
    }
    // game loop
    int enemies_killed = 0;
    while (player_lives) {
        update_board();
        char input = getchar();
        if (input == 'a')
            move_left();
        else if (input == 'd')
            move_right();
        // check for victory
        if (enemies_killed == ENEMIES_NEEDED) {
            printf("\nYou win!\n");
            exit(0);
        }
    }
    // game over
    printf("\nGame over!\n");
    exit(0);
}