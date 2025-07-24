//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: accurate
#include <stdio.h>
#include <stdbool.h>

char board[3][3]; //3x3 board

//initialize the board with empty values
void initialize_board(){
  for(int row=0; row<3; row++){
    for(int col=0; col<3; col++){
      board[row][col] = '-';
    }
  }
}

//print the current board
void print_board(){
  printf("\n");
  printf("Board:\n");
  for(int row=0; row<3; row++){
    for(int col=0; col<3; col++){
      printf("%c ", board[row][col]);
    }
    printf("\n");
  }
}

//check if given player has won the game
bool check_win(char player){
  //checking rows
  for(int row=0; row<3; row++){
    if(board[row][0] == player && board[row][1] == player && board[row][2] == player){
      return true;
    }
  }
  //checking columns
  for(int col=0; col<3; col++){
    if(board[0][col] == player && board[1][col] == player && board[2][col] == player){
      return true;
    }
  }
  //checking diagonals
  if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return true;
  }
  if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
    return true;
  }
  //player has not won the game
  return false;
}

//check if the game is a tie
bool check_tie(){
  //checking if all cells are filled
  for(int row=0; row<3; row++){
    for(int col=0; col<3; col++){
      if(board[row][col] == '-'){
        return false;
      }
    }
  }
  //game is a tie
  return true;
}

//initialize the board with empty values
void make_move(char player, int row, int col){
  board[row][col] = player;
}

//get the row and column for player's move
void get_player_move(char player, int *row, int *col){
  printf("Player %c's turn:\n", player);
  printf("Enter row number (0-2): ");
  scanf("%d", row);
  printf("Enter column number (0-2): ");
  scanf("%d", col);
}

//calculate the score for given move
int calculate_move_score(char player, int row, int col){
  int score = 0;

  //make the move on the board
  board[row][col] = player;
  
  //if the move wins the game
  if(check_win(player)){
    score = 10;
  }
  //if the move results in a tie
  else if(check_tie()){
    score = 0;
  }
  //if the move does not result in a win or tie
  else{
    //switch the player
    char opp_player;
    if(player == 'X'){
      opp_player = 'O';
    }
    else{
      opp_player = 'X';
    }
    //initialize the best score based on opposite player's move
    int best_score = calculate_move_score(opp_player, 0, 0);
    //check all possible moves and choose the best score
    for(int r=0; r<3; r++){
      for(int c=0; c<3; c++){
        if(board[r][c] == '-'){
          int move_score = calculate_move_score(opp_player, r, c);
          if(player == 'X'){
            if(move_score > best_score){
              best_score = move_score;
            }
          }
          else{
            if(move_score < best_score){
              best_score = move_score;
            }
          }
        }
      }
    }
    //subtract the best score from current player's score
    score = best_score * -1;
  }
  //undo the move on the board
  board[row][col] = '-';
  return score;
}

//get the row and column for AI's move
void get_computer_move(char player, int *row, int *col){
  int best_score = -100;
  //check all possible moves and choose the best move
  for(int r=0; r<3; r++){
    for(int c=0; c<3; c++){
      if(board[r][c] == '-'){
        int move_score = calculate_move_score(player, r, c);
        if(move_score > best_score){
          best_score = move_score;
          *row = r;
          *col = c;
        }
      }
    }
  }
}

//start the game
void play_tictactoe(){
  initialize_board();
  print_board();
  char player = 'X';
  while(true){
    if(player == 'X'){
      int row, col;
      get_player_move(player, &row, &col);
      make_move(player, row, col);
      print_board();
      if(check_win(player)){
        printf("X wins the game!\n");
        break;
      }
      if(check_tie()){
        printf("Game is a tie!\n");
        break;
      }
    }
    else{
      printf("Computer is making a move...\n");
      int row, col;
      get_computer_move(player, &row, &col);
      make_move(player, row, col);
      print_board();
      if(check_win(player)){
        printf("O wins the game!\n");
        break;
      }
      if(check_tie()){
        printf("Game is a tie!\n");
        break;
      }
    }
    //switch the player
    if(player == 'X'){
      player = 'O';
    }
    else{
      player = 'X';
    }
  }
}

int main(){
  printf("***Welcome to Tic Tac Toe Game!***\n");
  play_tictactoe();
  return 0;
}