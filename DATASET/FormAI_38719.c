//FormAI DATASET v1.0 Category: Poker Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_deck(int deck[52])
{
    int i, j;
    for (i = 0; i < 52; i++)
    {
        deck[i] = i;
    }
    for (i = 0; i < 52; i++)
    {
        j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

char* get_suit(int card)
{
    char* suit;
    int s = card/13;
    switch(s)
    {
        case 0:
            suit = "Spades";
            break;
        case 1:
            suit = "Hearts";
            break;
        case 2:
            suit = "Diamonds";
            break;
        case 3:
            suit = "Clubs";
            break;
        default:
            suit = "Unknown";
            break;
    }
    return suit;
}

char* get_face(int card)
{
    char* face;
    int f = card%13;
    switch(f)
    {
        case 0:
            face = "Ace";
            break;
        case 10:
            face = "Jack";
            break;
        case 11:
            face = "Queen";
            break;
        case 12:
            face = "King";
            break;
        default:
            face = malloc(2*sizeof(char));
            sprintf(face, "%d", f+1);
            break;
    }
    return face;
}

void print_card(int card)
{
    char* face = get_face(card);
    char* suit = get_suit(card);
    printf("%s of %s\n", face, suit);
    free(face);
}

void print_hand(int hand[5])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        print_card(hand[i]);
    }
    printf("\n");
}

int flush(int hand[5])
{
    int i, s;
    s = hand[0]/13;
    for (i = 1; i < 5; i++)
    {
        if (hand[i]/13 != s)
        {
            return 0;
        }
    }
    return 1;
}

int straight(int hand[5])
{
    int i, f0, f1;
    f1 = hand[0]%13;
    for (i = 1; i < 5; i++)
    {
        f0 = f1;
        f1 = hand[i]%13;
        if (f1 != (f0+1)%13)
        {
            return 0;
        }
    }
    return 1;
}

int straight_flush(int hand[5])
{
    if (straight(hand) && flush(hand))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int royal_flush(int hand[5])
{
    if (straight_flush(hand) && hand[0]%13 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int four_of_a_kind(int hand[5])
{
    int i, j, count;
    for (i = 0; i < 5; i++)
    {
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (hand[j]%13 == hand[i]%13)
            {
                count++;
            }
        }
        if (count == 4)
        {
            return 1;
        }
    }
    return 0;
}

int full_house(int hand[5])
{
    int i, j, count;
    int triple = 0;
    int pair = 0;
    for (i = 0; i < 5; i++)
    {
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (hand[j]%13 == hand[i]%13)
            {
                count++;
            }
        }
        if (count == 3)
        {
            triple = 1;
        }
        if (count == 2)
        {
            pair = 1;
        }
    }
    if (triple && pair)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int three_of_a_kind(int hand[5])
{
    int i, j, count;
    for (i = 0; i < 5; i++)
    {
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (hand[j]%13 == hand[i]%13)
            {
                count++;
            }
        }
        if (count == 3)
        {
            return 1;
        }
    }
    return 0;
}

int two_pair(int hand[5])
{
    int i, j, count;
    int pairs = 0;
    for (i = 0; i < 5; i++)
    {
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (hand[j]%13 == hand[i]%13)
            {
                count++;
            }
        }
        if (count == 2)
        {
            pairs++;
        }
    }
    if (pairs == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int one_pair(int hand[5])
{
    int i, j, count;
    for (i = 0; i < 5; i++)
    {
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (hand[j]%13 == hand[i]%13)
            {
                count++;
            }
        }
        if (count == 2)
        {
            return 1;
        }
    }
    return 0;
}

int hand_rank(int hand[5])
{
    if (royal_flush(hand))
    {
        return 10;
    }
    if (straight_flush(hand))
    {
        return 9;
    }
    if (four_of_a_kind(hand))
    {
        return 8;
    }
    if (full_house(hand))
    {
        return 7;
    }
    if (flush(hand))
    {
        return 6;
    }
    if (straight(hand))
    {
        return 5;
    }
    if (three_of_a_kind(hand))
    {
        return 4;
    }
    if (two_pair(hand))
    {
        return 3;
    }
    if (one_pair(hand))
    {
        return 2;
    }
    return 1;
}

int main()
{
    srand(time(NULL));
    int deck[52];
    int hand[5];
    int i, j, rank;
    char ch;

    initialize_deck(deck);

    printf("Welcome to the surprise Poker game!\n");
    printf("Press enter to start.\n");
    scanf("%c", &ch);
    printf("\n");

    for (i = 0; i < 5; i++)
    {
        hand[i] = deck[i];
    }

    printf("Your hand is:\n");
    print_hand(hand);

    rank = hand_rank(hand);
    switch(rank)
    {
        case 10:
            printf("Royal Flush!!\n");
            break;
        case 9:
            printf("Straight Flush!\n");
            break;
        case 8:
            printf("Four of a Kind!\n");
            break;
        case 7:
            printf("Full House!\n");
            break;
        case 6:
            printf("Flush!\n");
            break;
        case 5:
            printf("Straight!\n");
            break;
        case 4:
            printf("Three of a Kind!\n");
            break;
        case 3:
            printf("Two Pair!\n");
            break;
        case 2:
            printf("One Pair\n");
            break;
        default:
            printf("High Card\n");
            break;
    }

    return 0;
}