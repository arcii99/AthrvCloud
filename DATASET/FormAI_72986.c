//FormAI DATASET v1.0 Category: Checkers Game ; Style: mind-bending
#include <stdio.h>

int main() {
  // Initializing variables and arrays
  int board[8][8];
  int player = 1;
  int piece;
  int x1, y1, x2, y2;
  int i,j;

  // Setting up initial board configuration
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      if(i % 2 == 0){
        if(j % 2 == 0){
          board[i][j] = 0;
        }
        else{
          board[i][j] = 1;
        }
      }
      else{
        if(j % 2 == 0){
          board[i][j] = 1;
        }
        else{
          board[i][j] = 0;
        }
      }
      if(i < 3){
        if(board[i][j] == 1){
          board[i][j] = 2;
        }
      }
      if(i > 4){
        if(board[i][j] == 1){
          board[i][j] = 3;
        }
      }
    }
  }

  // Printing initial board configuration
  printf("Initial Board Configuration:\n");
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      printf("%d ",board[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Game loop
  while(1){
    // Printing current player and asking for input
    printf("Player %d's Turn:\n",player);
    printf("Enter the x and y coordinates of the piece to move:\n");
    scanf("%d %d",&x1,&y1);
    printf("Enter the x and y coordinates of the destination:\n");
    scanf("%d %d",&x2,&y2);

    // Checking if move is valid
    if(board[x1][y1] == player || board[x1][y1] == player + 2){
      if(board[x2][y2] == 0){
        if(abs(x1-x2) == 1 && abs(y1-y2) == 1){
          piece = board[x1][y1];
          board[x1][y1] = 0;
          board[x2][y2] = piece;
        }
        else if(abs(x1-x2) == 2 && abs(y1-y2) == 2){
          if(board[(x1+x2)/2][(y1+y2)/2] == 3-player){
            piece = board[x1][y1];
            board[x1][y1] = 0;
            board[x2][y2] = piece;
            board[(x1+x2)/2][(y1+y2)/2] = 0;
          }
          else{
            printf("Invalid Move!\n");
            continue;
          }
        }
        else{
          printf("Invalid Move!\n");
          continue;
        }       
      }
      else{
        printf("Invalid Move!\n");
        continue;
      }
    }
    else{
      printf("Invalid Piece!\n");
      continue;
    }

    // Printing updated board configuration
    printf("Updated Board Configuration:\n");
    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
        printf("%d ",board[i][j]);
      }
      printf("\n");
    }
    printf("\n");

    // Checking if game is over
    int p1 = 0;
    int p2 = 0;
    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
        if(board[i][j] == 1 || board[i][j] == 2){
          p1++;
        }
        else if(board[i][j] == 3 || board[i][j] == 4){
          p2++;
        }
      }
    }
    if(p1 == 0){
      printf("Player 2 Wins!\n");
      break;
    }
    else if(p2 == 0){
      printf("Player 1 Wins!\n");
      break;
    }

    // Switching players
    player = 3 - player;
  }
  
  return 0;
}