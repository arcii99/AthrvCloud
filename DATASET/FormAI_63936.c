//FormAI DATASET v1.0 Category: Poker Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char suits[4][8] = {"Spades", "Hearts", "Diamonds", "Clubs"};
char ranks[13][6] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

void shuffleDeck(int deck[][13]){
    int row;
    int column;
    for (int card = 1; card <= 52; card++){
        do{
            row = rand() % 4;
            column = rand() % 13;
        } while(deck[row][column] != 0);
        deck[row][column] = card;
    }
}

void displayCard(int deck[][13], int card){
    for (int row = 0; row < 4; row++){
        for (int column = 0; column < 13; column++){
            if(deck[row][column] == card){
                printf("%s of %s\n", ranks[column], suits[row]);
                return;
            }
        }
    }
}

void displayHand(int deck[][13], int hand[5]){
    for (int card = 0; card < 5; card++){
        displayCard(deck, hand[card]);
    }
}

int main(){
    int deck[4][13] = {0};
    int player_hand[5] = {0};
    srand(time(NULL));
    shuffleDeck(deck);
    for (int i = 0; i < 5; i++){
        do{
            player_hand[i] = rand() % 52 + 1;
        } while(player_hand[i] == player_hand[i-1]);
    }
    printf("Your hand:\n");
    displayHand(deck, player_hand);
    return 0;
}