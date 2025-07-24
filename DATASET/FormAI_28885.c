//FormAI DATASET v1.0 Category: Poker Game ; Style: random
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define NUM_CARDS 52 
#define HAND_SIZE 5 
#define MAX_ROUNDS 10 

char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" }; 
char *face[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" }; 

typedef struct card { 
    int value; 
    int suit; 
    int face; 
} card_t; 

void shuffle(card_t *deck); 
void print_hand(card_t *hand); 
int score_hand(card_t *hand); 
void play_game(); 

int main() { 
    srand(time(NULL)); 
    printf("Welcome to the Poker Game!\n"); 
    play_game(); 
    return 0; 
} 

void shuffle(card_t *deck) { 
    int i; 
    for(i = 0; i < NUM_CARDS; i++) { 
        int j = rand() % NUM_CARDS; 
        card_t temp = deck[j]; 
        deck[j] = deck[i]; 
        deck[i] = temp; 
    } 
} 

void print_hand(card_t *hand) { 
    int i; 
    for(i = 0; i < HAND_SIZE; i++) { 
        printf("%s of %s\n", face[hand[i].face], suit[hand[i].suit]); 
    } 
} 

int score_hand(card_t *hand) { 
    int i, j, score = 0; 
    int has_pair = 0, has_three = 0, has_four = 0; 

    for(i = 0; i < HAND_SIZE; i++) { 
        score += hand[i].value; 
        for(j = i+1; j < HAND_SIZE; j++) { 
            if(hand[i].face == hand[j].face) { 
                has_pair++; 
                if(has_pair == 2) { 
                    has_three = 0; 
                    has_four = 0; 
                    return (score + (hand[i].value * 2)); 
                } else if(has_pair == 3) { 
                    has_four = 0; 
                    return (score + (hand[i].value * 2)); 
                } else { 
                    has_three++; 
                    if(has_three == 2) { 
                        has_four = 0; 
                        return (score + (hand[i].value * 3)); 
                    } else if(has_three == 3) { 
                        return (score + (hand[i].value * 3)); 
                    } 
                } 
            } 
        } 
    } 

    if(has_four > 0) { 
        return (score + (hand[i-1].value * 4)); 
    } else if(has_three > 0 && has_pair > 0) { 
        return (score + (hand[i-1].value * 3) + (hand[i-2].value * 2)); 
    } else if(has_three > 0) { 
        return (score + (hand[i-1].value * 3)); 
    } else if(has_pair == 2) { 
        return (score + (hand[i-1].value * 2) + (hand[i-2].value * 2)); 
    } else if(has_pair == 1) { 
        return (score + (hand[i-1].value * 2)); 
    } 

    return score; 
} 

void play_game() { 
    int round, score = 0; 
    card_t deck[NUM_CARDS]; 
    for(int i = 0; i < NUM_CARDS; i++) { 
        deck[i].face = i % 13; 
        deck[i].suit = i / 13; 
        if(i < 10) { 
            deck[i].value = i + 1; 
        } else { 
            deck[i].value = 10; 
        } 
    } 

    for(round = 1; round <= MAX_ROUNDS; round++) { 
        shuffle(deck); 
        card_t hand[HAND_SIZE]; 
        for(int i = 0; i < HAND_SIZE; i++) { 
            hand[i] = deck[i+(round-1)*HAND_SIZE]; 
        } 

        printf("\nRound %d\n", round); 
        printf("Your hand is:\n"); 
        print_hand(hand); 
        score += score_hand(hand); 
        printf("Your score is: %d\n", score); 
    } 

    printf("\nFinal score is: %d\n", score); 
}