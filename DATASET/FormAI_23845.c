//FormAI DATASET v1.0 Category: Chess AI ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int board[8][8], turn;
int pieces[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
int values[6] = {100, 300, 320, 500, 900, 20000};
int player, depth, alpha, beta;
int new_board[8][8], new_pieces[2][6];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int evaluate(){
    int score = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] != 0){
                int p = board[i][j] < 0;
                int q = abs(board[i][j]) - 1;
                score += pieces[p][q] * values[q] * (p * 2 - 1);
            }
        }
    }
    return score;
}

int mini(int alpha, int beta, int depth){
    if(depth == 0) return evaluate();
    int best = 999999;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] > 0){
                for(int d = 0; d < 8; d++){
                    int nx = i + dx[d], ny = j + dy[d];
                    if(nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && board[nx][ny] <= 0){
                        for(int k = 0; k < 6; k++){
                            if(pieces[0][k] != 0 && ((k == 0 && nx == 0) || (k > 0))){
                                int temp = board[i][j];
                                board[i][j] = 0;
                                if(nx == 0 && k == 0) board[nx][ny] = 5;
                                else board[nx][ny] = -(k + 1);
                                pieces[0][k]--;
                                int val = maxi(alpha, beta, depth - 1);
                                if(val < best) best = val;
                                board[nx][ny] = 0;
                                board[i][j] = temp;
                                pieces[0][k]++;
                                if(best <= alpha) return best;
                                beta = (beta < best) ? beta : best;
                            }
                        }
                    }
                }
            }
        }
    }
    return best;
}

int maxi(int alpha, int beta, int depth){
    if(depth == 0) return evaluate();
    int best = -999999;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] < 0){
                for(int d = 0; d < 8; d++){
                    int nx = i + dx[d], ny = j + dy[d];
                    if(nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && board[nx][ny] >= 0){
                        for(int k = 0; k < 6; k++){
                            if(pieces[1][k] != 0 && ((k == 0 && nx == 7) || (k > 0))){
                                int temp = board[i][j];
                                board[i][j] = 0;
                                if(nx == 7 && k == 0) board[nx][ny] = -5;
                                else board[nx][ny] = k + 1;
                                pieces[1][k]--;
                                int val = mini(alpha, beta, depth - 1);
                                if(val > best) best = val;
                                board[nx][ny] = 0;
                                board[i][j] = temp;
                                pieces[1][k]++;
                                if(best >= beta) return best;
                                alpha = (alpha > best) ? alpha : best;
                            }
                        }
                    }
                }
            }
        }
    }
    return best;
}

int* AI_move(){
    int best = -999999, bestx, besty;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] < 0){
                for(int d = 0; d < 8; d++){
                    int nx = i + dx[d], ny = j + dy[d];
                    if(nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && board[nx][ny] >= 0){
                        for(int k = 0; k < 6; k++){
                            if(pieces[1][k] != 0 && ((k == 0 && nx == 7) || (k > 0))){
                                int temp = board[i][j];
                                board[i][j] = 0;
                                if(nx == 7 && k == 0) board[nx][ny] = -5;
                                else board[nx][ny] = k + 1;
                                pieces[1][k]--;
                                int val = mini(best, 999999, depth - 1);
                                if(val > best){
                                    best = val;
                                    bestx = i;
                                    besty = j;
                                }
                                board[nx][ny] = 0;
                                board[i][j] = temp;
                                pieces[1][k]++;
                            }
                        }
                    }
                }
            }
        }
    }
    int* ret = (int*)malloc(sizeof(int) * 4);
    ret[0] = bestx;
    ret[1] = besty;
    ret[2] = bestx + dx[rand() % 8];
    ret[3] = besty + dy[rand() % 8];
    return ret;
}

