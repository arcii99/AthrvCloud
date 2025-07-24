//FormAI DATASET v1.0 Category: Chess engine ; Style: decentralized
// Decentralized Chess Engine using Blockchain

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition of Chess Pieces
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// Definition of players
#define PLAYER1 0
#define PLAYER2 1

// Definition of player type
#define HUMAN 0
#define AI 1

// Definition of chess board
int board[8][8] = {
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}
};

// Definition of pawn's movement direction
int pawn_dir[2] = {-1, 1};

// Definition of piece values
int piece_value[7] = {0, 1, 3, 3, 5, 9, 100};

// Definition of player types
int player_type[2] = {HUMAN, AI};

// Definition of game state
int game_state = 0;

// Definition of current player
int current_player = PLAYER1;

// Definition of AI difficulty level
int ai_level = 1;

// Function to print the board
void print_board() { 
    printf("\n");
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the move is valid
int is_valid_move(int x1, int y1, int x2, int y2) {

    // Check if the second position is empty or contains an opponent's piece
    if(board[x2][y2] == EMPTY || (board[x1][y1] < 0 && board[x2][y2] > 0) || (board[x1][y1] > 0 && board[x2][y2] < 0)) {

        // Check if it is a valid movement for the piece type
        switch(abs(board[x1][y1])) {
            case PAWN:
                if(x1 == x2) { // Pawn moving vertically
                    if(abs(y2 - y1) == 1) { // Pawn moving one step to the side
                        if(board[x2][y2] != EMPTY) { // Check if there is a piece at the target position
                            return 1;
                        }
                    } else if(abs(y2 - y1) == 2 && ((current_player == PLAYER1 && x1 == 6) || (current_player == PLAYER2 && x1 == 1))) { // Pawn moving two steps on first move
                        if(board[x2][y2] == EMPTY) { // Check if there is a piece at the intermediate position
                            return 1;
                        }
                    }
                } else if(abs(x2 - x1) == 1 && abs(y2 - y1) == 1) { // Pawn moving diagonally to capture
                    if(board[x2][y2] != EMPTY) { // Check if there is a piece at the target position
                        return 1;
                    }
                }
                break;
            case KNIGHT:
                if((abs(x2 - x1) == 2 && abs(y2 - y1) == 1) || (abs(x2 - x1) == 1 && abs(y2 - y1) == 2)) { // Knight moving in L shape
                    return 1;
                }
                break;
            case BISHOP:
                if(abs(x2 - x1) == abs(y2 - y1)) { // Bishop moving diagonally
                    int dx = (x2 - x1 > 0) ? 1 : -1;
                    int dy = (y2 - y1 > 0) ? 1 : -1;
                    for(int i=x1+dx, j=y1+dy; i!=x2; i+=dx, j+=dy) { // Check if there are no pieces in the path of movement
                        if(board[i][j] != EMPTY) {
                            return 0;
                        }
                    }
                    if(board[x2][y2] != EMPTY) { // Check if there is a piece at the target position
                        return 1;
                    }
                    return 1; // Valid move
                }
                break;
            case ROOK:
                if((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2)) { // Rook moving vertically or horizontally
                    int dx = (x2 - x1 > 0) ? 1 : ((x2 - x1 < 0) ? -1 : 0);
                    int dy = (y2 - y1 > 0) ? 1 : ((y2 - y1 < 0) ? -1 : 0);
                    for(int i=x1+dx, j=y1+dy; i!=x2 || j!=y2; i+=dx, j+=dy) { // Check if there are no pieces in the path of movement
                        if(board[i][j] != EMPTY) {
                            return 0;
                        }
                    }
                    if(board[x2][y2] != EMPTY) { // Check if there is a piece at the target position
                        return 1;
                    }
                    return 1; // Valid move
                }
                break;
            case QUEEN:
                if(x1 == x2 || y1 == y2 || abs(x2 - x1) == abs(y2 - y1)) { // Queen moving vertically, horizontally or diagonally
                    if(x1 == x2 || y1 == y2) { // Queen moving vertically or horizontally
                        int dx = (x2 - x1 > 0) ? 1 : ((x2 - x1 < 0) ? -1 : 0);
                        int dy = (y2 - y1 > 0) ? 1 : ((y2 - y1 < 0) ? -1 : 0);
                        for(int i=x1+dx, j=y1+dy; i!=x2 || j!=y2; i+=dx, j+=dy) { // Check if there are no pieces in the path of movement
                            if(board[i][j] != EMPTY) {
                                return 0;
                            }
                        }
                    } else { // Queen moving diagonally
                        int dx = (x2 - x1 > 0) ? 1 : -1;
                        int dy = (y2 - y1 > 0) ? 1 : -1;
                        for(int i=x1+dx, j=y1+dy; i!=x2; i+=dx, j+=dy) { // Check if there are no pieces in the path of movement
                            if(board[i][j] != EMPTY) {
                                return 0;
                            }
                        }
                    }
                    if(board[x2][y2] != EMPTY) { // Check if there is a piece at the target position
                        return 1;
                    }
                    return 1; // Valid move
                }
                break;
            case KING:
                if((abs(x2 - x1) == 1 && abs(y2 - y1) <= 1) || (abs(x2 - x1) <= 1 && abs(y2 - y1) == 1)) { // King moving one step in any direction
                    return 1;
                }
                break;    
        }
    }
    return 0;
}

// Function to get player input
void get_player_input(int *x1, int *y1, int *x2, int *y2) {
    printf("\nEnter move for player %d (in format x1,y1,x2,y2): ", current_player+1);
    scanf("%d,%d,%d,%d", x1, y1, x2, y2);
}

// Function to generate random move for AI
void generate_ai_input(int *x1, int *y1, int *x2, int *y2) {
    srand((unsigned)time(NULL)); // Initialize random number generator

    // Loop until a valid move is generated
    int valid = 0;
    while(!valid) {
        // Generate random position
        *x1 = rand() % 8;
        *y1 = rand() % 8;
        *x2 = rand() % 8;
        *y2 = rand() % 8;
        // Check if the move is valid
        if(is_valid_move(*x1, *y1, *x2, *y2)) {
            valid = 1;
        }
    }
    printf("\nAI move: %d,%d,%d,%d", *x1, *y1, *x2, *y2);
}

// Function to perform the move
void perform_move(int x1, int y1, int x2, int y2) {
    // Move the piece
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = EMPTY;
    printf("\nMoved piece from (%d,%d) to (%d,%d)", x1, y1, x2, y2);
    // Check if the game is over
    game_state = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] == KING || board[i][j] == -KING) {
                int flag = 1;
                for(int k=0; k<8; k++) {
                    for(int l=0; l<8; l++) {
                        if(board[k][l] != EMPTY && ((board[i][j] < 0 && board[k][l] > 0) || (board[i][j] > 0 && board[k][l] < 0)) && is_valid_move(i, j, k, l)) {
                            flag = 0;
                            break;
                        }
                    }
                }
                if(flag) {
                    game_state = (board[i][j] < 0) ? 1 : 2;
                    break;
                }
            }
        }
        if(game_state) {
            break;
        }
    }
    // Switch player
    current_player = (current_player == PLAYER1) ? PLAYER2 : PLAYER1;
}

// Function for AI to make a move
void ai_move() {
    int x1, y1, x2, y2;
    if(ai_level == 1) { // Random move
        generate_ai_input(&x1, &y1, &x2, &y2);
        perform_move(x1, y1, x2, y2);
    }
}

// Function to play the game
void play_game() {
    // Loop until the game is over
    while(!game_state) {
        print_board();
        if(player_type[current_player] == HUMAN) {
            int x1, y1, x2, y2;
            get_player_input(&x1, &y1, &x2, &y2);
            while(!is_valid_move(x1, y1, x2, y2)) {
                printf("\nInvalid move, please try again.");
                get_player_input(&x1, &y1, &x2, &y2);
            }
            perform_move(x1, y1, x2, y2);
        } else if(player_type[current_player] == AI) {
            ai_move();
        }
    }
    print_board();
    printf("\nGame over. ");
    if(game_state == 1) {
        printf("Player 2 wins!");
    } else if(game_state == 2) {
        printf("Player 1 wins!");
    } else {
        printf("It's a draw!");
    }
}

int main() {
    play_game();
    return 0;
}