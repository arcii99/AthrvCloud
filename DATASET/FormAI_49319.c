//FormAI DATASET v1.0 Category: Poker Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_PLAYERS 4

typedef enum
{
    INVALID = -1,
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
} Suit;

typedef enum
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
} Rank;

typedef struct
{
    Rank rank;
    Suit suit;
} Card;

void shuffle(Card *deck, int size);
void print_card(Card card);
void print_hand(Card *hand, int size);
int compare_ranks(const void *a, const void *b);
int calculate_hand_value(Card *hand, int size);
int is_bust(int value);
int is_blackjack(int value);
int play_game();

int main()
{
    srand(time(NULL));
    play_game();
    return 0;
}

void shuffle(Card *deck, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        int j = rand() % size;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(Card card)
{
    switch (card.rank)
    {
        case ACE:
            printf("A");
            break;
        case JACK:
            printf("J");
            break;
        case QUEEN:
            printf("Q");
            break;
        case KING:
            printf("K");
            break;
        default:
            printf("%d", card.rank);
    }

    printf(" of ");

    switch (card.suit)
    {
        case CLUBS:
            printf("Clubs");
            break;
        case DIAMONDS:
            printf("Diamonds");
            break;
        case HEARTS:
            printf("Hearts");
            break;
        case SPADES:
            printf("Spades");
            break;
        default:
            printf("Invalid");
    }

    printf("\n");
}

void print_hand(Card *hand, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        print_card(hand[i]);
    }
}

int compare_ranks(const void *a, const void *b)
{
    Card *card_a = (Card *)a;
    Card *card_b = (Card *)b;

    if (card_a->rank < card_b->rank)
    {
        return -1;
    }
    else if (card_a->rank > card_b->rank)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int calculate_hand_value(Card *hand, int size)
{
    int i;
    int ace_count = 0;
    int value = 0;

    for (i = 0; i < size; i++)
    {
        switch (hand[i].rank)
        {
            case ACE:
                ace_count++;
                value += 11;
                break;
            case JACK:
            case QUEEN:
            case KING:
                value += 10;
                break;
            default:
                value += hand[i].rank;
        }
    }

    while (ace_count > 0 && value > 21)
    {
        value -= 10;
        ace_count--;
    }

    return value;
}

int is_bust(int value)
{
    return value > 21 ? 1 : 0;
}

int is_blackjack(int value)
{
    return value == 21 ? 1 : 0;
}

int play_game()
{
    Card deck[DECK_SIZE];
    int i, j, k;
    int player_scores[NUM_PLAYERS];
    Card player_hands[NUM_PLAYERS][10];
    int player_hand_sizes[NUM_PLAYERS];
    int dealer_score;
    Card dealer_hand[10];
    int dealer_hand_size;

    // Create deck
    k = 0;
    for (i = 1; i <= 13; i++)
    {
        for (j = CLUBS; j <= SPADES; j++)
        {
            deck[k].rank = (Rank)i;
            deck[k].suit = (Suit)j;
            k++;
        }
    }

    // Shuffle deck
    shuffle(deck, DECK_SIZE);

    // Deal initial cards
    for (i = 0; i < NUM_PLAYERS; i++)
    {
        player_hands[i][0] = deck[i*2];
        player_hands[i][1] = deck[i*2+1];
        player_hand_sizes[i] = 2;
        player_scores[i] = calculate_hand_value(player_hands[i], player_hand_sizes[i]);

        printf("Player %d's initial hand:\n", i+1);
        print_hand(player_hands[i], player_hand_sizes[i]);

        if (is_blackjack(player_scores[i]))
        {
            printf("Player %d has Blackjack!\n", i+1);
            player_scores[i] = 21;
        }
        else if (is_bust(player_scores[i]))
        {
            printf("Player %d has bust!\n", i+1);
            player_scores[i] = 0;
        }
        else
        {
            while (player_scores[i] < 17)
            {
                player_hands[i][player_hand_sizes[i]] = deck[i*2 + player_hand_sizes[i]];
                player_hand_sizes[i]++;
                player_scores[i] = calculate_hand_value(player_hands[i], player_hand_sizes[i]);

                printf("Player %d drew:\n", i+1);
                print_card(player_hands[i][player_hand_sizes[i]-1]);

                if (is_bust(player_scores[i]))
                {
                    printf("Player %d has bust!\n", i+1);
                    player_scores[i] = 0;
                    break;
                }
            }
        }

        printf("Player %d's score: %d\n", i+1, player_scores[i]);
    }

    // Deal dealer's cards
    dealer_hand[0] = deck[NUM_PLAYERS*2];
    dealer_hand[1] = deck[NUM_PLAYERS*2+1];
    dealer_hand_size = 2;
    dealer_score = calculate_hand_value(dealer_hand, dealer_hand_size);

    printf("\nDealer's initial hand:\n");
    print_card(dealer_hand[0]);
    printf("Unknown card\n");

    if (is_blackjack(dealer_score))
    {
        printf("Dealer has Blackjack!\n");
        dealer_score = 21;
    }
    else if (is_bust(dealer_score))
    {
        printf("Dealer has bust!\n");
        dealer_score = 0;
    }
    else
    {
        while (dealer_score < 17)
        {
            dealer_hand[dealer_hand_size] = deck[NUM_PLAYERS*2 + dealer_hand_size];
            dealer_hand_size++;
            dealer_score = calculate_hand_value(dealer_hand, dealer_hand_size);

            printf("Dealer drew:\n");
            print_card(dealer_hand[dealer_hand_size-1]);

            if (is_bust(dealer_score))
            {
                printf("Dealer has bust!\n");
                dealer_score = 0;
                break;
            }
        }
    }

    printf("Dealer's score: %d\n\n", dealer_score);

    // Determine winners
    int max_score = 0;
    int winners[NUM_PLAYERS];
    int num_winners = 0;

    for (i = 0; i < NUM_PLAYERS; i++)
    {
        if (player_scores[i] > max_score && player_scores[i] <= 21)
        {
            max_score = player_scores[i];
        }
    }

    for (i = 0; i < NUM_PLAYERS; i++)
    {
        if (player_scores[i] == max_score)
        {
            winners[num_winners] = i;
            num_winners++;
        }
    }

    if (dealer_score > max_score && dealer_score <= 21)
    {
        printf("Dealer wins!\n");
    }
    else if (dealer_score == max_score)
    {
        printf("Push!\n");
    }
    else
    {
        printf("Players ");
        for (i = 0; i < num_winners; i++)
        {
            printf("%d ", winners[i]+1);
        }
        printf("win!\n");
    }

    return 0;
}