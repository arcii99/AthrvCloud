//FormAI DATASET v1.0 Category: Poker Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5
#define MAX_PLAYERS 6

typedef enum {
    HEARTS, DIAMONDS, CLUBS, SPADES
} Suit;

typedef struct {
    Suit suit;
    int value;
} Card;

typedef struct {
    Card cards[HAND_SIZE];
    int rank;
} Hand;

typedef struct {
    int money;
    Hand hand;
    int hasFolded;
} Player;

typedef struct {
    Card deck[DECK_SIZE];
    int turn;
    int pot;
    int currentBet;
    int dealer;
    int smallBlind;
    int bigBlind;
    Player players[MAX_PLAYERS];
    int numPlayers;
} Game;

void shuffleDeck(Card deck[]) {
    int i;
    Card temp;
    for(i=0; i<DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void initializeDeck(Card deck[]) {
    int i;
    for(i=0; i<DECK_SIZE; i++) {
        int value = (i % 13) + 1;
        Suit suit;
        if(i < 13) {
            suit = HEARTS;
        }
        else if(i < 26) {
            suit = DIAMONDS;
        }
        else if(i < 39) {
            suit = CLUBS;
        }
        else {
            suit = SPADES;
        }
        deck[i] = (Card) {suit, value};
    }
}

void dealHands(Game* game) {
    int i, j;
    for(i=0; i<HAND_SIZE; i++) {
        for(j=0; j<game->numPlayers; j++) {
            if(!game->players[j].hasFolded) {
                game->players[j].hand.cards[i] = game->deck[game->numPlayers*i + j];
            }
        }
    }
}

void printCard(Card card) {
    char* suitStr;
    switch(card.suit) {
        case HEARTS:
            suitStr = "H";
            break;
        case DIAMONDS:
            suitStr = "D";
            break;
        case CLUBS:
            suitStr = "C";
            break;
        case SPADES:
            suitStr = "S";
            break;
    }
    printf("%d%s ", card.value, suitStr);
}

void printHand(Hand hand) {
    int i;
    for(i=0; i<HAND_SIZE; i++) {
        printCard(hand.cards[i]);
    }
    printf("\n");
}

void printPlayer(Player player) {
    printf("Hand: ");
    printHand(player.hand);
    printf("Money: $%d\n", player.money);
}

int compareCards(const void* card1Ptr, const void* card2Ptr) {
    Card card1 = *(Card*) card1Ptr;
    Card card2 = *(Card*) card2Ptr;
    return card2.value - card1.value;
}

int getHighestValueCard(Hand hand, int numToCheck) {
    qsort(hand.cards, HAND_SIZE, sizeof(Card), compareCards);
    return hand.cards[numToCheck-1].value;
}

int areAllCardsSameSuit(Hand hand) {
    int i;
    Suit suit = hand.cards[0].suit;
    for(i=1; i<HAND_SIZE; i++) {
        if(hand.cards[i].suit != suit) {
            return 0;
        }
    }
    return 1;
}

int isStraight(Hand hand) {
    int i;
    qsort(hand.cards, HAND_SIZE, sizeof(Card), compareCards);
    if(hand.cards[0].value == 1 && hand.cards[1].value == 10) {
        for(i=1; i<HAND_SIZE-1; i++) {
            if(hand.cards[i].value != hand.cards[i+1].value-1) {
                return 0;
            }
        }
        return 1;
    }
    else {
        for(i=0; i<HAND_SIZE-1; i++) {
            if(hand.cards[i].value != hand.cards[i+1].value-1) {
                return 0;
            }
        }
        return 1;
    }
}

int isFlush(Hand hand) {
    return areAllCardsSameSuit(hand);
}

int isStraightFlush(Hand hand) {
    return isStraight(hand) && isFlush(hand);
}

int isRoyalFlush(Hand hand) {
    qsort(hand.cards, HAND_SIZE, sizeof(Card), compareCards);
    return hand.cards[0].value == 1 && isStraightFlush(hand);
}

int isFourOfAKind(Hand hand) {
    int i;
    qsort(hand.cards, HAND_SIZE, sizeof(Card), compareCards);
    if(hand.cards[0].value == hand.cards[3].value) {
        return 1;
    }
    else if(hand.cards[1].value == hand.cards[4].value) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFullHouse(Hand hand) {
    int i;
    qsort(hand.cards, HAND_SIZE, sizeof(Card), compareCards);
    if(hand.cards[0].value == hand.cards[1].value && hand.cards[2].value == hand.cards[4].value) {
        return 1;
    }
    else if(hand.cards[0].value == hand.cards[2].value && hand.cards[3].value == hand.cards[4].value) {
        return 1;
    }
    else {
        return 0;
    }
}

int isThreeOfAKind(Hand hand) {
    int i;
    qsort(hand.cards, HAND_SIZE, sizeof(Card), compareCards);
    for(i=0; i<=2; i++) {
        if(hand.cards[i].value == hand.cards[i+2].value) {
            return 1;
        }
    }
    return 0;
}

int isTwoPair(Hand hand) {
    int i;
    int numPairs = 0;
    qsort(hand.cards, HAND_SIZE, sizeof(Card), compareCards);
    for(i=0; i<=2; i++) {
        if(hand.cards[i].value == hand.cards[i+1].value) {
            numPairs++;
            i++;
        }
    }
    return numPairs == 2;
}

int isPair(Hand hand) {
    int i;
    qsort(hand.cards, HAND_SIZE, sizeof(Card), compareCards);
    for(i=0; i<=3; i++) {
        if(hand.cards[i].value == hand.cards[i+1].value) {
            return 1;
        }
    }
    return 0;
}

int getHandRank(Hand hand) {
    if(isRoyalFlush(hand)) {
        return 10;
    }
    else if(isStraightFlush(hand)) {
        return 9;
    }
    else if(isFourOfAKind(hand)) {
        return 8;
    }
    else if(isFullHouse(hand)) {
        return 7;
    }
    else if(isFlush(hand)) {
        return 6;
    }
    else if(isStraight(hand)) {
        return 5;
    }
    else if(isThreeOfAKind(hand)) {
        return 4;
    }
    else if(isTwoPair(hand)) {
        return 3;
    }
    else if(isPair(hand)) {
        return 2;
    }
    else {
        return 1;
    }
}

void evaluateHand(Hand* hand) {
    hand->rank = getHandRank(*hand);
}

void exchangeCards(Game* game) {
    int i, j;
    for(i=0; i<game->numPlayers; i++) {
        if(game->players[i].hasFolded) {
            continue;
        }
        printf("Player %d, enter card positions to exchange (0-4) or -1 to keep all:\n", i+1);
        char input[16];
        fgets(input, 16, stdin);
        if(input[0] == '-') {
            continue;
        }
        int exchangeIndices[HAND_SIZE];
        int numToExchange = 0;
        int numRead = 0;
        char* token = strtok(input, " \n");
        while(token != NULL) {
            int val = atoi(token);
            if(val >= 0 && val < HAND_SIZE && val != numRead) {
                exchangeIndices[numToExchange++] = val;
            }
            numRead++;
            token = strtok(NULL, " \n");
        }
        for(j=0; j<numToExchange; j++) {
            game->players[i].hand.cards[exchangeIndices[j]] = game->deck[game->numPlayers*HAND_SIZE + i*numToExchange + j];
        }
        evaluateHand(&game->players[i].hand);
    }
}

void printGameState(Game* game) {
    printf("*** Turn %d ***\n", game->turn);
    printf("Pot: $%d\n", game->pot);
    printf("Current bet: $%d\n", game->currentBet);
    printf("Dealer: %d\n", game->dealer);
    printf("Small blind: %d\n", game->smallBlind);
    printf("Big blind: %d\n", game->bigBlind);
    int i;
    for(i=0; i<game->numPlayers; i++) {
        printf("Player %d:\n", i+1);
        printPlayer(game->players[i]);
    }
}

void dealFlop(Game* game) {
    int i;
    for(i=0; i<3; i++) {
        game->players[game->dealer+1+i].hand.cards[HAND_SIZE+i] = game->deck[game->numPlayers*HAND_SIZE + game->numPlayers*3 + i];
    }
}

void dealCard(Game* game) {
    game->players[game->turn].hand.cards[HAND_SIZE+3] = game->deck[game->numPlayers*HAND_SIZE + game->numPlayers*3 + 3 + game->turn];
}

void determineWinner(Game* game) {
    int i, j;
    for(i=0; i<game->numPlayers; i++) {
        evaluateHand(&game->players[i].hand);
    }
    int bestHandRank = 0;
    for(i=0; i<game->numPlayers; i++) {
        if(!game->players[i].hasFolded && game->players[i].hand.rank > bestHandRank) {
            bestHandRank = game->players[i].hand.rank;
        }
    }
    int numWinners = 0;
    int winners[MAX_PLAYERS];
    for(i=0; i<game->numPlayers; i++) {
        if(game->players[i].hand.rank == bestHandRank) {
            winners[numWinners++] = i;
        }
    }
    int winningsPerPlayer = game->pot / numWinners;
    printf("Winning hand(s):\n");
    for(i=0; i<numWinners; i++) {
        printHand(game->players[winners[i]].hand);
        game->players[winners[i]].money += winningsPerPlayer;
    }
    printf("All winning players receive $%d\n", winningsPerPlayer);
    for(i=0; i<game->numPlayers; i++) {
        if(game->players[i].money == 0) {
            printf("Player %d is out of money. They must leave the game.\n", i+1);
            game->numPlayers--;
            for(j=i; j<game->numPlayers; j++) {
                game->players[j] = game->players[j+1];
            }
        }
    }
}

void playGame() {
    srand(time(NULL));
    Game game;
    game.numPlayers = 6;
    game.dealer = -1;
    game.smallBlind = 5;
    game.bigBlind = 10;
    int i, j;

    printf("Welcome to C Poker Game!\n");

    for(i=0; i<game.numPlayers; i++) {
        game.players[i].money = 500;
    }

    while(game.numPlayers > 1) {
        game.pot = 0;
        game.turn = (game.dealer+1) % game.numPlayers;
        game.currentBet = game.bigBlind;
        game.dealer = (game.dealer+1) % game.numPlayers;

        for(i=0; i<game.numPlayers; i++) {
            game.players[i].hasFolded = 0;
        }

        printf("\n*** New round ***\n\n");
        initializeDeck(game.deck);
        shuffleDeck(game.deck);
        dealHands(&game);
        exchangeCards(&game);
        printGameState(&game);

        // pre-flop betting
        for(i=0; i<game.numPlayers; i++) {
            int playerIndex = (game.turn+i) % game.numPlayers;
            if(game.players[playerIndex].hasFolded) {
                continue;
            }
            int betAmount;
            if(i == 0) {
                betAmount = game.smallBlind;
            }
            else if(i == 1) {
                betAmount = game.bigBlind;
            }
            else {
                printf("Player %d, enter bet amount or -1 to fold:\n", playerIndex+1);
                scanf("%d", &betAmount);
                getchar();
                if(betAmount == -1) {
                    game.players[playerIndex].hasFolded = 1;
                    continue;
                }
            }
            if(betAmount > game.players[playerIndex].money) {
                betAmount = game.players[playerIndex].money;
            }
            game.players[playerIndex].money -= betAmount;
            game.pot += betAmount;
            if(betAmount > game.currentBet) {
                game.currentBet = betAmount;
            }
        }

        // flop
        dealFlop(&game);
        printGameState(&game);

        // post-flop betting
        for(i=0; i<game.numPlayers; i++) {
            int playerIndex = (game.turn+i) % game.numPlayers;
            if(game.players[playerIndex].hasFolded) {
                continue;
            }
            int betAmount;
            printf("Player %d, enter bet amount or -1 to fold:\n", playerIndex+1);
            scanf("%d", &betAmount);
            getchar();
            if(betAmount == -1) {
                game.players[playerIndex].hasFolded = 1;
                continue;
            }
            if(betAmount > game.players[playerIndex].money) {
                betAmount = game.players[playerIndex].money;
            }
            game.players[playerIndex].money -= betAmount;
            game.pot += betAmount;
            if(betAmount > game.currentBet) {
                game.currentBet = betAmount;
            }
        }

        // turn
        dealCard(&game);
        printGameState(&game);

        // post-turn betting
        for(i=0; i<game.numPlayers; i++) {
            int playerIndex = (game.turn+i) % game.numPlayers;
            if(game.players[playerIndex].hasFolded) {
                continue;
            }
            int betAmount;
            printf("Player %d, enter bet amount or -1 to fold:\n", playerIndex+1);
            scanf("%d", &betAmount);
            getchar();
            if(betAmount == -1) {
                game.players[playerIndex].hasFolded = 1;
                continue;
            }
            if(betAmount > game.players[playerIndex].money) {
                betAmount = game.players[playerIndex].money;
            }
            game.players[playerIndex].money -= betAmount;
            game.pot += betAmount;
            if(betAmount > game.currentBet) {
                game.currentBet = betAmount;
            }
        }

        // river
        dealCard(&game);
        printGameState(&game);

        // post-river betting
        for(i=0; i<game.numPlayers; i++) {
            int playerIndex = (game.turn+i) % game.numPlayers;
            if(game.players[playerIndex].hasFolded) {
                continue;
            }
            int betAmount;
            printf("Player %d, enter bet amount or -1 to fold:\n", playerIndex+1);
            scanf("%d", &betAmount);
            getchar();
            if(betAmount == -1) {
                game.players[playerIndex].hasFolded = 1;
                continue;
            }
            if(betAmount > game.players[playerIndex].money) {
                betAmount = game.players[playerIndex].money;
            }
            game.players[playerIndex].money -= betAmount;
            game.pot += betAmount;
            if(betAmount > game.currentBet) {
                game.currentBet = betAmount;
            }
        }

        determineWinner(&game);
    }

    printf("Game over! Player %d is the winner!\n", game.players[0].money == 0 ? 2 : 1);
}

int main() {
    playGame();
    return 0;
}