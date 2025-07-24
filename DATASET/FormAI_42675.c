//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(NULL));
  int probability = rand() % 101;
  if(probability <= 25){
    printf("The probability of an alien invasion is low.\n");
  }
  else if(probability > 25 && probability <= 75){
    printf("The probability of an alien invasion is moderate.\n");
  }
  else{
    printf("The probability of an alien invasion is high!\n");
  }
  return 0;
}