//FormAI DATASET v1.0 Category: Chess AI ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// define the board size as a global constant
#define BOARD_SIZE 8

// define structure to hold the state of the game
typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int turn;
} Game;

// function prototypes
void init_game(Game*);
void print_board(Game*);
int is_game_over(Game*);
int is_valid_move(Game*, int, int, int, int);
void make_move(Game*, int, int, int, int);
void* AI_thread(void*);

int main() {
    Game game;
    init_game(&game);
    print_board(&game);

    while (!is_game_over(&game)) {
        // create and run the AI thread
        pthread_t ai_thread;
        pthread_create(&ai_thread, NULL, AI_thread, &game);

        // get user input for a move
        int from_x, from_y, to_x, to_y;
        printf("Enter your move (from_x from_y to_x to_y): ");
        scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);

        // wait for AI thread to finish
        void* result;
        pthread_join(ai_thread, &result);

        // make the move chosen by the AI
        int* move = (int*) result;
        make_move(&game, move[0], move[1], move[2], move[3]);
        free(move);

        // make the user's move
        make_move(&game, from_x, from_y, to_x, to_y);

        // print the updated board
        print_board(&game);
    }

    printf("Game over!\n");
    return 0;
}

// function to initialize the game state
void init_game(Game* game) {
    // set up the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                game->board[i][j] = 0;
            } else {
                if (i < 3) {
                    game->board[i][j] = 1;
                } else if (i > 4) {
                    game->board[i][j] = -1;
                } else {
                    game->board[i][j] = 0;
                }
            }
        }
    }

    // set the turn to be the white player's turn
    game->turn = 1;
}

// function to print the current state of the board
void print_board(Game* game) {
    printf("\n   0 1 2 3 4 5 6 7\n\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == 0) {
                printf(". ");
            } else if (game->board[i][j] == 1) {
                printf("W ");
            } else if (game->board[i][j] == -1) {
                printf("B ");
            } else if (game->board[i][j] == 2) {
                printf("w ");
            } else if (game->board[i][j] == -2) {
                printf("b ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if the game is over
int is_game_over(Game* game) {
    // check if one of the players has no pieces left
    int white_pieces = 0;
    int black_pieces = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == 1 || game->board[i][j] == 2) {
                white_pieces++;
            } else if (game->board[i][j] == -1 || game->board[i][j] == -2) {
                black_pieces++;
            }
        }
    }
    if (white_pieces == 0 || black_pieces == 0) {
        return 1;
    }

    // check if the current player has no valid moves left
    int has_valid_move = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == game->turn ||
                game->board[i][j] == game->turn * 2) {
                for (int k = -1; k <= 1; k += 2) {
                    for (int l = -1; l <= 1; l += 2) {
                        if (is_valid_move(game, i, j, i + k, j + l)) {
                            has_valid_move = 1;
                            break;
                        }
                    }
                    if (has_valid_move) {
                        break;
                    }
                }
                if (has_valid_move) {
                    break;
                }
            }
        }
        if (has_valid_move) {
            break;
        }
    }
    if (!has_valid_move) {
        return 1;
    }

    return 0;
}

// function to check if a move is valid
int is_valid_move(Game* game, int from_x, int from_y, int to_x, int to_y) {
    // check if the piece being moved belongs to the current player
    if (game->board[from_x][from_y] != game->turn &&
        game->board[from_x][from_y] != game->turn * 2) {
        return 0;
    }

    // check if the destination is a valid location on the board
    if (to_x < 0 || to_x >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE) {
        return 0;
    }

    // check if the destination is empty
    if (game->board[to_x][to_y] != 0) {
        return 0;
    }

    // check if the move is a regular move or a jump
    int is_jump = 0;
    int jumped_x, jumped_y;
    if (to_x - from_x == game->turn * 2 || to_x - from_x == game->turn * -2) {
        is_jump = 1;
        jumped_x = from_x + (to_x - from_x) / 2;
        jumped_y = from_y + (to_y - from_y) / 2;
    }

    // check if the move is diagonal
    if (abs(to_x - from_x) != abs(to_y - from_y)) {
        return 0;
    }

    // check if the move is one space or two spaces
    if (abs(to_x - from_x) == 1) {
        if (!is_jump) {
            return 1;
        } else {
            return 0;
        }
    } else if (abs(to_x - from_x) == 2) {
        if (!is_jump) {
            return 0;
        } else {
            // check if the jumped piece belongs to the other player
            if (game->board[jumped_x][jumped_y] == game->turn * -1 ||
                game->board[jumped_x][jumped_y] == game->turn * -2) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    return 0;
}

// function to make a move
void make_move(Game* game, int from_x, int from_y, int to_x, int to_y) {
    // make the move
    game->board[to_x][to_y] = game->board[from_x][from_y];
    game->board[from_x][from_y] = 0;

    // check if the piece should be promoted
    if (game->board[to_x][to_y] == 1 && to_x == BOARD_SIZE - 1) {
        game->board[to_x][to_y] = 2;
    } else if (game->board[to_x][to_y] == -1 && to_x == 0) {
        game->board[to_x][to_y] = -2;
    }

    // check if the move was a jump
    if (abs(to_x - from_x) == 2) {
        int jumped_x = from_x + (to_x - from_x) / 2;
        int jumped_y = from_y + (to_y - from_y) / 2;
        game->board[jumped_x][jumped_y] = 0;
    }

    // switch the turn to the other player
    game->turn *= -1;
}

// function to determine the best possible move for the AI
void* AI_thread(void* arg) {
    Game* game = (Game*) arg;
    int* result = malloc(4 * sizeof(int));
    int max_score = -100;

    // iterate through all possible moves for the current player
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == game->turn ||
                game->board[i][j] == game->turn * 2) {
                for (int k = -1; k <= 1; k += 2) {
                    for (int l = -1; l <= 1; l += 2) {
                        if (is_valid_move(game, i, j, i + k, j + l)) {
                            // create a copy of the game state and make the move
                            Game new_game = *game;
                            make_move(&new_game, i, j, i + k, j + l);

                            // determine the score of the resulting game state
                            int score = 0;
                            for (int m = 0; m < BOARD_SIZE; m++) {
                                for (int n = 0; n < BOARD_SIZE; n++) {
                                    if (new_game.board[m][n] == game->turn) {
                                        score += 1;
                                    } else if (new_game.board[m][n] == game->turn * 2) {
                                        score += 2;
                                    } else if (new_game.board[m][n] == game->turn * -1) {
                                        score -= 1;
                                    } else if (new_game.board[m][n] == game->turn * -2) {
                                        score -= 2;
                                    }
                                }
                            }

                            // update the result if this move has a higher score
                            if (score > max_score) {
                                max_score = score;
                                result[0] = i;
                                result[1] = j;
                                result[2] = i + k;
                                result[3] = j + l;
                            }
                        }
                    }
                }
            }
        }
    }

    return (void*) result;
}