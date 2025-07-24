//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
/*
* C Memory Game Example Program
*
* This program is designed to mimic a simple memory game where the player
* tries to match pairs of cards by flipping them over two at a time.
*
* Each card has an image on it and the images are randomly shuffled after each turn.
* The player wins when all cards have been matched.
*
* Written by [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5
#define MAX_CARDS 10

// Structure for each card
typedef struct card
{
    char image[20];
    int matched;
    int flipped;
} Card;

// Function prototypes
void init_cards(Card cards[]);
void shuffle_cards(Card cards[]);
void print_board(Card cards[]);
int select_card(int *row, int *col);
int check_match(Card cards[], int row1, int col1, int row2, int col2);
int check_win(Card cards[]);

int main()
{
    Card cards[MAX_CARDS];
    int row1, col1, row2, col2, match;
    
    srand(time(NULL)); // Initialize random seed
    
    init_cards(cards);
    shuffle_cards(cards);

    printf("*** WELCOME TO MEMORY GAME! ***\n\n");
    printf("Try to match all pairs of cards to win the game.\n");
    printf("Enter row and column of two cards to flip over (e.g. 1 2):\n\n");
    
    while(1)
    {
        print_board(cards);

        select_card(&row1, &col1);
        while(cards[row1*COLS + col1].matched || cards[row1*COLS + col1].flipped) // Check if card has been matched or flipped already
        {
            printf("\nThis card has already been matched or flipped. Please select again.\n\n");
            select_card(&row1, &col1);
        }

        cards[row1*COLS + col1].flipped = 1;
        print_board(cards);

        select_card(&row2, &col2);
        while(cards[row2*COLS + col2].matched || cards[row2*COLS + col2].flipped) // Check if card has been matched or flipped already
        {
            printf("\nThis card has already been matched or flipped. Please select again.\n\n");
            select_card(&row2, &col2);
        }

        cards[row2*COLS + col2].flipped = 1;
        print_board(cards);

        match = check_match(cards, row1, col1, row2, col2);

        if(match)
        {
            printf("\n*** MATCH FOUND! ***\n\n");
            cards[row1*COLS + col1].matched = 1;
            cards[row2*COLS + col2].matched = 1;
        } 
        else 
        {
            printf("\n*** NO MATCH FOUND! ***\n\n");
            cards[row1*COLS + col1].flipped = 0;
            cards[row2*COLS + col2].flipped = 0;
        }

        if(check_win(cards))
        {
            printf("\n******************************\n");
            printf("*** CONGRATULATIONS, YOU WIN! ***\n");
            printf("******************************\n");
            break;
        }
    }

    return 0;
}

// Initialize the cards
void init_cards(Card cards[])
{
    int i;

    for(i = 0; i < MAX_CARDS; i++)
    {
        sprintf(cards[i].image, "card%d.jpg", i/2 + 1);
        cards[i].matched = 0;
        cards[i].flipped = 0;
    }
}

// Shuffle the cards
void shuffle_cards(Card cards[])
{
    int i, j;
    Card temp;

    // Shuffle the cards
    for(i = 0; i < MAX_CARDS; i++)
    {
        j = rand() % MAX_CARDS;

        temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

// Print the board
void print_board(Card cards[])
{
    int i, j;

    printf(" ");
    for(i = 0; i < COLS; i++)
    {
        printf("   %d  ", i+1);
    }
    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        printf("%d ", i+1);
        for(j = 0; j < COLS; j++)
        {
            printf(" [%c] ", (cards[i*COLS + j].matched || !cards[i*COLS + j].flipped) ? ' ' : cards[i*COLS + j].image[4]);
        }
        printf("\n");
    }

    printf("\n");
}

// Select a card
int select_card(int *row, int *col)
{
    printf("Enter row and column of card: ");
    scanf("%d %d", row, col);
    (*row)--;
    (*col)--;
    return 1;
}

// Check if cards match
int check_match(Card cards[], int row1, int col1, int row2, int col2)
{
    if(strcmp(cards[row1*COLS + col1].image, cards[row2*COLS + col2].image) == 0)
    {
        return 1;
    }
    return 0;
}

// Check if all cards have been matched
int check_win(Card cards[])
{
    int i;
    for(i = 0; i < MAX_CARDS; i++)
    {
        if(!cards[i].matched)
        {
            return 0;
        }
    }
    return 1;
}