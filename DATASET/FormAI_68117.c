//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>

/* Medieval style Greedy Algorithm */

int main() {
  int budget = 1000;  // Denars available for a knight to acquire armor and weapons
  int sword_cost = 400;
  int shield_cost = 300;
  int armor_cost = 600;
  
  int swords_bought = 0;
  int shields_bought = 0;
  int armor_bought = 0;

  while (budget > 0) {
    if (budget >= armor_cost) {
      armor_bought++;
      budget -= armor_cost;
    }
    else if (budget < armor_cost && budget >= shield_cost) {
      shields_bought++;
      budget -= shield_cost;
    }
    else if (budget < shield_cost && budget >= sword_cost) {
      swords_bought++;
      budget -= sword_cost;
    }
    else {
      break;
    }
  }

  printf("A valiant knight has acquired:\n");
  printf("%d suit(s) of armor\n", armor_bought);
  printf("%d shield(s)\n", shields_bought);
  printf("%d sword(s)\n", swords_bought);

  return 0;
}