//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define BOARD_SIZE 3

typedef enum {EMPTY, X, O} Mark;
typedef struct {
    Mark board[BOARD_SIZE][BOARD_SIZE];
    bool is_game_over;
    pthread_mutex_t mutex;
    pthread_cond_t game_over_cond;
} GameData;

typedef struct {
    GameData* game_data;
    Mark player_mark;
} PlayerData;

void print_board(GameData* game_data) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game_data->board[i][j] == X) {
                printf(" X ");
            } else if (game_data->board[i][j] == O) {
                printf(" O ");
            } else {
                printf("   ");
            }
            if (j < BOARD_SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) printf("-----------\n");
    }
}

bool check_winner(Mark mark, GameData* game_data) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        bool row_win = true;
        bool col_win = true;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game_data->board[i][j] != mark) row_win = false;
            if (game_data->board[j][i] != mark) col_win = false;
        }
        if (row_win || col_win) return true;
    }
    bool diag_win1 = true;
    bool diag_win2 = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game_data->board[i][i] != mark) diag_win1 = false;
        if (game_data->board[i][BOARD_SIZE - i - 1] != mark) diag_win2 = false;
    }
    if (diag_win1 || diag_win2) return true;
    return false;
}

bool is_full(GameData* game_data) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game_data->board[i][j] == EMPTY) return false;
        }
    }
    return true;
}

void* play_game(void* arg) {
    PlayerData* player_data = (PlayerData*) arg;
    while (true) {
        pthread_mutex_lock(&player_data->game_data->mutex);
        if (player_data->game_data->is_game_over) {
            pthread_mutex_unlock(&player_data->game_data->mutex);
            break;
        }
        printf("Player %d's turn!\n", player_data->player_mark);
        print_board(player_data->game_data);
        int row, col;
        do {
            printf("Enter row (0-2) and column (0-2) for your next move: ");
            scanf("%d %d", &row, &col);
        } while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || player_data->game_data->board[row][col] != EMPTY);
        player_data->game_data->board[row][col] = player_data->player_mark;
        if (check_winner(player_data->player_mark, player_data->game_data)) {
            printf("Player %d wins!\n", player_data->player_mark);
            player_data->game_data->is_game_over = true;
            pthread_cond_broadcast(&player_data->game_data->game_over_cond);
        } else if (is_full(player_data->game_data)) {
            printf("Game is a tie!\n");
            player_data->game_data->is_game_over = true;
            pthread_cond_broadcast(&player_data->game_data->game_over_cond);
        }
        pthread_mutex_unlock(&player_data->game_data->mutex);
    }
    pthread_exit(NULL);
}

int main() {
    GameData game_data = {
        .board = {
            {EMPTY, EMPTY, EMPTY},
            {EMPTY, EMPTY, EMPTY},
            {EMPTY, EMPTY, EMPTY}
        },
        .is_game_over = false,
        .mutex = PTHREAD_MUTEX_INITIALIZER,
        .game_over_cond = PTHREAD_COND_INITIALIZER
    };
    PlayerData player_data1 = {&game_data, X};
    PlayerData player_data2 = {&game_data, O};

    pthread_t player1_thread, player2_thread;

    pthread_create(&player1_thread, NULL, play_game, &player_data1);
    pthread_create(&player2_thread, NULL, play_game, &player_data2);

    pthread_mutex_lock(&game_data.mutex);
    while (!game_data.is_game_over) {
        pthread_cond_wait(&game_data.game_over_cond, &game_data.mutex);
    }
    pthread_mutex_unlock(&game_data.mutex);

    pthread_join(player1_thread, NULL);
    pthread_join(player2_thread, NULL);

    return 0;
}