//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
  srand(time(NULL)); //seeds the random function with the current time
  int num_attacks = rand() % 10 + 1; //creates a random number of potential alien attacks
  int invasion_probability = num_attacks * 10; //calculates the invasion probability based on the number of potential attacks

  printf("ALIEN INVASION PROBABILITY CALCULATOR\n");
  printf("------------------------------------\n\n");
  printf("Potential Alien Attacks: %d\n", num_attacks);
  printf("Invasion Probability: %d%%\n\n", invasion_probability);

  if(invasion_probability < 50){
    printf("Not very likely, but keep an eye on the skies!\n");
  }
  else if(invasion_probability >= 50 && invasion_probability < 80){
    printf("It's a possibility, prepare for the worst!\n");
  }
  else{
    printf("We're doomed! It's time to surrender to our alien overlords!\n");
  }

  return 0;
}