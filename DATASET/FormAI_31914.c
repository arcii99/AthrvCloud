//FormAI DATASET v1.0 Category: Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to initialize the game board with random numbers
void init_board(int board[][4]) {
    srand(time(NULL));
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            board[i][j] = rand() % 10 + 1;
        }
    }
}

// function to display the game board
void display_board(int board[][4]) {
    printf("==============\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("==============\n");
}

// function to move numbers to the left on the game board
void move_left(int board[][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 1; j < 4; j++) {
            if(board[i][j] != 0) {
                int k = j - 1;
                while(k >= 0 && board[i][k] == 0) {
                    k--;
                }
                if(k >= 0 && board[i][j] == board[i][k]) {
                    board[i][k] *= 2;
                    board[i][j] = 0;
                } else {
                    board[i][k+1] = board[i][j];
                    board[i][j] = 0;
                }
            }
        }
    }
}

// function to move numbers to the right on the game board
void move_right(int board[][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 2; j >= 0; j--) {
            if(board[i][j] != 0) {
                int k = j + 1;
                while(k <= 3 && board[i][k] == 0) {
                    k++;
                }
                if(k <= 3 && board[i][j] == board[i][k]) {
                    board[i][k] *= 2;
                    board[i][j] = 0;
                } else {
                    board[i][k-1] = board[i][j];
                    board[i][j] = 0;
                }
            }
        }
    }
}

// function to move numbers up on the game board
void move_up(int board[][4]) {
    for(int j = 0; j < 4; j++) {
        for(int i = 1; i < 4; i++) {
            if(board[i][j] != 0) {
                int k = i - 1;
                while(k >= 0 && board[k][j] == 0) {
                    k--;
                }
                if(k >= 0 && board[i][j] == board[k][j]) {
                    board[k][j] *= 2;
                    board[i][j] = 0;
                } else {
                    board[k+1][j] = board[i][j];
                    board[i][j] = 0;
                }
            }
        }
    }
}

// function to move numbers down on the game board
void move_down(int board[][4]) {
    for(int j = 0; j < 4; j++) {
        for(int i = 2; i >= 0; i--) {
            if(board[i][j] != 0) {
                int k = i + 1;
                while(k <= 3 && board[k][j] == 0) {
                    k++;
                }
                if(k <= 3 && board[i][j] == board[k][j]) {
                    board[k][j] *= 2;
                    board[i][j] = 0;
                } else {
                    board[k-1][j] = board[i][j];
                    board[i][j] = 0;
                }
            }
        }
    }
}

// function to check if the game is over and there are no possible moves
int is_game_over(int board[][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(board[i][j] == 0) {
                return 0;
            }
            if(i-1 >= 0 && board[i][j] == board[i-1][j]) {
                return 0;
            }
            if(i+1 <= 3 && board[i][j] == board[i+1][j]) {
                return 0;
            }
            if(j-1 >= 0 && board[i][j] == board[i][j-1]) {
                return 0;
            }
            if(j+1 <= 3 && board[i][j] == board[i][j+1]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int board[4][4];
    int score = 0;
    char move;

    init_board(board);
    display_board(board);

    do {
        printf("Enter move (WASD): ");
        scanf(" %c", &move);

        switch(move) {
            case 'a':
                move_left(board);
                break;
            case 'd':
                move_right(board);
                break;
            case 'w':
                move_up(board);
                break;
            case 's':
                move_down(board);
                break;
            default:
                printf("Invalid move. Please try again.\n");
                break;
        }

        score += 10;
        printf("Score: %d\n", score);
        display_board(board);

    } while(!is_game_over(board));

    printf("Game over!\n");
    printf("Final score: %d\n", score);

    return 0;
}