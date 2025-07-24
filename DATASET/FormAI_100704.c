//FormAI DATASET v1.0 Category: Poker Game ; Style: happy
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void pause() {
    // This function waits for the user to press enter before continuing
    printf("\n");
    system("pause");
}

void clear_screen() {
    // This function clears the screen
    system("cls");
}

void shuffle(int* deck, int size) {
    // This function shuffles the deck
    srand(time(0));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    int deck[52] = { 0 };
    int suit, rank, card = 0;

    // Create deck of cards
    for (suit = 0; suit < 4; suit++) {
        for (rank = 2; rank <= 14; rank++) {
            deck[card] = rank;
            card++;
        }
    }

    clear_screen();
    printf("Ready to play some poker? Let's shuffle the deck...\n");
    pause();
    shuffle(deck, 52);
    printf("Deck shuffled! Here are your cards:\n");
    pause();

    // Deal 5 random cards
    for (int i = 0; i < 5; i++) {
        int card_value = deck[i];
        char suit_symbol;
        if (i < 13) {
            suit_symbol = 'H';
        } else if (i < 26) {
            suit_symbol = 'D';
            card_value -= 13;
        } else if (i < 39) {
            suit_symbol = 'C';
            card_value -= 26;
        } else {
            suit_symbol = 'S';
            card_value -= 39;
        }
        printf("Card %d: %c%d\n", i + 1, suit_symbol, card_value);
    }

    printf("\n");
    printf("Looks like you've got a pretty good hand! Ready to bet?\n");
    pause();
    printf("Alright, let's play some poker!\n");

    return 0;
}