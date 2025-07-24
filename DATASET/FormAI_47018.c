//FormAI DATASET v1.0 Category: Poker Game ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Define card structures
typedef struct Card {
    int value; //value of card
    char suit; //suit of card
} Card;

//Define deck structure
typedef struct Deck {
    Card cards[52]; //array of cards
    int index;     //index of next card to be dealt
} Deck;

//Function to create deck of cards
void createDeck(Deck *deck) {
    int i, j, count = 0;
    char suits[4] = {'C', 'D', 'H', 'S'}; //array of suits
    for(i=0; i<4; i++) {
        for(j=1; j<=13; j++) {
            deck->cards[count].value = j;
            deck->cards[count].suit = suits[i];
            count++;
        }
    }
    deck->index = 0;
}

//Function to shuffle the deck
void shuffle(Deck *deck) {
    int i, j;
    Card temp;
    srand(time(NULL)); //initialize random seed
    for(i=0; i<52; i++) {
        j = rand() % 52;
        temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
    deck->index = 0; //reset index to 0 after shuffling
}

//Function to deal a hand
void deal(Deck *deck, Card *hand) {
    int i;
    for(i=0; i<5; i++) {
        hand[i] = deck->cards[deck->index++];
    }
}

//Function to display a card
void displayCard(Card card) {
    if(card.value < 10) {
        printf("%d%c ", card.value, card.suit);
    } else {
        switch(card.value) {
            case 10: printf("T%c ", card.suit); break;
            case 11: printf("J%c ", card.suit); break;
            case 12: printf("Q%c ", card.suit); break;
            case 13: printf("K%c ", card.suit); break;
        }
    }
}

//Function to display a hand
void displayHand(Card *hand) {
    int i;
    for(i=0; i<5; i++) {
        displayCard(hand[i]);
    }
}

//Function to evaluate a hand
int evaluateHand(Card *hand) {
    int i, j, temp;
    int counts[13] = {0}; //initialize counts array to 0
    char suits[5] = {'C', 'D', 'H', 'S', ' '}; //initialize suits array with extra space for output formatting
    int numSuits[4] = {0}; //initialize numSuits array to 0
    int flush = 0, straight = 0, pairs = 0, threeOfAKind = 0, fourOfAKind = 0;
    //Count the number of cards of each value and suit
    for(i=0; i<5; i++) {
        counts[hand[i].value-1]++;
        for(j=0; j<4; j++) {
            if(hand[i].suit == suits[j]) {
                numSuits[j]++;
            }
        }
    }
    //Check for flush
    for(i=0; i<4; i++) {
        if(numSuits[i] == 5) {
            flush = 1;
            break;
        }
    }
    //Check for straight
    for(i=0; i<9; i++) {
        temp = 0;
        for(j=i; j<i+5; j++) {
            if(counts[j] == 1) {
                temp++;
            }
        }
        if(temp == 5) {
            straight = 1;
            break;
        }
    }
    //Check for pairs, three of a kind, and four of a kind
    for(i=0; i<13; i++) {
        if(counts[i] == 2) {
            pairs++;
        } else if(counts[i] == 3) {
            threeOfAKind++;
        } else if(counts[i] == 4) {
            fourOfAKind++;
        }
    }
    //Determine hand rank
    if(flush && straight) {
        return 9; //straight flush
    } else if(fourOfAKind) {
        return 8; //four of a kind
    } else if(threeOfAKind && pairs) {
        return 7; //full house
    } else if(flush) {
        return 6; //flush
    } else if(straight) {
        return 5; //straight
    } else if(threeOfAKind) {
        return 4; //three of a kind
    } else if(pairs == 2) {
        return 3; //two pairs
    } else if(pairs == 1) {
        return 2; //one pair
    } else {
        return 1; //high card
    }
}

int main() {
    Deck deck;
    Card hand[5];
    int rank;
    createDeck(&deck);
    shuffle(&deck);
    deal(&deck, hand);
    printf("Your hand: ");
    displayHand(hand);
    rank = evaluateHand(hand);
    switch(rank) {
        case 1: printf("\nHigh card\n"); break;
        case 2: printf("\nOne pair\n"); break;
        case 3: printf("\nTwo pairs\n"); break;
        case 4: printf("\nThree of a kind\n"); break;
        case 5: printf("\nStraight\n"); break;
        case 6: printf("\nFlush\n"); break;
        case 7: printf("\nFull house\n"); break;
        case 8: printf("\nFour of a kind\n"); break;
        case 9: printf("\nStraight flush\n"); break;
    }
    return 0;
}