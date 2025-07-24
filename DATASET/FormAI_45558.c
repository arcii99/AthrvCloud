//FormAI DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

// function to calculate the score of the player based on their hand
int calculateScore(int* hand, int size) {
    int sum_of_cards = 0;
    int aces_count = 0;

    for (int i = 0; i < size; i++) {
        if (hand[i] == 1) {
            aces_count++;
        }
        sum_of_cards += fmin(hand[i], 10); // all face cards have a value of 10
    }

    while (aces_count > 0 && sum_of_cards + 10 <= 21) {
        sum_of_cards += 10;
        aces_count--;
    }

    return sum_of_cards;
}

int main() {
    int deck[52] = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,
                    7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10};

    int player_hand[10];
    int dealer_hand[10];

    int player_score = 0;
    int dealer_score = 0;

    int player_hand_size = 0;
    int dealer_hand_size = 0;

    char choice;

    srand(time(NULL)); // seeding the random number generator

    // shuffling the deck
    for (int i = 0; i < 52; i++) {
        int random_index = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[random_index];
        deck[random_index] = temp;
    }

    // initial deal
    player_hand[player_hand_size++] = deck[0];
    dealer_hand[dealer_hand_size++] = deck[1];
    player_hand[player_hand_size++] = deck[2];
    dealer_hand[dealer_hand_size++] = deck[3];

    player_score = calculateScore(player_hand, player_hand_size);
    dealer_score = calculateScore(dealer_hand, dealer_hand_size);

    // displaying initial hand
    printf("Your hand: [%d, %d]\n", player_hand[0], player_hand[1]);
    printf("Dealer's up card: [%d]\n", dealer_hand[0]);

    // player's turn
    while (1) {
        printf("Enter 'H' to hit and 'S' to stand: ");
        scanf(" %c", &choice);
        if (choice == 'H') {
            player_hand[player_hand_size++] = deck[player_hand_size + dealer_hand_size - 1];
            player_score = calculateScore(player_hand, player_hand_size);
            printf("Your hand: [");
            for (int i = 0; i < player_hand_size; i++) {
                printf("%d", player_hand[i]);
                if (i != player_hand_size - 1) {
                    printf(", ");
                }
            }
            printf("]\n");
            if (player_score > 21) {
                printf("Busted! Your score is %d\n", player_score);
                printf("Dealer wins!\n");
                return 0;
            }
        }
        else if (choice == 'S') {
            break;
        }
    }

    // dealer's turn
    while (dealer_score < 17) {
        dealer_hand[dealer_hand_size++] = deck[player_hand_size + dealer_hand_size - 1];
        dealer_score = calculateScore(dealer_hand, dealer_hand_size);
    }

    printf("Your score: %d\n", player_score);
    printf("Dealer's score: %d\n", dealer_score);

    if (dealer_score > 21) {
        printf("Dealer busted! You win!\n");
    }
    else if (player_score > dealer_score) {
        printf("You win!\n");
    }
    else if (dealer_score > player_score) {
        printf("Dealer wins!\n");
    }
    else {
        printf("It's a tie!\n");
    }

    return 0;
}