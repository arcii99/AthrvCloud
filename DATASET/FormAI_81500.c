//FormAI DATASET v1.0 Category: Scientific ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x = 69;
  printf("I like my integers like I like my jokes: %d\n", x);
  
  float pi = 3.14;
  printf("Pi is approximately %f, but who's counting?\n", pi);
  
  char response;
  printf("Are you laughing yet? (y/n): ");
  scanf("%c", &response);
  if(response == 'y') {
    printf("Great, you must be a programmer with a sense of humor.\n");
  }
  else {
    printf("Ah, a tough crowd. I'll need to work on my material.\n");
  }
  
  double e = 2.71828;
  printf("Euler's Number is %lf, but I'm not good at calculus so I just use it for comedic effect.\n", e);
  
  unsigned int punchline = rand() % 10 + 1;
  printf("Are you ready for the punchline? Here it is: %d\n", punchline);
  
  return 0;
}