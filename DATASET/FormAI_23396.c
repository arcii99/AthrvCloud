//FormAI DATASET v1.0 Category: Poker Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a deck of cards */
void generateDeck(int deck[]) {
    int card, suit;
    int index = 0;

    /* Loop through each suit */
    for (suit = 0; suit < 4; suit++) {
        /* Loop through each card */
        for (card = 1; card <= 13; card++) {
            deck[index] = card;
            index++;
        }
    }
}

/* Function to shuffle the deck */
void shuffleDeck(int deck[]) {
    int i, j, temp;

    /* Use current time as seed for random number generator */
    srand(time(0));

    /* Loop through deck, swapping each card with a random card */
    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

/* Function to print the current hand of cards */
void printHand(int hand[], int num_cards) {
    int i;

    printf("Your hand:\n");

    /* Loop through hand, printing each card */
    for (i = 0; i < num_cards; i++) {
        switch(hand[i]) {
            case 1:
                printf("Ace\n");
                break;
            case 11:
                printf("Jack\n");
                break;
            case 12:
                printf("Queen\n");
                break;
            case 13:
                printf("King\n");
                break;
            default:
                printf("%d\n", hand[i]);
                break;
        }
    }
}

/* Function to determine the value of a hand */
int handValue(int hand[], int num_cards) {
    int i;
    int value = 0;
    int num_aces = 0;

    /* Loop through hand, adding up the value of each card */
    for (i = 0; i < num_cards; i++) {
        if (hand[i] == 1) {
            /* Ace can be 1 or 11, so count the number of aces in the hand */
            num_aces++;
            value += 11;
        }
        else if (hand[i] >= 11) {
            /* Face cards are worth 10 */
            value += 10;
        }
        else {
            /* Number cards are worth their face value */
            value += hand[i];
        }
    }

    /* If the value of the hand is greater than 21 and there are aces in the hand */
    /* count each ace as 1 instead of 11 to see if that gives a hand value of 21 or less */
    while (value > 21 && num_aces > 0) {
        num_aces--;
        value -= 10;
    }

    return value;
}

int main() {
    int deck[52];
    int player_hand[10];
    int dealer_hand[10];
    int num_player_cards = 0;
    int num_dealer_cards = 0;
    char input[10];
    int player_value, dealer_value;

    /* Generate and shuffle the deck */
    generateDeck(deck);
    shuffleDeck(deck);

    /* Deal the first two cards to the player and dealer */
    player_hand[num_player_cards] = deck[0];
    num_player_cards++;
    dealer_hand[num_dealer_cards] = deck[1];
    num_dealer_cards++;
    player_hand[num_player_cards] = deck[2];
    num_player_cards++;
    dealer_hand[num_dealer_cards] = deck[3];
    num_dealer_cards++;

    /* Print out the player's hand */
    printHand(player_hand, num_player_cards);

    /* If the player's hand is already 21, then there's no need to do anything else */
    player_value = handValue(player_hand, num_player_cards);
    if (player_value == 21) {
        printf("Blackjack! You win!\n");
        return 0;
    }

    /* Ask the player if they want to hit or stand */
    while (player_value < 21) {
        printf("Do you want to hit or stand? ");
        scanf("%s", input);

        if (strcmp(input, "hit") == 0) {
            /* Deal another card to the player */
            player_hand[num_player_cards] = deck[num_player_cards + num_dealer_cards];
            num_player_cards++;

            /* Print out the player's hand */
            printHand(player_hand, num_player_cards);

            /* Determine the value of the player's hand */
            player_value = handValue(player_hand, num_player_cards);
        }
        else if (strcmp(input, "stand") == 0) {
            /* Player chooses to stand, so now the dealer plays */
            printf("Dealer's turn:\n");

            /* Print out the dealer's hand */
            printHand(dealer_hand, num_dealer_cards);

            /* Determine the value of the dealer's hand */
            dealer_value = handValue(dealer_hand, num_dealer_cards);

            /* Dealer must hit while their hand value is less than 17 */
            while (dealer_value < 17) {
                /* Deal another card to the dealer */
                dealer_hand[num_dealer_cards] = deck[num_player_cards + num_dealer_cards];
                num_dealer_cards++;

                /* Print out the dealer's hand */
                printHand(dealer_hand, num_dealer_cards);

                /* Determine the value of the dealer's hand */
                dealer_value = handValue(dealer_hand, num_dealer_cards);
            }

            /* Compare the player's hand value to the dealer's hand value */
            if (dealer_value > 21) {
                printf("Dealer busts, you win!\n");
            }
            else if (dealer_value > player_value) {
                printf("Dealer wins!\n");
            }
            else if (dealer_value == player_value) {
                printf("Push!\n");
            }
            else {
                printf("You win!\n");
            }

            return 0;
        }
        else {
            printf("Invalid input, please enter 'hit' or 'stand'\n");
        }
    }

    /* If the player's hand value is greater than 21, they bust */
    printf("Bust! You lose!\n");

    return 0;
}