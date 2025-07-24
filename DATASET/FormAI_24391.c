//FormAI DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 20
#define MAX_NAME_LENGTH 20

struct card {
    int value;
    char name[MAX_NAME_LENGTH];
    int revealed;
};

void shuffle(struct card* deck, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(struct card* c) {
    if (c->revealed) {
        printf("%s ", c->name);
    } else {
        printf("X ");
    }
}

void print_deck(struct card* deck, int size) {
    for (int i = 0; i < size; i++) {
        print_card(&deck[i]);
    }
    printf("\n");
}

void reveal_card(struct card* c) {
    c->revealed = 1;
}

void hide_card(struct card* c) {
    c->revealed = 0;
}

int main() {
    srand(time(NULL));
    
    struct card deck[NUM_CARDS];
    
    for (int i = 0; i < NUM_CARDS; i += 2) {
        deck[i].value = i / 2;
        sprintf(deck[i].name, "%c", (char) (i / 2 + 'A'));
        deck[i].revealed = 0;
        
        deck[i+1].value = i / 2;
        sprintf(deck[i+1].name, "%c", (char) (i / 2 + 'A'));
        deck[i+1].revealed = 0;
    }
    
    shuffle(deck, NUM_CARDS);
    
    printf("Welcome to the Memory Game!\n");
    printf("Try and guess which cards match.\n");
    printf("Enter a pair of card numbers to flip.\n\n");
    
    print_deck(deck, NUM_CARDS);
    
    int first_choice, second_choice;
    
    while (1) {
        printf("Enter first choice: ");
        scanf("%d", &first_choice);
        printf("Enter second choice: ");
        scanf("%d", &second_choice);
        
        printf("\n");
        
        reveal_card(&deck[first_choice]);
        reveal_card(&deck[second_choice]);
        
        print_deck(deck, NUM_CARDS);
        
        if (deck[first_choice].value == deck[second_choice].value) {
            printf("Match!\n");
        } else {
            printf("Not a match.\n");
            hide_card(&deck[first_choice]);
            hide_card(&deck[second_choice]);
        }
        
        int all_revealed = 1;
        for (int i = 0; i < NUM_CARDS; i++) {
            if (!deck[i].revealed) {
                all_revealed = 0;
                break;
            }
        }
        
        if (all_revealed) {
            printf("You win!\n");
            break;
        }
    }
    
    return 0;
}