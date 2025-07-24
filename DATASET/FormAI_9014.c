//FormAI DATASET v1.0 Category: Poker Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARD_COUNT 52 // number of cards in a deck
#define FACE_COUNT 13 // number of different faces (A-K)
#define SUIT_COUNT 4 // number of different suits (clubs, diamonds, hearts, spades)

// structure to hold a playing card
typedef struct {
    int face; // 1 = Ace, 11 = Jack, 12 = Queen, 13 = King
    int suit; // 0 = Clubs, 1 = Diamonds, 2 = Hearts, 3 = Spades
} card;

// function prototypes
void displayHand(int player, card hand[], int size);
void shuffleDeck(card deck[]);
void dealCards(card deck[], card player1[], card player2[], int size);
void sortHand(card hand[], int size);
int countPairs(card hand[], int size);
int countThreeOfAKind(card hand[], int size);
int countFourOfAKind(card hand[], int size);
int countFlush(card hand[], int size);
int countStraight(card hand[], int size);
int evaluateHand(card hand[], int size);

int main() {
    srand(time(NULL)); // seed the random number generator
    
    card deck[CARD_COUNT]; // declare the deck of cards
    card player1[5], player2[5]; // declare the hands of cards for two players
    
    shuffleDeck(deck); // shuffle the deck
    dealCards(deck, player1, player2, 5); // deal the cards
    
    // display each player's hand
    displayHand(1, player1, 5);
    displayHand(2, player2, 5);
    
    // evaluate each player's hand and declare the winner
    int score1 = evaluateHand(player1, 5);
    int score2 = evaluateHand(player2, 5);
    
    printf("\nPlayer 1's Hand: %d\n", score1);
    printf("Player 2's Hand: %d\n\n", score2);
    
    if (score1 == score2) {
        printf("It's a tie!\n");
    } else if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }
    
    return 0;
}

// function to display a hand of cards
void displayHand(int player, card hand[], int size) {
    printf("\nPlayer %d's Hand:\n", player);
    for (int i = 0; i < size; i++) {
        char face = ' ';
        switch(hand[i].face) {
            case 1: face = 'A'; break;
            case 10: face = 'T'; break;
            case 11: face = 'J'; break;
            case 12: face = 'Q'; break;
            case 13: face = 'K'; break;
            default: face = hand[i].face + '0'; break;
        }
        char suit = ' ';
        switch(hand[i].suit) {
            case 0: suit = 'C'; break;
            case 1: suit = 'D'; break;
            case 2: suit = 'H'; break;
            case 3: suit = 'S'; break;
        }
        printf("%c%c ", face, suit);
    }
    printf("\n");
}

// function to shuffle the deck of cards
void shuffleDeck(card deck[]) {
    for (int i = 0; i < CARD_COUNT; i++) {
        deck[i].face = (i % FACE_COUNT) + 1;
        deck[i].suit = i / FACE_COUNT;
    }
    for (int i = 0; i < CARD_COUNT; i++) {
        int j = rand() % CARD_COUNT;
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// function to deal cards to two players
void dealCards(card deck[], card player1[], card player2[], int size) {
    for (int i = 0; i < size; i++) {
        player1[i] = deck[i];
        player2[i] = deck[i+size];
    }
}

// function to sort a hand of cards by face value
void sortHand(card hand[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size; j++) {
            if (hand[i].face > hand[j].face) {
                card temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

// function to count pairs in a hand
int countPairs(card hand[], int size) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size; j++) {
            if (hand[i].face == hand[j].face) {
                count++;
            }
        }
    }
    return count;
}

// function to count three of a kinds in a hand
int countThreeOfAKind(card hand[], int size) {
    int count = 0;
    for (int i = 0; i < size - 2; i++) {
        if (hand[i].face == hand[i+1].face && hand[i].face == hand[i+2].face) {
            count++;
        }
    }
    return count;
}

// function to count four of a kinds in a hand
int countFourOfAKind(card hand[], int size) {
    int count = 0;
    for (int i = 0; i < size - 3; i++) {
        if (hand[i].face == hand[i+1].face && hand[i].face == hand[i+2].face && hand[i].face == hand[i+3].face) {
            count++;
        }
    }
    return count;
}

// function to count flushes in a hand
int countFlush(card hand[], int size) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        if (hand[i].suit != hand[i+1].suit) {
            return 0;
        }
    }
    return 1;
}

// function to count straights in a hand
int countStraight(card hand[], int size) {
    if (hand[0].face == 1 && hand[1].face == 10 && hand[2].face == 11 && hand[3].face == 12 && hand[4].face == 13) {
        return 1;
    }
    for (int i = 0; i < size - 1; i++) {
        if (hand[i+1].face - hand[i].face != 1) {
            return 0;
        }
    }
    return 1;
}

// function to evaluate a hand of cards
int evaluateHand(card hand[], int size) {
    sortHand(hand, size);
    if (countStraight(hand, size) && countFlush(hand, size)) {
        return 9; // straight flush
    } else if (countFourOfAKind(hand, size)) {
        return 8; // four of a kind
    } else if (countThreeOfAKind(hand, size) && countPairs(hand, size) == 1) {
        return 7; // full house
    } else if (countFlush(hand, size)) {
        return 6; // flush
    } else if (countStraight(hand, size)) {
        return 5; // straight
    } else if (countThreeOfAKind(hand, size)) {
        return 4; // three of a kind
    } else if (countPairs(hand, size) == 2) {
        return 3; // two pairs
    } else if (countPairs(hand, size) == 1) {
        return 2; // one pair
    } else {
        return 1; // high card
    }
}