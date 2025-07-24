//FormAI DATASET v1.0 Category: Poker Game ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char suits[] = {'C', 'D', 'H', 'S'};
char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

typedef struct Card{
    char suit;
    char rank;
}Card;

void shuffleDeck(Card* deck, int numCards){
    int randomIndex;
    Card tempCard;

    srand(time(NULL));

    for(int i=numCards-1; i>0; i--){
        randomIndex = rand() % (i+1);
        tempCard = deck[randomIndex];
        deck[randomIndex] = deck[i];
        deck[i] = tempCard;
    }
}

void initializeDeck(Card* deck, int numCards){
    int deckIndex = 0;

    for(int i=0; i<4; i++){
        for(int j=0; j<13; j++){
            deck[deckIndex].suit = suits[i];
            deck[deckIndex].rank = ranks[j];
            deckIndex++;
        }
    }

    shuffleDeck(deck, numCards);
}

int getNumericValue(Card c){
    if(c.rank >= '2' && c.rank <= '9')
        return c.rank - '0';
    else{
        switch(c.rank){
            case 'T': return 10;
            case 'J': return 11;
            case 'Q': return 12;
            case 'K': return 13;
            case 'A': return 14;
        }
    }

    return 0;
}

void printCard(Card c){
    printf("%c%c ", c.rank, c.suit);
}

int compareCards(const void* c1, const void* c2){
    return getNumericValue(*(Card*)c1) - getNumericValue(*(Card*)c2);
}

void dealCards(Card* deck, int numCards){
    Card player1Hand[5], player2Hand[5];
    int currentDeckIndex = 0;

    for(int i=0; i<5; i++){
        player1Hand[i] = deck[currentDeckIndex++];
        player2Hand[i] = deck[currentDeckIndex++];
    }

    qsort(player1Hand, 5, sizeof(Card), compareCards);
    qsort(player2Hand, 5, sizeof(Card), compareCards);

    printf("\nPlayer 1's hand: ");
    for(int i=0; i<5; i++){
        printCard(player1Hand[i]);
    }

    printf("\nPlayer 2's hand: ");
    for(int i=0; i<5; i++){
        printCard(player2Hand[i]);
    }
}

int main(){
    Card deck[52];
    int numCards = 52;

    initializeDeck(deck, numCards);
    dealCards(deck, numCards);

    return 0;
}