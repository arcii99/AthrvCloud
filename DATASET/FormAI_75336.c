//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char grid[3][3]; // the tic tac toe grid
char empty = '-'; // char used to represent empty squares on the grid
char human_char = 'X'; // character used for the human player
char ai_char = 'O'; // character used for the AI player

// function prototypes
void init_grid();
void print_grid();
int is_gameover();
void make_move(char, int, int);
int can_win(char, int*, int*);
int can_block(char, int*, int*);
void ai_turn();
int minimax(int, int, int);
int eval_game(int);

int main()
{
    int player_turn = 0;
    int winner = 0;

    init_grid(); // initialize the grid
    print_grid(); // print the empty grid

    while (!is_gameover()) {
        if (player_turn == 0) {
            // human turn
            int row, col;
            printf("\nHuman's turn:\nEnter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            if (row < 1 || row > 3 || col < 1 || col > 3 || grid[row-1][col-1] != empty) {
                printf("Invalid move! Please try again.\n");
            } else {
                make_move(human_char, row-1, col-1);
                player_turn = 1;
            }
        } else {
            // AI turn
            ai_turn();
            player_turn = 0;
        }
        print_grid(); // print the updated grid
    }

    winner = is_gameover();
    if (winner == 1) {
        printf("Human wins!\n");
    } else if (winner == 2) {
        printf("AI wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}

void init_grid() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            grid[i][j] = empty;
        }
    }
}

void print_grid() {
    int i, j;
    printf("\n+---+---+---+\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("| %c ", grid[i][j]);
        }
        printf("|\n+---+---+---+\n");
    }
}

int is_gameover() {
    int i, j;
    // check rows for winner
    for (i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            if (grid[i][0] == human_char) {
                return 1;
            } else if (grid[i][0] == ai_char) {
                return 2;
            }
        }
    }
    // check columns for winner
    for (j = 0; j < 3; j++) {
        if(grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]) {
            if (grid[0][j] == human_char) {
                return 1;
            } else if (grid[0][j] == ai_char) {
                return 2;
            }
        }
    }
    // check diagonals for winner
    if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        if (grid[0][0] == human_char) {
            return 1;
        } else if (grid[0][0] == ai_char) {
            return 2;
        }
    }
    if(grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]) {
        if (grid[2][0] == human_char) {
            return 1;
        } else if (grid[2][0] == ai_char) {
            return 2;
        }
    }
    // check for tie
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == empty) {
                return 0;
            }
        }
    }
    return 3; // tie
}

void make_move(char player, int row, int col) {
    grid[row][col] = player;
}

int can_win(char player, int* row_ptr, int* col_ptr) {
    int i, j;
    // check rows
    for (i = 0; i < 3; i++) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == empty) {
            *row_ptr = i;
            *col_ptr = 2;
            return 1;
        } else if (grid[i][0] == player && grid[i][1] == empty && grid[i][2] == player) {
            *row_ptr = i;
            *col_ptr = 1;
            return 1;
        } else if (grid[i][0] == empty && grid[i][1] == player && grid[i][2] == player) {
            *row_ptr = i;
            *col_ptr = 0;
            return 1;
        }
    }
    // check columns
    for (j = 0; j < 3; j++) {
        if (grid[0][j] == player && grid[1][j] == player && grid[2][j] == empty) {
            *row_ptr = 2;
            *col_ptr = j;
            return 1;
        } else if (grid[0][j] == player && grid[1][j] == empty && grid[2][j] == player) {
            *row_ptr = 1;
            *col_ptr = j;
            return 1;
        } else if (grid[0][j] == empty && grid[1][j] == player && grid[2][j] == player) {
            *row_ptr = 0;
            *col_ptr = j;
            return 1;
        }
    }
    // check diagonals
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == empty) {
        *row_ptr = 2;
        *col_ptr = 2;
        return 1;
    } else if (grid[0][0] == player && grid[1][1] == empty && grid[2][2] == player) {
        *row_ptr = 1;
        *col_ptr = 1;
        return 1;
    } else if (grid[0][0] == empty && grid[1][1] == player && grid[2][2] == player) {
        *row_ptr = 0;
        *col_ptr = 0;
        return 1;
    } else if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == empty) {
        *row_ptr = 2;
        *col_ptr = 0;
        return 1;
    } else if (grid[0][2] == player && grid[1][1] == empty && grid[2][0] == player) {
        *row_ptr = 1;
        *col_ptr = 1;
        return 1;
    } else if (grid[0][2] == empty && grid[1][1] == player && grid[2][0] == player) {
        *row_ptr = 0;
        *col_ptr = 2;
        return 1;
    }
    return 0;
}

