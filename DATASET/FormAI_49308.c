//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
  srand(time(NULL)); //seed the random number generator
  
  printf("Welcome to the typing speed test!\n");
  printf("Type the line you see as fast as you can.\n");
  
  int num_correct = 0;
  int num_total = 0;
  bool continue_game = true;
  
  while(continue_game) {
    char line[50];
    for(int i = 0; i < 50; i++) {
      line[i] = (char) (rand() % 26 + 97); //generate random lowercase letter
      printf("%c", line[i]); //print letter
    }
    
    printf("\nType the line: ");
    char input[50];
    fgets(input, 50, stdin); //get user input
    
    if(strcmp(input, line) == 0) { //compare input to generated line
      num_correct++;
      printf("Correct!\n");
    } else {
      printf("Incorrect.\n");
    }
    
    num_total++;
    
    printf("Type 'Q' to quit or any other key to continue.\n");
    char quit;
    scanf(" %c", &quit);
    
    if(quit == 'Q' || quit == 'q') {
      continue_game = false;
    }
  }
  
  printf("You got %d out of %d correct.\n", num_correct, num_total);
  
  return 0;
}