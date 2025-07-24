//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

char board[3][3];
char user = 'X', computer = 'O';

void print_board(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        printf("%c | ", board[i][j]);
    }
    printf("\n");
    printf("---------\n");
  }
}

void initialize_board(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        board[i][j] = '-';
    }
  }
}

int check_win(char player){
  int i,j;
  for(i=0;i<3;i++){
    if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
        return 1; // rows case
    }
    if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
        return 1; // column case
    }
  }
  if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return 1; // diagonal case
  }
  if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
    return 1; // diagonal case
  }
  return 0;
}

int minimax(int depth, int is_max){
  if(check_win(computer) == 1){
    return 10;
  }
  if(check_win(user) == 1){
    return -10;
  }
  int i, j, score;
  if(is_max){
    int best_score = -1000;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(board[i][j] == '-'){
                board[i][j] = computer;
                score = minimax(depth+1, !is_max);
                board[i][j] = '-';
                best_score = (score > best_score) ? score : best_score;
            }
        }
    }
    return best_score;
  }
  else{
    int best_score = 1000;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(board[i][j] == '-'){
                board[i][j] = user;
                score = minimax(depth+1, !is_max);
                board[i][j] = '-';
                best_score = (score < best_score) ? score : best_score;
            }
        }
    }
    return best_score;
  }   
}

int computer_move(){
  int i, j, best_score = -1000, move_score;
  int best_i, best_j;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        if(board[i][j] == '-'){
            board[i][j] = computer;
            move_score = minimax(0, 0);
            board[i][j] = '-';
            if(move_score > best_score){
                best_i = i;
                best_j = j;
                best_score = move_score;
            }
        }
    }
  }
  board[best_i][best_j] = computer;
  printf("Computer chose: [%d][%d]\n",best_i,best_j);
}

int main(){
  int i, j, choice_i, choice_j;
  initialize_board();
  printf("Welcome to Tic Tac Toe!\n");
  printf("You are playing as: %c\n",user);
  printf("Computer is playing as: %c\n",computer);
  printf("\nLet's start!\n");
  while(1){
    printf("\n-------\n");
    print_board();
    printf("Enter your move (row column): ");
    scanf("%d %d",&choice_i,&choice_j);
    if(board[choice_i][choice_j] == '-'){
        board[choice_i][choice_j] = user;
    }
    else{
        printf("Invalid move! Try again.\n");
        continue;
    }
    if(check_win(user) == 1){
        printf("\nCongratulations! You won!\n");
        break;
    }
    computer_move();
    if(check_win(computer) == 1){
        printf("\nSorry, you lost! Better luck next time!\n");
        break;
    }
    int empty_spaces = 0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(board[i][j] == '-'){
                empty_spaces = 1;
                break;
            }
        }
    }
    if(empty_spaces == 0){
        printf("\nIt's a tie!\n");
        break;
    }
  }
  return 0;
}