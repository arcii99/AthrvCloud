//FormAI DATASET v1.0 Category: Poker Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum {CLUBS, DIAMONDS, HEARTS, SPADES} Suit;
const char* suit_names[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

typedef enum {ACE, KING, QUEEN, JACK, TEN, NINE, EIGHT, SEVEN, SIX, FIVE, FOUR, THREE, TWO} Rank;
const char* rank_names[] = {"Ace", "King", "Queen", "Jack", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two"};

typedef struct card
{
    Suit suit;
    Rank rank;
} Card;

const Card deck[DECK_SIZE] = {
    {CLUBS, ACE}, {CLUBS, KING}, {CLUBS, QUEEN}, {CLUBS, JACK}, {CLUBS, TEN}, {CLUBS, NINE}, {CLUBS, EIGHT}, {CLUBS, SEVEN}, {CLUBS, SIX}, {CLUBS, FIVE}, {CLUBS, FOUR}, {CLUBS, THREE}, {CLUBS, TWO},
    {DIAMONDS, ACE}, {DIAMONDS, KING}, {DIAMONDS, QUEEN}, {DIAMONDS, JACK}, {DIAMONDS, TEN}, {DIAMONDS, NINE}, {DIAMONDS, EIGHT}, {DIAMONDS, SEVEN}, {DIAMONDS, SIX}, {DIAMONDS, FIVE}, {DIAMONDS, FOUR}, {DIAMONDS, THREE}, {DIAMONDS, TWO},
    {HEARTS, ACE}, {HEARTS, KING}, {HEARTS, QUEEN}, {HEARTS, JACK}, {HEARTS, TEN}, {HEARTS, NINE}, {HEARTS, EIGHT}, {HEARTS, SEVEN}, {HEARTS, SIX}, {HEARTS, FIVE}, {HEARTS, FOUR}, {HEARTS, THREE}, {HEARTS, TWO},
    {SPADES, ACE}, {SPADES, KING}, {SPADES, QUEEN}, {SPADES, JACK}, {SPADES, TEN}, {SPADES, NINE}, {SPADES, EIGHT}, {SPADES, SEVEN}, {SPADES, SIX}, {SPADES, FIVE}, {SPADES, FOUR}, {SPADES, THREE}, {SPADES, TWO}
};

int cmp_card(const void* a, const void* b)
{
    Card a_card = *(Card*)a;
    Card b_card = *(Card*)b;
    if(a_card.rank > b_card.rank)
        return -1;
    else if(a_card.rank < b_card.rank)
        return 1;
    else
        return 0;
}

int is_royal_flush(Card* hand)
{
    if(hand[0].rank == ACE && hand[1].rank == KING && hand[2].rank == QUEEN && hand[3].rank == JACK && hand[4].rank == TEN && hand[0].suit == hand[1].suit && hand[0].suit == hand[2].suit && hand[0].suit == hand[3].suit && hand[0].suit == hand[4].suit)
        return 1;
    else
        return 0;
}

int is_straight_flush(Card* hand)
{
    int i;
    for(i = 0;i < HAND_SIZE - 1;i++)
    {
        if(hand[i].rank - hand[i + 1].rank != 1 || hand[i].suit != hand[i + 1].suit)
            return 0;
    }
    return 1;
}

int is_four_of_a_kind(Card* hand)
{
    if(hand[0].rank == hand[1].rank && hand[1].rank == hand[2].rank && hand[2].rank == hand[3].rank)
        return 1;
    else if(hand[1].rank == hand[2].rank && hand[2].rank == hand[3].rank && hand[3].rank == hand[4].rank)
        return 1;
    else
        return 0;
}

int is_full_house(Card* hand)
{
    if(hand[0].rank == hand[1].rank && hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank)
        return 1;
    else if(hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank && hand[3].rank == hand[4].rank)
        return 1;
    else
        return 0;
}

int is_flush(Card* hand)
{
    if(hand[0].suit == hand[1].suit && hand[0].suit == hand[2].suit && hand[0].suit == hand[3].suit && hand[0].suit == hand[4].suit)
        return 1;
    else
        return 0;
}

int is_straight(Card* hand)
{
    int i;
    for(i = 0;i < HAND_SIZE - 1;i++)
    {
        if(hand[i].rank - hand[i + 1].rank != 1)
            return 0;
    }
    return 1;
}

int is_three_of_a_kind(Card* hand)
{
    if(hand[0].rank == hand[1].rank && hand[1].rank == hand[2].rank)
        return 1;
    else if(hand[1].rank == hand[2].rank && hand[2].rank == hand[3].rank)
        return 1;
    else if(hand[2].rank == hand[3].rank && hand[3].rank == hand[4].rank)
        return 1;
    else
        return 0;
}

int is_two_pair(Card* hand)
{
    if(hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank)
        return 1;
    else if(hand[0].rank == hand[1].rank && hand[3].rank == hand[4].rank)
        return 1;
    else if(hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank)
        return 1;
    else
        return 0;
}

int is_one_pair(Card* hand)
{
    if(hand[0].rank == hand[1].rank)
        return 1;
    else if(hand[1].rank == hand[2].rank)
        return 1;
    else if(hand[2].rank == hand[3].rank)
        return 1;
    else if(hand[3].rank == hand[4].rank)
        return 1;
    else
        return 0;
}

char* hand_name(Card* hand)
{
    if(is_royal_flush(hand))
        return "Royal Flush";
    else if(is_straight_flush(hand))
        return "Straight Flush";
    else if(is_four_of_a_kind(hand))
        return "Four of a Kind";
    else if(is_full_house(hand))
        return "Full House";
    else if(is_flush(hand))
        return "Flush";
    else if(is_straight(hand))
        return "Straight";
    else if(is_three_of_a_kind(hand))
        return "Three of a Kind";
    else if(is_two_pair(hand))
        return "Two Pair";
    else if(is_one_pair(hand))
        return "One Pair";
    else
        return "High Card";
}

void shuffle(Card* deck)
{
    int i;
    for(i = 0;i < DECK_SIZE;i++)
    {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(Card* deck, Card* hand, int num_cards)
{
    int i;
    for(i = 0;i < num_cards;i++)
    {
        hand[i] = deck[i];
    }
}

void print_card(Card card)
{
    printf("%s of %s\n", rank_names[card.rank], suit_names[card.suit]);
}

void print_hand(Card* hand, int num_cards)
{
    int i;
    for(i = 0;i < num_cards;i++)
    {
        print_card(hand[i]);
    }
}

int main()
{
    srand(time(NULL));

    Card deck_copy[DECK_SIZE];
    int i;
    for(i = 0;i < DECK_SIZE;i++)
    {
        deck_copy[i] = deck[i];
    }

    shuffle(deck_copy);

    Card hand[HAND_SIZE];
    deal_cards(deck_copy, hand, HAND_SIZE);

    qsort(hand, HAND_SIZE, sizeof(Card), cmp_card);

    printf("Your hand:\n");
    print_hand(hand, HAND_SIZE);

    printf("Hand name: %s\n", hand_name(hand));

    return 0;
}