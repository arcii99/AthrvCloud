//FormAI DATASET v1.0 Category: Memory Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

int board[BOARD_SIZE][BOARD_SIZE];
int temp_board[BOARD_SIZE][BOARD_SIZE];

void print_board() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void shuffle_board() {
    int values[BOARD_SIZE*BOARD_SIZE/2];
    for(int i=0; i<BOARD_SIZE*BOARD_SIZE/2; i++) {
        values[i] = i+1;
    }

    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(i==0 && j==0) continue;

            int random_index = rand()%(BOARD_SIZE*BOARD_SIZE/2);

            while(values[random_index] == -1) {
                random_index = rand()%(BOARD_SIZE*BOARD_SIZE/2);
            }

            board[i][j] = values[random_index];
            values[random_index] = -1;

            // Place a pair for each number
            board[BOARD_SIZE-i-1][BOARD_SIZE-j-1] = board[i][j];
        }
    }
}

void copy_board() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            temp_board[i][j] = board[i][j];
        }
    }
}

int board_changed() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(temp_board[i][j] != board[i][j]) {
                return 1;
            }
        }
    }

    return 0;
}

int valid_move(int x1, int y1, int x2, int y2) {
    if(x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE) {
        return 0;
    }

    if(x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
        return 0;
    }

    if(board[x1][y1] == -1 || board[x2][y2] == -1) {
        return 0;
    }

    if(board[x1][y1] != board[x2][y2]) {
        return 0;
    }

    if(x1 == x2 && y1 == y2) {
        return 0;
    }

    return 1;
}

int remove_pair(int x1, int y1, int x2, int y2) {
    if(!valid_move(x1, y1, x2, y2)) {
        return 0;
    }

    board[x1][y1] = -1;
    board[x2][y2] = -1;
    copy_board();

    return 1;
}

int is_game_over() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] != -1) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    srand(time(NULL));

    shuffle_board();
    print_board();

    // Main game loop
    int moves = 0;
    while(1) {
        printf("Enter first selection (x, y): ");
        int x1, y1;
        scanf("%d %d", &x1, &y1);

        printf("Enter second selection (x, y): ");
        int x2, y2;
        scanf("%d %d", &x2, &y2);

        int result = remove_pair(x1, y1, x2, y2);

        if(!result) {
            printf("Invalid move.\n");
        } else {
            moves++;

            printf("Valid move! Moves: %d\n", moves);

            if(is_game_over()) {
                printf("Congratulations! You completed the game in %d moves.\n", moves);
                break;
            }

            print_board();
        }

        printf("\n");
    }

    return 0;
}