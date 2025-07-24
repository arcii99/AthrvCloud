//FormAI DATASET v1.0 Category: Chess engine ; Style: immersive
#include <stdio.h>

// Chess board structure
struct board {
    char grid[8][8];
    int white_king_x, white_king_y, black_king_x, black_king_y;
    int move_count;
} chess;

// Function to initialize the chess board
void init_board() {
    //Initialize empty board
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            chess.grid[i][j] = ' ';
        }
    }

    // Initialize pawns for both sides
    for(int i=0; i<8; i++){
        chess.grid[1][i] = 'P';
        chess.grid[6][i] = 'p';
    }

    // Initialize rooks, knights and bishops for both sides
    char pieces[6] = {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'};
    for(int i=0; i<8; i++){
        chess.grid[0][i] = pieces[i];
        chess.grid[7][i] = pieces[i] + 32;

        if(chess.grid[0][i] == 'K'){
            chess.white_king_x = 0;
            chess.white_king_y = i;
        }

        if(chess.grid[7][i] == 'k'){
            chess.black_king_x = 7;
            chess.black_king_y = i;
        }
    }

    // Set move count to 0
    chess.move_count = 0;
}

// Function to display the chess board on the console
void display_board() {
    for(int i=0; i<8; i++){
        printf("+---+---+---+---+---+---+---+---+\n");
        for(int j=0; j<8; j++){
            printf("| %c ", chess.grid[i][j]);
        }
        printf("|\n");
    }
    printf("+---+---+---+---+---+---+---+---+\n");
}

// Function to check if a move is valid or not
int is_valid_move(int x1, int y1, int x2, int y2) {
    char piece = chess.grid[x1][y1];

    if(piece == 'P'){
        //check for pawn
        if(chess.move_count == 0 && x2 == x1+2 && y1 == y2){
            if(chess.grid[x2][y2] != ' '){
                return 0;
            }
            return 1;
        }

        if(x2 == x1+1 && y1 == y2){
            return chess.grid[x2][y2] == ' ';
        }

        if(x2 == x1+1 && y2 == y1-1){
            return chess.grid[x2][y2] != ' ' && chess.grid[x2][y2]<='Z';
        }

        if(x2 == x1+1 && y2 == y1+1){
            return chess.grid[x2][y2] != ' ' && chess.grid[x2][y2]<='Z';
        }

        return 0;
    }

    //check for bishop
    if(piece == 'B'){
        return 0;
    }

    //check for knight
    if(piece == 'N'){
        return 0;
    }

    //check for rook
    if(piece == 'R'){
        return 0;
    }

    //check for queen
    if(piece == 'Q'){
        return 0;
    }

    //check for king
    if(piece == 'K'){
        return 0;
    }

    return 0;
}

// Main function to play the game
int main() {
    init_board();
    display_board();

    int start_x, start_y, end_x, end_y;
    while(1){
        printf("\n%c's move: ", 'W' + chess.move_count%2);

        // Read move input from user
        scanf("%d%d%d%d", &start_x, &start_y, &end_x, &end_y);

        if(is_valid_move(start_x, start_y, end_x, end_y)){
            // Move is valid, update the board
            chess.grid[end_x][end_y] = chess.grid[start_x][start_y];
            chess.grid[start_x][start_y] = ' ';
            chess.move_count++;

            // Update king positions if necessary
            if(chess.grid[end_x][end_y] == 'K'){
                chess.white_king_x = end_x;
                chess.white_king_y = end_y;
            }else if(chess.grid[end_x][end_y] == 'k'){
                chess.black_king_x = end_x;
                chess.black_king_y = end_y;
            }

            // Display updated board
            display_board();
        }else{
            printf("Invalid move!\n");
        }
    }

    return 0;
}