//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate a random number between 1 and 75
int get_random_number() {
   return rand() % 75 + 1;
}

//Function to check if a number is already marked in the bingo card
int is_duplicate(int selected_values[], int value) {
   for (int i=0; i<25; i++) {
      if (selected_values[i] == value) {
         return 1;
      }
   }
   return 0;
}

//Function to print the bingo card
void print_card(int card[5][5], int selected_values[]) {
   printf("\n\n");
   for (int i=0; i<5; i++) {
      for (int j=0; j<5; j++) {
         if (selected_values[card[i][j]-1] == 1) {
            printf("| X ");
         } else {
            printf("| %d ", card[i][j]);
         }
      }
      printf("|\n");
   }
}

//Function to check if the player has won
int check_win(int selected_values[]) {
   int rows[5] = {0,0,0,0,0}, cols[5] = {0,0,0,0,0}, diag1 = 0, diag2 = 0;
   for (int i=0; i<5; i++) {
      for (int j=0; j<5; j++) {
         if (selected_values[i*5+j] == 1) {
            rows[i]++;
            cols[j]++;
            if (i == j) {
               diag1++;
            }
            if (i+j == 4) {
               diag2++;
            }
         }
      }
   }
   for (int i=0; i<5; i++) {
      if (rows[i] == 5) {
         return 1; //row bingo
      }
      if (cols[i] == 5) {
         return 1; //column bingo
      }
   }
   if (diag1 == 5 || diag2 == 5) {
      return 1; //diagonal bingo
   }
   return 0; //no bingo
}

int main() {
   int card[5][5] = {0}, selected_values[25] = {0};
   srand(time(NULL)); //initialize random seed
   printf("Welcome to Bingo Simulator!\n");
   printf("Press ENTER to generate a Bingo card.\n");
   getchar(); //wait for the user to press ENTER
   for (int i=0; i<5; i++) {
      for (int j=0; j<5; j++) {
         if (i == 2 && j == 2) {
            card[i][j] = 0; //mark the center cell as free
         } else {
            int value;
            do {
               value = get_random_number(); //get a random number
            } while (is_duplicate(selected_values, value) == 1); //make sure the number is not already in use
            card[i][j] = value; //assign the value to the cell
            selected_values[value-1] = 1; //mark the value as used
         }
      }
   }
   printf("Your Bingo card is ready!\n");
   print_card(card, selected_values); //print the bingo card
   printf("Press ENTER to start the game.\n");
   getchar(); //wait for the user to press ENTER
   printf("The game has begun!\n");
   int number = 0, count = 0;
   do {
      number = get_random_number(); //get a random number
      printf("The number called is: %d\n", number);
      for (int i=0; i<25; i++) {
         if (card[i/5][i%5] == number && selected_values[number-1] == 0) {
            selected_values[number-1] = 1; //mark the number as used
            count++;
            printf("You have marked %d numbers.\n", count);
            print_card(card, selected_values); //print the updated bingo card
            if (check_win(selected_values) == 1) {
               printf("BINGO!!! You have won the game in %d tries.\n", count);
               return 0; //exit the program
            }
            break;
         }
      }
   } while (1); //infinite loop until the player wins
   return 0;
}