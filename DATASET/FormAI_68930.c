//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define BOARD_SIZE 3
#define EMPTY 0
#define X_MARK 1
#define O_MARK 2
#define DRAW 3

int get_board_score(int board[BOARD_SIZE][BOARD_SIZE], int player_mark);
int get_best_move(int board[BOARD_SIZE][BOARD_SIZE], int player_mark);
int minimax(int board[BOARD_SIZE][BOARD_SIZE], int depth, int is_maximizer, int player_mark, int alpha, int beta);

void print_board(int board[BOARD_SIZE][BOARD_SIZE]){
    printf("  ");
    for(int i=0;i<BOARD_SIZE;i++){
        printf("%d ", i+1);
    }
    printf("\n");
    for(int i=0;i<BOARD_SIZE;i++){
        printf("%d|", i+1);
        for(int j=0;j<BOARD_SIZE;j++){
            switch(board[i][j]){
                case X_MARK:
                    printf("X|");
                    break;
                case O_MARK:
                    printf("O|");
                    break;
                default:
                    printf(" |");
                    break;
            }
        }
        printf("\n");
    }
}

int check_winner(int board[BOARD_SIZE][BOARD_SIZE]){
    // check for rows
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }

    // check for columns
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[0][i] != EMPTY && board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }

    // check for diagonal
    if(board[0][0] != EMPTY && board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }

    // check for opposite diagonal
    if(board[0][2] != EMPTY && board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return board[0][2];
    }

    // check for draw
    int is_draw = 1;
    for(int i=0;i<BOARD_SIZE;i++) {
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j] == EMPTY){
                is_draw = 0;
            }
        }
    }
    if(is_draw){
        return DRAW;
    }

    return EMPTY;
}

int get_board_score(int board[BOARD_SIZE][BOARD_SIZE], int player_mark){
    int winner = check_winner(board);
    if(winner == player_mark){
        return 10;
    }
    else if(winner == DRAW){
        return 0;
    }
    else{
        return -10;
    }
}

int get_best_move(int board[BOARD_SIZE][BOARD_SIZE], int player_mark){
    int best_move = -1;
    int best_score = -999;
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j] == EMPTY){
                board[i][j] = player_mark;
                int score = minimax(board, 0, 0, player_mark, -999, 999);
                board[i][j] = EMPTY;
                if(score > best_score){
                    best_move = i*BOARD_SIZE+j;
                    best_score = score;
                }
            }
        }
    }
    return best_move;
}

int minimax(int board[BOARD_SIZE][BOARD_SIZE], int depth, int is_maximizer, int player_mark, int alpha, int beta){
    int winner = check_winner(board);
    if(winner != EMPTY){
        return get_board_score(board, player_mark);
    }

    if(is_maximizer){
        int best_score = -999;
        for(int i=0;i<BOARD_SIZE;i++){
            for(int j=0;j<BOARD_SIZE;j++){
                if(board[i][j] == EMPTY){
                    board[i][j] = player_mark;
                    int score = minimax(board, depth+1, 0, player_mark, alpha, beta);
                    board[i][j] = EMPTY;
                    best_score = (score > best_score)? score: best_score;
                    alpha = (alpha > best_score)? alpha: best_score;
                    if(alpha > beta){
                        return best_score;
                    }
                }
            }
        }
        return best_score;
    }
    else{
        int best_score = 999;
        for(int i=0;i<BOARD_SIZE;i++){
            for(int j=0;j<BOARD_SIZE;j++){
                if(board[i][j] == EMPTY){
                    board[i][j] = (player_mark==X_MARK)? O_MARK: X_MARK;
                    int score = minimax(board, depth+1, 1, player_mark, alpha, beta);
                    board[i][j] = EMPTY;
                    best_score = (score < best_score)? score: best_score;
                    beta = (beta < best_score)? beta: best_score;
                    if(alpha > beta){
                        return best_score;
                    }
                }
            }
        }
        return best_score;
    }
}

void clear_screen(){
    printf("\033[2J\033[1;1H");
}

void play_game(){
    int board[BOARD_SIZE][BOARD_SIZE] = {0};

    int player_mark = X_MARK;
    int ai_mark = O_MARK;

    while(check_winner(board) == EMPTY){
        clear_screen();

        printf("[Player %s turn]\n", (player_mark == X_MARK)? "X": "O");
        print_board(board);

        int is_valid_move = 0;
        while(!is_valid_move){
            printf("Enter move (row,col): ");
            char move_str[256];
            fgets(move_str, 256, stdin);

            int row = move_str[0] - '0' - 1;
            int col = move_str[2] - '0' - 1;

            if(row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != EMPTY){
                printf("Invalid move, try again.\n");
            }
            else{
                board[row][col] = player_mark;
                is_valid_move = 1;
            }
        }

        if(check_winner(board) != EMPTY){
            break;
        }

        printf("[AI turn]\n");
        int ai_move = get_best_move(board, ai_mark);
        board[ai_move/BOARD_SIZE][ai_move%BOARD_SIZE] = ai_mark;

        if(check_winner(board) != EMPTY){
            break;
        }

        player_mark = (player_mark == X_MARK)? O_MARK: X_MARK;
        ai_mark = (ai_mark == X_MARK)? O_MARK: X_MARK;
    }

    clear_screen();
    printf("Final result:\n");
    print_board(board);

    int winner = check_winner(board);
    switch(winner){
        case X_MARK:
            printf("Player X wins!\n");
            break;
        case O_MARK:
            printf("Player O wins!\n");
            break;
        case DRAW:
            printf("Draw game!\n");
            break;
        default:
            printf("Unknown winner\n");
            break;
    }
}

int main(){
    srand(time(NULL));
    play_game();
    return 0;
}