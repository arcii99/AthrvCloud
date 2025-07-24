//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
char board[9] = {'1','2','3','4','5','6','7','8','9'};

int check_win(){
  for(int i=0;i<3;i++){
    if(board[i]==board[i+3] && board[i]==board[i+6])
      return 1;
  }
  for(int i=0;i<9;i+=3){
    if(board[i]==board[i+1] && board[i]==board[i+2])
      return 1;
  }
  if(board[0]==board[4] && board[0]==board[8])
    return 1;
  if(board[2]==board[4] && board[2]==board[6])
    return 1;
  return 0;
}

int minimax(int depth, int turn){
  if(check_win())
    return (turn?-1:1);
  if(depth==9)
    return 0;
  int best_val = (turn?-1:1)*1000;
  int score;
  for(int i=0;i<9;i++){
    if(board[i]>='1' && board[i]<='9'){
      board[i] = (turn?'O':'X');
      score = minimax(depth+1, !turn);
      board[i] = i+'1';
      best_val = (turn?score>best_val:score<best_val)?score:best_val;
    }
  }
  return best_val;
}

int get_best_move(){
  int best_move = 0;
  int best_val = -1000;
  int score;
  for(int i=0;i<9;i++){
    if(board[i]>='1' && board[i]<='9'){
      board[i] = 'O';
      score = minimax(0,0);
      board[i] = i+'1';
      if(score>best_val){
        best_val = score;
        best_move = i;
      }
    }
  }
  return best_move;
}

void print_board(){
  printf(" %c | %c | %c\n", board[0], board[1], board[2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c\n", board[3], board[4], board[5]);
  printf("---|---|---\n");
  printf(" %c | %c | %c\n", board[6], board[7], board[8]);
}

int main(){
  int move;
  int player = 0;
  printf("\nTic Tac Toe\n\n");
  printf("Player 1 (X)  -  Player 2 (O)\n\n");
  printf("Please choose a number between 1 and 9 as your move\n\n");
  print_board();
  
  while(!check_win() && player<9){
    if(player%2==0){
      printf("\nPlayer 1, What is Your Move: ");
      scanf("%d", &move);
      if(board[move-1]=='X' || board[move-1]=='O'){
        printf("\nInvalid Move. Please choose a Number between 1 and 9 as Your Move\n");
       continue;
      }
      board[move-1] = 'X';
    }
    else{
      printf("\nAI's Move: ");
      move = get_best_move();
      printf("%d\n\n", move+1);
      board[move] = 'O';
    }
    player++;
    print_board();
  }
  if(check_win())
    printf("Congratulations!! Player %d has Won.\n\n", (player%2)?1:2);
  else
    printf("The Game is a Tie!!\n\n");
  return 0;
}