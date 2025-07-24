//FormAI DATASET v1.0 Category: Checkers Game ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

int board[SIZE][SIZE];

void init_board(){
    int i, j;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if( (i+j)%2 == 0 ){
                if(i < 3){
                    board[i][j] = 1;
                }
                else if(i > 4){
                    board[i][j] = 2;
                }
                else{
                    board[i][j] = 0;
                }
            }
            else{
                board[i][j] = -1;
            }
        }
    }
}

void print_board(){
    int i, j;
    printf("   ");
    for(i=0; i<SIZE; i++){
        printf("%c ", i+'A');
    }
    printf("\n");
    for(i=0; i<SIZE; i++){
        printf("%d ", i+1);
        for(j=0; j<SIZE; j++){
            if(board[i][j] == 0){
                printf(". ");
            }
            else if(board[i][j] == 1){
                printf("O ");
            }
            else if(board[i][j] == 2){
                printf("X ");
            }
            else{
                printf("# ");
            }
        }
        printf("%d\n", i+1);
    }
    printf("   ");
    for(i=0; i<SIZE; i++){
        printf("%c ", i+'A');
    }
    printf("\n");
}

int is_valid_move(int player, int r1, int c1, int r2, int c2){
    if(board[r2][c2] != 0){
        return 0;
    }

    if(player == 1){
        if(r2 > r1){
            return 0;
        }
        if( abs(r1-r2) == 1 && abs(c1-c2) == 1 ){
            return 1;
        }
        else if( abs(r1-r2) == 2 && abs(c1-c2) == 2 ){
            int mid_r = (r1+r2)/2;
            int mid_c = (c1+c2)/2;
            if(board[mid_r][mid_c] == 2){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    else if(player == 2){
        if(r2 < r1){
            return 0;
        }
        if( abs(r1-r2) == 1 && abs(c1-c2) == 1 ){
            return 1;
        }
        else if( abs(r1-r2) == 2 && abs(c1-c2) == 2 ){
            int mid_r = (r1+r2)/2;
            int mid_c = (c1+c2)/2;
            if(board[mid_r][mid_c] == 1){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

int do_capture(int player){
    int r, c, i, j, r2, c2, found=0;
    for(r=0; r<SIZE; r++){
        for(c=0; c<SIZE; c++){
            if(board[r][c] != player && board[r][c] != player*10){
                continue;
            }
            for(i=-2; i<=2; i++){
                for(j=-2; j<=2; j++){
                    r2 = r+i;
                    c2 = c+j;
                    if(is_valid_move(player, r, c, r2, c2)){
                        if(abs(i) == 2 && abs(j) == 2){
                            int mid_r = (r+r2)/2;
                            int mid_c = (c+c2)/2;
                            board[mid_r][mid_c] = 0;
                            found = 1;
                        }
                    }
                }
            }
        }
    }

    return found;
}

int do_move(int player, int r1, int c1, int r2, int c2){
    if(is_valid_move(player, r1, c1, r2, c2)){
        board[r2][c2] = player;
        board[r1][c1] = 0;
        return 1;
    }
    else{
        return 0;
    }
}

int get_winner(){
    int i, j;
    int n1=0, n2=0;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if(board[i][j] == 1 || board[i][j] == 11){
                n1++;
            }
            else if(board[i][j] == 2 || board[i][j] == 12){
                n2++;
            }
        }
    }

    if(n1 == 0 || n2 == 0){
        if(n1 == 0){
            return 2;
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

int main(){
    int r1, c1, r2, c2;
    int player = 1;
    init_board();
    int winner = 0;
    while(winner == 0){
        printf("\n\n");
        print_board();
        if(player == 1){
            printf("Player O's turn\n");
        }
        else if(player == 2){
            printf("Player X's turn\n");
        }
        printf("Enter the source position (A1-H8): ");
        scanf(" %c%c", &c1, &r1);
        r1 -= '1';
        c1 -= 'A';
        printf("Enter the destination position (A1-H8): ");
        scanf(" %c%c", &c2, &r2);
        r2 -= '1';
        c2 -= 'A';
        if(do_move(player, r1, c1, r2, c2)){
            if(player == 1 && r2 == 0){
                board[r2][c2] = 11;
            }
            else if(player == 2 && r2 == 7){
                board[r2][c2] = 12;
            }
            if(do_capture(player)){
                printf("You can capture again\n");
            }
            else{
                if(player == 1){
                    player = 2;
                }
                else if(player == 2){
                    player = 1;
                }
            }
            winner = get_winner();
        }
        else{
            printf("Invalid move\n");
        }
    }

    printf("\n\n");
    print_board();
    if(winner == 1){
        printf("Player O wins\n");
    }
    else if(winner == 2){
        printf("Player X wins\n");
    }
    else{
        printf("It's a tie\n");
    }

    return 0;
}