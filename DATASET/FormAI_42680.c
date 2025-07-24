//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initialize_board(char board[3][3]){
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            board[row][col] = '-';
        }
    }
}

void print_board(char board[3][3]){
    printf("\n");
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

int get_user_choice(){
    int choice;
    printf("Enter position to make your move (1-9): ");
    scanf("%d", &choice);
    return choice;
}

void convert_choice_to_row_col(int choice, int *row, int *col){
    *row = (choice-1) / 3;
    *col = (choice-1) % 3;
}

int is_valid_move(char board[3][3], int row, int col){
    if(board[row][col] == '-'){
        return 1;
    }else{
        return 0;
    }
}

int check_win(char board[3][3], char symbol){
    for(int row=0; row<3; row++){
        if(board[row][0] == symbol && board[row][1] == symbol && board[row][2] == symbol){
            return 1;
        }
    }
    for(int col=0; col<3; col++){
        if(board[0][col] == symbol && board[1][col] == symbol && board[2][col] == symbol){
            return 1;
        }
    }
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol){
        return 1;
    }
    if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol){
        return 1;
    }
    return 0;
}

int is_board_full(char board[3][3]){
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            if(board[row][col] == '-'){
                return 0;
            }
        }
    }
    return 1;
}

void get_computer_move(char board[3][3], int *row, int *col){
    int available_moves[9][2];
    int count = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == '-'){
                available_moves[count][0] = i;
                available_moves[count][1] = j;
                count++;
            }
        }
    }
    if(count > 0){
        int index = rand() % count;
        *row = available_moves[index][0];
        *col = available_moves[index][1];
    }
}

int main(){
    char board[3][3];
    initialize_board(board);
    int user_choice;
    int row, col;
    int computer_row, computer_col;
    int game_over = 0;
    srand(time(NULL));
    printf("Welcome to C-Tac-Toe!\n");
    printf("You are X, computer is O\n");
    printf("Enter 1-9 to make your move\n");
    printf("Here's the board:\n");
    print_board(board);

    while(!game_over){
        user_choice = get_user_choice();
        convert_choice_to_row_col(user_choice, &row, &col);
        while (!is_valid_move(board, row, col)){
            printf("Invalid move, try again.\n");
            user_choice = get_user_choice();
            convert_choice_to_row_col(user_choice, &row, &col);
        }
        board[row][col] = 'X';
        print_board(board);
        if(check_win(board, 'X')){
            printf("Congratulations, you won the game!\n");
            game_over = 1;
            break;
        }
        if(is_board_full(board)){
            printf("The game is a tie.\n");
            game_over = 1;
            break;
        }

        printf("Computer's move:\n");
        get_computer_move(board, &computer_row, &computer_col);
        board[computer_row][computer_col] = 'O';
        print_board(board);
        if(check_win(board, 'O')){
            printf("Sorry, you lost the game.\n");
            game_over = 1;
            break;
        }
        if(is_board_full(board)){
            printf("The game is a tie.\n");
            game_over = 1;
            break;
        }
    }

    return 0;
}