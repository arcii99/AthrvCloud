//FormAI DATASET v1.0 Category: Chess engine ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_DEPTH 4

char board[8][8] = {
{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
{' ', '.', ' ', '.', ' ', '.', ' ', '.'},
{'.', ' ', '.', ' ', '.', ' ', '.', ' '},
{' ', '.', ' ', '.', ' ', '.', ' ', '.'},
{'.', ' ', '.', ' ', '.', ' ', '.', ' '},
{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

struct state{
    char board[8][8];
    int value;
};

void print_board(char board[8][8]){
    int i, j;
    for(i=0; i<8; ++i){
        for(j=0; j<8; ++j){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int evaluate_board(char board[8][8]){
    int i, j, white=0, black=0;
    for(i=0; i<8; ++i){
        for(j=0; j<8; ++j){
            if(board[i][j] == 'K'){
                black += 100;
            } else if(board[i][j] == 'k'){
                white += 100;
            } else if(board[i][j] == 'Q'){
                black += 9;
            } else if(board[i][j] == 'q'){
                white += 9;
            } else if(board[i][j] == 'R'){
                black += 5;
            } else if(board[i][j] == 'r'){
                white += 5;
            } else if(board[i][j] == 'B' || board[i][j] == 'N'){
                black += 3;
            } else if(board[i][j] == 'b' || board[i][j] == 'n'){
                white += 3;
            } else if(board[i][j] == 'P'){
                black += 1;
            } else if(board[i][j] == 'p'){
                white += 1;
            }
        }
    }
    return black - white;
}

int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

int alpha_beta(char board[8][8], int depth, int alpha, int beta, int maximizingPlayer){
    if(depth == MAX_DEPTH){
        return evaluate_board(board);
    }
    int value;
    char temp_board[8][8];
    int i, j, k;
    if(maximizingPlayer){
        value = INT_MIN;
        for(i=0; i<8; ++i){
            for(j=0; j<8; ++j){
                if(board[i][j] == ' ' || board[i][j] == '.'){
                    continue;
                }
                if(isupper(board[i][j])){
                    char piece = board[i][j];
                    for(k=0; k<8; ++k){
                        int new_i = i + (k+1)*((piece=='N' || piece=='S')||(piece=='P'&&k==0));
                        int new_j = j + (k+1)*((piece=='E' || piece=='W')||(piece=='P'&&k==0));
                        if(new_i<0 || new_i>7 || new_j<0 || new_j>7 || board[new_i][new_j] == '#'){
                            break;
                        }
                        if(isupper(board[new_i][new_j])){
                            break;
                        }
                        if(islower(board[new_i][new_j])){
                            memcpy(temp_board, board, sizeof(board));
                            temp_board[new_i][new_j] = temp_board[i][j];
                            temp_board[i][j] = ' ';
                            value = max(value, alpha_beta(temp_board, depth+1, alpha, beta, 0));
                            alpha = max(alpha, value);
                            if(alpha >= beta){
                                break;
                            }
                        } else {
                            memcpy(temp_board, board, sizeof(board));
                            temp_board[new_i][new_j] = temp_board[i][j];
                            temp_board[i][j] = ' ';
                            value = max(value, alpha_beta(temp_board, depth+1, alpha, beta, 0));
                            alpha = max(alpha, value);
                            if(alpha >= beta){
                                break;
                            }
                            break;
                        }
                    }
                }
            }
            if(alpha >= beta){
                break;
            }
        }
    } else {
        value = INT_MAX;
        for(i=0; i<8; ++i){
            for(j=0; j<8; ++j){
                if(board[i][j] == ' ' || board[i][j] == '.'){
                    continue;
                }
                if(islower(board[i][j])){
                    char piece = board[i][j];
                    for(k=0; k<8; ++k){
                        int new_i = i - (k+1)*((piece=='N' || piece=='S')||(piece=='P'&&k==0));
                        int new_j = j - (k+1)*((piece=='E' || piece=='W')||(piece=='P'&&k==0));
                        if(new_i<0 || new_i>7 || new_j<0 || new_j>7 || board[new_i][new_j] == '#'){
                            break;
                        }
                        if(islower(board[new_i][new_j])){
                            break;
                        }
                        if(isupper(board[new_i][new_j])){
                            memcpy(temp_board, board, sizeof(board));
                            temp_board[new_i][new_j] = temp_board[i][j];
                            temp_board[i][j] = ' ';
                            value = min(value, alpha_beta(temp_board, depth+1, alpha, beta, 1));
                            beta = min(beta, value);
                            if(alpha >= beta){
                                break;
                            }
                        } else {
                            memcpy(temp_board, board, sizeof(board));
                            temp_board[new_i][new_j] = temp_board[i][j];
                            temp_board[i][j] = ' ';
                            value = min(value, alpha_beta(temp_board, depth+1, alpha, beta, 1));
                            beta = min(beta, value);
                            if(alpha >= beta){
                                break;
                            }
                            break;
                        }
                    }
                }
            }
            if(alpha >= beta){
                break;
            }
        }
    }
    return value;
}

char * get_user_move(){
    char *move = malloc(10 * sizeof(char));
    printf("Enter move (e.g. a2a4): ");
    scanf("%s", move);
    return move;
}

int main(){
    char *move;
    while(1){
        system("clear");
        print_board(board);
        move = get_user_move();
        int i1=move[1]-'1', i2=move[3]-'1', j1=move[0]-'a', j2=move[2]-'a';
        char temp = board[i2][j2];
        board[i2][j2] = board[i1][j1];
        board[i1][j1] = ' ';
        int value = alpha_beta(board, 0, INT_MIN, INT_MAX, 0);
        printf("Value: %d\n", value);
        board[i1][j1] = board[i2][j2];
        board[i2][j2] = temp;
        getchar();getchar();
    }
    return 0;
}