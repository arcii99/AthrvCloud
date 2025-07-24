//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include<stdio.h>
#include<stdlib.h>

int main() {
  
  int n, i, j, temp, count = 0;   // initialize the variables 
  printf("Enter the number of coins: ");
  scanf("%d", &n);   //input the number of coins

  int coin_value[n];
  printf("Enter the coin values (in cents) in decreasing order: ");
  for(i = 0; i < n; i++) {
    scanf("%d", &coin_value[i]);   //input the coin values in decreasing order
  }

  int change, coins_used[n], total_coins = 0;   // initialize other variables
  printf("Enter the amount of change required (in cents): ");
  scanf("%d", &change);    //input the change required

  for(i = 0; i < n; i++) {
    coins_used[i] = 0;   //initialize the coins used
  }

  printf("\n");

  while(change != 0) {
    for(i = 0; i < n; i++) {
      if(change >= coin_value[i] && coins_used[i] == 0) {   // check if the change is greater than the coin value and the coin is not already used
        coins_used[i] = 1;   //mark the coin as used
        count++;     //increase count of coins used
        change -= coin_value[i];   //subtract the value of coin from the change
        break;    //exit the loop
      }
    }
  }

  printf("Coins used:\n");

  for(i = 0; i < n; i++) {
    if(coins_used[i] == 1) {
      printf("%d cents\n", coin_value[i]);   //print the coins used
      total_coins++;   //increase the count of total coins used
    }
  }

  printf("\nTotal coins used: %d\n", total_coins);
  
  return 0;    // program executed successfully
}