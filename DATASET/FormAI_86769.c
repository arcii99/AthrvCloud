//FormAI DATASET v1.0 Category: Poker Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to randomly shuffle an array
void shuffle(int arr[], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int deck[52];
    int i, j, k;
    int players = 0;
    int player_hand[5], dealer_hand[5];
    int player_sum = 0, dealer_sum = 0;
    char hit_stand;

    // Initialize deck
    for (i = 0; i < 52; i++) {
        deck[i] = i + 1;
    }

    // Shuffle deck
    shuffle(deck, 52);

    // Welcome message
    printf("Welcome to the Poker Game!\n");

    // Ask user to enter number of players
    while (players < 1 || players > 5) {
        printf("How many players? (1-5): ");
        scanf("%d", &players);
    }

    // Deal cards to player and dealer
    for (i = 0; i < 2; i++) {
        for (j = 0; j < players; j++) {
            player_hand[j * 2 + i] = deck[i * players + j];
        }
        dealer_hand[i] = deck[i * players + players * 2];
    }

    // Display player's hand
    printf("Player's hand:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", player_hand[i]);
    }
    printf("\n");

    // Prompt user to hit or stand
    printf("Hit or stand? (h/s): ");
    scanf(" %c", &hit_stand);

    // Process hit or stand
    if (hit_stand == 'h') {
        // Deal another card
        player_hand[2] = deck[players * 2 + 2];
    }

    // Display player's hand again
    printf("Player's hand:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", player_hand[i]);
    }
    printf("\n");

    // Calculate player's sum
    for (i = 0; i < 5; i++) {
        j = player_hand[i] % 13;
        if (j == 0) {
            j = 13;
        }
        if (j > 10) {
            j = 10;
        }
        player_sum += j;
    }

    // Calculate dealer's sum
    j = dealer_hand[0] % 13;
    if (j == 0) {
        j = 13;
    }
    if (j > 10) {
        j = 10;
    }
    dealer_sum += j;
    j = dealer_hand[1] % 13;
    if (j == 0) {
        j = 13;
    }
    if (j > 10) {
        j = 10;
    }
    dealer_sum += j;

    // Display dealer's hand
    printf("Dealer's hand:\n");
    printf("%d %d\n", dealer_hand[0], dealer_hand[1]);

    // Dealer's turn
    while (dealer_sum < 17) {
        dealer_hand[2] = deck[players * 2 + 3];
        j = dealer_hand[2] % 13;
        if (j == 0) {
            j = 13;
        }
        if (j > 10) {
            j = 10;
        }
        dealer_sum += j;
    }

    // Display dealer's hand again
    printf("Dealer's hand:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", dealer_hand[i]);
    }
    printf("\n");

    // Compare sums and display winner
    if (player_sum > dealer_sum && player_sum <= 21) {
        printf("Player wins!\n");
    } else if (dealer_sum > player_sum && dealer_sum <= 21) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}