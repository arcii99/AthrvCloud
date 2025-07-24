//FormAI DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 52
#define MAX_SUIT 4
#define MAX_RANK 13

void shuffle(int *deck, int size);
void print_card(int card);

int main(void) {
    time_t t;
    srand((unsigned) time(&t)); // seed the random function with current time
    
    // Generate deck of cards
    int deck[MAX_CARDS];
    for (int i = 0; i < MAX_CARDS; i++) {
        deck[i] = i;
    }
    
    // Shuffle the deck
    shuffle(deck, MAX_CARDS);
    
    // Start the game
    int score = 0;
    int current_card = deck[0];
    while (1) {
        printf("Current card: ");
        print_card(current_card);
        printf("Score: %d\n", score);
        
        char choice;
        printf("Higher or lower (h/l)? ");
        scanf(" %c", &choice);
        
        int next_card = deck[score+1];
        if ((next_card%MAX_RANK) > (current_card%MAX_RANK) && choice == 'h') {
            printf("\nCorrect!\n");
            score++;
            current_card = next_card;
        } else if ((next_card%MAX_RANK) < (current_card%MAX_RANK) && choice == 'l') {
            printf("\nCorrect!\n");
            score++;
            current_card = next_card;
        } else {
            printf("\nIncorrect!\n");
            printf("Final score: %d\n",score);
            break;
        }
    }
    
    return 0;
}

void shuffle(int *deck, int size) {
    for (int i = size-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(int card) {
    char *suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    printf("%s of %s\n", ranks[card%MAX_RANK], suits[card/MAX_RANK]);
}