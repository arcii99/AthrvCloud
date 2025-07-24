//FormAI DATASET v1.0 Category: Chess AI ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>

#define SIZE 8

int board[SIZE][SIZE] = {    // initialize the board
    {-2,-3,-4,-5,-6,-4,-3,-2},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1},
    {2,3,4,5,6,4,3,2}
};

void print_board(){
    for(int i=0; i<SIZE; i++){
        printf("%d ", SIZE-i);
        for(int j=0; j<SIZE; j++){
            switch(board[i][j]){
                case 0: putchar('.');
                        break;
                case 1: putchar('P');
                        break;
                case 2: putchar('R');
                        break;
                case 3: putchar('N');
                        break;
                case 4: putchar('B');
                        break;
                case 5: putchar('Q');
                        break;
                case 6: putchar('K');
                        break;
                case -1: putchar('p');
                         break;
                case -2: putchar('r');
                         break;
                case -3: putchar('n');
                         break;
                case -4: putchar('b');
                         break;
                case -5: putchar('q');
                         break;
                case -6: putchar('k');
                         break;
            }
            putchar(' ');
        }
        putchar('\n');
    }
    putchar(' ');
    for(int i=0; i<SIZE; i++){
        printf(" %c", 97+i);
    }
    putchar('\n');
}

