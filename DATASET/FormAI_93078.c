//FormAI DATASET v1.0 Category: Poker Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARD_COUNT 52
#define RANK_COUNT 13
#define SUIT_COUNT 4
#define HAND_SIZE 5

enum ranks { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum suits { CLUBS, DIAMONDS, HEARTS, SPADES };

struct card 
{
    int rank;
    int suit;
};

void init_deck(struct card deck[]) 
{
    int i, j, count = 0;
    for (i = ACE; i <= KING; i++)
        for (j = CLUBS; j <= SPADES; j++) 
        {
            deck[count].rank = i;
            deck[count].suit = j;
            count++;
        }
}

void shuffle_deck(struct card deck[], int num_cards) 
{
    int i, random_index;
    struct card temp;
    srand(time(NULL));
    for (i = 0; i < num_cards; i++) 
    {
        random_index = rand() % num_cards;
        temp = deck[i];
        deck[i] = deck[random_index];
        deck[random_index] = temp;
    }
}

void print_card(struct card c) 
{
    char* ranks[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    char* suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    printf("%s of %s\n", ranks[c.rank], suits[c.suit]);
}

void print_hand(struct card hand[], int size) 
{
    int i;
    for (i = 0; i < size; i++) 
    {
        print_card(hand[i]);
    }
}

void deal_player_hand(struct card deck[], struct card hand[]) 
{
    int i;
    for (i = 0; i < HAND_SIZE; i++) 
    {
        hand[i] = deck[i];
    }
}

int is_flush(struct card hand[]) 
{
    int i, suit = hand[0].suit;
    for (i = 1; i < HAND_SIZE; i++) 
    {
        if (hand[i].suit != suit) 
        {
            return 0;
        }
    }
    return 1;
}

void play_game() 
{
    struct card deck[CARD_COUNT];
    struct card player_hand[HAND_SIZE];
    int i;

    init_deck(deck);
    shuffle_deck(deck, CARD_COUNT);

    deal_player_hand(deck, player_hand);
    print_hand(player_hand, HAND_SIZE);

    if (is_flush(player_hand)) 
    {
        printf("Flush! You win!\n");
    } 
    else 
    {
        printf("Better luck next time.\n");
    }
}

int main() 
{
    play_game();
    return 0;
}