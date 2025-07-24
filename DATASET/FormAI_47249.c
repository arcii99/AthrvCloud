//FormAI DATASET v1.0 Category: Chess engine ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int x;
    int y;
} Coord;

typedef struct {
    Coord start; // starting coordinates of piece
    Coord end; // ending coordinates of piece
} Move;

typedef enum {
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
} Piece;

typedef struct {
    Piece piece;
    int color; // 0 refers to white, 1 refers to black
} Square;

typedef struct {
    int turn; // 0 refers to white's turn, 1 refers to black's turn
    Square board[8][8];
} GameState;

// function to initialize the game state with starting position
void init_game_state(GameState *game_state) {
    // initialize empty squares
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            game_state->board[i][j].piece = EMPTY;
        }
    }

    // initialize pawns
    for(int i = 0; i < 8; i++) {
        game_state->board[1][i].piece = PAWN;
        game_state->board[1][i].color = 0;
        game_state->board[6][i].piece = PAWN;
        game_state->board[6][i].color = 1;
    }

    // initialize knights
    game_state->board[0][1].piece = KNIGHT;
    game_state->board[0][1].color = 0;
    game_state->board[0][6].piece = KNIGHT;
    game_state->board[0][6].color = 0;
    game_state->board[7][1].piece = KNIGHT;
    game_state->board[7][1].color = 1;
    game_state->board[7][6].piece = KNIGHT;
    game_state->board[7][6].color = 1;

    // initialize bishops
    game_state->board[0][2].piece = BISHOP;
    game_state->board[0][2].color = 0;
    game_state->board[0][5].piece = BISHOP;
    game_state->board[0][5].color = 0;
    game_state->board[7][2].piece = BISHOP;
    game_state->board[7][2].color = 1;
    game_state->board[7][5].piece = BISHOP;
    game_state->board[7][5].color = 1;

    // initialize rooks
    game_state->board[0][0].piece = ROOK;
    game_state->board[0][0].color = 0;
    game_state->board[0][7].piece = ROOK;
    game_state->board[0][7].color = 0;
    game_state->board[7][0].piece = ROOK;
    game_state->board[7][0].color = 1;
    game_state->board[7][7].piece = ROOK;
    game_state->board[7][7].color = 1;

    // initialize queens
    game_state->board[0][3].piece = QUEEN;
    game_state->board[0][3].color = 0;
    game_state->board[7][3].piece = QUEEN;
    game_state->board[7][3].color = 1;

    // initialize kings
    game_state->board[0][4].piece = KING;
    game_state->board[0][4].color = 0;
    game_state->board[7][4].piece = KING;
    game_state->board[7][4].color = 1;

    // initialize turn to white's turn
    game_state->turn = 0;
}

// function to print the game state
void print_game_state(GameState *game_state) {
    printf("   a  b  c  d  e  f  g  h\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for(int j = 0; j < 8; j++) {
            if(game_state->board[i][j].piece == EMPTY) {
                printf("[ ]");
            } else {
                switch(game_state->board[i][j].piece) {
                    case PAWN:
                        printf("[P]");
                        break;
                    case KNIGHT:
                        printf("[N]");
                        break;
                    case BISHOP:
                        printf("[B]");
                        break;
                    case ROOK:
                        printf("[R]");
                        break;
                    case QUEEN:
                        printf("[Q]");
                        break;
                    case KING:
                        printf("[K]");
                        break;
                }
            }
        }
        printf(" %d\n", 8 - i);
    }
    printf("   a  b  c  d  e  f  g  h\n");
}

