//FormAI DATASET v1.0 Category: Checkers Game ; Style: statistical
#include <stdio.h>

#define BOARD_SIZE 8
#define PLAYER_1 1
#define PLAYER_2 2
#define EMPTY 0
#define PIECE_PLAYER_1 1
#define PIECE_PLAYER_2 2
#define KING_PLAYER_1 3
#define KING_PLAYER_2 4

// creates a board
void create_board(int board[BOARD_SIZE][BOARD_SIZE]){
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if((i+j)%2 == 0) {
                if(i<3) {
                    // fill first 3 rows with player 1 pieces
                    board[i][j] = PIECE_PLAYER_1;
                } else if(i>4) {
                    // fill last 3 rows with player 2 pieces
                    board[i][j] = PIECE_PLAYER_2;
                } else {
                    // fill empty rows with 0s
                    board[i][j] = EMPTY;
                }
            } else {
                // change empty cells values to -1
                board[i][j] = -1;
            }
        }
    }
}

// prints the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE], int player_turn) {
    printf("\n");
    printf("Player %d's turn\n", player_turn);
    printf("\n    0   1   2   3   4   5   6   7\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i);
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("|");
            switch(board[i][j]) {
                case -1:
                    printf("   ");
                    break;
                case 0:
                    printf("   ");
                    break;
                case PIECE_PLAYER_1:
                    printf(" 1 ");
                    break;
                case PIECE_PLAYER_2:
                    printf(" 2 ");
                    break;
                case KING_PLAYER_1:
                    printf(" 1K");
                    break;
                case KING_PLAYER_2:
                    printf(" 2K");
                    break;
                default:
                    printf("ERR");
                    break;
            }
        }
        printf("| %d\n", i);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    0   1   2   3   4   5   6   7\n");
}

// moves a piece from old coordinates to new coordinates
void move_piece(int board[BOARD_SIZE][BOARD_SIZE], int piece_row, int piece_col, int dest_row, int dest_col) {
    int piece_type = board[piece_row][piece_col];
    board[dest_row][dest_col] = piece_type;
    board[piece_row][piece_col] = EMPTY;

    // check for promotion
    if(piece_type == PIECE_PLAYER_1 && dest_row == BOARD_SIZE-1) {
        board[dest_row][dest_col] = KING_PLAYER_1;
    } else if(piece_type == PIECE_PLAYER_2 && dest_row == 0) {
        board[dest_row][dest_col] = KING_PLAYER_2;
    }
}

// captures a piece
void capture_piece(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    board[row][col] = EMPTY;
}

// checks if a capture is possible for a piece
int can_capture(int board[BOARD_SIZE][BOARD_SIZE], int piece_row, int piece_col, int player) {
    int piece_type = board[piece_row][piece_col];
    if(piece_type == KING_PLAYER_1 || piece_type == KING_PLAYER_2) {
        // diagonal moves for kings
        for(int i=-1; i<=1; i+=2) {
            for(int j=-1; j<=1; j+=2) {
                int cap_row = piece_row + i;
                int cap_col = piece_col + j;
                if(cap_row >= BOARD_SIZE || cap_col >= BOARD_SIZE || cap_row < 0 || cap_col < 0 || board[cap_row][cap_col] == EMPTY) {
                    continue;
                }
                int cap_type = board[cap_row][cap_col];
                if(cap_type == (player == PLAYER_1 ? PIECE_PLAYER_2 : PIECE_PLAYER_1) || cap_type == (player == PLAYER_1 ? KING_PLAYER_2 : KING_PLAYER_1)) {
                    int cap_dir_row = i > 0 ? 1 : -1;
                    int cap_dir_col = j > 0 ? 1 : -1;
                    int dest_row = cap_row + cap_dir_row;
                    int dest_col = cap_col + cap_dir_col;
                    if(dest_row >= BOARD_SIZE || dest_col >= BOARD_SIZE || dest_row < 0 || dest_col < 0 || board[dest_row][dest_col] != EMPTY) {
                        continue;
                    }
                    return 1;
                }
            }
        }
    } else {
        // diagonal moves for regular pieces
        int forward = player == PLAYER_1 ? 1 : -1;
        for(int i=-1; i<=1; i+=2) {
            int cap_row = piece_row + forward;
            int cap_col = piece_col + i;
            if(cap_row >= BOARD_SIZE || cap_col >= BOARD_SIZE || cap_row < 0 || cap_col < 0 || board[cap_row][cap_col] == EMPTY) {
                continue;
            }
            int cap_type = board[cap_row][cap_col];
            if(cap_type == (player == PLAYER_1 ? PIECE_PLAYER_2 : PIECE_PLAYER_1) || cap_type == (player == PLAYER_1 ? KING_PLAYER_2 : KING_PLAYER_1)) {
                int cap_dir_row = forward;
                int cap_dir_col = i > 0 ? 1 : -1;
                int dest_row = cap_row + cap_dir_row;
                int dest_col = cap_col + cap_dir_col;
                if(dest_row >= BOARD_SIZE || dest_col >= BOARD_SIZE || dest_row < 0 || dest_col < 0 || board[dest_row][dest_col] != EMPTY) {
                    continue;
                }
                return 1;
            }
        }
    }
    return 0;
}

