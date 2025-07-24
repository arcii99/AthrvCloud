//FormAI DATASET v1.0 Category: Checkers Game ; Style: active
#include <stdio.h>

char board[8][8]={  //initializing the checker board with black and white checkers
        {' ','W',' ','W',' ','W',' ','W'},
        {'W',' ','W',' ','W',' ','W',' '},
        {' ','W',' ','W',' ','W',' ','W'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'B',' ','B',' ','B',' ','B',' '},
        {' ','B',' ','B',' ','B',' ','B'},
        {'B',' ','B',' ','B',' ','B',' '}
};

int is_valid_move(int i, int j, int x, int y, char player){  //method to check if a move is valid
    if (board[x][y] != ' ' || (x+y)%2 == 0){  //checking if the destination cell is empty and if it is a dark cell
        return 0;
    }

    int dx = x-i;  //calculating the horizontal distance
    int dy = y-j;  //calculating the vertical distance

    if (player == 'W'){  //checking if the piece belongs to white player
        if (dx == -1)  //if the piece is not a king then it can only move in one direction
            return 0;
        if (dx == -2 && abs(dy) == 2 && board[x+1][(y+j)/2] == 'B')  //checking if a jump move is valid
            return 1;
        if (dx == -1 && abs(dy) == 1)  //checking if a simple move is valid
            return 1;
    }
    else if (player == 'B'){  //checking if the piece belongs to black player
        if (dx == 1)  //if the piece is not a king then it can only move in one direction
            return 0;
        if (dx == 2 && abs(dy) == 2 && board[x-1][(y+j)/2] == 'W')  //checking if a jump move is valid
            return 1;
        if (dx == 1 && abs(dy) == 1)  //checking if a simple move is valid
            return 1;
    }
    return 0;
}

void make_move(int i, int j, int x, int y, char player){  //method to make the move
    board[x][y] = board[i][j];  //moving the player's piece to the destination cell
    board[i][j] = ' ';  //removing the player's piece from the current cell
    
    if (player == 'W' && x == 0){  //if the white player's piece has reached the last row then it becomes a king
        board[x][y] = 'K';
    }
    else if (player == 'B' && x == 7){  //if the black player's piece has reached the last row then it becomes a king
        board[x][y] = 'K';
    }

    if (abs(x-i) == 2){  //if the move was a jump then remove the jumped piece from the board
        int xm = (x+i)/2;  //calculating the row of the jumped piece
        int ym = (y+j)/2;  //calculating the column of the jumped piece
        board[xm][ym] = ' ';
    }
}

int main(){
    char player = 'W';  //setting the initial player to white
    int i, j, x, y;

    while(1){  //infinite loop to keep the game running
        printf("\n\n");
        printf("    1   2   3   4   5   6   7   8\n");
        printf("  ---------------------------------\n");
        for (i=0; i<8; i++){
            printf("%d |", i+1);
            for (j=0; j<8; j++){
                printf(" %c |", board[i][j]);
            }
            printf("\n");
            printf("  ---------------------------------\n");
        }

        printf("\n%c's turn:\n", player);  //prompting the player to make a move
        printf("Enter x1: ");
        scanf("%d", &i);
        printf("Enter y1: ");
        scanf("%d", &j);
        printf("Enter x2: ");
        scanf("%d", &x);
        printf("Enter y2: ");
        scanf("%d", &y);

        if (is_valid_move(i-1, j-1, x-1, y-1, player)){  //checking if the move is valid
            make_move(i-1, j-1, x-1, y-1, player);  //making the move
            if (player == 'W')  //switching the player
                player = 'B';
            else
                player = 'W';
        }
        else{
            printf("Invalid move!\n");  //if the move is invalid then prompt the player to try again
        }
    }

    return 0;
}