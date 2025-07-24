//FormAI DATASET v1.0 Category: Memory Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_CARDS 16

char cards[NUM_CARDS]; // An array to store the cards
bool cards_visible[NUM_CARDS]; // An array to store if the cards are visible or not
char previous_card; // A variable to store the previous card picked
int previous_card_index; // A variable to store the index of the previous card picked

// Function to initialize the cards array with values from 'A' to 'H'
void initialize_cards() {
    char card_value = 'A';
    for(int i = 0; i < NUM_CARDS; i += 2) {
        cards[i] = card_value;
        cards[i+1] = card_value;
        card_value++;
    }
}

// Function to shuffle the cards
void shuffle_cards() {
    srand(time(NULL));
    for(int i = NUM_CARDS - 1; i > 0; i--) {
        int j = rand() % (i+1);
        char temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

// Function to print the cards
void print_cards() {
    printf("  ");
    for(int i = 0; i < NUM_CARDS; i++) {
        printf("%2d", i);
    }
    printf("\n");
    for(int i = 0; i < NUM_CARDS; i++) {
        if(i == 0) printf("%c ", 201);
        else if(i == NUM_CARDS - 1) printf("%c\n", 187);
        else printf("%c%c", 203, 205);
    }
    for(int i = 0; i < NUM_CARDS; i++) {
        if(i == 0) printf("%c", 186);
        if(cards_visible[i]) printf("%c ", cards[i]);
        else printf("  ");
        printf("%c", 186);
    }
    printf("\n");
    for(int i = 0; i < NUM_CARDS; i++) {
        if(i == 0) printf("%c ", 200);
        else if(i == NUM_CARDS - 1) printf("%c\n", 188);
        else printf("%c%c", 202, 205);
    }
}

// Function to pick a card
void pick_card() {
    int index;
    printf("Enter the index of a card to pick: ");
    scanf("%d", &index);
    if (cards_visible[index]) {
        printf("That card is already visible!\n");
        pick_card(); // Try again
    }
    else {
        cards_visible[index] = true;
        if(previous_card == '\0') {
            previous_card = cards[index];
            previous_card_index = index;
        }
        else {
            if(cards[index] == previous_card) {
                printf("You found a match!\n");
                previous_card = '\0';
            }
            else {
                printf("Those cards do not match!\n");
                cards_visible[index] = false;
                cards_visible[previous_card_index] = false;
                previous_card = '\0';
            }
        }
    }
}

int main() {
    initialize_cards(); // Initialize the cards with values from 'A' to 'H'
    shuffle_cards(); // Shuffle the cards
    while(true) {
        print_cards();
        pick_card(); // Ask the user to pick a card
    }
    return 0;
}