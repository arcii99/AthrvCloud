//FormAI DATASET v1.0 Category: Poker Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MAX_CARDS 52

typedef struct {
    char suit;
    char face[2];
} Card;

typedef struct {
    Card hand[2];
    int chips;
    int bet;
} Player;

int main(){
    srand(time(NULL));
    int numPlayers;

    do {
        printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
    } while(numPlayers < 1 || numPlayers > MAX_PLAYERS);

    Player players[MAX_PLAYERS];
    int currentPlayer = 0;
    char suits[] = {'H', 'D', 'C', 'S'};

    //Deal the cards
    Card deck[MAX_CARDS];
    int cardCount = 0;

    for(int i=0; i<4; i++){
        for(int j=1; j<=13; j++){
            deck[cardCount].suit = suits[i];
            sprintf(deck[cardCount].face, "%d", j);
            cardCount++;
        }
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<numPlayers; j++){
            int randomIndex = rand() % cardCount;
            players[j].hand[i] = deck[randomIndex];
            for(int k=randomIndex; k<cardCount-1; k++){
                deck[k] = deck[k+1];
            }
            cardCount--;
        }
    }

    //Print the initial hands
    for(int i=0; i<numPlayers; i++){
        printf("Player %d: %c%s %c%s\n", i+1, players[i].hand[0].suit, players[i].hand[0].face, players[i].hand[1].suit, players[i].hand[1].face);
    }

    //Place bets
    for(int i=0; i<numPlayers; i++){
        int bet;
        do {
            printf("Player %d, enter your bet (you have %d chips): ", i+1, players[i].chips);
            scanf("%d", &bet);
            if(bet > players[i].chips){
                printf("Invalid bet! You only have %d chips.\n", players[i].chips);
            }
        } while(bet > players[i].chips);

        players[i].chips -= bet;
        players[i].bet = bet;
    }

    //Flop
    cardCount--;
    Card flop[3];
    for(int i=0; i<3; i++){
        flop[i] = deck[cardCount];
        cardCount--;
    }
    printf("Flop: %c%s %c%s %c%s\n", flop[0].suit, flop[0].face, flop[1].suit, flop[1].face, flop[2].suit, flop[2].face);

    //Place bets again
    for(int i=0; i<numPlayers; i++){
        int bet;
        do {
            printf("Player %d, enter your bet (you have %d chips): ", i+1, players[i].chips);
            scanf("%d", &bet);
            if(bet > players[i].chips){
                printf("Invalid bet! You only have %d chips.\n", players[i].chips);
            } else if(bet < players[i].bet) {
                printf("Invalid bet! You must bet at least %d chips.\n", players[i].bet);
            }
        } while(bet > players[i].chips || bet < players[i].bet);

        players[i].chips -= bet;
        players[i].bet += bet;
    }

    //Turn
    cardCount--;
    Card turn = deck[cardCount];
    cardCount--;
    printf("Turn: %c%s\n", turn.suit, turn.face);

    //Place bets one more time
    for(int i=0; i<numPlayers; i++){
        int bet;
        do {
            printf("Player %d, enter your bet (you have %d chips): ", i+1, players[i].chips);
            scanf("%d", &bet);
            if(bet > players[i].chips){
                printf("Invalid bet! You only have %d chips.\n", players[i].chips);
            } else if(bet < players[i].bet) {
                printf("Invalid bet! You must bet at least %d chips.\n", players[i].bet);
            }
        } while(bet > players[i].chips || bet < players[i].bet);

        players[i].chips -= bet;
        players[i].bet += bet;
    }

    //River
    cardCount--;
    Card river = deck[cardCount];
    printf("River: %c%s\n", river.suit, river.face);

    //Evaluate hands
    int handValues[MAX_PLAYERS];
    for(int i=0; i<numPlayers; i++){
        Card allCards[7];
        allCards[0] = players[i].hand[0];
        allCards[1] = players[i].hand[1];
        allCards[2] = flop[0];
        allCards[3] = flop[1];
        allCards[4] = flop[2];
        allCards[5] = turn;
        allCards[6] = river;

        //Sort cards by face value
        for(int j=0; j<6; j++){
            for(int k=j+1; k<7; k++){
                if(atoi(allCards[k].face) > atoi(allCards[j].face)){
                    Card temp = allCards[j];
                    allCards[j] = allCards[k];
                    allCards[k] = temp;
                }
            }
        }

        //Check for royal flush
        if(allCards[0].face[0] == 'A' && allCards[1].face[0] == 'K' && allCards[2].face[0] == 'Q' && allCards[3].face[0] == 'J' && allCards[4].face[0] == 'T' && allCards[0].suit == allCards[1].suit && allCards[1].suit == allCards[2].suit && allCards[2].suit == allCards[3].suit && allCards[3].suit == allCards[4].suit){
            handValues[i] = 10;
        }
        //Check for straight flush
        else if(atoi(allCards[0].face) == atoi(allCards[1].face) + 1 && atoi(allCards[0].face) == atoi(allCards[2].face) + 2 && atoi(allCards[0].face) == atoi(allCards[3].face) + 3 && atoi(allCards[0].face) == atoi(allCards[4].face) + 4 && allCards[0].suit == allCards[1].suit && allCards[1].suit == allCards[2].suit && allCards[2].suit == allCards[3].suit && allCards[3].suit == allCards[4].suit){
            handValues[i] = 9;
        }
        //Check for four of a kind
        else if(atoi(allCards[0].face) == atoi(allCards[1].face) && atoi(allCards[0].face) == atoi(allCards[2].face) && atoi(allCards[0].face) == atoi(allCards[3].face) || atoi(allCards[1].face) == atoi(allCards[2].face) && atoi(allCards[1].face) == atoi(allCards[3].face) && atoi(allCards[1].face) == atoi(allCards[4].face)){
            handValues[i] = 8;
        }
        //Check for full house
        else if(atoi(allCards[0].face) == atoi(allCards[1].face) && atoi(allCards[0].face) == atoi(allCards[2].face) && atoi(allCards[3].face) == atoi(allCards[4].face) || atoi(allCards[0].face) == atoi(allCards[1].face) && atoi(allCards[2].face) == atoi(allCards[3].face) && atoi(allCards[2].face) == atoi(allCards[4].face)){
            handValues[i] = 7;
        }
        //Check for flush
        else if(allCards[0].suit == allCards[1].suit && allCards[1].suit == allCards[2].suit && allCards[2].suit == allCards[3].suit && allCards[3].suit == allCards[4].suit){
            handValues[i] = 6;
        }
        //Check for straight
        else if(atoi(allCards[0].face) == atoi(allCards[1].face) + 1 && atoi(allCards[0].face) == atoi(allCards[2].face) + 2 && atoi(allCards[0].face) == atoi(allCards[3].face) + 3 && atoi(allCards[0].face) == atoi(allCards[4].face) + 4){
            handValues[i] = 5;
        }
        //Check for three of a kind
        else if(atoi(allCards[0].face) == atoi(allCards[1].face) && atoi(allCards[0].face) == atoi(allCards[2].face) || atoi(allCards[1].face) == atoi(allCards[2].face) && atoi(allCards[1].face) == atoi(allCards[3].face) || atoi(allCards[2].face) == atoi(allCards[3].face) && atoi(allCards[2].face) == atoi(allCards[4].face)){
            handValues[i] = 4;
        }
        //Check for two pair
        else if(atoi(allCards[0].face) == atoi(allCards[1].face) && atoi(allCards[2].face) == atoi(allCards[3].face) || atoi(allCards[0].face) == atoi(allCards[1].face) && atoi(allCards[3].face) == atoi(allCards[4].face) || atoi(allCards[1].face) == atoi(allCards[2].face) && atoi(allCards[3].face) == atoi(allCards[4].face)){
            handValues[i] = 3;
        }
        //Check for pair
        else if(atoi(allCards[0].face) == atoi(allCards[1].face) || atoi(allCards[1].face) == atoi(allCards[2].face) || atoi(allCards[2].face) == atoi(allCards[3].face) || atoi(allCards[3].face) == atoi(allCards[4].face)){
            handValues[i] = 2;
        }
        //Otherwise, check for high card
        else {
            handValues[i] = 1;
        }

    }

    //Calculate the winner and distribute the pot
    int pot = 0;
    int winnerIndex;
    int winnerHandValue = 0;
    for(int i=0; i<numPlayers; i++){
        pot += players[i].bet;
        if(handValues[i] > winnerHandValue){
            winnerIndex = i;
            winnerHandValue = handValues[i];
        }
    }

    printf("Player %d wins the pot of %d chips with a hand value of %d!\n", winnerIndex+1, pot, winnerHandValue);

    //Quit
    return 0;
}