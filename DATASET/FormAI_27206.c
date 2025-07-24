//FormAI DATASET v1.0 Category: Poker Game ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void displayCard(int card){
    int value = card % 13 + 1;
    int suit = card / 13;
    char valueChar;
    char suitChar;
    
    switch(value){
        case 1:
            valueChar = 'A';
            break;
        case 11:
            valueChar = 'J';
            break;
        case 12:
            valueChar = 'Q';
            break;
        case 13:
            valueChar = 'K';
            break;
        default:
            valueChar = value + '0';
            break;
    }
    
    switch(suit){
        case 0:
            suitChar = 'C';
            break;
        case 1:
            suitChar = 'D';
            break;
        case 2:
            suitChar = 'H';
            break;
        case 3:
            suitChar = 'S';
            break;
    }
    
    printf("[%c%c] ", valueChar, suitChar);
}

void dealCards(int numPlayers, int cards[][2], int numCards){
    int remainingCards = numCards;
    int selectedCard;
    int player;
    int i, j;
    srand(time(NULL));
    
    for(i=0; i<2; i++){
        for(j=0; j<numPlayers; j++){
            selectedCard = rand() % remainingCards;
            cards[selectedCard][0] = j;
            cards[selectedCard][1] = numCards - remainingCards;
            remainingCards--;
        }
    }
}

int main(){
    int numPlayers = 2;
    int numCards = 52;
    int cards[52][2];
    int i, j;
    
    for(i=0; i<numPlayers; i++){
        printf("Player %d: ", i+1);
        
        for(j=0; j<2; j++){
            displayCard(cards[j*numPlayers+i][1]);
        }
        
        printf("\n");
    }
    
    return 0;
}