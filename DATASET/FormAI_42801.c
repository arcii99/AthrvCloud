//FormAI DATASET v1.0 Category: Checkers Game ; Style: all-encompassing
#include<stdio.h>

// Checking move is valid or not
int isMoveValid(int board[][8], int xs, int ys, int xe, int ye, int player){
   
   int xdiff = xe - xs;
   int ydiff = ye - ys;
   
   // Check out of bounds move
   if(xe > 7 || xe < 0 || ye > 7 || ye < 0 || board[xs][ys] == 0)
      return 0;

   // Check if there is a piece already present at new location
   if(board[xe][ye] != 0)
      return 0;
   
   // Check if move is diagonal
   if(xdiff == ydiff)
   {
      // Check for normal move
      if(board[xs][ys] == player && (xdiff == 1 || xdiff == -1))
      {
         if(player == 1 && ys > ye)
            return 0;
         if(player == 2 && ys < ye)
            return 0;
         return 1;
      }
      // Check for jump move
      if(board[xs][ys] == player+2 && (xdiff == 2 || xdiff == -2))
      {
         int xm = xs + (xe-xs)/2;
         int ym = ys + (ye-ys)/2;
         if(board[xm][ym] != player && board[xm][ym] != player+2)
         {
            if(player == 1 && ys > ye)
               return 0;
            if(player == 2 && ys < ye)
               return 0;
            return 1;
         }
      }
   }
   return 0;
}

// Make move and return score
int makeMove(int board[][8], int xs, int ys, int xe, int ye, int player){
   int score = 0;
   int xdiff = xe - xs;
   int ydiff = ye - ys;
   
   if(isMoveValid(board, xs, ys, xe, ye, player))
   {
      // Normal move
      if(board[xs][ys] == player)
      {
         board[xs][ys] = 0;
         board[xe][ye] = player;
         return 1;
      }
      // Jump move
      if(board[xs][ys] == player+2)
      {
         int xm = xs + (xe-xs)/2;
         int ym = ys + (ye-ys)/2;
         if(board[xm][ym] != player && board[xm][ym] != player+2)
         {
            board[xs][ys] = 0;
            board[xm][ym] = 0;
            board[xe][ye] = player+2;
            score = 2;
         }
      }
   }
   return score;
}

// Print board to console
void printBoard(int board[][8])
{
   printf("\n  ---------------------------------\n");
   for(int i=0; i<8; i++)
   {
      printf("%d", 8-i);
      for(int j=0; j<8; j++)
      {
         printf("| ");
         if(board[i][j] == 0)
            printf(" ");
         else if(board[i][j] == 1)
            printf("R");
         else if(board[i][j] == 2)
            printf("B");
         else if(board[i][j] == 3)
            printf("K");
         else if(board[i][j] == 4)
            printf("Q");
      }
      printf("|");
      printf("\n  ---------------------------------\n");
   }
   printf("    A  B  C  D  E  F  G  H\n\n");
}

// Move processor
void processMove(int board[][8], int player)
{
   int moveValid = 0;
   int xs, xe, ys, ye;
   while(!moveValid)
   {
      char move[5];
      printf("Player %d's turn (e.g. C3-D4): ", player);
      scanf("%s", move);
      xs = 8-(move[1]-'0');
      xe = 8-(move[4]-'0');
      ys = move[0]-'A';
      ye = move[3]-'A';
      
      moveValid = isMoveValid(board, xs, ys, xe, ye, player);
      if(!moveValid)
         printf("Invalid move, please try again.\n");
   }
   makeMove(board, xs, ys, xe, ye, player);
}

// Determine winner
int determineWinner(int board[][8])
{
   int redCount = 0;
   int blackCount = 0;
   for(int i=0; i<8; i++)
   {
      for(int j=0; j<8; j++)
      {
         if(board[i][j] == 1 || board[i][j] == 3 || board[i][j] == 4)
            redCount++;
         if(board[i][j] == 2 || board[i][j] == 3 || board[i][j] == 4)
            blackCount++;
      }
   }
   if(redCount == 0)
      return 2;
   if(blackCount == 0)
      return 1;
   return 0;
}

// Main method
int main()
{
   int board[8][8] = {{0,1,0,1,0,1,0,1},
                      {1,0,1,0,1,0,1,0},
                      {0,1,0,1,0,1,0,1},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {2,0,2,0,2,0,2,0},
                      {0,2,0,2,0,2,0,2},
                      {2,0,2,0,2,0,2,0}};

   int player = 1;
   int winner = 0;
   while(winner == 0)
   {
      printBoard(board);
      processMove(board, player);
      if(player == 1)
         player = 2;
      else
         player = 1;
      winner = determineWinner(board);
   }
   printBoard(board);
   printf("Player %d wins!\n", winner);
   return 0;
}