int main(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = 0;
        }
    }
    for(int i = 0; i < 6; i++){
        board[1][i] = -(i + 1);
        board[6][i] = i + 1;
    }
    while(1){
        int* ret = AI_move();
        int fx = ret[0], fy = ret[1], tx = ret[2], ty = ret[3];
        if(tx >= 0 && tx < 8 && ty >= 0 && ty < 8){
            board[tx][ty] = board[fx][fy];
            board[fx][fy] = 0;
        }
        printf("AI: Moved from (%d, %d) to (%d, %d)\n", fx + 1, fy + 1, tx + 1, ty + 1);
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 5){
                    printf("AI: Promote pawn from (%d, %d)\n", i + 1, j + 1);
                    board[i][j] = -1;
                }
                else if(board[i][j] == -5){
                    printf("AI: Promote pawn from (%d, %d)\n", i + 1, j + 1);
                    board[i][j] = 1;
                }
            }
        }
        int legal = 1;
        while(legal){
            printf("Enter move (e.g. 'from to'):\n");
            int fx, fy, tx, ty;
            scanf("%d %d %d %d", &fx, &fy, &tx, &ty);
            if(fx >= 1 && fx <= 8 && fy >= 1 && fy <= 8 && tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8){
                fx--;
                fy--;
                tx--;
                ty--;
                if(board[fx][fy] > 0){
                    if(board[tx][ty] >= 0){
                        int d = 0, q = abs(board[fx][fy]) - 1;
                        if(board[fx][fy] == 1){
                            if(fx == 1 && tx == 3 && fy == ty && board[2][fy] == 0 && board[3][fy] == 0){
                                board[tx][ty] = 1;
                                board[fx][fy] = 0;
                                if(board[tx + 1][ty] < 0 && board[tx + 1][ty] != -5) pieces[1][abs(board[tx + 1][ty]) - 1]--;
                                break;
                            }
                            else if(tx == fx - 1 && fy == ty && board[tx][ty] == 0){
                                board[tx][ty] = 1;
                                board[fx][fy] = 0;
                                if(board[tx][ty] >= 0 && board[tx][ty] != 5) pieces[0][abs(board[tx][ty]) - 1]--;
                                if(tx == 0) board[tx][ty] = 5;
                                break;
                            }
                        }
                        switch(q){
                            case 1:
                            case 2:
                                if((abs(fx - tx) == 1 && abs(fy - ty) == 2) || (abs(fx - tx) == 2 && abs(fy - ty) == 1)) d = 1;
                                break;
                            case 3:
                                if((abs(fx - tx) == abs(fy - ty)) && (board[tx][ty] <= 0)) d = 1;
                                break;
                            case 4:
                                if((abs(fx - tx) == abs(fy - ty) && abs(fx - tx) > 0) || (fx == tx || fy == ty)){
                                    int error = 0;
                                    if(fx == tx && fy < ty){
                                        for(int i = fy + 1; i < ty; i++){
                                            if(board[fx][i] != 0) error = 1;
                                        }
                                    }
                                    else if(fx == tx && fy > ty){
                                        for(int i = fy - 1; i > ty; i--){
                                            if(board[fx][i] != 0) error = 1;
                                        }
                                    }
                                    else if(fy == ty && fx < tx){
                                        for(int i = fx + 1; i < tx; i++){
                                            if(board[i][fy] != 0) error = 1;
                                        }
                                    }
                                    else if(fy == ty && fx > tx){
                                        for(int i = fx - 1; i > tx; i--){
                                            if(board[i][fy] != 0) error = 1;
                                        }
                                    }
                                    if(error == 0) d = 1;
                                }
                                break;
                            case 5:
                                if(((abs(fx - tx) == abs(fy - ty)) || (fx == tx || fy == ty)) && (board[tx][ty] <= 0)){
                                    int error = 0;
                                    int mx = (fx > tx) ? -1 : 1;
                                    int my = (fy > ty) ? -1 : 1;
                                    int i, j;
                                    i = fx + mx;
                                    j = fy + my;
                                    while(i != tx || j != ty){
                                        if(board[i][j] != 0){
                                            error = 1;
                                            break;
                                        }
                                        i += mx;
                                        j += my;
                                    }
                                    if(error == 0) d = 1;
                                }
                                break;
                            case 6:
                                if(abs(fx - tx) <= 1 && abs(fy - ty) <= 1 && board[tx][ty] <= 0) d = 1;
                                break;
                        }
                        if(d == 1){
                            if(board[tx][ty] < 0){
                                pieces[1][abs(board[tx][ty]) - 1]--;
                                if(abs(board[tx][ty]) == 1) printf("Pawn Captured!\n");
                                else printf("Piece Captured!\n");
                            }
                            board[tx][ty] = board[fx][fy];
                            board[fx][fy] = 0;
                            if((board[tx][ty] == 1 && tx == 0) || (board[tx][ty] == -1 && tx == 7)){
                                int p;
                                printf("Choose Promotion (2:Knight,3:Bishop,4:Rook,5:Queen):\n");
                                scanf("%d", &p);
                                switch(p){
                                    case 2:
                                        board[tx][ty] = 2;
                                        break;
                                    case 3:
                                        board[tx][ty] = 3;
                                        break;
                                    case 4:
                                        board[tx][ty] = 4;
                                        break;
                                    default:
                                        board[tx][ty] = 5;
                                        break;
                                }
                            }
                            break;
                        }
                    }
                }
            }
            if(board[tx][ty] > 0) printf("Illegal move. Try Again!\n");
            else printf("Invalid move. Try Again!\n");
        }
    }
    return 0;
}