//FormAI DATASET v1.0 Category: Chess AI ; Style: mathematical
// Chess AI example program in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WHITE 0
#define BLACK 1
#define EMPTY 2

int board[8][8] = {{4, 2, 3, 5, 6, 3, 2, 4},
                   {1, 1, 1, 1, 1, 1, 1, 1},
                   {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                   {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                   {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                   {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                   {1, 1, 1, 1, 1, 1, 1, 1},
                   {4, 2, 3, 5, 6, 3, 2, 4}};

int evaluate_board(int player){
    int score = 0;
    int i, j, piece;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            piece = board[i][j];
            if(piece == EMPTY) continue;
            if(piece & WHITE){
                score += get_piece_value(piece, player);
            }else{
                score -= get_piece_value(piece, player);
            }
        }
    }
    return score;
}

int get_piece_value(int piece, int player){
    int value = 0;
    switch(piece){
        case 1: // Pawn
            value = 10;
            break;
        case 2: // Knight
            value = 30;
            break;
        case 3: // Bishop
            value = 30;
            break;
        case 4: // Rook
            value = 50;
            break;
        case 5: // Queen
            value = 90;
            break;
        case 6: // King
            value = 900;
            break;
    }
    if(player == BLACK) value *= -1;
    return value;
}

void make_move(int *move){
    int i, j, piece, from_row, from_col, to_row, to_col;
    from_row = move[0];
    from_col = move[1];
    to_row = move[2];
    to_col = move[3];
    piece = board[from_row][from_col];
    board[from_row][from_col] = EMPTY;
    board[to_row][to_col] = piece;
}

void generate_move(int *move){
    int i, j;
    int valid_moves[30][4];
    int move_count = 0;

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j] & WHITE){
                generate_piece_moves(valid_moves, &move_count, i, j);
            }
        }
    }

    srand(time(NULL));
    int random_index = rand() % move_count;
    for(i=0;i<4;i++){
        move[i] = valid_moves[random_index][i];
    }
}

void generate_piece_moves(int valid_moves[][4], int *move_count, int row, int col){
    int i,j, target_row, target_col;
    int piece = board[row][col];
    switch(piece){
        case 1: // Pawn
            if(row > 0 && board[row-1][col] == EMPTY){
                valid_moves[*move_count][0] = row;
                valid_moves[*move_count][1] = col;
                valid_moves[*move_count][2] = row-1;
                valid_moves[*move_count][3] = col;
                (*move_count)++;
            }
            break;
        case 2: // Knight
            for(i=-2;i<=2;i++){
                for(j=-2;j<=2;j++){
                    if(abs(i*j) != 2) continue;
                    target_row = row+i;
                    target_col = col+j;
                    if(target_row < 0 || target_row >= 8 || target_col < 0 || target_col >= 8) continue;
                    if(board[target_row][target_col] == EMPTY || (board[target_row][target_col] & BLACK)){
                        valid_moves[*move_count][0] = row;
                        valid_moves[*move_count][1] = col;
                        valid_moves[*move_count][2] = target_row;
                        valid_moves[*move_count][3] = target_col;
                        (*move_count)++;  
                    }
                }
            }
            break;
        case 3: // Bishop
            generate_diagonal_moves(valid_moves, move_count, row, col);
            break;
        case 4: // Rook  
            generate_straight_moves(valid_moves, move_count, row, col);
            break;
        case 5: // Queen
            generate_straight_moves(valid_moves, move_count, row, col);
            generate_diagonal_moves(valid_moves, move_count, row, col);
            break;
        case 6: // King
            for(i=-1;i<=1;i++){
                for(j=-1;j<=1;j++){
                    target_row = row+i;
                    target_col = col+j;
                    if(target_row < 0 || target_row >= 8 || target_col < 0 || target_col >= 8) continue;
                    if(board[target_row][target_col] == EMPTY || (board[target_row][target_col] & BLACK)){
                        valid_moves[*move_count][0] = row;
                        valid_moves[*move_count][1] = col;
                        valid_moves[*move_count][2] = target_row;
                        valid_moves[*move_count][3] = target_col;
                        (*move_count)++;  
                    }
                }
            }
            break;
    }
}

