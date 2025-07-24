//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
   int matrix[4][4], x, y, score = 0, high_score = 0, flag = 0;
   char choice;
   srand(time(0)); // seeding random number generator
   
   // initializing the matrix with zeros
   for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
         matrix[i][j] = 0;
      }
   }

   printf(" Welcome to 2048! Press 'n' to start a new game or 'r' for the rules\n");

   while(1) {
      scanf(" %c", &choice);
      
      if (choice == 'n') {
         int cnt = 0;
         
         // initializing two random positions in the matrix
         while(cnt < 2) {
            x = rand() % 4;
            y = rand() % 4;
            if (matrix[x][y] == 0) {
               matrix[x][y] = 2 * (rand() % 2 + 1);
               cnt++;
            }
         }

         // printing the matrix
         printf("\n Current matrix: \n");
         for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
               printf(" %d\t", matrix[i][j]);
            }
            printf("\n");
         }

         printf("\n Use arrow keys to move the tiles\n");

         while(1) {
            // reading arrow key input from user
            char input;
            scanf(" %c", &input);

            // moving the tiles based on user input
            if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
               switch(input) {

                  // moving upwards
                  case 'w': {

                     // loop to move numbers upwards
                     for (int i = 0; i < 4; i++) {
                        for (int j = 1; j < 4; j++) {

                           // check if present cell is not zero
                           if (matrix[j][i] != 0) {

                              // loop to move current element upwards
                              for (int k = j - 1; k >= 0; k--) {

                                 // check if previous cell is zero
                                 if (matrix[k][i] == 0) {
                                    matrix[k][i] = matrix[k + 1][i];
                                    matrix[k + 1][i] = 0;
                                 }

                                 // check if previous cell has same number
                                 else if (matrix[k][i] == matrix[k + 1][i]) {
                                    matrix[k][i] += matrix[k + 1][i];
                                    matrix[k + 1][i] = 0;
                                    score += matrix[k][i];
                                    break;
                                 }

                                 // if previous cell has different number
                                 else {
                                    break;
                                 }
                              }
                           }
                        }
                     }
                     
                     flag = 1; // setting flag to check if any move was made
                     break;
                  }

                  // moving left
                  case 'a': {

                     // loop to move numbers left
                     for (int i = 0; i < 4; i++) {
                        for (int j = 1; j < 4; j++) {

                           // check if present cell is not zero
                           if (matrix[i][j] != 0) {

                              // loop to move current element left
                              for (int k = j - 1; k >= 0; k--) {

                                 // check if previous cell is zero
                                 if (matrix[i][k] == 0) {
                                    matrix[i][k] = matrix[i][k + 1];
                                    matrix[i][k + 1] = 0;
                                 }

                                 // check if previous cell has same number
                                 else if (matrix[i][k] == matrix[i][k + 1]) {
                                    matrix[i][k] += matrix[i][k + 1];
                                    matrix[i][k + 1] = 0;
                                    score += matrix[i][k];
                                    break;
                                 }

                                 // if previous cell has different number
                                 else {
                                    break;
                                 }
                              }
                           }
                        }
                     }

                     flag = 1;
                     break;
                  }

                  // moving downwards
                  case 's': {

                     // loop to move numbers downwards
                     for (int i = 0; i < 4; i++) {
                        for (int j = 2; j >= 0; j--) {

                           // check if present cell is not zero
                           if (matrix[j][i] != 0) {

                              // loop to move current element downwards
                              for (int k = j + 1; k < 4; k++) {

                                 // check if previous cell is zero
                                 if (matrix[k][i] == 0) {
                                    matrix[k][i] = matrix[k - 1][i];
                                    matrix[k - 1][i] = 0;
                                 }

                                 // check if previous cell has same number
                                 else if (matrix[k][i] == matrix[k - 1][i]) {
                                    matrix[k][i] += matrix[k - 1][i];
                                    matrix[k - 1][i] = 0;
                                    score += matrix[k][i];
                                    break;
                                 }

                                 // if previous cell has different number
                                 else {
                                    break;
                                 }
                              }
                           }
                        }
                     }

                     flag = 1;
                     break;
                  }

                  // moving right
                  case 'd': {

                     // loop to move numbers right
                     for (int i = 0; i < 4; i++) {
                        for (int j = 2; j >= 0; j--) {

                           // check if present cell is not zero
                           if (matrix[i][j] != 0) {

                              // loop to move current element right
                              for (int k = j + 1; k < 4; k++) {

                                 // check if previous cell is zero
                                 if (matrix[i][k] == 0) {
                                    matrix[i][k] = matrix[i][k - 1];
                                    matrix[i][k - 1] = 0;
                                 }

                                 // check if previous cell has same number
                                 else if (matrix[i][k] == matrix[i][k - 1]) {
                                    matrix[i][k] += matrix[i][k - 1];
                                    matrix[i][k - 1] = 0;
                                    score += matrix[i][k];
                                    break;
                                 }

                                 // if previous cell has different number
                                 else {
                                    break;
                                 }
                              }
                           }
                        }
                     }

                     flag = 1;
                     break;
                  }

                  default:
                     break;
               }

               // add a new number in random empty position in the matrix
               if (flag == 1) {
                  flag = 0;
                  int row, col, num;
                  do {
                     row = rand() % 4;
                     col = rand() % 4;
                  } while(matrix[row][col] != 0);
                  num = 2 * (rand() % 2 + 1);
                  matrix[row][col] = num;
                  
                  // printing the updated matrix and score
                  printf("\n Current matrix: \n");
                  for (int i = 0; i < 4; i++) {
                     for (int j = 0; j < 4; j++) {
                        printf(" %d\t", matrix[i][j]);
                     }
                     printf("\n");
                  }
                  printf(" Score: %d\n", score);
                  
                  // updating the high score
                  if (score > high_score) {
                     high_score = score;
                  }
                  
                  // check if game is over
                  int game_over = 1;
                  for (int i = 0; i < 4; i++) {
                     for (int j = 0; j < 4; j++) {
                        if (matrix[i][j] == 0) {
                           game_over = 0;
                           break;
                        }
                        if (i > 0 && (matrix[i][j] == matrix[i - 1][j])) {
                           game_over = 0;
                           break;
                        }
                        if (j > 0 && (matrix[i][j] == matrix[i][j - 1])) {
                           game_over = 0;
                           break;
                        }
                     }
                     if (game_over == 0) {
                        break;
                     }
                  }
                  if (game_over == 1) {
                     printf(" Game Over!\n");
                     printf(" Your score: %d\n", score);
                     printf(" High score: %d\n", high_score);
                     return 0;
                  }
               }
            }
            else if (input == 'n') {
               break;
            }
            else if (input == 'r') {
               printf("\n The goal of the game is to combine the tiles with the same number until you reach the number 2048\n");
               printf(" You can only move the tiles using arrow keys, and all tiles are moved to their farthest position\n");
               printf(" Press 'n' to start a new game\n");
            }
            else {
               printf(" Invalid input, try again\n");
            }
         }
      }
      else if (choice == 'r') {
         printf("\n The goal of the game is to combine the tiles with the same number until you reach the number 2048\n");
         printf(" You can only move the tiles using arrow keys, and all tiles are moved to their farthest position\n");
         printf(" Press 'n' to start a new game\n");
      }
      else {
         printf(" Invalid input, try again\n");
      }
   }
   return 0;
}