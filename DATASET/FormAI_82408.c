//FormAI DATASET v1.0 Category: Chess AI ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int depth = 3;

//board position structure
struct board_pos{
    char board[8][8];
    int value;
};

//function to initialize the chess board
void init_board(struct board_pos *pos){
    int i,j;
    char board[8][8] = {
                        {'R','N','B','Q','K','B','N','R'},
                        {'P','P','P','P','P','P','P','P'},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {'p','p','p','p','p','p','p','p'},
                        {'r','n','b','q','k','b','n','r'}
                      };
    
    //copy the board to the board position structure
    memcpy(pos->board,board,sizeof(board));
    pos->value = 0;
}

//function to calculate position value
void calculate_value(struct board_pos *pos){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            switch(pos->board[i][j]){
                case 'P': pos->value += 100; break;
                case 'p': pos->value -= 100; break;
                case 'N': pos->value += 320; break;
                case 'n': pos->value -= 320; break;
                case 'B': pos->value += 330; break;
                case 'b': pos->value -= 330; break;
                case 'R': pos->value += 500; break;
                case 'r': pos->value -= 500; break;
                case 'Q': pos->value += 900; break;
                case 'q': pos->value -= 900; break;
            }
        }
    }
}

//function to print the board
void print_board(struct board_pos *pos){
    int i,j;
    for(i=0;i<8;i++){
        printf("%d ", 8-i);
        for(j=0;j<8;j++){
            printf("%c ", pos->board[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

//function to check if a move is valid
int is_valid_move(int x1, int y1, int x2, int y2, struct board_pos *pos){
    char piece = pos->board[x1][y1];
    char target = pos->board[x2][y2];
    int i,j;

    //check if the move is legal for the piece type
    switch(piece){
        case 'P': 
            if(target != ' ' && x2 == x1+1 && (y2 == y1+1 || y2 == y1-1)){
                return 1;
            }
            if(target != ' ' || y2 != y1){
                return 0;
            }
            if(x1 == 6 && x2 == 4 && pos->board[5][y1] == ' ' && pos->board[4][y1] == ' '){
                return 1;
            }
            if(x2 == x1-1){
                return 1;
            }
            return 0;
        case 'p':
            if(target != ' ' && x2 == x1-1 && (y2 == y1+1 || y2 == y1-1)){
                return 1;
            }
            if(target != ' ' || y2 != y1){ 
                return 0;
            }
            if(x1 == 1 && x2 == 3 && pos->board[2][y1] == ' ' && pos->board[3][y1] == ' '){
                return 1;
            }
            if(x2 == x1+1){
                return 1;
            }
            return 0;
        case 'N':
        case 'n':
            if(target == ' ' || isupper(target) != isupper(piece)){
                if(abs(x2-x1) == 2 && abs(y2-y1) == 1){
                    return 1;
                }
                if(abs(x2-x1) == 1 && abs(y2-y1) == 2){
                    return 1;
                }
            }
            return 0;
        case 'B':
        case 'b':
            if(abs(x2-x1) != abs(y2-y1)){
                return 0;
            }
            if(x2 > x1 && y2 > y1){
                for(i=x1+1,j=y1+1;i<x2;i++,j++){
                    if(pos->board[i][j] != ' '){
                        return 0;
                    }
                }
                return 1;
            }
            if(x2 > x1 && y2 < y1){
                for(i=x1+1,j=y1-1;i<x2;i++,j--){
                    if(pos->board[i][j] != ' '){
                        return 0;
                    }
                }
                return 1;
            }
            if(x2 < x1 && y2 < y1){
                for(i=x1-1,j=y1-1;i>x2;i--,j--){
                    if(pos->board[i][j] != ' '){
                        return 0;
                    }
                }
                return 1;
            }
            if(x2 < x1 && y2 > y1){
                for(i=x1-1,j=y1+1;i>x2;i--,j++){
                    if(pos->board[i][j] != ' '){
                        return 0;
                    }
                }
                return 1;
            }
        case 'R':
        case 'r':
            if(x1 == x2){
                if(y2 > y1){
                    for(j=y1+1;j<y2;j++){
                        if(pos->board[x1][j] != ' '){
                            return 0;
                        }
                    }
                    return 1;
                }
                else{
                    for(j=y1-1;j>y2;j--){
                        if(pos->board[x1][j] != ' '){
                            return 0;
                        }
                    }
                    return 1;
                }
            }
            if(y1 == y2){
                if(x2 > x1){
                    for(i=x1+1;i<x2;i++){
                        if(pos->board[i][y1] != ' '){
                            return 0;
                        }
                    }
                    return 1;
                }
                else{
                    for(i=x1-1;i>x2;i--){
                        if(pos->board[i][y1] != ' '){
                            return 0;
                        }
                    }
                    return 1;
                }
            }
            return 0;
        case 'Q':
        case 'q':
            if(x2 == x1 || y2 == y1){
                return is_valid_move(x1, y1, x2, y2, pos);
            }
            if(abs(x2-x1) == abs(y2-y1)){
                return is_valid_move(x1, y1, x2, y2, pos);
            }
            return 0;
        case 'K':
        case 'k':
            if(abs(x2-x1) <= 1 && abs(y2-y1) <= 1){
                return 1;
            }
            return 0;
    }
    return 0;
}

//function to make a move
void make_move(int x1, int y1, int x2, int y2, struct board_pos *pos){
    char piece = pos->board[x1][y1];
    char target = pos->board[x2][y2];

    //update board
    pos->board[x2][y2] = piece;
    pos->board[x1][y1] = ' ';

    //update position value
    switch(piece){
        case 'P': pos->value += 10*(8-x2); break;
        case 'p': pos->value -= 10*x2; break;
        case 'N': pos->value += 30; break;
        case 'n': pos->value -= 30; break;
        case 'B': pos->value += 30; break;
        case 'b': pos->value -= 30; break;
        case 'R': pos->value += 50; break;
        case 'r': pos->value -= 50; break;
        case 'Q': pos->value += 90; break;
        case 'q': pos->value -= 90; break;
    }
    if(target != ' '){
        switch(target){
            case 'P': pos->value -= 10*(8-x2); break;
            case 'p': pos->value += 10*x2; break;
            case 'N': pos->value -= 30; break;
            case 'n': pos->value += 30; break;
            case 'B': pos->value -= 30; break;
            case 'b': pos->value += 30; break;
            case 'R': pos->value -= 50; break;
            case 'r': pos->value += 50; break;
            case 'Q': pos->value -= 90; break;
            case 'q': pos->value += 90; break;
        }
    }
}

//function to undo a move
void undo_move(int x1, int y1, int x2, int y2, char piece, char target, struct board_pos *pos){
    //update board and position value
    pos->board[x1][y1] = piece;
    pos->board[x2][y2] = target;
    switch(piece){
        case 'P': pos->value -= 10*(8-x2); break;
        case 'p': pos->value += 10*x2; break;
        case 'N': pos->value -= 30; break;
        case 'n': pos->value += 30; break;
        case 'B': pos->value -= 30; break;
        case 'b': pos->value += 30; break;
        case 'R': pos->value -= 50; break;
        case 'r': pos->value += 50; break;
        case 'Q': pos->value -= 90; break;
        case 'q': pos->value += 90; break;
    }
    if(target != ' '){
        switch(target){
            case 'P': pos->value += 10*(8-x2); break;
            case 'p': pos->value -= 10*x2; break;
            case 'N': pos->value += 30; break;
            case 'n': pos->value -= 30; break;
            case 'B': pos->value += 30; break;
            case 'b': pos->value -= 30; break;
            case 'R': pos->value += 50; break;
            case 'r': pos->value -= 50; break;
            case 'Q': pos->value += 90; break;
            case 'q': pos->value -= 90; break;
        }
    }
}

//function to find the best move for the current position
void find_best_move(struct board_pos *pos, int cur_depth, int alpha, int beta, int *best_x1, int *best_y1, int *best_x2, int *best_y2){
    int i,j,valid_move,is_max,alpha_backup,beta_backup,value_backup;
    struct board_pos child_pos;
    *best_x1 = *best_y1 = *best_x2 = *best_y2 = -1;

    //check if maximum depth has been reached
    if(cur_depth == depth){
        return;
    }

    //determine if we are minimizing or maximizing
    if(cur_depth % 2 == 0){
        is_max = 1;
    }
    else{
        is_max = 0;
    }

    //iterate over all possible moves
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(is_max && isupper(pos->board[i][j])){
                int k,l;
                for(k=0;k<8;k++){
                    for(l=0;l<8;l++){
                        if(is_valid_move(i,j,k,l,pos)){
                            valid_move = 1;

                            //create child position
                            memcpy(&child_pos,pos,sizeof(struct board_pos));
                            make_move(i,j,k,l,&child_pos);
                            calculate_value(&child_pos);
                            alpha_backup = alpha;
                            beta_backup = beta;
                            value_backup = child_pos.value;

                            //get the value of the best move from the child position
                            find_best_move(&child_pos,cur_depth+1,alpha,beta,best_x1,best_y1,best_x2,best_y2);
                            if(is_max){
                                if(child_pos.value > alpha){
                                    alpha = child_pos.value;
                                    *best_x1 = i;
                                    *best_y1 = j;
                                    *best_x2 = k;
                                    *best_y2 = l;
                                }
                            }
                            else{
                                if(child_pos.value < beta){
                                    beta = child_pos.value;
                                    *best_x1 = i;
                                    *best_y1 = j;
                                    *best_x2 = k;
                                    *best_y2 = l;
                                }
                            }

                            //restore position value and alpha/beta values
                            memcpy(pos,&child_pos,sizeof(struct board_pos));
                            alpha = alpha_backup;
                            beta = beta_backup;
                            child_pos.value = value_backup;

                            //beta pruning
                            if(alpha >= beta){
                                return;
                            }
                        }
                    }
                }
            }
            else if(!is_max && islower(pos->board[i][j])){
                int k,l;
                for(k=0;k<8;k++){
                    for(l=0;l<8;l++){
                        if(is_valid_move(i,j,k,l,pos)){
                            valid_move = 1;

                            //create child position
                            memcpy(&child_pos,pos,sizeof(struct board_pos));
                            make_move(i,j,k,l,&child_pos);
                            calculate_value(&child_pos);
                            alpha_backup = alpha;
                            beta_backup = beta;
                            value_backup = child_pos.value;

                            //get the value of the best move from the child position
                            find_best_move(&child_pos,cur_depth+1,alpha,beta,best_x1,best_y1,best_x2,best_y2);
                            if(is_max){
                                if(child_pos.value > alpha){
                                    alpha = child_pos.value;
                                    *best_x1 = i;
                                    *best_y1 = j;
                                    *best_x2 = k;
                                    *best_y2 = l;
                                }
                            }
                            else{
                                if(child_pos.value < beta){
                                    beta = child_pos.value;
                                    *best_x1 = i;
                                    *best_y1 = j;
                                    *best_x2 = k;
                                    *best_y2 = l;
                                }
                            }

                            //restore position value and alpha/beta values
                            memcpy(pos,&child_pos,sizeof(struct board_pos));
                            alpha = alpha_backup;
                            beta = beta_backup;
                            child_pos.value = value_backup;

                            //alpha pruning
                            if(alpha >= beta){
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

//main function
int main(){
    struct board_pos pos;
    int x1,y1,x2,y2;

    //initialize board
    init_board(&pos);

    //print board
    print_board(&pos);

    //get best move
    find_best_move(&pos,0,INT_MIN,INT_MAX,&x1,&y1,&x2,&y2);
    printf("Best Move: %c%d to %c%d\n",'a'+y1,8-x1,'a'+y2,8-x2);

    return 0;
}