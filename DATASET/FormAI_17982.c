//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5

// Initialize the Bingo Board
void initialize_board(int board[ROWS][COLS]){
   for(int i=0;i<ROWS;i++){
      for(int j=0;j<COLS;j++){
         board[i][j]=0;
      }
   }
}

// Display the Bingo Board
void display_board(int board[ROWS][COLS]){
   printf("-------------------------------------------------------\n");
   printf("|    B     |     I      |     N      |     G      |     O      |\n");
   printf("-------------------------------------------------------\n");
   for(int i=0;i<ROWS;i++){
      for(int j=0;j<COLS;j++){
         if(j==0){
            printf("|    %d     ",board[i][j]);
         }
         else if(j==COLS-1){
            printf("|     %d     |\n",board[i][j]);
         }
         else{
            printf("|     %d     ",board[i][j]);
         }
      }
      printf("-------------------------------------------------------\n");
   }
}

// Generate a Random Number between Min and Max (inclusive)
int generate_random(int min,int max){
   return (rand()%(max-min+1))+min;
}

// Check if the Current Board has a Bingo
int check_bingo(int board[ROWS][COLS]){
   int i,j,flag=0;

   // Check for Horizontal Bingo
   for(i=0;i<ROWS;i++){
      flag=1;
      for(j=0;j<COLS;j++){
         if(board[i][j]==0){
            flag=0;
            break;
         }
      }
      if(flag){
         return 1;
      }
   }

   // Check for Vertical Bingo
   for(j=0;j<COLS;j++){
      flag=1;
      for(i=0;i<ROWS;i++){
         if(board[i][j]==0){
            flag=0;
            break;
         }
      }
      if(flag){
         return 1;
      }
   }

   // Check for Diagonal Bingo (Top-Left to Bottom-Right)
   flag=1;
   for(i=0;i<ROWS;i++){
      if(board[i][i]==0){
         flag=0;
         break;
      }
   }
   if(flag){
      return 1;
   }

   // Check for Diagonal Bingo (Top-Right to Bottom-Left)
   flag=1;
   for(i=0;i<ROWS;i++){
      if(board[i][COLS-i-1]==0){
         flag=0;
         break;
      }
   }
   if(flag){
      return 1;
   }

   // If no Bingo, return 0
   return 0;
}

// The Main Function
int main(){

   // Setting up Random Seed
   srand(time(0));
   
   // Initializing the Bingo Board
   int board[ROWS][COLS];
   initialize_board(board);
   display_board(board);

   // Generating the Numbers 
   int count=0,num,min=1,max=75;
   while(count<25){
      num=generate_random(min,max);
      if(board[(num-1)/COLS][(num-1)%COLS]==0){
         board[(num-1)/COLS][(num-1)%COLS]=num;
         count++;
      }
   }

   // Playing the Round of Bingo
   int bingo=0;
   printf("\nLet's play Bingo!!!\n");
   while(!bingo){
      printf("\nEnter the next number: ");
      scanf("%d",&num);
      for(int i=0;i<ROWS;i++){
         for(int j=0;j<COLS;j++){
            if(board[i][j]==num){
               board[i][j]=0;
               display_board(board);
               bingo=check_bingo(board);
               break;
            }
         }
         if(bingo){
            break;
         }
      }
   }
   printf("\nBingo!!! You won!!!");
   
   return 0;
}