// checks if a move is possible for a piece
int can_move(int board[BOARD_SIZE][BOARD_SIZE], int piece_row, int piece_col, int player) {
    int piece_type = board[piece_row][piece_col];
    if(piece_type == KING_PLAYER_1 || piece_type == KING_PLAYER_2) {
        // diagonal moves for kings
        for(int i=-1; i<=1; i+=2) {
            for(int j=-1; j<=1; j+=2) {
                int dest_row = piece_row + i;
                int dest_col = piece_col + j;
                if(dest_row >= BOARD_SIZE || dest_col >= BOARD_SIZE || dest_row < 0 || dest_col < 0 || board[dest_row][dest_col] != EMPTY) {
                    continue;
                }
                if(can_capture(board, piece_row, piece_col, player)) {
                    return 1;
                }
                return 1;
            }
        }
    } else {
        // diagonal moves for regular pieces
        int forward = player == PLAYER_1 ? 1 : -1;
        for(int i=-1; i<=1; i+=2) {
            int dest_row = piece_row + forward;
            int dest_col = piece_col + i;
            if(dest_row >= BOARD_SIZE || dest_col >= BOARD_SIZE || dest_row < 0 || dest_col < 0 || board[dest_row][dest_col] != EMPTY) {
                continue;
            }
            if(can_capture(board, piece_row, piece_col, player)) {
                return 1;
            }
            return 1;
        }
    }
    return 0;
}

