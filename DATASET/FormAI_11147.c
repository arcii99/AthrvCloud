//FormAI DATASET v1.0 Category: Poker Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int deck[52];
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int player_hand[5], dealer_hand[5];
    int player_score = 0, dealer_score = 0;
    char play_again = 'y';

    srand(time(NULL));

    while (play_again == 'y') {
        printf("Dealing cards...\n");
        //initialize deck
        for (int i = 0; i < 52; i++) {
            deck[i] = i;
        }
        //shuffle deck
        for (int i = 0; i < 52; i++) {
            int j = rand() % 52;
            int temp = deck[i];
            deck[i] = deck[j];
            deck[j] = temp;
        }
        //deal initial hands for player and dealer
        for (int i = 0; i < 5; i++) {
            player_hand[i] = deck[i * 2];
            dealer_hand[i] = deck[i * 2 + 1];
        }
        //calculate scores
        for (int i = 0; i < 5; i++) {
            int player_card_value = player_hand[i] % 13;
            if (player_card_value > 9) {
                player_card_value = 10;
            } else if (player_card_value == 0) {
                player_card_value = 11;
            } else {
                player_card_value++;
            }
            player_score += player_card_value;

            int dealer_card_value = dealer_hand[i] % 13;
            if (dealer_card_value > 9) {
                dealer_card_value = 10;
            } else if (dealer_card_value == 0) {
                dealer_card_value = 11;
            } else {
                dealer_card_value++;
            }
            dealer_score += dealer_card_value;
        }
        printf("\nYour hand:\n");
        for (int i = 0; i < 5; i++) {
            printf("%s of %s\n", faces[player_hand[i] % 13], suits[player_hand[i] / 13]);
        }
        printf("\nDealer's hand:\n");
        printf("%s of %s\n", faces[dealer_hand[0] % 13], suits[dealer_hand[0] / 13]);
        printf("Unknown card\n\n");
        //player's turn
        int player_stay = 0;
        while (!player_stay) {
            printf("Hit or stay? (h/s)");
            char choice;
            scanf("%c", &choice);
            if (choice == 'h') {
                int new_card = deck[5 + player_stay];
                player_hand[player_stay] = new_card;
                int new_card_value = new_card % 13;
                if (new_card_value > 9) {
                    new_card_value = 10;
                } else if (new_card_value == 0) {
                    new_card_value = 11;
                } else {
                    new_card_value++;
                }
                player_score += new_card_value;
                player_stay++;
                printf("\nYour hand:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%s of %s\n", faces[player_hand[i] % 13], suits[player_hand[i] / 13]);
                }
                printf("\nDealer's hand:\n");
                printf("%s of %s\n", faces[dealer_hand[0] % 13], suits[dealer_hand[0] / 13]);
                printf("Unknown card\n\n");
                if (player_stay == 5) {
                    printf("You reached the maximum number of cards. Your turn is over.\n\n");
                    player_stay = 1;
                }
            } else if (choice == 's') {
                printf("\nYour turn is over.\n");
                player_stay = 1;
                printf("\nDealer's turn.\n");
            } else {
                printf("\nInvalid choice. Please type h for hit or s for stay.\n");
            }
            fflush(stdin);
        }
        //dealer's turn
        while (dealer_score <= player_score && dealer_score < 21) {
            int new_card = deck[10 + dealer_score % 5];
            dealer_hand[dealer_score % 5] = new_card;
            int new_card_value = new_card % 13;
            if (new_card_value > 9) {
                new_card_value = 10;
            } else if (new_card_value == 0) {
                new_card_value = 11;
            } else {
                new_card_value++;
            }
            dealer_score += new_card_value;
            printf("\nDealer hits.\n");
            printf("Dealer's new card: %s of %s\n", faces[new_card % 13], suits[new_card / 13]);
        }
        if (dealer_score > 21) {
            printf("\nThe dealer busts! You win!\n");
        } else if (dealer_score > player_score) {
            printf("\nThe dealer wins with a score of %d to %d.\n", dealer_score, player_score);
        } else {
            printf("\nYou win with a score of %d to %d!\n", player_score, dealer_score);
        }
        printf("Play again? (y/n)");
        scanf(" %c", &play_again);
        player_score = 0;
        dealer_score = 0;
    }
    return 0;
}