int can_block(char player, int* row_ptr, int* col_ptr) {
    int i, j;
    // check rows
    for (i = 0; i < 3; i++) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == empty) {
            *row_ptr = i;
            *col_ptr = 2;
            return 1;
        } else if (grid[i][0] == player && grid[i][1] == empty && grid[i][2] == player) {
            *row_ptr = i;
            *col_ptr = 1;
            return 1;
        } else if (grid[i][0] == empty && grid[i][1] == player && grid[i][2] == player) {
            *row_ptr = i;
            *col_ptr = 0;
            return 1;
        }
    }
    // check columns
    for (j = 0; j < 3; j++) {
        if (grid[0][j] == player && grid[1][j] == player && grid[2][j] == empty) {
            *row_ptr = 2;
            *col_ptr = j;
            return 1;
        } else if (grid[0][j] == player && grid[1][j] == empty && grid[2][j] == player) {
            *row_ptr = 1;
            *col_ptr = j;
            return 1;
        } else if (grid[0][j] == empty && grid[1][j] == player && grid[2][j] == player) {
            *row_ptr = 0;
            *col_ptr = j;
            return 1;
        }
    }
    // check diagonals
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == empty) {
        *row_ptr = 2;
        *col_ptr = 2;
        return 1;
    } else if (grid[0][0] == player && grid[1][1] == empty && grid[2][2] == player) {
        *row_ptr = 1;
        *col_ptr = 1;
        return 1;
    } else if (grid[0][0] == empty && grid[1][1] == player && grid[2][2] == player) {
        *row_ptr = 0;
        *col_ptr = 0;
        return 1;
    } else if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == empty) {
        *row_ptr = 2;
        *col_ptr = 0;
        return 1;
    } else if (grid[0][2] == player && grid[1][1] == empty && grid[2][0] == player) {
        *row_ptr = 1;
        *col_ptr = 1;
        return 1;
    } else if (grid[0][2] == empty && grid[1][1] == player && grid[2][0] == player) {
        *row_ptr = 0;
        *col_ptr = 2;
        return 1;
    }
    return 0;
}

void ai_turn() {
    int row, col;
    printf("\nAI's turn:\n");
    // check if AI can win in one move
    if (can_win(ai_char, &row, &col)) {
        make_move(ai_char, row, col);
    }
    // block human if they can win in one move
    else if (can_block(human_char, &row, &col)) {
        make_move(ai_char, row, col);
    }
    // check if AI can create a fork
    else if (minimax(1, 0, ai_char) == 2) {
        if (grid[0][0] == empty) {
            make_move(ai_char, 0, 0);
        } else if (grid[2][0] == empty) {
            make_move(ai_char, 2, 0);
        } else if (grid[0][2] == empty) {
            make_move(ai_char, 0, 2);
        } else if (grid[2][2] == empty) {
            make_move(ai_char, 2, 2);
        }
    }
    // block human's fork
    else if (minimax(1, 0, human_char) == 2) {
        int human_row, human_col;
        can_block(human_char, &human_row, &human_col);
        if (human_row == 1 && human_col == 1) {
            if (grid[0][0] == empty) {
                make_move(ai_char, 0, 0);
            } else if (grid[2][0] == empty) {
                make_move(ai_char, 2, 0);
            } else if (grid[0][2] == empty) {
                make_move(ai_char, 0, 2);
            } else if (grid[2][2] == empty) {
                make_move(ai_char, 2, 2);
            }
        } else {
            make_move(ai_char, 1, 1);
        }
    }
    // check center
    else if (grid[1][1] == empty) {
        make_move(ai_char, 1, 1);
    }
    // random move
    else {
        int r, c;
        do {
            r = rand() % 3;
            c = rand() % 3;
        } while (grid[r][c] != empty);
        make_move(ai_char, r, c);
    }
}

int minimax(int depth, int maximizing, int player) {
    int other_player = (player == human_char) ? ai_char : human_char;
    int row, col, i, j;
    int score = eval_game(player);

    if (score == 10 || score == -10 || !is_gameover()) {
        return score;
    }

    if (maximizing) {
        // find max
        int max_val = -100;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (grid[i][j] == empty) {
                    grid[i][j] = player;
                    score = minimax(depth+1, 0, other_player);
                    if (score > max_val) {
                        max_val = score;
                        row = i;
                        col = j;
                    }
                    grid[i][j] = empty;
                }
            }
        }
        if (depth == 0) {
            make_move(player, row, col);
        }
        return max_val;
    } else {
        // find min
        int min_val = 100;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (grid[i][j] == empty) {
                    grid[i][j] = player;
                    score = minimax(depth+1, 1, other_player);
                    if (score < min_val) {
                        min_val = score;
                    }
                    grid[i][j] = empty;
                }
            }
        }
        return min_val;
    }
}

int eval_game(int player) {
    int other_player = (player == human_char) ? ai_char : human_char;
    int i, j;
    // check for win
    if (is_gameover()) {
        int winner = is_gameover();
        if (winner == 1 && player == human_char) {
            return -10;
        } else if (winner == 2 && player == ai_char) {
            return -10;
        } else if (winner == 1 && player == ai_char) {
            return 10;
        } else if (winner == 2 && player == human_char) {
            return 10;
        } else {
            return 0;
        }
    }
    // check for forks
    int fork_count = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == empty) {
                grid[i][j] = player;
                if (minimax(1, 0, other_player) == 2) {
                    fork_count++;
                }
                grid[i][j] = empty;
            }
        }
    }
    if (fork_count >= 2) {
        return 2;
    } else {
        return 0;
    }
}