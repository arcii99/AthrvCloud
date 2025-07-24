//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>

int main() {
  int amount, coins[] = {50, 25, 10, 5, 1}; // set of available coins
  int numCoins[sizeof(coins) / sizeof(int)] = {0}; // array to hold the number of coins required for each coin
  printf("Enter the amount: ");
  scanf("%d", &amount); // read the amount

  int index = 0; // index for the coins array
  while (amount) {
    if (amount >= coins[index]) { // if the current coin is less than or equal to the remaining amount
      amount -= coins[index]; // subtract the coin value from the remaining amount
      numCoins[index]++; // increment the counter for the current coin
    } else {
      index++; // move to the next coin
    }
  }

  // Output the result
  if (numCoins[0] > 0 || numCoins[1] > 0) { // Output in Dollars and Cents if input is greater than/equal to 100
    printf("The minimum number of coins required to make a change of $%d.%02d is:\n", amount/100, amount%100);
    printf("%d half-dollar(s), %d quarter(s), %d dime(s), %d nickel(s), and %d penny/pennies.\n",
           numCoins[0], numCoins[1], numCoins[2], numCoins[3], numCoins[4]);
  } else if (numCoins[2] > 0 || numCoins[3] > 0 || numCoins[4] > 0) { // Output in Cents if input is less than 100
    printf("The minimum number of coins required to make a change of %d cents is:\n", amount);
    printf("%d dimes, %d nickel(s), and %d penny/pennies.\n", numCoins[2], numCoins[3], numCoins[4]);
  } else { // Output in Penny/Pennies if input is a penny
    printf("The minimum number of coins required to make a change of one penny is:\n");
    printf("%d penny/pennies.\n", numCoins[4]);
  }

  return 0;
}