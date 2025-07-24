//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_ROWS 10  // Maximum number of rows in the game board
#define MAX_COLS 20  // Maximum number of columns in the game board
#define MAX_SCORE 100  // The maximum score required to win the game

int game_board[MAX_ROWS][MAX_COLS];  // The game board array
int player_score = 0;  // The score of the player
int game_over = 0;  // Flag to indicate if the game is over
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // A mutex to access the shared variables


void print_board() {
    // Function to print the game board with current score and game over message if needed
    system("clear");
    for(int i=0; i<MAX_ROWS; i++) {
        for(int j=0; j<MAX_COLS; j++) {
            printf("%d ", game_board[i][j]);
        }
        printf("\n");
    }
    printf("\nScore: %d", player_score);
    if(game_over) {
        printf("\nGAME OVER\n");
    }
    printf("\n");
}

void* update_score() {
    // Thread function to update the player's score every second
    while(!game_over) {
        sleep(1);
        pthread_mutex_lock(&mutex);
        player_score++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void* move_left() {
    // Thread function to move the player left
    while(!game_over) {
        int col = 0;
        scanf("%d", &col);
        if(col >= MAX_COLS || col < 0) {
            printf("Invalid move\n");
        } else {
            pthread_mutex_lock(&mutex);
            for(int i=0; i<MAX_ROWS; i++) {
                game_board[i][col] = 0;
            }
            game_board[MAX_ROWS-1][col] = 1;
            pthread_mutex_unlock(&mutex);
        }
    }
    pthread_exit(NULL);
}

int main() {
    // Initialize game board
    for(int i=0; i<MAX_ROWS; i++) {
        for(int j=0; j<MAX_COLS; j++) {
            game_board[i][j] = 0;
        }
    }
    game_board[MAX_ROWS-1][MAX_COLS/2] = 1;

    // Create threads for updating score and moving left
    pthread_t score_thread, move_left_thread;
    pthread_create(&score_thread, NULL, update_score, NULL);
    pthread_create(&move_left_thread, NULL, move_left, NULL);

    // Game loop
    while(!game_over) {
        // Check if player has won the game
        if(player_score >= MAX_SCORE) {
            printf("Congratulations! You have won the game!\n");
            game_over = 1;
            pthread_cancel(score_thread);
            pthread_cancel(move_left_thread);
            continue;
        }

        // Generate obstacles randomly on the game board
        pthread_mutex_lock(&mutex);
        for(int i=0; i<MAX_ROWS-1; i++) {
            for(int j=0; j<MAX_COLS; j++) {
                game_board[i][j] = game_board[i+1][j];
            }
        }
        for(int j=0; j<MAX_COLS; j++) {
            if(rand() % 10 == 0) {
                game_board[MAX_ROWS-1][j] = 1;
            } else {
                game_board[MAX_ROWS-1][j] = 0;
            }
        }
        if(game_board[MAX_ROWS-1][MAX_COLS/2] == 1) {
            printf("You hit an obstacle! Game Over\n");
            game_over = 1;
            pthread_cancel(score_thread);
            pthread_cancel(move_left_thread);
        }
        pthread_mutex_unlock(&mutex);

        // Print game board after each update
        print_board();
    }

    return 0;
}