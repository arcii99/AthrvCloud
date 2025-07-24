//FormAI DATASET v1.0 Category: Chess AI ; Style: Cryptic
//Cryptic C Chess AI
#include<stdio.h>
#include<stdlib.h>

int board[8][8] = {{2,3,4,5,6,4,3,2},
                   {1,1,1,1,1,1,1,1},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {-1,-1,-1,-1,-1,-1,-1,-1},
                   {-2,-3,-4,-5,-6,-4,-3,-2}};

int evaluate_board(){
    int i, j, score = 0;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(board[i][j] == 1)
                score += 10;
            if(board[i][j] == -1)
                score -= 10;
            if(board[i][j] == 2)
                score += 50;
            if(board[i][j] == -2)
                score -= 50;
            if(board[i][j] == 3)
                score += 30;
            if(board[i][j] == -3)
                score -= 30;
            if(board[i][j] == 4)
                score += 30;
            if(board[i][j] == -4)
                score -= 30;
            if(board[i][j] == 5)
                score += 90;
            if(board[i][j] == -5)
                score -= 90;
            if(board[i][j] == 6)
                score += 900;
            if(board[i][j] == -6)
                score -= 900;           
        }
    }
    return score;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int min(int a, int b){
    return (a < b) ? a : b;
}

int mini_max(int depth, int alpha, int beta, int maximizing_player){
    if(depth == 0)
        return evaluate_board();
    int i, j, score;
    if(maximizing_player == 1){
        score = -100000;
        for(i = 0; i < 8; i++){
            for(j = 0; j < 8; j++){
                if(board[i][j] > 0){
                    int temp = board[i][j];
                    board[i][j] = 0;
                    for(int k = 0; k < 8; k++){
                        for(int l = 0; l < 8; l++){
                            if(board[k][l] <= 0){
                                int temp2 = board[k][l];
                                board[k][l] = temp;
                                int current_score = mini_max(depth-1, alpha, beta, -1);
                                score = max(score, current_score);
                                alpha = max(alpha, score);
                                if(beta <= alpha){
                                    board[k][l] = temp2;
                                    board[i][j] = temp;
                                    break;
                                }
                                board[k][l] = temp2;
                            }
                        }
                    }
                    board[i][j] = temp;
                }
            }
        }
        return score;
    }
    else{
        score = 100000;
        for(i = 0; i < 8; i++){
            for(j = 0; j < 8; j++){
                if(board[i][j] < 0){
                    int temp = board[i][j];
                    board[i][j] = 0;
                    for(int k = 0; k < 8; k++){
                        for(int l = 0; l < 8; l++){
                            if(board[k][l] >= 0){
                                int temp2 = board[k][l];
                                board[k][l] = temp;
                                int current_score = mini_max(depth-1, alpha, beta, 1);
                                score = min(score, current_score);
                                beta = min(beta, score);
                                if(beta <= alpha){
                                    board[k][l] = temp2;
                                    board[i][j] = temp;
                                    break;
                                }
                                board[k][l] = temp2;
                            }
                        }
                    }
                    board[i][j] = temp;
                }
            }
        }
        return score;
    }
}

//main function to test the AI
int main(){
    printf("Cryptic C Chess AI\n");
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    int score = mini_max(3, -100000, 100000, 1);
    printf("\nScore = %d", score);
    return 0;
}