//FormAI DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the table 

int table[SIZE][SIZE]; // The table array 

/* Function to print the table */
void printTable(){
  printf("\n\n"); // Two new lines for spacing 
  for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE; j++){
      printf("%d ",table[i][j]); // Print each table element 
    }
    printf("\n"); // Move to next line 
  }
  printf("\n\n"); // Two new lines for spacing 
}

/* Function to initialize the table */
void initTable(){
  srand(time(NULL)); // Seed the random number generator 

  /* Set all the table elements to 0 */
  for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE; j++){
      table[i][j] = 0;
    }
  }
  
  /* Place a random number of coins (1-10) on the table */
  int numCoins = rand() % 10 + 1;
  printf("Placing %d coins on the table...\n\n", numCoins);
  for(int i=0; i<numCoins; i++){
    int x = rand() % SIZE;
    int y = rand() % SIZE;
    table[x][y] = 1; // Place the coin 
  }
  
  printTable(); // Print the table 
}

/* Function to play the game */
void playGame(){
  int score = 0; // Player's score
  int turns = 10; // Number of turns allowed
  
  while(turns>0){
    int row,col;
    printf("Enter the row and column (0-9) to make your move: ");
    scanf("%d %d",&row,&col); // Get user input 
    while(row<0 || row>=SIZE || col<0 || col>=SIZE){
      printf("Invalid move. Enter the row and column (0-9) to make your move: ");
      scanf("%d %d",&row,&col); // Get user input 
    }
    
    if(table[row][col] == 1){
      score++; // Increase the score if the move is valid 
      table[row][col] = 0; // Remove the coin from the table 
      printf("You found a coin! Score: %d\n",score);
    }
    else{
      printf("No coin found. Score: %d\n",score);
    }
    
    turns--; // Decrease the number of turns left 
    
    printTable(); // Print the table 
  }
  
  printf("Game over. Final score: %d\n",score); // Display the final score 
}

/* Main function */
int main(){
  printf("Welcome to the Coin Hunt game!\n");
  initTable(); // Initialize the table 
  playGame(); // Play the game 
  return 0;
}