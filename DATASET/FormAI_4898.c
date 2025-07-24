//FormAI DATASET v1.0 Category: Poker Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For time(NULL)

// Define deck constants
#define CARDNUM 52
#define SUITS 4
#define RANKS 13
#define HANDSIZE 5

// Define card struct
struct card{
    int rank;
    int suit;
};

// Function to print a card
void printCard(struct card c){
    char rankChar;
    switch(c.rank){
        case 1:
            rankChar = 'A'; break;
        case 10:
            rankChar = 'X'; break;
        case 11:
            rankChar = 'J'; break;
        case 12:
            rankChar = 'Q'; break;
        case 13:
            rankChar = 'K'; break;
        default:
            rankChar = c.rank + '0';
    }
    char suitChar;
    switch(c.suit){
        case 1:
            suitChar = 'H'; break;
        case 2:
            suitChar = 'D'; break;
        case 3:
            suitChar = 'C'; break;
        case 4:
            suitChar = 'S'; break;
    }
    printf("%c%c ", rankChar, suitChar);
}

// Function to initialize deck
void initDeck(struct card deck[]){
    int i, j;
    for(i = 0; i < SUITS; i++){
        for(j = 0; j < RANKS; j++){
            deck[i*RANKS+j].rank = j+1;
            deck[i*RANKS+j].suit = i+1;
        }
    }
}

// Function to shuffle deck
void shuffleDeck(struct card deck[]){
    int i;
    srand(time(NULL));
    for(i = 0; i < CARDNUM; i++){
        int j = rand() % CARDNUM;
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to determine hand type
int handType(struct card hand[]){
    int i, j;
    int ranks[RANKS] = {0};
    int suits[SUITS] = {0};
    for(i = 0; i < HANDSIZE; i++){
        ranks[hand[i].rank-1]++;
        suits[hand[i].suit-1]++;
    }
    int flush = 0, straight = 0, straightFlush = 0, threeKind = 0, fourKind = 0, pairs = 0;
    // Check for flush
    for(i = 0; i < SUITS; i++){
        if(suits[i] == HANDSIZE){
            flush = 1;
            break;
        }
    }
    // Check for straight and straight flush
    for(i = 0; i < RANKS; i++){
        if(ranks[i] == 1){
            if(straight == 0){
                int k = i+1;
                while(k <= RANKS && ranks[k] == 1) k++;
                if(k-i == HANDSIZE){
                    straight = 1;
                    if(flush == 1){
                        straightFlush = 1;
                        break;
                    }
                }
            }
        }
    }
    // Check for three and four of a kind, and pairs
    for(i = 0; i < RANKS; i++){
        if(ranks[i] == 4){
            fourKind = 1;
            break;
        }
        if(ranks[i] == 3){
            threeKind = 1;
            break;
        }
        if(ranks[i] == 2){
            pairs++;
        }
    }
    if(straightFlush == 1){
        return 9;
    }
    if(fourKind == 1){
        return 8;
    }
    if(threeKind == 1 && pairs == 1){
        return 7;
    }
    if(flush == 1){
        return 6;
    }
    if(straight == 1){
        return 5;
    }
    if(threeKind == 1){
        return 4;
    }
    if(pairs == 2){
        return 3;
    }
    if(pairs == 1){
        return 2;
    }
    return 1;
}

int main(){
    struct card deck[CARDNUM];
    initDeck(deck);
    int i, j;
    // Shuffle deck
    shuffleDeck(deck);
    // Deal hands
    struct card hand1[HANDSIZE], hand2[HANDSIZE], communityCards[5];
    for(i = 0; i < HANDSIZE; i++){
        hand1[i] = deck[i];
        hand2[i] = deck[i+HANDSIZE];
    }
    for(i = 0; i < 5; i++){
        communityCards[i] = deck[i+HANDSIZE*2];
    }
    // Print hands and community cards
    printf("Player 1's hand: ");
    for(i = 0; i < HANDSIZE; i++){
        printCard(hand1[i]);
    }
    printf("\nPlayer 2's hand: ");
    for(i = 0; i < HANDSIZE; i++){
        printCard(hand2[i]);
    }
    printf("\nCommunity cards: ");
    for(i = 0; i < 5; i++){
        printCard(communityCards[i]);
    }
    printf("\n");
    // Determine winner
    int hand1Type = handType(hand1), hand2Type = handType(hand2), communityCardsType = handType(communityCards);
    printf("Player 1's hand type: %d\n", hand1Type);
    printf("Player 2's hand type: %d\n", hand2Type);
    printf("Community cards type: %d\n", communityCardsType);
    if(hand1Type == hand2Type){
        printf("Tie!\n");
    }
    else if(hand1Type > hand2Type){
        printf("Player 1 wins!\n");
    }
    else{
        printf("Player 2 wins!\n");
    }
    return 0;
}