//FormAI DATASET v1.0 Category: Checkers Game ; Style: retro
#include <stdio.h>

void print_board(char board[8][8]){
    printf("  0 1 2 3 4 5 6 7 \n");
    for(int r = 0; r<8; r++){
        printf("%d ",r);
        for(int c = 0; c<8; c++){
            printf("%c ", board[r][c]);
        }
        printf("%d",r);
        printf("\n");
    }
    printf("  0 1 2 3 4 5 6 7 \n");
}

int main(){

    char player1 = 'x';
    char player2 = 'o';
    int turn = 0;
    int x_pos = 0, y_pos = 0;
    int move_x = 0, move_y = 0, legal_move = 0, capture_move = 0;
    char checkers_board[8][8] = {{'o','-','o','-','o','-','o','-'},
                                {'-','o','-','o','-','o','-','o'},
                                {'o','-','o','-','o','-','o','-'},
                                {'-','-','-','-','-','-','-','-'},
                                {'-','-','-','-','-','-','-','-'},
                                {'-','x','-','x','-','x','-','x'},
                                {'x','-','x','-','x','-','x','-'},
                                {'-','x','-','x','-','x','-','x'}};
    while(1){
        // Player 1 moves
        if(turn%2 == 0){
            printf("It's player %c's turn\n",player1);
            printf("Enter the position of the checker you'd like to move (e.g. 1 2): \n");
            scanf("%d %d",&x_pos,&y_pos);
            if(checkers_board[x_pos][y_pos] != player1){
                printf("Not a valid starting position.\n");
                continue;
            }
            printf("Enter the position of the space you'd like to move to (e.g. 3 4): \n");
            scanf("%d %d",&move_x,&move_y);
            if(checkers_board[move_x][move_y] != '-'){
                printf("Not a valid move.\n");
                continue;
            }
            if(x_pos - move_x == 1 || x_pos - move_x == -1){
                if(y_pos - move_y == 1 || y_pos - move_y == -1){
                    checkers_board[move_x][move_y] = player1;
                    checkers_board[x_pos][y_pos] = '-';
                }
                else{
                    printf("Not a valid move.\n");
                    continue;
                }
            }
            else if(x_pos - move_x == 2 || x_pos - move_x == -2){
                if(y_pos - move_y == 2 && checkers_board[x_pos-1][y_pos-1] == player2){
                    checkers_board[move_x][move_y] = player1;
                    checkers_board[x_pos][y_pos] = '-';
                    checkers_board[x_pos-1][y_pos-1] = '-';
                    capture_move = 1;
                }
                else if(y_pos - move_y == -2 && checkers_board[x_pos-1][y_pos+1] == player2){
                    checkers_board[move_x][move_y] = player1;
                    checkers_board[x_pos][y_pos] = '-';
                    checkers_board[x_pos-1][y_pos+1] = '-';
                    capture_move = 1;
                }
                else{
                    printf("Not a valid move.\n");
                    continue;
                }
            }
            else{
                printf("Not a valid move.\n");
                continue;
            }
            legal_move = 1;
        }
        // Player 2 moves
        else{
            printf("It's player %c's turn\n",player2);
            printf("Enter the position of the checker you'd like to move (e.g. 1 2): \n");
            scanf("%d %d",&x_pos,&y_pos);
            if(checkers_board[x_pos][y_pos] != player2){
                printf("Not a valid starting position.\n");
                continue;
            }
            printf("Enter the position of the space you'd like to move to (e.g. 3 4): \n");
            scanf("%d %d",&move_x,&move_y);
            if(checkers_board[move_x][move_y] != '-'){
                printf("Not a valid move.\n");
                continue;
            }
            if(x_pos - move_x == 1 || x_pos - move_x == -1){
                if(y_pos - move_y == 1 || y_pos - move_y == -1){
                    checkers_board[move_x][move_y] = player2;
                    checkers_board[x_pos][y_pos] = '-';
                }
                else{
                    printf("Not a valid move.\n");
                    continue;
                }
            }
            else if(x_pos - move_x == 2 || x_pos - move_x == -2){
                if(y_pos - move_y == 2 && checkers_board[x_pos-1][y_pos-1] == player1){
                    checkers_board[move_x][move_y] = player2;
                    checkers_board[x_pos][y_pos] = '-';
                    checkers_board[x_pos-1][y_pos-1] = '-';
                    capture_move = 1;
                }
                else if(y_pos - move_y == -2 && checkers_board[x_pos-1][y_pos+1] == player1){
                    checkers_board[move_x][move_y] = player2;
                    checkers_board[x_pos][y_pos] = '-';
                    checkers_board[x_pos-1][y_pos+1] = '-';
                    capture_move = 1;
                }
                else{
                    printf("Not a valid move.\n");
                    continue;
                }
            }
            else{
                printf("Not a valid move.\n");
                continue;
            }
            legal_move = 1;
        }
        if (legal_move == 1){
            turn += 1;
            legal_move = 0;
        }
        // Winning condition
        if(turn%2 == 1 && capture_move == 1){
            int player1_checkers = 0, player2_checkers = 0;
            for(int i = 0; i<8; i++){
                for(int j = 0; j<8; j++){
                    if(checkers_board[i][j] == player1 || checkers_board[i][j] == 'X'){
                        player1_checkers += 1;
                    }
                    else if(checkers_board[i][j] == player2 || checkers_board[i][j] == 'O'){
                        player2_checkers += 1;
                    }
                }
            }
            if(player1_checkers == 0){
                printf("Player %c wins!\n", player2);
                break;
            }
            else if(player2_checkers == 0){
                printf("Player %c wins!\n", player1);
                break;
            }
            capture_move = 0;
        }
        print_board(checkers_board);
    }
    return 0;
}