// function to check if a move is valid
int is_valid_move(GameState *game_state, Move *move) {
    // check if start and end coordinates are within the board
    if(move->start.x < 0 || move->start.x > 7 || move->start.y < 0 || move->start.y > 7 || move->end.x < 0 || move->end.x > 7 || move->end.y < 0 || move->end.y > 7) {
        return 0;
    }

    // check if there is a piece at the starting coordinates
    if(game_state->board[move->start.x][move->start.y].piece == EMPTY) {
        return 0;
    }

    // check if the piece is moving to a square occupied by a piece of the same color
    if(game_state->board[move->end.x][move->end.y].piece != EMPTY && game_state->board[move->start.x][move->start.y].color == game_state->board[move->end.x][move->end.y].color) {
        return 0;
    }

    // check if the move is valid for the piece
    switch(game_state->board[move->start.x][move->start.y].piece) {
        case PAWN:
            // if pawn is moving forward
            if(move->start.y == move->end.y) {
                // if pawn is moving two squares forward and the squares in between are empty
                if(move->start.x == 1 && move->end.x == 3 && game_state->board[2][move->end.y].piece == EMPTY) {
                    return 1;
                }
                // if pawn is moving one square forward and the square is empty
                if(move->start.x == move->end.x - 1 && game_state->board[move->end.x][move->end.y].piece == EMPTY) {
                    return 1;
                }
            }
            // if pawn is capturing
            if(abs(move->start.y - move->end.y) == 1 && move->start.x == move->end.x - 1) {
                // if pawn is capturing a piece of the opposite color
                if(game_state->board[move->end.x][move->end.y].piece != EMPTY && game_state->board[move->start.x][move->start.y].color != game_state->board[move->end.x][move->end.y].color) {
                    return 1;
                }
            }
            break;
        case KNIGHT:
            // check if knight is moving to a square that is two squares horizontally or vertically and one square horizontally or vertically away
            if((abs(move->start.x - move->end.x) == 2 && abs(move->start.y - move->end.y) == 1) || (abs(move->start.x - move->end.x) == 1 && abs(move->start.y - move->end.y) == 2)) {
                return 1;
            }
            break;
        case BISHOP:
            // check if bishop is moving diagonally and the squares in between are empty
            if(abs(move->start.x - move->end.x) == abs(move->start.y - move->end.y)) {
                int x_dir = (move->end.x > move->start.x) ? 1 : -1;
                int y_dir = (move->end.y > move->start.y) ? 1 : -1;
                for(int i = move->start.x + x_dir, j = move->start.y + y_dir; i != move->end.x; i += x_dir, j += y_dir) {
                    if(game_state->board[i][j].piece != EMPTY) {
                        return 0;
                    }
                }
                return 1;
            }
            break;
        case ROOK:
            // check if rook is moving horizontally or vertically and the squares in between are empty
            if(move->start.x == move->end.x || move->start.y == move->end.y) {
                int x_dir = (move->end.x > move->start.x) ? 1 : (move->end.x == move->start.x) ? 0 : -1;
                int y_dir = (move->end.y > move->start.y) ? 1 : (move->end.y == move->start.y) ? 0 : -1;
                for(int i = move->start.x + x_dir, j = move->start.y + y_dir; i != move->end.x || j != move->end.y; i += x_dir, j += y_dir) {
                    if(game_state->board[i][j].piece != EMPTY) {
                        return 0;
                    }
                }
                return 1;
            }
            break;
        case QUEEN:
            // check if queen is moving horizontally, vertically, or diagonally and the squares in between are empty
            if(move->start.x == move->end.x || move->start.y == move->end.y || abs(move->start.x - move->end.x) == abs(move->start.y - move->end.y)) {
                int x_dir, y_dir;
                if(move->start.x == move->end.x) {
                    x_dir = 0;
                } else {
                    x_dir = (move->end.x > move->start.x) ? 1 : -1;
                }
                if(move->start.y == move->end.y) {
                    y_dir = 0;
                } else {
                    y_dir = (move->end.y > move->start.y) ? 1 : -1;
                }
                if(move->start.x != move->end.x && move->start.y != move->end.y) {
                    x_dir = (move->end.x > move->start.x) ? 1 : (move->end.x == move->start.x) ? 0 : -1;
                    y_dir = (move->end.y > move->start.y) ? 1 : (move->end.y == move->start.y) ? 0 : -1;
                }
                for(int i = move->start.x + x_dir, j = move->start.y + y_dir; i != move->end.x || j != move->end.y; i += x_dir, j += y_dir) {
                    if(game_state->board[i][j].piece != EMPTY) {
                        return 0;
                    }
                }
                return 1;
            }
            break;
        case KING:
            // check if king is moving one square in any direction
            if((abs(move->start.x - move->end.x) <= 1) && (abs(move->start.y - move->end.y) <= 1)) {
                return 1;
            }
            break;
    }

    return 0;
}

// function to perform a move
void perform_move(GameState *game_state, Move *move) {
    game_state->board[move->end.x][move->end.y] = game_state->board[move->start.x][move->start.y];
    game_state->board[move->start.x][move->start.y].piece = EMPTY;
    game_state->board[move->start.x][move->start.y].color = 0;

    game_state->turn = (game_state->turn == 0) ? 1 : 0;
}

void *play_game(void *game_state_ptr) {
    GameState *game_state = (GameState *) game_state_ptr;

    while(1) {
        // print game state and ask for move
        print_game_state(game_state);
        printf("%s\n", (game_state->turn == 0) ? "White's turn" : "Black's turn");
        printf("Enter start and end coordinates of the form 'a1 a3': ");
        char start_c, end_c;
        int start_r, end_r;
        scanf(" %c%d %c%d", &start_c, &start_r, &end_c, &end_r);

        // convert coordinates to indices
        Coord start, end;
        start.y = start_c - 'a';
        start.x = 8 - start_r;
        end.y = end_c - 'a';
        end.x = 8 - end_r;

        // create move
        Move move;
        move.start = start;
        move.end = end;

        // check if move is valid and perform the move if it is
        if(is_valid_move(game_state, &move)) {
            perform_move(game_state, &move);
        } else {
            printf("Invalid move\n");
        }
    }
}

int main() {
    // initialize game state
    GameState game_state;
    init_game_state(&game_state);

    // create thread for playing game
    pthread_t game_thread;
    pthread_create(&game_thread, NULL, play_game, (void *) &game_state);
    pthread_join(game_thread, NULL);

    return 0;
}