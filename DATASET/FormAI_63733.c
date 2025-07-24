//FormAI DATASET v1.0 Category: Game of Life ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define ROWS 20
#define COLS 20
#define GENERATIONS 25
#define PLAYERS 2

int board[ROWS][COLS];
int new_board[ROWS][COLS];
int player_scores[PLAYERS];

pthread_barrier_t barrier;

void init_board() {
    // initialize cells randomly
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % PLAYERS;
            new_board[i][j] = board[i][j];
        }
    }
}

void print_board() {
    // print current board
    printf("Current board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int row, int col, int player) {
    // count neighbors of current cell that belong to current player
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int r = row + i;
            int c = col + j;
            if (r < 0) r = ROWS - 1;
            if (r >= ROWS) r = 0;
            if (c < 0) c = COLS - 1;
            if (c >= COLS) c = 0;
            if (board[r][c] == player) count++;
        }
    }
    return count;
}

void* play_game(void* arg) {
    // play game for given player
    int player = *(int*)arg;
    int start = player * (ROWS / PLAYERS);
    int end = start + (ROWS / PLAYERS);

    for (int g = 0; g < GENERATIONS; g++) {
        // calculate next generation
        for (int i = start; i < end; i++) {
            for (int j = 0; j < COLS; j++) {
                int count = count_neighbors(i, j, player);
                if (board[i][j] == player) {
                    if (count <= 1 || count >= 4) {
                        // cell dies
                        new_board[i][j] = -1;
                    } else {
                        // cell survives
                        new_board[i][j] = player;
                    }
                } else {
                    if (count == 3) {
                        // cell borns
                        new_board[i][j] = player;
                    } else {
                        // cell stays dead
                        new_board[i][j] = -1;
                    }
                }
            }
        }

        // synchronize threads before updating board
        pthread_barrier_wait(&barrier);

        // update board
        for (int i = start; i < end; i++) {
            for (int j = 0; j < COLS; j++) {
                if (new_board[i][j] != -1) {
                    board[i][j] = new_board[i][j];
                }
            }
        }

        // calculate scores
        int score = 0;
        for (int i = start; i < end; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == player) {
                    score++;
                }
            }
        }
        player_scores[player] = score;

        // synchronize threads before printing scores
        pthread_barrier_wait(&barrier);

        // print scores
        if (player == 0 && g == GENERATIONS - 1) {
            printf("Final scores: Player 0-%d, Player 1-%d\n", player_scores[0], player_scores[1]);
        } else if (player == 0) {
            printf("Player 0 score after generation %d: %d\n", g+1, player_scores[0]);
        } else if (player == 1) {
            printf("Player 1 score after generation %d: %d\n", g+1, player_scores[1]);
        }

        // synchronize threads before next generation
        pthread_barrier_wait(&barrier);
    }

    return NULL;
}

int main() {
    init_board();
    print_board();

    pthread_t threads[PLAYERS];
    int player_ids[PLAYERS];
    pthread_barrier_init(&barrier, NULL, PLAYERS);

    for (int i = 0; i < PLAYERS; i++) {
        player_ids[i] = i;
        pthread_create(&threads[i], NULL, play_game, &player_ids[i]);
    }

    for (int i = 0; i < PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_barrier_destroy(&barrier);

    return 0;
}