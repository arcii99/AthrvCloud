//FormAI DATASET v1.0 Category: Poker Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *deck, int size){
    int i, j, temp;
    for(i = size-1; i > 0; i--){
        j = rand() % (i+1);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

void dealCards(int *deck, int size){
    int i;
    for(i=0; i<size; i++){
        printf("Player %d's card: %d\n", i+1, deck[i]);
    }
}

int main(){
    srand(time(NULL));
    int numPlayers = 4;
    int deck[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};
    shuffle(deck, 52);
    dealCards(deck, numPlayers);
    return 0;
}