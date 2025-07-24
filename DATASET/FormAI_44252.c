//FormAI DATASET v1.0 Category: Poker Game ; Style: ephemeral
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 0 and n
int rand_num(int n)
{
    srand(time(NULL));  // Seed the random number generator
    int random_num = rand() % n;  // Generate a random number between 0 and n
    return random_num;
}

// Function to shuffle the deck of cards
void shuffle(int *deck)
{
    for (int i = 0; i < 52; i++)
    {
        int random_index = rand_num(52);
        // Swap the values at index i and random_index
        int temp = deck[i];
        deck[i] = deck[random_index];
        deck[random_index] = temp;
    }
}

// Function to print the cards in a hand
void print_hand(int *hand, int num_cards_in_hand)
{
    for (int i = 0; i < num_cards_in_hand; i++)
    {
        // Print the rank of the card
        if (hand[i] % 13 == 0)
        {
            printf("Ace");
        }
        else if (hand[i] % 13 == 10)
        {
            printf("Jack");
        }
        else if (hand[i] % 13 == 11)
        {
            printf("Queen");
        }
        else if (hand[i] % 13 == 12)
        {
            printf("King");
        }
        else
        {
            printf("%d", (hand[i] % 13) + 1);
        }
        // Print the suit of the card
        if (hand[i] / 13 == 0)
        {
            printf(" of Hearts\n");
        }
        else if (hand[i] / 13 == 1)
        {
            printf(" of Diamonds\n");
        }
        else if (hand[i] / 13 == 2)
        {
            printf(" of Clubs\n");
        }
        else if (hand[i] / 13 == 3)
        {
            printf(" of Spades\n");
        }
    }
}

int main()
{
    // Initialize the deck of cards
    int deck[52];
    for (int i = 0; i < 52; i++)
    {
        deck[i] = i;
    }

    shuffle(deck);

    // Initialize the player and computer's hands
    int player_hand[2], computer_hand[2];
    player_hand[0] = deck[0];
    computer_hand[0] = deck[1];
    player_hand[1] = deck[2];
    computer_hand[1] = deck[3];

    printf("Player's hand:\n");
    print_hand(player_hand, 2);
    printf("Computer's hand:\n");
    print_hand(computer_hand, 2);

    return 0;
}