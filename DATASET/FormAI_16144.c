//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define BOARD_SIZE 3
#define PLAYER_1 1
#define PLAYER_2 2
#define EMPTY_SPACE -1

int board[BOARD_SIZE][BOARD_SIZE];

bool game_over = false;
int turn = PLAYER_1;

pthread_mutex_t mutex;

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_SPACE;
        }
    }
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j] == PLAYER_1 ? 'X' : board[i][j] == PLAYER_2 ? 'O' : '-');
        }
        printf("\n");
    }
}

bool is_valid_move(int row, int col) {
    return board[row][col] == EMPTY_SPACE;
}

void make_move(int player, int row, int col) {
    board[row][col] = player;
}

void check_win() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != EMPTY_SPACE && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            game_over = true;
            return;
        }
    }
    
    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != EMPTY_SPACE && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            game_over = true;
            return;
        }
    }
    
    // Check diagonals
    if (board[0][0] != EMPTY_SPACE && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        game_over = true;
        return;
    }
    
    if (board[0][2] != EMPTY_SPACE && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        game_over = true;
        return;
    }
    
    // Check for tie
    bool tie = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY_SPACE) {
                tie = false;
                break;
            }
        }
    }
    
    if (tie) {
        game_over = true;
    }
}

void* player_thread(void* arg) {
    int player = *(int*)arg;
    
    while (!game_over) {
        pthread_mutex_lock(&mutex);
        if (turn != player) {
            pthread_mutex_unlock(&mutex);
            continue;
        }
        
        printf("Player %d's turn.\n", player);
        print_board();
        
        int row, col;
        printf("Enter row and column (0-2): ");
        scanf("%d %d", &row, &col);
        
        if (!is_valid_move(row, col)) {
            printf("Invalid move. Try again.\n");
            pthread_mutex_unlock(&mutex);
            continue;
        }
        
        make_move(player, row, col);
        check_win();
        
        turn = player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
        pthread_mutex_unlock(&mutex);
    }
    
    return NULL;
}

int main() {
    initialize_board();
    
    pthread_mutex_init(&mutex, NULL);
    
    pthread_t player_1_tid, player_2_tid;
    int player_1 = PLAYER_1;
    int player_2 = PLAYER_2;
    
    pthread_create(&player_1_tid, NULL, player_thread, &player_1);
    pthread_create(&player_2_tid, NULL, player_thread, &player_2);
    
    pthread_join(player_1_tid, NULL);
    pthread_join(player_2_tid, NULL);
    
    print_board();
    
    pthread_mutex_destroy(&mutex);
    
    return 0;
}