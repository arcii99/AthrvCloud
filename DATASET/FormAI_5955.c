//FormAI DATASET v1.0 Category: Poker Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NPLAYERS 4 // Number of players in the game
#define DECKSIZE 52 // Number of cards in the deck
#define HANDSIZE 5 // Number of cards to be dealt to each player
#define ROUNDS 3 // Number of rounds to be played in the game

// Structure representing a card
typedef struct{
    int value; // 2-10, 11 for Jack, 12 for Queen, 13 for King, 14 for Ace
    char suit; // Hearts (H), Diamonds (D), Clubs (C), Spades (S)
} Card;

// Global variables
Card deck[DECKSIZE];
int currentCardIndex = -1; // Index of the top card in the deck
int roundNumber = 0; // Current round number
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for thread synchronization

// Function to initialize the deck
void initializeDeck(){
    int i, j, k = 0;
    for(i=2; i<=14; i++){
        for(j=0; j<4; j++){
            Card newCard;
            newCard.value = i;
            switch (j){
                case 0:
                    newCard.suit = 'H';
                    break;
                case 1:
                    newCard.suit = 'D';
                    break;
                case 2:
                    newCard.suit = 'C';
                    break;
                case 3:
                    newCard.suit = 'S';
                    break;
            }
            deck[k++] = newCard;
        }
    }
}

// Function to shuffle the deck
void shuffleDeck(){
    srand(time(NULL));
    int i, j;
    for(i=0; i<DECKSIZE; i++){
        j = rand() % DECKSIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print a card
void printCard(Card card){
    switch (card.value){
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            printf("%d%c ", card.value, card.suit);
            break;
        case 11:
            printf("J%c ", card.suit);
            break;
        case 12:
            printf("Q%c ", card.suit);
            break;
        case 13:
            printf("K%c ", card.suit);
            break;
        case 14:
            printf("A%c ", card.suit);
            break;
    }
}

// Function to deal the cards to the players
void dealCards(Card *hand){
    int i;
    pthread_mutex_lock(&mutex); // Acquire the lock
    for(i=0; i<HANDSIZE; i++){
        hand[i] = deck[++currentCardIndex];
    }
    pthread_mutex_unlock(&mutex); // Release the lock
}

// Function to evaluate the hand of a player
int evaluateHand(Card *hand){
    int i, j, k, l, m, n;
    int flush = 0, straight = 0, pair = 0, twoPair = 0, threeOfAKind = 0, fourOfAKind = 0, fullHouse = 0;
    int values[5], suits[5];
    for(i=0; i<5; i++){
        values[i] = hand[i].value;
        suits[i] = hand[i].suit;
    }
    for(i=0; i<4; i++){
        if(suits[i] == suits[i+1]){
            flush++;
        }
    }
    for(i=0; i<4; i++){
        for(j=i+1; j<5; j++){
            if(values[i] == values[j]){
                pair++;
                for(k=j+1; k<5; k++){
                    if(values[j] == values[k]){
                        threeOfAKind++;
                        for(l=k+1; l<5; l++){
                            if(values[k] == values[l]){
                                fourOfAKind++;
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=0; i<3; i++){
        if(values[i] == values[i+1]-1){
            if(values[i+1] == values[i+2]-1){
                if(values[i+2] == values[i+3]-1){
                    if(values[i+3] == values[i+4]-1){
                        straight = 1;
                        break;
                    }
                }
            }
        }
    }
    if(pair == 2){
        twoPair = 1;
    }
    if(threeOfAKind == 1 && pair == 1){
        fullHouse = 1;
    }
    if(flush == 4 && straight == 1){
        return 8;
    }
    else if(fourOfAKind == 1){
        return 7;
    }
    else if(fullHouse == 1){
        return 6;
    }
    else if(flush == 4){
        return 5;
    }
    else if(straight == 1){
        return 4;
    }
    else if(threeOfAKind == 1){
        return 3;
    }
    else if(twoPair == 1){
        return 2;
    }
    else if(pair == 1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to print the hand of a player
void printHand(Card *hand){
    int i;
    for(i=0; i<HANDSIZE; i++){
        printCard(hand[i]);
    }
}

// Thread function for each player
void *playerFunction(void *arg){
    int playerId = *(int *)arg;
    Card hand[HANDSIZE];
    int score = 0;
    int i;
    printf("Player %d: ", playerId);
    dealCards(hand); // Deal the cards to the player
    printf("Dealt hand: ");
    printHand(hand);
    score = evaluateHand(hand); // Evaluate the hand of the player
    printf("\nPlayer %d: Score is %d\n\n", playerId, score);
    pthread_exit(NULL);
}

// Function to play a round of the game
void playRound(){
    int i;
    pthread_t players[NPLAYERS];
    int playerIds[NPLAYERS];
    for(i=0; i<NPLAYERS; i++){
        playerIds[i] = i+1;
        pthread_create(&players[i], NULL, playerFunction, &playerIds[i]);
    }
    for(i=0; i<NPLAYERS; i++){
        pthread_join(players[i], NULL);
    }
}

int main(){
    initializeDeck(); // Initialize the deck
    shuffleDeck(); // Shuffle the deck
    while(roundNumber < ROUNDS){
        printf("*** ROUND %d ***\n", roundNumber+1);
        playRound(); // Play a round of the game
        roundNumber++;
    }
    printf("End of game.\n");
    return 0;
}