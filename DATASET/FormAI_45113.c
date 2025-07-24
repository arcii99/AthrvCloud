//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>

int main() {
   int num_coins, target_amount;
   printf("Enter the number of coins available: ");
   scanf("%d", &num_coins);
   int coins[num_coins];
   printf("Enter the denominations of the coins separated by spaces: ");
   for (int i=0; i<num_coins; i++) {
      scanf("%d", &coins[i]);
   }
   printf("Enter the target amount: ");
   scanf("%d", &target_amount);
   
   int coin_count[num_coins], temp_amount=target_amount, total_coins=0;
   for (int i=0; i<num_coins; i++) {
      coin_count[i] = 0;
   }
   
   while (temp_amount > 0) {
      for (int i=num_coins-1; i>=0; i--) {
         if (temp_amount >= coins[i]) {
            coin_count[i]++;
            temp_amount -= coins[i];
            total_coins++;
            break;
         }
      }
   }
   
   printf("Minimum coins required to form the target amount: %d\n", total_coins);
   printf("Denominations used: ");
   for (int i=0; i<num_coins; i++) {
      printf("%d x %d, ", coins[i], coin_count[i]);
   }
   return 0;
}