//FormAI DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROUNDS 10 // maximum rounds in the game
#define PAIR_COUNT 10 // number of pairs in the game
#define CARD_COUNT (PAIR_COUNT * 2) // total number of cards in the game

typedef struct {
    int value, visible;
} Card;

int main() {
    srand(time(0)); // seed the random number generator
    
    Card cards[CARD_COUNT]; // array of cards
    for (int i = 0; i < PAIR_COUNT; i++) {
        cards[i * 2].value = i;
        cards[i * 2 + 1].value = i;
    }
    
    int round = 1, score = 0;
    while (round <= MAX_ROUNDS && score < PAIR_COUNT) {
        printf("Round #%d\n", round);
        
        // shuffle the cards
        for (int i = 0; i < CARD_COUNT; i++) {
            int j = rand() % CARD_COUNT;
            Card temp = cards[i];
            cards[i] = cards[j];
            cards[j] = temp;
        }
        
        // hide all cards
        for (int i = 0; i < CARD_COUNT; i++) {
            cards[i].visible = 0;
        }
        
        // play the game
        int selection[2] = {-1, -1};
        int count = 0;
        while (count < 2) {
            // display the cards
            for (int i = 0; i < CARD_COUNT; i++) {
                if (cards[i].visible) {
                    printf("%d ", cards[i].value);
                } else {
                    printf("? ");
                }
                if ((i + 1) % 5 == 0) {
                    printf("\n");
                }
            }
            
            // prompt the user for selection
            if (count == 0) {
                printf("Enter the index of the first card: ");
            } else {
                printf("Enter the index of the second card: ");
            }
            int index;
            scanf("%d", &index);
            
            // check the selection
            if (index < 0 || index >= CARD_COUNT) {
                printf("Invalid index\n");
            } else if (cards[index].visible) {
                printf("Card already revealed\n");
            } else {
                cards[index].visible = 1;
                selection[count] = index;
                count++;
            }
        }
        
        // check for a match
        if (cards[selection[0]].value == cards[selection[1]].value) {
            printf("Match!\n");
            score++;
        } else {
            printf("No match\n");
        }
        
        round++;
    }
    
    printf("Game over. You scored %d out of %d\n", score, PAIR_COUNT);
    
    return 0;
}