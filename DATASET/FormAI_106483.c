//FormAI DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CARDS 24
#define MAX_NAME_SIZE 20

// Struct for a single card in the game
typedef struct Card {
    char name[MAX_NAME_SIZE];
    int value;
    int found;
} Card;

// Function to create a new card with a given name and value
Card create_card(char* name, int value) {
    Card card;
    strcpy(card.name, name);
    card.value = value;
    card.found = 0;
    return card;
}

// Function to initialize the deck of cards with known names and values
void init_deck(Card* deck) {
    deck[0] = create_card("ace", 1);
    deck[1] = create_card("two", 2);
    deck[2] = create_card("three", 3);
    deck[3] = create_card("four", 4);
    deck[4] = create_card("five", 5);
    deck[5] = create_card("six", 6);
    deck[6] = create_card("seven", 7);
    deck[7] = create_card("eight", 8);
    deck[8] = create_card("nine", 9);
    deck[9] = create_card("ten", 10);
    deck[10] = create_card("jack", 10);
    deck[11] = create_card("queen", 10);
    deck[12] = create_card("king", 10);
    deck[13] = create_card("ace", 1);
    deck[14] = create_card("two", 2);
    deck[15] = create_card("three", 3);
    deck[16] = create_card("four", 4);
    deck[17] = create_card("five", 5);
    deck[18] = create_card("six", 6);
    deck[19] = create_card("seven", 7);
    deck[20] = create_card("eight", 8);
    deck[21] = create_card("nine", 9);
    deck[22] = create_card("ten", 10);
    deck[23] = create_card("jack", 10);
}

// Function to shuffle the deck of cards
void shuffle_deck(Card* deck) {
    int i, j;
    Card temp;
    for (i = 0; i < MAX_CARDS; i++) {
        j = rand() % MAX_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print the current state of the board (cards that have been found, and cards that are still hidden)
void print_board(Card* board) {
    int i;
    printf("\n      MEMORY GAME\n");
    printf("-------------------------\n");
    for (i = 0; i < MAX_CARDS; i++) {
        if (board[i].found) {
            printf("[%s]  ", "FOUND");
        } else {
            printf("[%d]   ", i);
        }
        if ((i + 1) % 6 == 0) {
            printf("\n");
        }
    }
    printf("-------------------------\n");
}

// Function to get a valid card index from the user
int get_card_index(Card* board) {
    int index;
    do {
        printf("\nEnter the index of the card you want to flip (0-23): ");
        scanf("%d", &index);
        if (index < 0 || index > 23 || board[index].found) { // Check if the index is valid and the card has not already been found
            printf("Invalid index or card already found. Try again.\n");
        }
    } while (index < 0 || index > 23 || board[index].found);
    return index;
}

// Function to play the game
void play_game(Card* deck) {
    Card board[MAX_CARDS];
    int i, index1, index2, num_found = 0;
    for (i = 0; i < MAX_CARDS; i++) {
        board[i] = create_card("hidden", 0);
    }
    shuffle_deck(deck);
    print_board(board);
    while (num_found < MAX_CARDS) { // Keep playing until all cards have been found
        index1 = get_card_index(board);
        board[index1] = deck[index1];
        print_board(board);
        index2 = get_card_index(board);
        board[index2] = deck[index2];
        print_board(board);
        if (board[index1].value == board[index2].value) { // If the two flipped cards have the same value, mark them as found
            board[index1].found = 1;
            board[index2].found = 1;
            printf("\nMATCH FOUND!\n");
            num_found += 2; // Increase the number of cards found by 2
        } else { // If the two flipped cards do not have the same value, flip them back over
            printf("\nNO MATCH. TRY AGAIN.\n");
            board[index1] = create_card("hidden", 0);
            board[index2] = create_card("hidden", 0);
        }
        print_board(board);
    }
    printf("\nCONGRATULATIONS! YOU WIN!\n");
}

// Main function to run the game
int main() {
    Card deck[MAX_CARDS];
    init_deck(deck);
    srand(time(NULL));
    play_game(deck);
    return 0;
}