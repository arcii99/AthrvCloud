//FormAI DATASET v1.0 Category: Stock market tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

printf("Welcome to the Wacky Stock Market Tracker!\n");
printf("Where the numbers don't matter and the money is fake!\n");

int current_price = rand() % 100 + 1;
int previous_price = rand() % 100 + 1;

printf("\nThe current price of Wacky Inc. is: $%d", current_price);
printf("\nThe previous price of Wacky Inc. was: $%d", previous_price);

if (current_price > previous_price) {
    printf("\nWowzers, the price went up! Buy, buy, buy!");
} else if (current_price < previous_price) {
    printf("\nOh no! The price went down. Sell, sell, sell!");
} else {
    printf("\nMeh. The price hasn't changed much. Do whatever you want, no one really knows what they're doing anyway.");
}

printf("\n\nDisclaimer: The Wacky Stock Market Tracker is not responsible for any financial ruin caused by following its advice.");
printf("\nRemember, it's all just a game and none of this is real money.");

return 0;

}