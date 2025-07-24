//FormAI DATASET v1.0 Category: Chess AI ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 3

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

typedef struct {
    int x;
    int y;
}Move;

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int player;
    Move last_move;
}Game;

void print_board(Game *game) {
    printf("  ");
    for (int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j=0; j<BOARD_SIZE; j++) {
            printf("%d ", game->board[i][j]);
        }
        printf("\n");
    }
}

int minimax(Game *game, int depth, int alpha, int beta, int maximizing_player) {
    if (depth == 0 || game->player == 0 || game->player == 1) {
        int score = 0;
        for (int i=0; i<BOARD_SIZE; i++) {
            for (int j=0; j<BOARD_SIZE; j++) {
                if (game->board[i][j] == game->player) {
                    score += 1;
                } else if (game->board[i][j] == (game->player ^ 1)) {
                    score -= 1;
                }
            }
        }
        return score;
    }

    int best_score;
    if (maximizing_player) {
        best_score = -10000;
        for (int i=0; i<BOARD_SIZE; i++) {
            for (int j=0; j<BOARD_SIZE; j++) {
                if (game->board[i][j] == game->player) {
                    if (i > 0 && game->board[i-1][j] == -1) {
                        Game child_game = *game;
                        child_game.board[i-1][j] = child_game.board[i][j];
                        child_game.board[i][j] = -1;
                        child_game.player ^= 1;
                        child_game.last_move.x = i-1;
                        child_game.last_move.y = j;
                        int score = minimax(&child_game, depth-1, alpha, beta, 0);
                        best_score = max(best_score, score);
                        alpha = max(alpha, best_score);
                        if (beta <= alpha) {
                            break;
                        }
                    }
                    if (i < BOARD_SIZE-1 && game->board[i+1][j] == -1) {
                        Game child_game = *game;
                        child_game.board[i+1][j] = child_game.board[i][j];
                        child_game.board[i][j] = -1;
                        child_game.player ^= 1;
                        child_game.last_move.x = i+1;
                        child_game.last_move.y = j;
                        int score = minimax(&child_game, depth-1, alpha, beta, 0);
                        best_score = max(best_score, score);
                        alpha = max(alpha, best_score);
                        if (beta <= alpha) {
                            break;
                        }
                    }
                    if (j > 0 && game->board[i][j-1] == -1) {
                        Game child_game = *game;
                        child_game.board[i][j-1] = child_game.board[i][j];
                        child_game.board[i][j] = -1;
                        child_game.player ^= 1;
                        child_game.last_move.x = i;
                        child_game.last_move.y = j-1;
                        int score = minimax(&child_game, depth-1, alpha, beta, 0);
                        best_score = max(best_score, score);
                        alpha = max(alpha, best_score);
                        if (beta <= alpha) {
                            break;
                        }
                    }
                    if (j < BOARD_SIZE-1 && game->board[i][j+1] == -1) {
                        Game child_game = *game;
                        child_game.board[i][j+1] = child_game.board[i][j];
                        child_game.board[i][j] = -1;
                        child_game.player ^= 1;
                        child_game.last_move.x = i;
                        child_game.last_move.y = j+1;
                        int score = minimax(&child_game, depth-1, alpha, beta, 0);
                        best_score = max(best_score, score);
                        alpha = max(alpha, best_score);
                        if (beta <= alpha) {
                            break;
                        }
                    }
                }
            }
        }
    } else {
        best_score = 10000;
        for (int i=0; i<BOARD_SIZE; i++) {
            for (int j=0; j<BOARD_SIZE; j++) {
                if (game->board[i][j] == (game->player^1)) {
                    if (i > 0 && game->board[i-1][j] == -1) {
                        Game child_game = *game;
                        child_game.board[i-1][j] = child_game.board[i][j];
                        child_game.board[i][j] = -1;
                        child_game.player ^= 1;
                        child_game.last_move.x = i-1;
                        child_game.last_move.y = j;
                        int score = minimax(&child_game, depth-1, alpha, beta, 1);
                        best_score = min(best_score, score);
                        beta = min(beta, best_score);
                        if (beta <= alpha) {
                            break;
                        }
                    }
                    if (i < BOARD_SIZE-1 && game->board[i+1][j] == -1) {
                        Game child_game = *game;
                        child_game.board[i+1][j] = child_game.board[i][j];
                        child_game.board[i][j] = -1;
                        child_game.player ^= 1;
                        child_game.last_move.x = i+1;
                        child_game.last_move.y = j;
                        int score = minimax(&child_game, depth-1, alpha, beta, 1);
                        best_score = min(best_score, score);
                        beta = min(beta, best_score);
                        if (beta <= alpha) {
                            break;
                        }
                    }
                    if (j > 0 && game->board[i][j-1] == -1) {
                        Game child_game = *game;
                        child_game.board[i][j-1] = child_game.board[i][j];
                        child_game.board[i][j] = -1;
                        child_game.player ^= 1;
                        child_game.last_move.x = i;
                        child_game.last_move.y = j-1;
                        int score = minimax(&child_game, depth-1, alpha, beta, 1);
                        best_score = min(best_score, score);
                        beta = min(beta, best_score);
                        if (beta <= alpha) {
                            break;
                        }
                    }
                    if (j < BOARD_SIZE-1 && game->board[i][j+1] == -1) {
                        Game child_game = *game;
                        child_game.board[i][j+1] = child_game.board[i][j];
                        child_game.board[i][j] = -1;
                        child_game.player ^= 1;
                        child_game.last_move.x = i;
                        child_game.last_move.y = j+1;
                        int score = minimax(&child_game, depth-1, alpha, beta, 1);
                        best_score = min(best_score, score);
                        beta = min(beta, best_score);
                        if (beta <= alpha) {
                            break;
                        }
                    }
                }
            }
        }
    }
    return best_score;
}

