//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

int main() {
  // Print out a curious message to the user
  printf("Welcome to the C Pattern printing program! Are you ready to see some crazy patterns?!");

  // Declare some variables to hold user input
  int rows, cols;

  // Ask the user for input and scan it in
  printf("\n\nHow many rows do you want in your pattern? ");
  scanf("%d", &rows);

  // Ask for column input and scan it in
  printf("How many columns do you want in your pattern? ");
  scanf("%d", &cols);

  // Print out the user's chosen pattern
  printf("\n\nBehold, your chosen pattern:\n\n");

  // Use a loop to print out the pattern
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      // If i OR j is less than half the number of rows, print an X
      if (i < rows / 2 || j < cols / 2) {
        printf("X ");
      }
      // If i AND j are greater than half the number of rows, print an O
      else if (i >= rows / 2 && j >= cols / 2) {
        printf("O ");
      }
      // Otherwise, print a dash
      else {
        printf("- ");
      }
    }
    // Print out a new line at the end of each row
    printf("\n");
  }

  // Now we're done! Print out a concluding message
  printf("\n\nThanks for trying out the C Pattern printing program. I hope you enjoyed the patterns!");
  
  // Indicate successful execution of the program
  return 0;
}