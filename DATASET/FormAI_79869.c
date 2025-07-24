//FormAI DATASET v1.0 Category: Poker Game ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    // Initialize deck of cards
    int cards[52] = {1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10};
    int player_total = 0;

    // Randomize the deck
    srand(time(NULL));
    for (int i = 0; i < 52 - 1; i++) {
        int j = i + rand() / (RAND_MAX / (52 - i) + 1);
        int temp = cards[j];
        cards[j] = cards[i];
        cards[i] = temp;
    }

    // Dealing the cards
    printf("Your cards:\n");
    for (int i = 0; i < 2; i++) {
        player_total += cards[i];
        printf("%d\n", cards[i]);
    }

    // Player's turn
    char choice = 'y';
    int index = 2;
    while (choice == 'y') {
        printf("Do you want another card? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
        player_total += cards[index];
        printf("Your card: %d\n", cards[index]);
        index++;
        printf("Your total: %d\n", player_total);
    }

    // Dealer's turn
    int dealer_total = 0;
    printf("\nDealer's cards:\n");
    for (int i = index; i < index + 2; i++) {
        dealer_total += cards[i];
        printf("%d\n", cards[i]);
    }
    while (dealer_total < 17) {
        dealer_total += cards[index];
        index++;
    }

    // Determine winner
    printf("\nYour total: %d", player_total);
    printf("\nDealer's total: %d", dealer_total);
    if (player_total > dealer_total) {
        printf("\nYou win!");
    } else if (dealer_total > player_total) {
        printf("\nDealer wins.");
    } else {
        printf("\nIt's a tie.");
    }

    return 0;
}