//FormAI DATASET v1.0 Category: Table Game ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to display the current state of the board
void displayBoard(char board[][3]){
   printf("\n-------------\n");
   for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
         printf("| %c ", board[i][j]);
      }
      printf("|\n-------------\n");
   }
}

// Function that checks if the game is over
int isGameOver(char board[][3]){
   //check horizontal
   for (int i = 0; i < 3; i++){
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
         return 1;
      }
   }
   //check vertical
   for (int i = 0; i < 3; i++){
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '){
         return 1;
      }
   }
   //check diagonal
   if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
      return 1;
   }
   if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '){
      return 1;
   }
   //check if the board is full
   for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
         if (board[i][j] == ' '){
            return 0;
         }
      }
   }
   //if none of the above cases are true, the game is not over
   return -1;
}

// Function that allows the player to make a move
void playerMove(char board[][3]){
   while(1){
      int row,col;
      printf("Enter row and column (1-3): ");
      scanf("%d%d", &row, &col);
      if(board[row-1][col-1]==' '){
         board[row-1][col-1]='X';
         break;
      }
      printf("Invalid move. Please try again.\n");
   }
}

// Function that allows the computer to make a move
void computerMove(char board[][3]){
   while(1){
      int row=rand()%3;
      int col=rand()%3;
      if(board[row][col]==' '){
         board[row][col]='O';
         break;
      }
   }
}

// Function that plays one round of the game
void play(char board[][3], int* playerScore, int* computerScore){
   displayBoard(board);
   playerMove(board);
   if(isGameOver(board)==1){
      printf("\nYou win!\n");
      (*playerScore)++;
      return;
   }
   else if(isGameOver(board)==0){
      printf("\nIt's the computer's turn.\n");
      computerMove(board);
      if(isGameOver(board)==1){
         printf("\nYou lose!\n");
         (*computerScore)++;
         return;
      }
   }
   else{
      printf("\nDraw!\n");
      return;
   }
}

// Function that starts the game
void startGame(){
   char board[3][3];
   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         board[i][j]=' ';
      }
   }
   int playerScore=0;
   int computerScore=0;
   while(1){
      play(board, &playerScore, &computerScore);
      printf("Player score: %d\n", playerScore);
      printf("Computer score: %d\n", computerScore);
      printf("\nDo you want to play again? (y/n): ");
      char playAgain;
      scanf(" %c", &playAgain);
      if(playAgain!='y'){
         break;
      }
      //reset the board
      for(int i=0;i<3;i++){
         for(int j=0;j<3;j++){
            board[i][j]=' ';
         }
      }
   }
}

// Main function
int main(){
   srand(time(NULL));
   printf("Welcome to the C Table Game!\n");
   printf("You will be playing against the computer. Good luck!\n\n");
   startGame();
   return 0;
}