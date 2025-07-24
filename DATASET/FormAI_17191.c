//FormAI DATASET v1.0 Category: Poker Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to initialize a deck of cards */
void initializeDeck(int deck[])
{
    int i, j, k=0;
    for(i=0; i<4; i++) // Loop through suits
    {
        for(j=1; j<=13; j++) // Loop through ranks
        {
            deck[k++] = j; // Store each card in the deck
        }
    }
}

/* Function to shuffle the deck of cards */
void shuffleDeck(int deck[])
{
    int i, j, temp;
    for(i=51; i>=0; i--)
    {
        j = rand() % (i+1); // Generate random index to swap with
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

/* Function to print the rank of a card */
void printRank(int rank)
{
    switch(rank)
    {
        case 1:
            printf("Ace");
            break;
        case 2:
            printf("Two");
            break;
        case 3:
            printf("Three");
            break;
        case 4:
            printf("Four");
            break;
        case 5:
            printf("Five");
            break;
        case 6:
            printf("Six");
            break;
        case 7:
            printf("Seven");
            break;
        case 8:
            printf("Eight");
            break;
        case 9:
            printf("Nine");
            break;
        case 10:
            printf("Ten");
            break;
        case 11:
            printf("Jack");
            break;
        case 12:
            printf("Queen");
            break;
        case 13:
            printf("King");
            break;
        default:
            break;
    }
}

/* Function to determine the value of a hand */
int handValue(int hand[])
{
    int i, value=0, aces=0;
    for(i=0; i<5; i++)
    {
        if(hand[i] <= 10)
            value += hand[i];
        else if(hand[i] <= 13)
            value += 10;
        else
        {
            value +=1;
            aces++;
        }
    }
    while(value + 10 <= 21 && aces > 0) // Allow aces to be worth 11 if it doesn't bust the hand
    {
        value += 10;
        aces--;
    }
    return value;
}

/* Function to print the status of a hand */
void printHand(int hand[])
{
    int i;
    for(i=0; i<5; i++)
    {
        if(hand[i] != 0)
        {
            printRank(hand[i] % 13);
            switch(hand[i] / 13)
            {
                case 0:
                    printf(" of Diamonds\n");
                    break;
                case 1:
                    printf(" of Clubs\n");
                    break;
                case 2:
                    printf(" of Hearts\n");
                    break;
                case 3:
                    printf(" of Spades\n");
                    break;
                default:
                    break;
            }
        }
    }
}

/* Main function */
int main()
{
    int deck[52] = {0}, playerHand[5] = {0}, dealerHand[5] = {0}; // Initialize deck and hands
    int currentPlayerValue, dealerValue, pot=0, playerBet=0, dealerBet=0, turn=0;

    srand((unsigned int) time(NULL)); // Seed random number generator

    printf("Welcome to C Poker!\n");
    while(1) // Game loop
    {
        printf("\nPot: %d\n", pot);
        printf("Player's Bet: %d\n", playerBet);
        initializeDeck(deck);
        shuffleDeck(deck);

        playerHand[0] = deck[0];
        dealerHand[0] = deck[1];
        playerHand[1] = deck[2];
        dealerHand[1] = deck[3];
        currentPlayerValue = handValue(playerHand);
        dealerValue = handValue(dealerHand);

        printf("Player's Hand:\n");
        printHand(playerHand);
        printf("Value: %d\n", currentPlayerValue);

        printf("Dealer's Hand:\n");
        printRank(dealerHand[0] % 13);
        switch(dealerHand[0] / 13)
        {
            case 0:
                printf(" of Diamonds\n");
                break;
            case 1:
                printf(" of Clubs\n");
                break;
            case 2:
                printf(" of Hearts\n");
                break;
            case 3:
                printf(" of Spades\n");
                break;
            default:
                break;
        }

        if(currentPlayerValue == 21) // Player has blackjack
        {
            printf("BLACKJACK! Player wins!\n");
            pot -= playerBet;
            playerBet = 0;
            dealerBet = 0;
            continue;
        }
        else if(dealerValue == 21) // Dealer has blackjack
        {
            printf("Dealer has BLACKJACK! Dealer wins!\n");
            pot += dealerBet;
            playerBet = 0;
            dealerBet = 0;
            continue;
        }

        printf("Enter your bet: ");
        scanf("%d", &playerBet);
        if(playerBet > 100 || playerBet < 1) // Bet must be between 1 and 100 chips
        {
            printf("Invalid bet! Bet must be between 1 and 100 chips.\n");
            continue;
        }

        pot += playerBet;
        dealerBet = playerBet;

        while(1) // Player's turn
        {
            turn++;
            printf("Player's Turn %d\n", turn);
            printf("\nPot: %d\n", pot);
            printf("Player's Bet: %d\n", playerBet);

            printf("Player's Hand:\n");
            printHand(playerHand);
            printf("Value: %d\n", currentPlayerValue);

            if(currentPlayerValue == 21) // Player has 21
            {
                printf("Player has 21! Player wins!\n");
                pot -= playerBet;
                playerBet = 0;
                dealerBet = 0;
                break;
            }
            else if(currentPlayerValue > 21) // Player has busted
            {
                printf("Player has busted!Dealer wins!\n");
                pot += dealerBet;
                playerBet = 0;
                dealerBet = 0;
                break;
            }

            printf("Enter 1 to hit or 2 to stand: ");
            int choice;
            scanf("%d", &choice);
            if(choice == 1) // Player hits
            {
                playerHand[turn+1] = deck[4+turn];
                currentPlayerValue = handValue(playerHand);
            }
            else // Player stands
            {
                break;
            }
        }

        if(playerBet == 0 && dealerBet == 0) // Round is over, ask to play again
        {
            char choice;
            printf("\nPlay again? (y/n): ");
            scanf(" %c", &choice);
            if(choice == 'y')
            {
                continue;
            }
            else
            {
                printf("Thanks for playing!\n");
                return 0;
            }
        }

        printf("Dealer's Turn\n");
        printf("\nPot: %d\n", pot);
        printf("Dealer's Bet: %d\n", dealerBet);
        printf("Dealer's Hand:\n");
        printHand(dealerHand);
        printf("Value: %d\n", dealerValue);

        while(dealerValue < 17) // Dealer hits until value is 17 or greater
        {
            turn++;
            printf("Dealer's Turn %d\n", turn);

            dealerHand[turn+1] = deck[4+turn];
            dealerValue = handValue(dealerHand);

            printf("\nPot: %d\n", pot);
            printf("Dealer's Bet: %d\n", dealerBet);

            printf("Dealer's Hand:\n");
            printHand(dealerHand);
            printf("Value: %d\n", dealerValue);
        }

        if(dealerValue > 21) // Dealer has busted
        {
            printf("Dealer has busted! Player wins!\n");
            pot -= dealerBet;
            dealerBet = 0;
            playerBet = 0;
            continue;
        }
        else if(dealerValue > currentPlayerValue) // Dealer has higher value
        {
            printf("Dealer wins!\n");
            pot += dealerBet;
            dealerBet = 0;
            playerBet = 0;
        }
        else if(dealerValue < currentPlayerValue) // Player has higher value
        {
            printf("Player wins!\n");
            pot -= playerBet;
            dealerBet = 0;
            playerBet = 0;
        }
        else // Tie
        {
            printf("Tie!\n");
            dealerBet = 0;
            playerBet = 0;
        }

    }
    return 0;
}