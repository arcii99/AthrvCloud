//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int check_win(char *board, char c){
    if((board[0] == c && board[1] == c && board[2] == c) ||
       (board[3] == c && board[4] == c && board[5] == c) ||
       (board[6] == c && board[7] == c && board[8] == c) ||
       (board[0] == c && board[3] == c && board[6] == c) ||
       (board[1] == c && board[4] == c && board[7] == c) ||
       (board[2] == c && board[5] == c && board[8] == c) ||
       (board[0] == c && board[4] == c && board[8] == c) ||
       (board[2] == c && board[4] == c && board[6] == c)){
        return 1;
    }
    return 0;
}

int minimax(char *board, int depth, int isMaximizing, char curr_player, char ai_player, char human_player){
    int score = 0;
    if(check_win(board, ai_player)){
        score = 1;
        return score - depth;
    }else if(check_win(board, human_player)){
        score = -1;
        return score + depth;
    }else if(board[0] == ' ' || board[1] == ' ' || board[2] == ' ' ||
             board[3] == ' ' || board[4] == ' ' || board[5] == ' ' ||
             board[6] == ' ' || board[7] == ' ' || board[8] == ' '){
        if(isMaximizing){
            int bestScore = -1000;
            for(int i=0; i<9; i++){
                if(board[i] == ' '){
                    board[i] = ai_player;
                    int curr_score = minimax(board, depth+1, 0, curr_player, ai_player, human_player);
                    board[i] = ' ';
                    if(curr_score > bestScore){
                        bestScore = curr_score;
                    }
                }
            }
            score = bestScore;
        }else{
            int bestScore = 1000;
            for(int i=0; i<9; i++){
                if(board[i] == ' '){
                    board[i] = human_player;
                    int curr_score = minimax(board, depth+1, 1, curr_player, ai_player, human_player);
                    board[i] = ' ';
                    if(curr_score < bestScore){
                        bestScore = curr_score;
                    }
                }
            }
            score = bestScore;
        }
        return score;
    }else{
        return 0;
    }
}

int get_move(char *board, char curr_player, char ai_player, char human_player){
    int bestMove = -1;
    int bestScore = -1000;
    for(int i=0; i<9; i++){
        if(board[i] == ' '){
            board[i] = ai_player;
            int curr_score = minimax(board, 0, 0, curr_player, ai_player, human_player);
            board[i] = ' ';
            if(curr_score > bestScore){
                bestScore = curr_score;
                bestMove = i;
            }
        }
    }
    return bestMove;
}

void print_board(char *board){
    printf("\n-------------\n");
    for(int i=0; i<3; i++){
        printf("| %c | %c | %c |\n", board[3*i], board[3*i+1], board[3*i+2]);
        printf("-------------\n");
    }
}

int main(){
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char curr_player = 'X';
    char ai_player = 'O';
    char human_player = 'X';
    int move;

    printf("Do you want to play first? (Y/N)\n");
    char answer = getchar();
    if(answer == 'Y' || answer == 'y'){
        curr_player = 'X';
    }else{
        curr_player = 'O';
        ai_player = 'X';
        human_player = 'O';
    }

    while(1){
        print_board(board);
        if(curr_player == human_player){
            printf("Enter move (0-8): ");
            scanf("%d", &move);
            if(board[move] == ' '){
                board[move] = human_player;
                curr_player = ai_player;
            }else{
                printf("Invalid move, try again.\n");
            }
        }else{
            printf("Thinking...\n");
            move = get_move(board, curr_player, ai_player, human_player);
            board[move] = ai_player;
            curr_player = human_player;
        }
        if(check_win(board, ai_player)){
            print_board(board);
            printf("You lost!\n");
            break;
        }else if(check_win(board, human_player)){
            print_board(board);
            printf("You won!\n");
            break;
        }else if(board[0] != ' ' && board[1] != ' ' && board[2] != ' ' &&
                 board[3] != ' ' && board[4] != ' ' && board[5] != ' ' &&
                 board[6] != ' ' && board[7] != ' ' && board[8] != ' '){
            print_board(board);
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}