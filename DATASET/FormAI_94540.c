//FormAI DATASET v1.0 Category: Checkers Game ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

/*Printing the Checker board*/
void print_board(char board[8][8]){
    printf("\n    1   2   3   4   5   6   7   8  \n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for(int i=0; i<8; i++){
        printf("%d ", i+1);
        for(int j=0; j<8; j++){
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
}
/*Checking if Move is Valid*/
int is_valid_movement(char color, int x1, int y1, int x2, int y2, char board[8][8]){
    if(board[x2][y2] != ' '){
        return 0;
    }
    if(color == 'b'){
        if((x1 <= x2) || (abs(x1-x2) != abs(y1-y2))){
            return 0;
        }
        if(abs(x1-x2) > 2){
            return 0;
        }
        if((abs(x1-x2) == 2) && (board[(x1+x2)/2][(y1+y2)/2] != 'w') && (board[(x1+x2)/2][(y1+y2)/2] != 'W')){
            return 0;
        }
        if((board[x1][y1] == 'b') && (x1-x2) != 1){
            return 0;
        }
        if((board[x1][y1] == 'B') && (abs(x1-x2) != abs(y1-y2))){
            return 0;
        }
    }
    else{
        if((x1 >= x2) || (abs(x1-x2) != abs(y1-y2))){
            return 0;
        }
        if(abs(x1-x2) > 2){
            return 0;
        }
        if((abs(x1-x2) == 2) && (board[(x1+x2)/2][(y1+y2)/2] != 'b') && (board[(x1+x2)/2][(y1+y2)/2] != 'B')){
            return 0;
        }
        if((board[x1][y1] == 'w') && (x2-x1) != 1){
            return 0;
        }
        if((board[x1][y1] == 'W') && (abs(x1-x2) != abs(y1-y2))){
            return 0;
        }
    }
    return 1;
}

/*Checking for a winner*/
char check_winner(char board[8][8]){
    int b=0, w=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[i][j] == 'b' || board[i][j] == 'B'){
                b++;
            }
            if(board[i][j] == 'w' || board[i][j] == 'W'){
                w++;
            }
        }
    }
    if(b == 0){
        return 'w';
    }
    if(w == 0){
        return 'b';
    }
    return ' ';
}

/*Main Function*/
int main(){
    char board[8][8]={
                {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
                {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
                {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '},
                {' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
                {'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '}
            };
    print_board(board);
    char color='b', select='n';
    int x1=0, y1=0, x2=0, y2=0;
    while(check_winner(board) == ' '){
        printf("%c's turn\n", color);
        printf("Do you want to select a piece (y/n)? ");
        scanf(" %c", &select);
        if(select == 'y'){
            printf("Enter the row and column of the selected piece: ");
            scanf("%d %d", &x1, &y1);
            if((color == 'b' && board[x1-1][y1-1] != 'b' && board[x1-1][y1-1] != 'B') || (color == 'w' && board[x1-1][y1-1] != 'w' && board[x1-1][y1-1] != 'W')){
                printf("Invalid piece selection.\n");
                continue;
            }
            printf("Enter the row and column of the new location: ");
            scanf("%d %d", &x2, &y2);
            if(!is_valid_movement(color, x1-1, y1-1, x2-1, y2-1, board)){
                printf("Invalid movement.\n");
                continue;
            }
            board[x2-1][y2-1] = board[x1-1][y1-1];
            board[x1-1][y1-1] = ' ';
            if((color == 'b' && x2 == 8 && board[x2-1][y2-1] == 'b') || (color == 'w' && x2 == 1 && board[x2-1][y2-1] == 'w')){
                board[x2-1][y2-1] = (color == 'b' ? 'B' : 'W');
            }
            color = (color == 'b' ? 'w' : 'b');
            print_board(board);
        }
        else{
            int valid=0;
            while(!valid){
                printf("Enter the row and column of the new location: ");
                scanf("%d %d", &x2, &y2);
                for(int i=0; i<8; i++){
                    for(int j=0; j<8; j++){
                        if((color == 'b' && (board[i][j] == 'b' || board[i][j] == 'B') && is_valid_movement(color, i, j, x2-1, y2-1, board)) || (color == 'w' && (board[i][j] == 'w' || board[i][j] == 'W') && is_valid_movement(color, i, j, x2-1, y2-1, board))){
                            valid = 1;
                            x1 = i+1;
                            y1 = j+1;
                            break;
                        }
                    }
                    if(valid){
                        break;
                    }
                }
                if(!valid){
                    printf("Invalid movement.\n");
                    continue;
                }
                board[x2-1][y2-1] = board[x1-1][y1-1];
                board[x1-1][y1-1] = ' ';
                if((color == 'b' && x2 == 8 && board[x2-1][y2-1] == 'b') || (color == 'w' && x2 == 1 && board[x2-1][y2-1] == 'w')){
                    board[x2-1][y2-1] = (color == 'b' ? 'B' : 'W');
                }
                color = (color == 'b' ? 'w' : 'b');
                print_board(board);
            }
        }
    }
    printf("%c is the winner!", check_winner(board));
    return 0;
}