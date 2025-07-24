//FormAI DATASET v1.0 Category: Stock market tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  float stock1 = 10.5;
  float stock2 = 20.0;
  float stock3 = 15.75;
  float stock4 = 8.25;
  float stock5 = 12.5;

  srand(time(NULL));

  printf("********** STOCK TRACKER **********\n");

  int i;
  for(i = 0; i < 10; i++) {
    int change1 = rand() % 21 - 10;
    int change2 = rand() % 21 - 10;
    int change3 = rand() % 21 - 10;
    int change4 = rand() % 21 - 10;
    int change5 = rand() % 21 - 10;

    stock1 += (float)change1 / 10.0;
    stock2 += (float)change2 / 10.0;
    stock3 += (float)change3 / 10.0;
    stock4 += (float)change4 / 10.0;
    stock5 += (float)change5 / 10.0;

    printf("\n\n**** DAY %d ****\n", i+1);
    printf("STOCK 1: %.2f (%c%.2f)\n", stock1, change1 >= 0 ? '+' : '-', abs(change1) / 10.0);
    printf("STOCK 2: %.2f (%c%.2f)\n", stock2, change2 >= 0 ? '+' : '-', abs(change2) / 10.0);
    printf("STOCK 3: %.2f (%c%.2f)\n", stock3, change3 >= 0 ? '+' : '-', abs(change3) / 10.0);
    printf("STOCK 4: %.2f (%c%.2f)\n", stock4, change4 >= 0 ? '+' : '-', abs(change4) / 10.0);
    printf("STOCK 5: %.2f (%c%.2f)\n", stock5, change5 >= 0 ? '+' : '-', abs(change5) / 10.0);
  }

  printf("\n\n********** FINAL STOCK PRICES **********\n");
  printf("STOCK 1: %.2f\n", stock1);
  printf("STOCK 2: %.2f\n", stock2);
  printf("STOCK 3: %.2f\n", stock3);
  printf("STOCK 4: %.2f\n", stock4);
  printf("STOCK 5: %.2f\n", stock5);

  return 0;
}