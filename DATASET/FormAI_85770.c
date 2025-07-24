//FormAI DATASET v1.0 Category: Poker Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 0 and 51
int generate_card()
{
    return rand() % 52;
}

// Function to convert card number to a string value
char* card_value(int card)
{
    char* values[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                      "Jack", "Queen", "King", "Ace", "Two", "Three", "Four", "Five", "Six",
                      "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace", "Two",
                      "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack",
                      "Queen", "King", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                      "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    return values[card];
}

// Function to convert card number to a string suit
char* card_suit(int card)
{
    char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades", "Hearts", "Diamonds", "Clubs", "Spades",
                     "Hearts", "Diamonds", "Clubs", "Spades", "Hearts", "Diamonds", "Clubs", "Spades",
                     "Hearts", "Diamonds", "Clubs", "Spades", "Hearts", "Diamonds", "Clubs", "Spades",
                     "Hearts", "Diamonds", "Clubs", "Spades", "Hearts", "Diamonds", "Clubs", "Spades",
                     "Hearts", "Diamonds", "Clubs", "Spades", "Hearts", "Diamonds", "Clubs", "Spades",
                     "Hearts", "Diamonds", "Clubs", "Spades", "Hearts", "Diamonds", "Clubs", "Spades"};
    return suits[card];
}

// Function to calculate the total value of hand
int hand_value(int hand[], int size)
{
    int total = 0;
    int aces = 0;
    for(int i=0; i<size; i++)
    {
        if(hand[i] % 13 >= 10)
        {
            total += 10;
        }
        else if(hand[i] % 13 == 0)
        {
            aces++;
            total += 11;
        }
        else
        {
            total += hand[i] % 13 + 2;
        }
    }
    while(total > 21 && aces > 0)
    {
        total -= 10;
        aces--;
    }
    return total;
}

int main()
{
    srand(time(NULL));  // Seed the random number generator
    
    int deck[52];  // Create a deck of 52 cards
    for(int i=0; i<52; i++)
    {
        deck[i] = i;
    }
    
    int player_hand[10];  // Player's hand
    int dealer_hand[10];  // Dealer's hand
    int player_score, dealer_score;
    int player_size = 0, dealer_size = 0;
    char choice;
    int card;
    
    // Deal the initial cards
    player_hand[player_size++] = generate_card();
    player_hand[player_size++] = generate_card();
    dealer_hand[dealer_size++] = generate_card();
    dealer_hand[dealer_size++] = generate_card();
    
    printf("Player:\n");
    printf("  %s of %s\n", card_value(player_hand[0]), card_suit(player_hand[0]));
    printf("  %s of %s\n", card_value(player_hand[1]), card_suit(player_hand[1]));
    
    printf("\nDealer:\n");
    printf("  %s of %s\n", card_value(dealer_hand[0]), card_suit(dealer_hand[0]));
    printf("  [Hidden]\n");
    
    // Player's turn
    while(1)
    {
        printf("\nDo you want to hit or stand? [h/s]\n");
        scanf(" %c", &choice);
        if(choice == 'h')
        {
            card = generate_card();
            player_hand[player_size++] = card;
            printf("  %s of %s\n", card_value(card), card_suit(card));
            player_score = hand_value(player_hand, player_size);
            if(player_score > 21)
            {
                printf("You bust! Dealer wins.\n");
                return 0;
            }
        }
        else if(choice == 's')
        {
            break;
        }
    }
    
    // Dealer's turn
    printf("\nDealer's turn:\n");
    printf("  %s of %s\n", card_value(dealer_hand[0]), card_suit(dealer_hand[0]));
    printf("  %s of %s\n", card_value(dealer_hand[1]), card_suit(dealer_hand[1]));
    while(dealer_score < 17)
    {
        card = generate_card();
        dealer_hand[dealer_size++] = card;
        printf("  %s of %s\n", card_value(card), card_suit(card));
        dealer_score = hand_value(dealer_hand, dealer_size);
        if(dealer_score > 21)
        {
            printf("Dealer busts! You win.\n");
            return 0;
        }
    }
    
    // Determine the winner
    player_score = hand_value(player_hand, player_size);
    dealer_score = hand_value(dealer_hand, dealer_size);
    printf("\nPlayer's score: %d\n", player_score);
    printf("Dealer's score: %d\n", dealer_score);
    if(player_score > dealer_score)
    {
        printf("You win!\n");
    }
    else if(player_score == dealer_score)
    {
        printf("It's a tie!\n");
    }
    else
    {
        printf("Dealer wins!\n");
    }
    
    return 0;
}