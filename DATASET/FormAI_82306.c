//FormAI DATASET v1.0 Category: Poker Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

enum suits { HEARTS, DIAMONDS, CLUBS, SPADES };
enum ranks { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

typedef struct
{
    int rank;
    int suit;
} card;

void initialise_deck(card *deck);
void shuffle_deck(card *deck);
void deal_cards(card *deck, card *hand);
void print_hand(card *hand);
int evaluate_hand(card *hand);

int main()
{
    card deck[DECK_SIZE];
    card hand[HAND_SIZE];
    int score;

    initialise_deck(deck);
    shuffle_deck(deck);
    deal_cards(deck, hand);
    print_hand(hand);
    score = evaluate_hand(hand);
    printf("Score: %d", score);

    return 0;
}

void initialise_deck(card *deck)
{
    int i, j;

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 13; j++)
        {
            deck[i*13 + j].rank = j;
            deck[i*13 + j].suit = i;
        }
    }
}

void shuffle_deck(card *deck)
{
    int i;
    card temp;

    srand(time(NULL));
    for(i = 0; i < DECK_SIZE; i++)
    {
        int j = rand() % DECK_SIZE;

        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(card *deck, card *hand)
{
    int i;

    for(i = 0; i < HAND_SIZE; i++)
    {
        hand[i] = deck[i];
    }
}

void print_hand(card *hand)
{
    int i;

    for(i = 0; i < HAND_SIZE; i++)
    {
        switch(hand[i].rank)
        {
            case ACE:
                printf("Ace ");
                break;
            case TWO:
                printf("Two ");
                break;
            case THREE:
                printf("Three ");
                break;
            case FOUR:
                printf("Four ");
                break;
            case FIVE:
                printf("Five ");
                break;
            case SIX:
                printf("Six ");
                break;
            case SEVEN:
                printf("Seven ");
                break;
            case EIGHT:
                printf("Eight ");
                break;
            case NINE:
                printf("Nine ");
                break;
            case TEN:
                printf("Ten ");
                break;
            case JACK:
                printf("Jack ");
                break;
            case QUEEN:
                printf("Queen ");
                break;
            case KING:
                printf("King ");
                break;
        }

        switch(hand[i].suit)
        {
            case HEARTS:
                printf("of Hearts\n");
                break;
            case DIAMONDS:
                printf("of Diamonds\n");
                break;
            case CLUBS:
                printf("of Clubs\n");
                break;
            case SPADES:
                printf("of Spades\n");
                break;          
        }
    }
}

int evaluate_hand(card *hand)
{
    int i, j;
    int score = 0;
    int straight, flush, pairs;

    for(i = 0; i < HAND_SIZE; i++)
    {
        if(hand[i].rank == ACE)
        {
            score += 14;
        }
        else
        {
            score += hand[i].rank + 1;
        }
    }

    straight = 1;
    for(i = 0; i < HAND_SIZE - 1; i++)
    {
        if(hand[i].rank != hand[i+1].rank - 1)
        {
            straight = 0;
            break;
        }
    }

    flush = 1;
    for(i = 0; i < HAND_SIZE - 1; i++)
    {
        if(hand[i].suit != hand[i+1].suit)
        {
            flush = 0;
            break;
        }
    }

    pairs = 0;
    for(i = 0; i < HAND_SIZE - 1; i++)
    {
        for(j = i + 1; j < HAND_SIZE; j++)
        {
            if(hand[i].rank == hand[j].rank)
            {
                pairs++;
            }
        }
    }

    if(straight && flush && hand[0].rank == 10)
    {
        score = 100;
    }
    else if(straight && flush && hand[0].rank != 10)
    {
        score = 75;
    }
    else if(pairs == 6)
    {
        score = 50;
    }
    else if(pairs == 4)
    {
        score = 25;
    }
    else if(flush)
    {
        score = 20;
    }
    else if(straight)
    {
        score = 15;
    }
    else if(pairs == 3)
    {
        score = 10;
    }

    return score;
}