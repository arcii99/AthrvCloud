//FormAI DATASET v1.0 Category: Poker Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

// The Card structure
typedef struct {
    int value; // Ace = 1, ..., King = 13
    char suit; // C = Clubs, H = Hearts, D = Diamonds, S = Spades
    int used; // 0 = not used, 1 = used
} Card;

// Function Prototypes
void shuffleDeck(Card []);
void dealCards(Card [], Card []);
void printCards(Card []);
int evaluateHand(Card []);

int main(void) {
    // Initialize the deck of cards
    Card deck[DECK_SIZE];
    int i, j, k = 0;
    for (i = 1; i <= 13; i++) {
        for (j = 0; j < 4; j++) {
            deck[k].value = i;
            if (j == 0) deck[k].suit = 'C';
            else if (j == 1) deck[k].suit = 'H';
            else if (j == 2) deck[k].suit = 'D';
            else if (j == 3) deck[k].suit = 'S';
            deck[k].used = 0;
            k++;
        }
    }
    
    // Shuffle the deck
    srand(time(NULL)); // Seed the random number generator
    shuffleDeck(deck);
    
    // Deal the cards
    Card playerHand[HAND_SIZE];
    Card dealerHand[HAND_SIZE];
    dealCards(deck, playerHand);
    dealCards(deck, dealerHand);
    
    // Print the cards
    printf("Your hand:\n");
    printCards(playerHand);
    printf("Dealer's hand:\n");
    printCards(dealerHand);
    
    // Evaluate the hands
    int playerScore = evaluateHand(playerHand);
    int dealerScore = evaluateHand(dealerHand);
    
    // Determine the winner
    if (playerScore > dealerScore) {
        printf("You win!\n");
    } else if (playerScore < dealerScore) {
        printf("Dealer wins.\n");
    } else {
        printf("It's a tie.\n");
    }
    
    return 0;
}

// Function to shuffle the deck
void shuffleDeck(Card deck[]) {
    int i, j;
    Card temp;
    for (i = 0; i < DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to deal cards
void dealCards(Card deck[], Card hand[]) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        int j = 0;
        do {
            j = rand() % DECK_SIZE;
        } while (deck[j].used == 1);
        hand[i] = deck[j];
        deck[j].used = 1;
    }
}

// Function to print the cards in a hand
void printCards(Card hand[]) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        printf("%d%c ", hand[i].value, hand[i].suit);
    }
    printf("\n");
}

// Function to evaluate a hand
int evaluateHand(Card hand[]) {
    int i, j, k, l, m;
    int flush = 0, straight = 0, fourOfAKind = 0, threeOfAKind = 0, pair1 = 0, pair2 = 0;
    int values[HAND_SIZE];
    char suits[HAND_SIZE];
    for (i = 0; i < HAND_SIZE; i++) {
        values[i] = hand[i].value;
        suits[i] = hand[i].suit;
    }
    // Check for flush
    for (i = 0; i < HAND_SIZE - 1; i++) {
        if (suits[i] == suits[i+1]) {
            flush++;
        }
    }
    // Check for straight
    for (i = 0; i < HAND_SIZE - 1; i++) {
        if (values[i] == values[i+1] - 1) {
            straight++;
        }
    }
    // Check for four of a kind, three of a kind, pairs
    for (i = 0; i < HAND_SIZE; i++) {
        int count = 0;
        for (j = 0; j < HAND_SIZE; j++) {
            if (values[i] == values[j] && i != j) {
                count++;
            }
        }
        if (count == 3) {
            fourOfAKind = values[i];
            break;
        } else if (count == 2) {
            if (pair1 == 0) {
                pair1 = values[i];
            } else {
                pair2 = values[i];
            }
            threeOfAKind = values[i];
        } else if (count == 1) {
            pair1 = values[i];
        }
    }
    // Check for royal flush
    if (flush == HAND_SIZE - 1 && values[0] == 1 && values[1] == 10 &&
        values[2] == 11 && values[3] == 12 && values[4] == 13) {
        return 100;
    }
    // Check for straight flush
    if (flush == HAND_SIZE - 1 && straight == HAND_SIZE - 1) {
        return 90;
    }
    // Check for four of a kind
    if (fourOfAKind != 0) {
        return 80 + fourOfAKind;
    }
    // Check for full house
    if (pair1 != 0 && threeOfAKind != 0) {
        return 70;
    }
    // Check for flush
    if (flush == HAND_SIZE - 1) {
        return 60;
    }
    // Check for straight
    if (straight == HAND_SIZE - 1) {
        return 50;
    }
    // Check for three of a kind
    if (threeOfAKind != 0) {
        return 40 + threeOfAKind;
    }
    // Check for two pair
    if (pair1 != 0 && pair2 != 0) {
        return 30;
    }
    // Check for pair
    if (pair1 != 0) {
        return 20 + pair1;
    }
    // If none of the above, return high card
    return values[HAND_SIZE-1];
}