//FormAI DATASET v1.0 Category: Poker Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 6
#define MAX_CARDS 52
#define MAX_CARD_NAME 3
#define HAND_SIZE 5

/* Card structure */
struct card
{
    int value;
    char suit; 
    char name[MAX_CARD_NAME];
};

/* Player structure */
struct player
{
    int id;
    struct card hand[HAND_SIZE];
    int score;
};

/* Function to create a deck of cards */
void createDeck(struct card *deck)
{
    int i,j;
    int count = 0;
    char suits[] = {'S', 'H', 'D', 'C'};
    
    for(i=0; i<4; i++)
    {
        for(j=1; j<=13; j++)
        {
            deck[count].value = j;
            deck[count].suit = suits[i];

            if(j == 1)
            {
                strcpy(deck[count].name, "A");
            }
            else if(j == 11)
            {
                strcpy(deck[count].name, "J");
            }
            else if(j == 12)
            {
                strcpy(deck[count].name, "Q");
            }
            else if(j == 13)
            {
                strcpy(deck[count].name, "K");
            }
            else
            {
                sprintf(deck[count].name, "%d", j);
            }
            count++;
        }
    }
}

/* Function to shuffle the deck */
void shuffleDeck(struct card *deck)
{
    int i, j;
    struct card temp;

    for(i=0; i<MAX_CARDS; i++)
    {
        j = rand() % MAX_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

/* Function to deal a specific number of cards to each player */
void dealCards(struct player *players, struct card *deck, int numPlayers)
{
    int i,j,k;
    k = 0;
    for(i=0; i< numPlayers; i++)
    {
        for(j=0; j< HAND_SIZE; j++)
        {
            players[i].hand[j] = deck[k];
            k++;
        }
    }
}

/* Function to evaluate the poker hands for each player */
void evaluateHands(struct player *players, int numPlayers)
{
    int i,j,k;
    int pairs = 0;
    int threeOfAKind = 0;
    int fourOfAKind = 0;
    int flushFlag = 0;
    int straightFlag = 0;
    int fullHouseFlag = 0;
    int score = 0;
    int maxScore = 0;

    for(i=0; i<numPlayers; i++)
    {
        pairs = 0;
        threeOfAKind = 0;
        fourOfAKind = 0;
        flushFlag = 1;
        straightFlag = 1;
        fullHouseFlag = 0;
        score = 0;

        /* Evaluate for flush and straight */
        for(j=0; j<HAND_SIZE-1; j++)
        {
            if(players[i].hand[j].suit != players[i].hand[j+1].suit)
            {
                flushFlag = 0;
            }

            if(players[i].hand[j].value + 1 != players[i].hand[j+1].value)
            {
                straightFlag = 0;
            }
        }

        if(flushFlag == 1 && straightFlag == 1)
        {
            score = 9;
        }
        else
        {
            /* Evaluate for pairs, three of a kind, and four of a kind */
            for(j=0; j<HAND_SIZE-1; j++)
            {
                for(k=j+1; k<HAND_SIZE; k++)
                {
                    if(players[i].hand[j].value == players[i].hand[k].value)
                    {
                        pairs++;

                        if(pairs == 1)
                        {
                            score += 1;
                        }
                        else if(pairs == 2)
                        {
                            score += 2;

                            if(threeOfAKind == 1)
                            {
                                fullHouseFlag = 1;
                            }
                        }
                        else if(pairs == 3)
                        {
                            /* Four of a kind */
                            score += 6;
                            fourOfAKind = 1;
                        }
                    }
                }
            }

            /* Evaluate for three of a kind */
            for(j=0; j<HAND_SIZE-2; j++)
            {
                if(players[i].hand[j].value == players[i].hand[j+1].value && players[i].hand[j+1].value == players[i].hand[j+2].value)
                {
                    threeOfAKind = 1;

                    if(pairs >= 1)
                    {
                        fullHouseFlag = 1;
                    }
                }
            }

            if(threeOfAKind == 1 && pairs == 1)
            {
                /* Full house */
                score += 3;
                fullHouseFlag = 1;
            }
            else if(threeOfAKind == 1)
            {
                /* Three of a kind */
                score += 2;
            }

            if(maxScore < score)
            {
                maxScore = score;
            }

            if(fourOfAKind == 1)
            {
                maxScore = 6;
            }
            else if(fullHouseFlag == 1)
            {
                maxScore = 3;
            }
            else if(flushFlag == 1)
            {
                maxScore = 5;
            }
            else if(straightFlag == 1)
            {
                maxScore = 4;
            }
            else if(threeOfAKind == 1)
            {
                maxScore = 2;
            }
            else if(pairs == 2)
            {
                maxScore = 1;
            }
            else if(pairs == 1)
            {
                maxScore = 0;
            }
        }
        players[i].score = maxScore;
    }
}

/* Function to display the hands of each player */
void displayHands(struct player *players, int numPlayers)
{
    int i,j;

    for(i=0; i<numPlayers; i++)
    {
        printf("Player %d: ", players[i].id);
        
        for(j=0; j< HAND_SIZE; j++)
        {
            printf("%s%c ", players[i].hand[j].name, players[i].hand[j].suit);
        }
        
        printf("\n");
    }
}

/* Function to determine the winner of the game */
int determineWinner(struct player *players, int numPlayers)
{
    int i;
    int maxScore = 0;
    int winner = 0;

    for(i=0; i<numPlayers; i++)
    {
        if(players[i].score > maxScore)
        {
            maxScore = players[i].score;
            winner = i;
        }
        else if(players[i].score == maxScore)
        {
            /* Check high card */
            if(players[i].hand[HAND_SIZE-1].value > players[winner].hand[HAND_SIZE-1].value)
            {
                winner = i;
            }
        }
    }

    return winner;
}

int main()
{
    srand(time(NULL)); /* Set the random seed */
    struct card deck[MAX_CARDS];
    struct player players[MAX_PLAYERS];
    int numPlayers = 3;
    int winner;

    createDeck(deck);
    shuffleDeck(deck);
    dealCards(players, deck, numPlayers);
    displayHands(players, numPlayers);
    evaluateHands(players, numPlayers);
    winner = determineWinner(players, numPlayers);

    printf("The winner is player %d with a score of %d!\n", players[winner].id, players[winner].score);

    return 0;
}