Move get_computer_move(Game *game) {
    Move best_move;
    int best_score = -10000;
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            if (game->board[i][j] == game->player) {
                if (i > 0 && game->board[i-1][j] == -1) {
                    Game child_game = *game;
                    child_game.board[i-1][j] = child_game.board[i][j];
                    child_game.board[i][j] = -1;
                    child_game.player ^= 1;
                    child_game.last_move.x = i-1;
                    child_game.last_move.y = j;
                    int score = minimax(&child_game, MAX_DEPTH, -10000, 10000, 0);
                    if (score > best_score) {
                        best_score = score;
                        best_move.x = i-1;
                        best_move.y = j;
                    }
                }
                if (i < BOARD_SIZE-1 && game->board[i+1][j] == -1) {
                    Game child_game = *game;
                    child_game.board[i+1][j] = child_game.board[i][j];
                    child_game.board[i][j] = -1;
                    child_game.player ^= 1;
                    child_game.last_move.x = i+1;
                    child_game.last_move.y = j;
                    int score = minimax(&child_game, MAX_DEPTH, -10000, 10000, 0);
                    if (score > best_score) {
                        best_score = score;
                        best_move.x = i+1;
                        best_move.y = j;
                    }
                }
                if (j > 0 && game->board[i][j-1] == -1) {
                    Game child_game = *game;
                    child_game.board[i][j-1] = child_game.board[i][j];
                    child_game.board[i][j] = -1;
                    child_game.player ^= 1;
                    child_game.last_move.x = i;
                    child_game.last_move.y = j-1;
                    int score = minimax(&child_game, MAX_DEPTH, -10000, 10000, 0);
                    if (score > best_score) {
                        best_score = score;
                        best_move.x = i;
                        best_move.y = j-1;
                    }
                }
                if (j < BOARD_SIZE-1 && game->board[i][j+1] == -1) {
                    Game child_game = *game;
                    child_game.board[i][j+1] = child_game.board[i][j];
                    child_game.board[i][j] = -1;
                    child_game.player ^= 1;
                    child_game.last_move.x = i;
                    child_game.last_move.y = j+1;
                    int score = minimax(&child_game, MAX_DEPTH, -10000, 10000, 0);
                    if (score > best_score) {
                        best_score = score;
                        best_move.x = i;
                        best_move.y = j+1;
                    }
                }
            }
        }
    }
    return best_move;
}

int is_game_over(Game *game) {
    int player_count = 0;
    int opponent_count = 0;
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            if (game->board[i][j] == game->player) {
                player_count++;
            } else if (game->board[i][j] == (game->player ^ 1)) {
                opponent_count++;
            }
        }
    }
    if (player_count == 0) {
        return 1;
    }
    if (opponent_count == 0) {
        return 2;
    }
    return 0;
}

void play_game() {
    Game game;
    memset(game.board, -1, sizeof(game.board));
    game.player = 0;
    game.last_move.x = -1;
    game.last_move.y = -1;

    printf("Welcome to Chess.ai! You're the player 0\n");
    printf("You can move your pieces one space at a time diagonally or forwards if you have not moved that piece before.\n");
    printf("The number on each square represents the player who has claimed that position, 0 = player and 1 = computer.\n");
    printf("0 pieces => You Won | 1 pieces => Computer won\n");
    printf("\n");

    while (1) {
        if (game.player == 0) {
            print_board(&game);
            printf("Enter your move (x y): ");
            int x, y;
            scanf("%d %d", &x, &y);
            if (game.board[x][y] != game.player) {
                printf("Invalid move. Try again.\n");
                continue;
            }
            if (x == game.last_move.x && y == game.last_move.y) {
                printf("Cannot move the same piece twice in a row. Try again.\n");
                continue;
            }
            if (x > 0 && game.board[x-1][y] == -1) {
                game.board[x-1][y] = game.board[x][y];
                game.board[x][y] = -1;
                game.player ^= 1;
                game.last_move.x = x-1;
                game.last_move.y = y;
            } else if (x < BOARD_SIZE-1 && game.board[x+1][y] == -1) {
                game.board[x+1][y] = game.board[x][y];
                game.board[x][y] = -1;
                game.player ^= 1;
                game.last_move.x = x+1;
                game.last_move.y = y;
            } else if (y > 0 && game.board[x][y-1] == -1) {
                game.board[x][y-1] = game.board[x][y];
                game.board[x][y] = -1;
                game.player ^= 1;
                game.last_move.x = x;
                game.last_move.y = y-1;
            } else if (y < BOARD_SIZE-1 && game.board[x][y+1] == -1) {
                game.board[x][y+1] = game.board[x][y];
                game.board[x][y] = -1;
                game.player ^= 1;
                game.last_move.x = x;
                game.last_move.y = y+1;
            } else {
                printf("Invalid move. Try again.\n");
                continue;
            }
        } else {
            printf("Computer's move...\n");
            Move move = get_computer_move(&game);
            game.board[move.x][move.y] = game.board[move.x+1][move.y];
            game.board[move.x+1][move.y] = -1;
            game.player ^= 1;
            game.last_move.x = move.x;
            game.last_move.y = move.y;
        }

        int game_result = is_game_over(&game);
        if (game_result == 1) {
            printf("You won!\n");
            break;
        } else if (game_result == 2) {
            printf("Computer won!\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    play_game();

    return 0;
}