//FormAI DATASET v1.0 Category: Poker Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {hearts, diamonds, clubs, spades} Suit;
typedef struct Card {
    Suit suit;
    int value;
} Card;

void shuffle(Card deck[]);
void deal(Card deck[], int player_hand[], int dealer_hand[], int deck_index);
void display_hand(int hand[]);
int check_score(int hand[]);
void hit(Card deck[], int hand[], int *deck_index);

int main() {
    // Create a deck of cards
    Card deck[52];
    for (int i = 0; i < 13; i++) {
        deck[i].suit = hearts;
        deck[i].value = i + 1;
    }
    for (int i = 13; i < 26; i++) {
        deck[i].suit = diamonds;
        deck[i].value = i - 12;
    }
    for (int i = 26; i < 39; i++) {
        deck[i].suit = clubs;
        deck[i].value = i - 25;
    }
    for (int i = 39; i < 52; i++) {
        deck[i].suit = spades;
        deck[i].value = i - 38;
    }

    // Shuffle the deck
    srand(time(0));
    shuffle(deck);

    // Deal the cards
    int player_hand[5] = {0};
    int dealer_hand[5] = {0};
    int deck_index = 0;
    deal(deck, player_hand, dealer_hand, deck_index);

    // Display the hands
    printf("Player's hand:\n");
    display_hand(player_hand);
    printf("\n");
    printf("Dealer's hand:\n");
    display_hand(dealer_hand);
    printf("\n");

    // Player's turn
    printf("Player, it's your turn!\n");
    int score = check_score(player_hand);
    while (score < 21) {
        char choice;
        printf("Your current score is %d. Would you like to hit or stay? (h/s) ", score);
        scanf(" %c", &choice);
        if (choice == 'h') {
            hit(deck, player_hand, &deck_index);
            printf("Player's hand:\n");
            display_hand(player_hand);
            printf("\n");
            score = check_score(player_hand);
        }
        else if (choice == 's') {
            break;
        }
        else {
            printf("Invalid choice. Please enter 'h' to hit or 's' to stay.\n");
        }
    }

    // Dealer's turn
    printf("Dealer's turn!\n");
    score = check_score(dealer_hand);
    while (score < 17) {
        hit(deck, dealer_hand, &deck_index);
        printf("Dealer's hand:\n");
        display_hand(dealer_hand);
        printf("\n");
        score = check_score(dealer_hand);
    }

    // Determine the winner
    printf("Player's hand:\n");
    display_hand(player_hand);
    printf("\n");
    printf("Dealer's hand:\n");
    display_hand(dealer_hand);
    printf("\n");
    int player_score = check_score(player_hand);
    int dealer_score = check_score(dealer_hand);
    if (player_score > 21) {
        printf("Player busts! Dealer wins!\n");
    }
    else if (dealer_score > 21) {
        printf("Dealer busts! Player wins!\n");
    }
    else if (player_score > dealer_score) {
        printf("Player wins!\n");
    }
    else if (dealer_score > player_score) {
        printf("Dealer wins!\n");
    }
    else {
        printf("It's a tie!\n");
    }

    return 0;
}

void shuffle(Card deck[]) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(Card deck[], int player_hand[], int dealer_hand[], int deck_index) {
    for (int i = 0; i < 2; i++) {
        player_hand[i] = deck[deck_index].value;
        dealer_hand[i] = deck[deck_index + 1].value;
        deck_index += 2;
    }
}

void display_hand(int hand[]) {
    for (int i = 0; i < 5 && hand[i] != 0; i++) {
        printf("%d ", hand[i]);
    }
}

int check_score(int hand[]) {
    int score = 0;
    int ace_count = 0;
    for (int i = 0; i < 5 && hand[i] != 0; i++) {
        if (hand[i] == 1) {
            ace_count++;
            score++;
        }
        else if (hand[i] < 10) {
            score += hand[i];
        }
        else {
            score += 10;
        }
    }
    while (ace_count > 0 && score + 10 <= 21) {
        score += 10;
        ace_count--;
    }
    return score;
}

void hit(Card deck[], int hand[], int *deck_index) {
    int i = 0;
    while (hand[i] != 0) {
        i++;
    }
    hand[i] = deck[*deck_index].value;
    (*deck_index)++;
}