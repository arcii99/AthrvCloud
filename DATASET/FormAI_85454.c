//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define ROWS 10
#define COLS 10
#define ALIEN_HORIZONTAL_SPEED 1
#define ALIEN_VERTICAL_DISTANCE 1
#define ALIEN_POINTS 10
#define PLAYER_LIVES 3
#define PLAYER_GUN_DELAY 200000
#define PLAYER_SHOT_SPEED 1

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int board[ROWS][COLS] = {{0}};
int player_row, player_col;
int score = 0, level = 1, lives = PLAYER_LIVES;

void move_aliens(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        int i, j;
        for(i=0; i<ROWS; i++){
            for(j=0; j<COLS; j++){
                if (board[i][j] == 1) {
                    board[i][j] = 0;
                    if (j + ALIEN_HORIZONTAL_SPEED >= COLS){ // Reached right side of board
                        printf("\nAliens win!\n");
                        exit(0);
                    }
                    else{ //Move right
                        board[i][j + ALIEN_HORIZONTAL_SPEED] = 1;
                    }
                }
            }

        }
        usleep(ALIEN_VERTICAL_DISTANCE * 1000000); // Move down after each left-right motion
        pthread_mutex_unlock(&mutex);
    }
}

void player_shoot(void *arg){
    while(1){
        char c = getchar();
        if (c == ' '){
            int i;
            for(i=player_row-PLAYER_SHOT_SPEED; i>=0; i--){
                if (board[i][player_col] == 1){
                    pthread_mutex_lock(&mutex);
                    board[i][player_col] = 0;
                    score += ALIEN_POINTS;
                    printf("\nSCORE: %d\n", score);
                    pthread_mutex_unlock(&mutex);
                    break;
                }
            }
            usleep(PLAYER_GUN_DELAY);
        }
    }
}

void move_player(void *arg){
    while(1){
        char c = getchar();
        if (c == 'a' && player_col > 0){
            pthread_mutex_lock(&mutex);
            board[player_row][player_col] = 0;
            player_col--;
            board[player_row][player_col] = -1;
            pthread_mutex_unlock(&mutex);
        }
        if (c == 'd' && player_col < COLS-1){
            pthread_mutex_lock(&mutex);
            board[player_row][player_col] = 0;
            player_col++;
            board[player_row][player_col] = -1;
            pthread_mutex_unlock(&mutex);
        }
    }
}

int main(){

    // Initialize board
    board[ROWS-1][COLS/2] = -1; // Player at bottom center
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<COLS; j++){
            board[i][j] = 1; // Aliens at top rows
        }
    }

    player_row = ROWS-1;
    player_col = COLS/2;

    // Create threads
    pthread_t aliens_thread, player_thread, player_gun_thread;
    pthread_create(&aliens_thread, NULL, move_aliens, NULL);
    pthread_create(&player_gun_thread, NULL, player_shoot, NULL);
    pthread_create(&player_thread, NULL, move_player, NULL);

    // Play game until player wins
    while(1){
        printf("\nLEVEL: %d\n", level);
        printf("LIVES: %d\n", lives);

        pthread_mutex_lock(&mutex);
        // Print board
        for(i=0; i<ROWS; i++){
            for(j=0; j<COLS; j++){
                if (board[i][j] == 0){
                    printf(".");
                }
                else if (board[i][j] == 1){
                    printf("A");
                }
                else{
                    printf("P");
                }
            }
            printf("\n");
        }
        pthread_mutex_unlock(&mutex);

        // Check if player has lost
        if (lives == 0){
            printf("\nGame over! Aliens win!\n");
            exit(0);
        }

        // Level up
        if (score >= level*100){
            printf("\nLevel up!\n");
            level++;
            pthread_mutex_lock(&mutex);
            for(i=0; i<ROWS; i++){
                for(j=0; j<COLS; j++){
                    board[i][j] = 0;
                }
            }
            player_row = ROWS-1;
            player_col = COLS/2;
            board[player_row][player_col] = -1;

            for(i=0; i<level*3; i++){
                board[level*3-i][COLS/2] = 1;
            }
            pthread_mutex_unlock(&mutex);
        }

        usleep(50000); // Wait before refreshing screen

    }

    return 0;
}