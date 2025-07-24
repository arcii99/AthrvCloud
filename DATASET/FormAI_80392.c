//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: minimalist
#include <stdio.h>

void print_grid(char grid[3][3]){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      printf("%c | ", grid[i][j]);
    }
    printf("\n----------\n");
  }
}

char check_winner(char grid[3][3]){
  for(int i=0;i<3;i++){
    if(grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2]){
      return grid[i][0];
    }
    if(grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i]){
      return grid[0][i];
    }
  }
  if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]){
    return grid[0][0];
  }
  if(grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0]){
    return grid[0][2];
  }
  return ' ';
}

int get_move(char grid[3][3], char player){
  printf("Player %c's turn. Please enter row and column (separated by a space): ", player);
  int row, col;
  scanf("%d %d", &row, &col);
  if(grid[row][col]!=' '){
    printf("Position is already taken. Please choose another position.\n");
    return get_move(grid, player);
  }
  grid[row][col] = player;
  return 0;
}

int get_random_move(char grid[3][3]){
  int row, col;
  do{
    row = rand()%3;
    col = rand()%3;
  }while(grid[row][col]!=' ');
  grid[row][col] = 'O';
  return 0;
}

int main(){
  char grid[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
  };
  printf("Welcome to Tic Tac Toe!\n");
  printf("Instructions: Please enter the row and column number that you want to place your mark. The grid is numbered from 0 to 2.\n");
  printf("Here is the initial grid:\n");
  
  print_grid(grid);
  
  while(check_winner(grid)==' '){
    get_move(grid, 'X');
    print_grid(grid);
    
    if(check_winner(grid)!=' '){
      break;
    }
    
    printf("AI's turn:\n");
    get_random_move(grid);
    print_grid(grid);  
  } 
  
  char winner = check_winner(grid);
  printf("Game over. ");
  if(winner=='X'){
    printf("You win!\n");
  }else if(winner=='O'){
    printf("AI wins!\n");
  }else{
    printf("It is a tie!\n");
  }

  return 0;
}