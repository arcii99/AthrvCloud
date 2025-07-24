//FormAI DATASET v1.0 Category: Poker Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct card{
    int value;
    int suit;
} Card;

Card deck[DECK_SIZE];
Card hand[HAND_SIZE];

char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
char *suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

void shuffle_deck(){
    int i, j;
    Card temp;
    for(i = DECK_SIZE-1; i > 0; i--){
        j = rand() % i;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(Card card){
    printf("%s of %s\n", values[card.value], suits[card.suit]);
}

void deal_hand(){
    int i;
    for(i = 0; i < HAND_SIZE; i++){
        hand[i] = deck[i];
        print_card(hand[i]);
    }
}

int check_pair(){
    int i, j;
    for(i = 0; i < HAND_SIZE-1; i++){
        for(j = i+1; j < HAND_SIZE; j++){
            if(hand[i].value == hand[j].value){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int i;
    srand(time(0));
    for(i = 0; i < DECK_SIZE; i++){
        deck[i].value = i % 13;
        deck[i].suit = i / 13;
    }
    shuffle_deck();
    deal_hand();
    if(check_pair()){
        printf("You have a pair!\n");
    }
    else{
        printf("No pair.\n");
    }
    return 0;
}