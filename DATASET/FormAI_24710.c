//FormAI DATASET v1.0 Category: Checkers Game ; Style: relaxed
#include<stdio.h>

char board[8][8] = {
    {'*', 'b', '*', 'b', '*', 'b', '*', 'b'},
    {'b', '*', 'b', '*', 'b', '*', 'b', '*'},
    {'*', 'b', '*', 'b', '*', 'b', '*', 'b'},
    {' ', '*', ' ', '*', ' ', '*', ' ', '*'},
    {'*', ' ', '*', ' ', '*', ' ', '*', ' '},
    {'w', '*', 'w', '*', 'w', '*', 'w', '*'},
    {'*', 'w', '*', 'w', '*', 'w', '*', 'w'},
    {'w', '*', 'w', '*', 'w', '*', 'w', '*'}
}; // initializing the checkers board

int turn = 1; // initializing the turn to 1, with 1 representing white and -1 representing black
int selected_piece_x, selected_piece_y, move_x, move_y; // variables to store piece coordinates and move coordinates

void print_board(){ // function to print the board in its current state
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int legal_move(){ // function to check if the selected move is legal
    if(board[move_x][move_y] != ' ' || (move_x+move_y)%2 != 0) return 0; // cannot move to a non-empty or non-black square
    int dx = move_x - selected_piece_x;
    int dy = move_y - selected_piece_y;
    if(board[selected_piece_x][selected_piece_y] == 'w'){ // white piece
        if(dy == -1 && abs(dx) == 1) return 1; // 1 diagonal move
        if(dy == -2 && abs(dx) == 2 && board[selected_piece_x-1][(selected_piece_y+move_y)/2] == 'b') return 1; // 1 jump move
    }
    else{ // black piece
        if(dy == 1 && abs(dx) == 1) return 1; // 1 diagonal move
        if(dy == 2 && abs(dx) == 2 && board[selected_piece_x+1][(selected_piece_y+move_y)/2] == 'w') return 1; // 1 jump move
    }
    return 0;
}

int move_piece(){ // function to move the selected piece
    if(!legal_move()) return 0; // check if move is legal
    board[move_x][move_y] = board[selected_piece_x][selected_piece_y]; // move the piece
    board[selected_piece_x][selected_piece_y] = ' ';
    if(abs(move_x-selected_piece_x) == 2){ // jump move, capture the opponent's piece
        board[(move_x+selected_piece_x)/2][(move_y+selected_piece_y)/2] = ' ';
    }
    if(move_x == 0 || move_x == 7){ // crowned, make it a king
        board[move_x][move_y] = toupper(board[move_x][move_y]);
    }
    return 1;
}

int main(){
    int gameover = 0; // initializing gameover to 0
    while(!gameover){ // loop until gameover
        printf("Turn %d:\n", turn);
        print_board(); // print the board
        printf("Enter the coordinates of the piece you want to move (row col): ");
        scanf("%d %d", &selected_piece_x, &selected_piece_y); // get the coordinates of the piece to move
        printf("Enter the coordinates of the place you want to move (row col): ");
        scanf("%d %d", &move_x, &move_y); // get the coordinates of the place to move
        if(move_piece()){ // move the piece
            if(turn == 1) turn = -1; // change turn
            else turn = 1;
        }
    }
    return 0; // end of program
}