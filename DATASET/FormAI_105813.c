//FormAI DATASET v1.0 Category: Chess engine ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define the chess board size constant
#define SIZE 8

//define the constants for the pieces (capital letters for black, lowercase for white)
#define EMPTY '.'
#define KING 'k'
#define QUEEN 'q'
#define ROOK 'r'
#define BISHOP 'b'
#define KNIGHT 'n'
#define PAWN 'p'
#define BLACK_KING 'K'
#define BLACK_QUEEN 'Q'
#define BLACK_ROOK 'R'
#define BLACK_BISHOP 'B'
#define BLACK_KNIGHT 'N'
#define BLACK_PAWN 'P'

//function to print the chess board
void print_board(char board[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE-i);
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

//function to initialize the chess board with starting layout
void init_board(char board[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(i == 0 || i == 7) {
                switch(j) {
                    case 0:
                    case 7:
                        board[i][j] = (i == 0) ? BLACK_ROOK : ROOK;
                        break;
                    case 1:
                    case 6:
                        board[i][j] = (i == 0) ? BLACK_KNIGHT : KNIGHT;
                        break;
                    case 2:
                    case 5:
                        board[i][j] = (i == 0) ? BLACK_BISHOP : BISHOP;
                        break;
                    case 3:
                        board[i][j] = (i == 0) ? BLACK_QUEEN : QUEEN;
                        break;
                    case 4:
                        board[i][j] = (i == 0) ? BLACK_KING : KING;
                        break;
                    default:
                        break;
                }
            }
            else if(i == 1 || i == 6) {
                board[i][j] = (i == 1) ? BLACK_PAWN : PAWN;
            }
            else {
                board[i][j] = EMPTY;
            }
        }
    }
}

//function to get user input
void get_input(char* input) {
    printf("> ");
    scanf("%s", input);
}

//function to validate user input
int validate_input(char* input) {
    if(strlen(input) != 2) return 0;
    if(input[0] < 'a' || input[0] > 'h') return 0;
    if(input[1] < '1' || input[1] > '8') return 0;
    return 1;
}

//function to move a piece on the chess board
void move_piece(char board[SIZE][SIZE], int from_i, int from_j, int to_i, int to_j) {
    board[to_i][to_j] = board[from_i][from_j];
    board[from_i][from_j] = EMPTY;
}

//function to get the color of a piece ('W' for white, 'B' for black)
char get_color(char piece) {
    return (piece == BLACK_KING || piece == BLACK_QUEEN || piece == BLACK_ROOK || piece == BLACK_BISHOP || piece == BLACK_KNIGHT || piece == BLACK_PAWN) ? 'B' : 'W';
}