bool move_piece(int x1, int y1, int x2, int y2){
    if(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 >= SIZE || y1 >= SIZE || x2 >= SIZE || y2 >= SIZE){
        printf("Invalid input. Please enter again.\n");
        return false;
    }
    if(board[x1][y1] == 0){
        printf("There is no piece at this position. Please enter again.\n");
        return false;
    }
    if(board[x2][y2] != 0 && (board[x1][y1] > 0) == (board[x2][y2] > 0)){
        printf("You cannot capture your own piece. Please enter again.\n");
        return false;
    }
    switch(board[x1][y1]){
        case 1: if((y2 != y1 && board[x2][y2] == 0) || (y2 == y1 && board[x2][y2] != 0)){
                    printf("Invalid move for pawn. Please enter again.\n");
                    return false;
                }
                if(board[x2][y2] == 0 && (x2-x1)*(x2-x1) > 1 && x1 != 1){
                    printf("Invalid move for pawn. Please enter again.\n");
                    return false;
                }
                if(board[x2][y2] == 0 && (x2-x1)*(x2-x1) > 4 && x1 == 1){
                    printf("Invalid move for pawn. Please enter again.\n");
                    return false;
                }
                if(board[x2][y2] != 0 && (x2-x1)*(x2-x1) != 2){
                    printf("Invalid move for pawn. Please enter again.\n");
                    return false;
                }
                if(board[x2][y2] == 0 && (x2-x1) != 1 && (x2-x1) != 2){
                    printf("Invalid move for pawn. Please enter again.\n");
                    return false;
                }
                if(board[x2][y2] != 0 && (x2-x1) != 1){
                    printf("Invalid move for pawn. Please enter again.\n");
                    return false;
                }
                if((x2-x1) == 2 && board[x1+1][y1] != 0){
                    printf("Invalid move for pawn. Please enter again.\n");
                    return false;
                }
                if((x2-x1) == 2 && board[x2][y2] != 0){
                    printf("Invalid move for pawn. Please enter again.\n");
                    return false;
                }
                if(abs(y2-y1) == 1 && board[x2][y2] == 0){
                    printf("Invalid move for pawn. Please enter again.\n");
                    return false;
                }
                if(abs(y2-y1) == 2 && board[x2][y2] != 0){
                    printf("Invalid move for pawn. Please enter again.\n");
                    return false;
                }
                break;
        case 2: if(x1 != x2 && y1 != y2){
                    printf("Invalid move for rook. Please enter again.\n");
                    return false;
                }
                if(x1 == x2){
                    for(int i=y1+1; i<y2; i++){
                        if(board[x1][i] != 0){
                            printf("Invalid move for rook. Please enter again.\n");
                            return false;
                        }
                    }
                    for(int i=y1-1; i>y2; i--){
                        if(board[x1][i] != 0){
                            printf("Invalid move for rook. Please enter again.\n");
                            return false;
                        }
                    }
                }
                if(y1 == y2){
                    for(int i=x1+1; i<x2; i++){
                        if(board[i][y1] != 0){
                            printf("Invalid move for rook. Please enter again.\n");
                            return false;
                        }
                    }
                    for(int i=x1-1; i>x2; i--){
                        if(board[i][y1] != 0){
                            printf("Invalid move for rook. Please enter again.\n");
                            return false;
                        }
                    }
                }
                break;
        case 3: if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) != 5){
                    printf("Invalid move for knight. Please enter again.\n");
                    return false;
                }
                if(board[x2][y2] != 0 && (board[x1][y1] > 0) == (board[x2][y2] > 0)){
                    printf("You cannot capture your own piece. Please enter again.\n");
                    return false;
                }
                break;
        case 4: if((x2-x1) != (y2-y1) && (x2-x1) != (y1-y2)){
                    printf("Invalid move for bishop. Please enter again.\n");
                    return false;
                }
                if(x1 < x2 && y1 < y2){
                    for(int i=x1+1, j=y1+1; i<x2; i++, j++){
                        if(board[i][j] != 0){
                            printf("Invalid move for bishop. Please enter again.\n");
                            return false;
                        }
                    }
                }
                if(x1 < x2 && y1 > y2){
                    for(int i=x1+1, j=y1-1; i<x2; i++, j--){
                        if(board[i][j] != 0){
                            printf("Invalid move for bishop. Please enter again.\n");
                            return false;
                        }
                    }
                }
                if(x1 > x2 && y1 < y2){
                    for(int i=x1-1, j=y1+1; i>x2; i--, j++){
                        if(board[i][j] != 0){
                            printf("Invalid move for bishop. Please enter again.\n");
                            return false;
                        }
                    }
                }
                if(x1 > x2 && y1 > y2){
                    for(int i=x1-1, j=y1-1; i>x2; i--, j--){
                        if(board[i][j] != 0){
                            printf("Invalid move for bishop. Please enter again.\n");
                            return false;
                        }
                    }
                }
                break;
        case 5: if(x1 != x2 && y1 != y2){
                    if((x2-x1) != (y2-y1) && (x2-x1) != (y1-y2)){
                        printf("Invalid move for queen. Please enter again.\n");
                        return false;
                    }
                    if(x1 < x2 && y1 < y2){
                        for(int i=x1+1, j=y1+1; i<x2; i++, j++){
                            if(board[i][j] != 0){
                                printf("Invalid move for queen. Please enter again.\n");
                                return false;
                            }
                        }
                    }
                    if(x1 < x2 && y1 > y2){
                        for(int i=x1+1, j=y1-1; i<x2; i++, j--){
                            if(board[i][j] != 0){
                                printf("Invalid move for queen. Please enter again.\n");
                                return false;
                            }
                        }
                    }
                    if(x1 > x2 && y1 < y2){
                        for(int i=x1-1, j=y1+1; i>x2; i--, j++){
                            if(board[i][j] != 0){
                                printf("Invalid move for queen. Please enter again.\n");
                                return false;
                            }
                        }
                    }
                    if(x1 > x2 && y1 > y2){
                        for(int i=x1-1, j=y1-1; i>x2; i--, j--){
                            if(board[i][j] != 0){
                                printf("Invalid move for queen. Please enter again.\n");
                                return false;
                            }
                        }
                    }
                }
                else{
                    if(x1 == x2){
                        for(int i=y1+1; i<y2; i++){
                            if(board[x1][i] != 0){
                                printf("Invalid move for queen. Please enter again.\n");
                                return false;
                            }
                        }
                        for(int i=y1-1; i>y2; i--){
                            if(board[x1][i] != 0){
                                printf("Invalid move for queen. Please enter again.\n");
                                return false;
                            }
                        }
                    }
                    if(y1 == y2){
                        for(int i=x1+1; i<x2; i++){
                            if(board[i][y1] != 0){
                                printf("Invalid move for queen. Please enter again.\n");
                                return false;
                            }
                        }
                        for(int i=x1-1; i>x2; i--){
                            if(board[i][y1] != 0){
                                printf("Invalid move for queen. Please enter again.\n");
                                return false;
                            }
                        }
                    }
                }
                break;
        case 6: if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) > 2){
                    printf("Invalid move for king. Please enter again.\n");
                    return false;
                }
                break;
    }
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = 0;
    return true;
}

int main(){
    int x1, y1, x2, y2;
    while(true){
        print_board();
        printf("Enter position of piece to move (row column): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter new position for piece (row column): ");
        scanf("%d %d", &x2, &y2);
        if(move_piece(SIZE-x1, y1-1, SIZE-x2, y2-1)){
            printf("Move successful!\n");
        }
    }
    return 0;
}