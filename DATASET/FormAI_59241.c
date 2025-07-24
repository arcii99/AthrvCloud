//FormAI DATASET v1.0 Category: Table Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int balance = 1000;
   int bet = 0;

   while (balance > 0) {
      printf("\nCurrent balance: $%d", balance);
      printf("\nEnter your bet amount: $");
      scanf("%d", &bet);

      if (bet > balance) {
         printf("\nSorry, you do not have enough funds to make that bet.\n");
         continue;
      } else if (bet == 0) {
         printf("\nGoodbye!\n");
         break;
      }

      balance -= bet;
      printf("\nRolling dice...");

      srand(time(0));
      int dice1 = rand() % 6 + 1;
      int dice2 = rand() % 6 + 1;
      int sum = dice1 + dice2;

      printf("\nYou rolled a %d and a %d, for a total of %d.\n", dice1, dice2, sum);

      if (sum == 7) {
         balance += bet * 2;
         printf("\nCongratulations! You won $%d!\n", bet * 2);
      } else {
         printf("\nSorry, you lost $%d.\n", bet);
      }
   }

   printf("\nGame over. Final balance: $%d\n", balance);
   return 0;
}