void generate_straight_moves(int valid_moves[][4], int *move_count, int row, int col){
    int i, target_row, target_col;
    // Top Moves
    for(i=row-1;i>=0;i--){
        if(board[i][col] == EMPTY || (board[i][col] & BLACK)){
            valid_moves[*move_count][0] = row;
            valid_moves[*move_count][1] = col;
            valid_moves[*move_count][2] = i;
            valid_moves[*move_count][3] = col;
            (*move_count)++;  
            if(board[i][col] & BLACK){
                break;
            }
        }else{
            break;
        }
    }
    // Bottom Moves
    for(i=row+1;i<8;i++){
        if(board[i][col] == EMPTY || (board[i][col] & BLACK)){
            valid_moves[*move_count][0] = row;
            valid_moves[*move_count][1] = col;
            valid_moves[*move_count][2] = i;
            valid_moves[*move_count][3] = col;
            (*move_count)++;  
            if(board[i][col] & BLACK){
                break;
            }
        }else{
            break;
        }
    }
    // Left Moves
    for(i=col-1;i>=0;i--){
        if(board[row][i] == EMPTY || (board[row][i] & BLACK)){
            valid_moves[*move_count][0] = row;
            valid_moves[*move_count][1] = col;
            valid_moves[*move_count][2] = row;
            valid_moves[*move_count][3] = i;
            (*move_count)++;  
            if(board[row][i] & BLACK){
                break;
            }
        }else{
            break;
        }
    }
    // Left Moves
    for(i=col+1;i<8;i++){
        if(board[row][i] == EMPTY || (board[row][i] & BLACK)){
            valid_moves[*move_count][0] = row;
            valid_moves[*move_count][1] = col;
            valid_moves[*move_count][2] = row;
            valid_moves[*move_count][3] = i;
            (*move_count)++;  
            if(board[row][i] & BLACK){
                break;
            }
        }else{
            break;
        }
    }
}

void generate_diagonal_moves(int valid_moves[][4], int *move_count, int row, int col){
    int i, target_row, target_col;
    // Up-Left Moves 
    for(i=1;i<=7;i++){
        target_row = row-i;
        target_col = col-i;
        if(target_row < 0 || target_row >= 8 || target_col < 0 || target_col >= 8) break;
        if(board[target_row][target_col] == EMPTY || (board[target_row][target_col] & BLACK)){
            valid_moves[*move_count][0] = row;
            valid_moves[*move_count][1] = col;
            valid_moves[*move_count][2] = target_row;
            valid_moves[*move_count][3] = target_col;
            (*move_count)++;  
            if(board[target_row][target_col] & BLACK){
                break;
            }
        }else{
            break;
        }   
    }
    // Up-Right Moves 
    for(i=1;i<=7;i++){
        target_row = row-i;
        target_col = col+i;
        if(target_row < 0 || target_row >= 8 || target_col < 0 || target_col >= 8) break;
        if(board[target_row][target_col] == EMPTY || (board[target_row][target_col] & BLACK)){
            valid_moves[*move_count][0] = row;
            valid_moves[*move_count][1] = col;
            valid_moves[*move_count][2] = target_row;
            valid_moves[*move_count][3] = target_col;
            (*move_count)++;  
            if(board[target_row][target_col] & BLACK){
                break;
            }
        }else{
            break;
        }   
    }
    // Down-Left Moves 
    for(i=1;i<=7;i++){
        target_row = row+i;
        target_col = col-i;
        if(target_row < 0 || target_row >= 8 || target_col < 0 || target_col >= 8) break;
        if(board[target_row][target_col] == EMPTY || (board[target_row][target_col] & BLACK)){
            valid_moves[*move_count][0] = row;
            valid_moves[*move_count][1] = col;
            valid_moves[*move_count][2] = target_row;
            valid_moves[*move_count][3] = target_col;
            (*move_count)++;  
            if(board[target_row][target_col] & BLACK){
                break;
            }
        }else{
            break;
        }   
    }
    // Down-Right Moves 
    for(i=1;i<=7;i++){
        target_row = row+i;
        target_col = col+i;
        if(target_row < 0 || target_row >= 8 || target_col < 0 || target_col >= 8) break;
        if(board[target_row][target_col] == EMPTY || (board[target_row][target_col] & BLACK)){
            valid_moves[*move_count][0] = row;
            valid_moves[*move_count][1] = col;
            valid_moves[*move_count][2] = target_row;
            valid_moves[*move_count][3] = target_col;
            (*move_count)++;  
            if(board[target_row][target_col] & BLACK){
                break;
            }
        }else{
            break;
        }   
    }
}

int main(){
    int player = WHITE;
    int move[4];
    while(1){
        // Make Move for Player
        generate_move(move);
        make_move(move);
        // Change Turn
        player = !player;
        // Evaluate Board
        int score = evaluate_board(player);
        if(score == 0){
            printf("Draw!");
            break;
        }else if(score > 0){
            printf("Player 1 Wins!");
            break;
        }else{
            printf("Player 2 Wins!");
            break;
        }
    }
    return 0;
}