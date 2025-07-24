//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //Seed for random numbers

  printf("Welcome to the Airport Baggage Handling Simulation!\n\n");

  int bags_landed = rand() % 31 + 20; //Random number of bags between 20-50
  int bags_handled = 0;
  int conveyor_full = 0;
  int bags_on_conveyor = 0;
  
  while (bags_handled < bags_landed) {
    int new_bags = rand() % 11; //Random number of new bags between 0-10
    
    //Add new bags to conveyor
    if (bags_on_conveyor + new_bags > 20) {
      printf("Conveyor is full!\n");
      conveyor_full = 1;
    } else {
      printf("%d bags landed.\n%d new bags added to conveyor.\n", bags_landed, new_bags);
      bags_on_conveyor += new_bags;
    }
    
    //Handle bags on conveyor
    if (bags_on_conveyor > 0 && !conveyor_full) {
      int bags_handled_now = rand() % (bags_on_conveyor + 1);
      printf("%d bags handled.\n", bags_handled_now);
      bags_handled += bags_handled_now;
      bags_on_conveyor -= bags_handled_now;
    }
    
    //Check if all bags have been handled
    if (bags_handled == bags_landed) {
      printf("All bags have been handled. Simulation over.\n");
    }
  }
  
  return 0;
}