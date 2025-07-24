//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: immersive
#include <stdio.h>

/*This program uses greedy algorithms to solve the classic "Coin Change" problem
Suppose we have an unlimited number of coins of denominations 1, 5, 10, 25, 50.
Given a certain amount of change, this program will output the minimum number of coins needed to make that change.*/

int main(){

  int change, coins = 0;

  printf("Enter the amount of change required (in cents): ");
  scanf("%d", &change);

  while(change > 0){

    if(change >= 50){
      change -= 50;
      coins++;
    }
    else if(change >= 25){
      change -= 25;
      coins++;
    }
    else if(change >= 10){
      change -= 10;
      coins++;
    }
    else if(change >= 5){
      change -= 5;
      coins++;
    }
    else{
      change -= 1;
      coins++;
    }
  }

  printf("\nMinimum number of coins required = %d\n", coins);

  return 0;
}