// checks if the game has ended
int game_over(int board[BOARD_SIZE][BOARD_SIZE]) {
    int player1_pieces = 0;
    int player2_pieces = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == PIECE_PLAYER_1 || board[i][j] == KING_PLAYER_1) {
                player1_pieces++;
            }
            if(board[i][j] == PIECE_PLAYER_2 || board[i][j] == KING_PLAYER_2) {
                player2_pieces++;
            }
        }
    }
    if(player1_pieces == 0 || player2_pieces == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int player_turn = PLAYER_1;
    int game_finished = 0;

    create_board(board);

    while(!game_finished) {
        print_board(board, player_turn);

        // check if current player can move
        int can_player_move = 0;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if((player_turn == PLAYER_1 && (board[i][j] == PIECE_PLAYER_1 || board[i][j] == KING_PLAYER_1)) || (player_turn == PLAYER_2 && (board[i][j] == PIECE_PLAYER_2 || board[i][j] == KING_PLAYER_2))) {
                    if(can_move(board, i, j, player_turn)) {
                        can_player_move = 1;
                    }
                }
            }
        }
        if(!can_player_move) {
            printf("\nPlayer %d cannot move, the game is over\n", player_turn);
            game_finished = 1;
            break;
        }

        int piece_row = -1;
        int piece_col = -1;
        int dest_row = -1;
        int dest_col = -1;

        printf("Type in the coordinates of the piece you want to move (row, column): ");
        scanf("%d,%d", &piece_row, &piece_col);

        if(piece_row < 0 || piece_row >= BOARD_SIZE || piece_col < 0 || piece_col >= BOARD_SIZE) {
            printf("Those coordinates are invalid, please try again\n");
            continue;
        }

        if((player_turn == PLAYER_1 && (board[piece_row][piece_col] != PIECE_PLAYER_1 && board[piece_row][piece_col] != KING_PLAYER_1)) || (player_turn == PLAYER_2 && (board[piece_row][piece_col] != PIECE_PLAYER_2 && board[piece_row][piece_col] != KING_PLAYER_2))) {
            printf("That's not your piece, please try again\n");
            continue;
        }

        printf("Type in the coordinates of the destination you want to move to (row, column): ");
        scanf("%d,%d", &dest_row, &dest_col);

        if(dest_row < 0 || dest_row >= BOARD_SIZE || dest_col < 0 || dest_col >= BOARD_SIZE || board[dest_row][dest_col] != EMPTY) {
            printf("Those coordinates are invalid, please try again\n");
            continue;
        }

        int piece_type = board[piece_row][piece_col];
        if(piece_type == KING_PLAYER_1 || piece_type == KING_PLAYER_2) {
            // diagonal moves for kings
            int dir_row = dest_row > piece_row ? 1 : -1;
            int dir_col = dest_col > piece_col ? 1 : -1;
            int curr_row = piece_row + dir_row;
            int curr_col = piece_col + dir_col;
            while(curr_row != dest_row && curr_col != dest_col) {
                if(board[curr_row][curr_col] != EMPTY) {
                    printf("You can only jump over pieces with a capture, please try again\n");
                    continue;
                }
                curr_row += dir_row;
                curr_col += dir_col;
            }
        } else {
            // diagonal moves for regular pieces
            int forward = player_turn == PLAYER_1 ? 1 : -1;
            int dir_row = dest_row > piece_row ? 1 : -1;
            int dir_col = dest_col > piece_col ? 1 : -1;
            if(piece_type == PIECE_PLAYER_1 && dir_row == -1) {
                printf("Regular pieces can only move forwards, please try again\n");
                continue;
            }
            if(piece_type == PIECE_PLAYER_2 && dir_row == 1) {
                printf("Regular pieces can only move forwards, please try again\n");
                continue;
            }
            int curr_row = piece_row + dir_row;
            int curr_col = piece_col + dir_col;
            while(curr_row != dest_row && curr_col != dest_col) {
                if(board[curr_row][curr_col] != EMPTY) {
                    printf("You can only jump over pieces with a capture, please try again\n");
                    continue;
                }
                curr_row += dir_row;
                curr_col += dir_col;
            }
        }

        move_piece(board, piece_row, piece_col, dest_row, dest_col);

        // check for captures
        int did_capture = 0;
        if(abs(dest_row-piece_row) == 2 && abs(dest_col-piece_col) == 2) {
            int capture_row = (dest_row + piece_row)/2;
            int capture_col = (dest_col + piece_col)/2;
            capture_piece(board, capture_row, capture_col);
            did_capture = 1;
        }

        // check for promotion
        if(board[dest_row][dest_col] == PIECE_PLAYER_1 && dest_row == BOARD_SIZE-1) {
            board[dest_row][dest_col] = KING_PLAYER_1;
        } else if(board[dest_row][dest_col] == PIECE_PLAYER_2 && dest_row == 0) {
            board[dest_row][dest_col] = KING_PLAYER_2;
        }

        // check if the player can keep capturing
        if(did_capture && can_capture(board, dest_row, dest_col, player_turn)) {
            piece_row = dest_row;
            piece_col = dest_col;
            printf("\nYou have captured an enemy piece and have another capture available, please choose a new destination for your piece\n");
            continue;
        }

        game_finished = game_over(board);
        player_turn = player_turn == PLAYER_1 ? PLAYER_2 : PLAYER_1;
    }

    printf("\nGame over!\n");
    print_board(board, player_turn);

    return 0;
}