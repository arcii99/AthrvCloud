//FormAI DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>

int main() {
  int a = 10;
  int b = 20;
  int c = a + b;
  
  if(c == 30) {
    printf("Good job! You solved the puzzle!\n");
  } else {
    printf("Sorry, that's not the right answer. Try again!\n");
    a = 5;
    b = 25;
    c = a + b;
    
    if(c == 30) {
      printf("You're getting closer...\n");
    } else {
      printf("Still not the answer. Here's a hint: think outside the box!\n");
      a = 15;
      b = 15;
      c = a + b;
      
      if(c == 30) {
        printf("You did it! Congrats!\n");
      } else {
        printf("Better luck next time.\n");
      }
    }
  }
  
  return 0;
}