//function to check if the game has ended (either one player has won or it is a draw)
int is_game_over(char board[SIZE][SIZE]) {
    //check for checkmate (if king is in checkmate, game is over)
    int black_king_i = -1, black_king_j = -1, white_king_i = -1, white_king_j = -1;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == BLACK_KING) {
                black_king_i = i;
                black_king_j = j;
            }
            else if(board[i][j] == KING) {
                white_king_i = i;
                white_king_j = j;
            }
        }
    }
    //check if black king is in check
    if(black_king_i != -1) {
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(board[i][j] != EMPTY && get_color(board[i][j]) == 'W') {
                    if(validate_move(board, i, j, black_king_i, black_king_j)) {
                        printf("Checkmate! White wins!\n");
                        return 1;
                    }
                }
            }
        }
        //check if black king is in stalemate (cannot move but is not in check)
        int has_valid_move = 0;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(board[i][j] != EMPTY && get_color(board[i][j]) == 'B') {
                    for(int ti = 0; ti < SIZE; ti++) {
                        for(int tj = 0; tj < SIZE; tj++) {
                            if(validate_move(board, i, j, ti, tj)) {
                                has_valid_move = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(!has_valid_move) {
            printf("Stalemate! Game is a draw.\n");
            return 1;
        }
    }
    //check if white king is in check
    if(white_king_i != -1) {
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(board[i][j] != EMPTY && get_color(board[i][j]) == 'B') {
                    if(validate_move(board, i, j, white_king_i, white_king_j)) {
                        printf("Checkmate! Black wins!\n");
                        return 1;
                    }
                }
            }
        }
        //check if white king is in stalemate (cannot move but is not in check)
        int has_valid_move = 0;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(board[i][j] != EMPTY && get_color(board[i][j]) == 'W') {
                    for(int ti = 0; ti < SIZE; ti++) {
                        for(int tj = 0; tj < SIZE; tj++) {
                            if(validate_move(board, i, j, ti, tj)) {
                                has_valid_move = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(!has_valid_move) {
            printf("Stalemate! Game is a draw.\n");
            return 1;
        }
    }
    return 0;
}

//function to validate a move
int validate_move(char board[SIZE][SIZE], int from_i, int from_j, int to_i, int to_j) {
    char piece = board[from_i][from_j];
    char dest = board[to_i][to_j];
    if(get_color(piece) == get_color(dest)) return 0;
    switch(piece) {
        case PAWN:
            if(from_j == to_j && dest == EMPTY) {
                if(from_i == 6 && to_i == 4 && board[5][from_j] == EMPTY) {
                    return 1;
                }
                if(from_i == to_i-1) {
                    return 1;
                }
            }
            else if((from_i == to_i-1) && (from_j == to_j+1 || from_j == to_j-1) && get_color(dest) == 'B') {
                return 1;
            }
            break;
        case BLACK_PAWN:
            if(from_j == to_j && dest == EMPTY) {
                if(from_i == 1 && to_i == 3 && board[2][from_j] == EMPTY) {
                    return 1;
                }
                if(from_i == to_i+1) {
                    return 1;
                }
            }
            else if((from_i == to_i+1) && (from_j == to_j+1 || from_j == to_j-1) && get_color(dest) == 'W') {
                return 1;
            }
            break;
        case ROOK:
        case BLACK_ROOK:
            if(from_i == to_i) {
                int min_j = (from_j < to_j) ? from_j : to_j;
                int max_j = (from_j < to_j) ? to_j : from_j;
                for(int j = min_j+1; j < max_j; j++) {
                    if(board[from_i][j] != EMPTY) {
                        return 0;
                    }
                }
                return 1;
            }
            else if(from_j == to_j) {
                int min_i = (from_i < to_i) ? from_i : to_i;
                int max_i = (from_i < to_i) ? to_i : from_i;
                for(int i = min_i+1; i < max_i; i++) {
                    if(board[i][from_j] != EMPTY) {
                        return 0;
                    }
                }
                return 1;
            }
            break;
        case BISHOP:
        case BLACK_BISHOP:
            if(abs(from_i-to_i) == abs(from_j-to_j)) {
                int i, j;
                if(from_i < to_i && from_j < to_j) {
                    i = from_i+1;
                    j = from_j+1;
                    while(i < to_i) {
                        if(board[i][j] != EMPTY) {
                            return 0;
                        }
                        i++;
                        j++;
                    }
                    return 1;
                }
                else if(from_i < to_i && from_j > to_j) {
                    i = from_i+1;
                    j = from_j-1;
                    while(i < to_i) {
                        if(board[i][j] != EMPTY) {
                            return 0;
                        }
                        i++;
                        j--;
                    }
                    return 1;
                }
                else if(from_i > to_i && from_j < to_j) {
                    i = from_i-1;
                    j = from_j+1;
                    while(i > to_i) {
                        if(board[i][j] != EMPTY) {
                            return 0;
                        }
                        i--;
                        j++;
                    }
                    return 1;
                }
                else {
                    i = from_i-1;
                    j = from_j-1;
                    while(i > to_i) {
                        if(board[i][j] != EMPTY) {
                            return 0;
                        }
                        i--;
                        j--;
                    }
                    return 1;
                }
            }
            break;
        case KNIGHT:
        case BLACK_KNIGHT:
            if((abs(from_i-to_i) == 2 && abs(from_j-to_j) == 1) || (abs(from_i-to_i) == 1 && abs(from_j-to_j) == 2)) {
                return 1;
            }
            break;
        case QUEEN:
        case BLACK_QUEEN:
            if(from_i == to_i || from_j == to_j) {
                if(from_i == to_i) {
                    int min_j = (from_j < to_j) ? from_j : to_j;
                    int max_j = (from_j < to_j) ? to_j : from_j;
                    for(int j = min_j+1; j < max_j; j++) {
                        if(board[from_i][j] != EMPTY) {
                            return 0;
                        }
                    }
                    return 1;
                }
                else if(from_j == to_j) {
                    int min_i = (from_i < to_i) ? from_i : to_i;
                    int max_i = (from_i < to_i) ? to_i : from_i;
                    for(int i = min_i+1; i < max_i; i++) {
                        if(board[i][from_j] != EMPTY) {
                            return 0;
                        }
                    }
                    return 1;
                }
            }
            else if(abs(from_i-to_i) == abs(from_j-to_j)) {
                int i, j;
                if(from_i < to_i && from_j < to_j) {
                    i = from_i+1;
                    j = from_j+1;
                    while(i < to_i) {
                        if(board[i][j] != EMPTY) {
                            return 0;
                        }
                        i++;
                        j++;
                    }
                    return 1;
                }
                else if(from_i < to_i && from_j > to_j) {
                    i = from_i+1;
                    j = from_j-1;
                    while(i < to_i) {
                        if(board[i][j] != EMPTY) {
                            return 0;
                        }
                        i++;
                        j--;
                    }
                    return 1;
                }
                else if(from_i > to_i && from_j < to_j) {
                    i = from_i-1;
                    j = from_j+1;
                    while(i > to_i) {
                        if(board[i][j] != EMPTY) {
                            return 0;
                        }
                        i--;
                        j++;
                    }
                    return 1;
                }
                else {
                    i = from_i-1;
                    j = from_j-1;
                    while(i > to_i) {
                        if(board[i][j] != EMPTY) {
                            return 0;
                        }
                        i--;
                        j--;
                    }
                    return 1;
                }
            }
            break;
        default:
            break;
    }
    return 0;
}

//main function
int main(void) {
    //initialize variables and random seed for computer move
    char board[SIZE][SIZE];
    char input[10];
    int player_turn = 1;
    srand(time(NULL));

    //initialize board and print starting position
    init_board(board);
    print_board(board);

    //game loop
    while(1) {
        char from[3], to[3];
        if(player_turn) {
            printf("White's turn.\n");
            printf("Enter `from` square: ");
            get_input(from);
            while(!validate_input(from)) {
                printf("Invalid input. Enter `from` square: ");
                get_input(from);
            }
            printf("Enter `to` square: ");
            get_input(to);
            while(!validate_input(to)) {
                printf("Invalid input. Enter `to` square: ");
                get_input(to);
            }
            int from_i = SIZE - (from[1] - '0');
            int from_j = from[0] - 'a';
            int to_i = SIZE - (to[1] - '0');
            int to_j = to[0] - 'a';
            if(validate_move(board, from_i, from_j, to_i, to_j)) {
                move_piece(board, from_i, from_j, to_i, to_j);
                print_board(board);
                if(is_game_over(board)) {
                    break;
                }
                player_turn = 0;
            }
            else {
                printf("Invalid move!\n");
            }
        }
        else {
            printf("Black's turn.\n");
            //use randomization to generate computer move
            int from_i = rand() % SIZE;
            int from_j = rand() % SIZE;
            while(board[from_i][from_j] == EMPTY || get_color(board[from_i][from_j]) != 'B') {
                from_i = rand() % SIZE;
                from_j = rand() % SIZE;
            }
            int to_i = rand() % SIZE;
            int to_j = rand() % SIZE;
            while(!validate_move(board, from_i, from_j, to_i, to_j)) {
                to_i = rand() % SIZE;
                to_j = rand() % SIZE;
            }
            move_piece(board, from_i, from_j, to_i, to_j);
            printf("Black moves %c%d to %c%d.\n", 'a'+from_j, SIZE-from_i, 'a'+to_j, SIZE-to_i);
            print_board(board);
            if(is_game_over(board)) {
                break;
            }
            player_turn = 1;
        }
    }

    //exit program
    return 0;
}