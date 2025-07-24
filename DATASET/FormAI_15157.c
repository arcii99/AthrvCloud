//FormAI DATASET v1.0 Category: Poker Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_CARDS 52
#define MAX_PLAYERS 6

struct card {
    char suit[10];
    char face[10];
    int value;
    int dealt;
};

struct player {
    char name[20];
    int chips;
    int folded;
    int curBet;
    struct card hand[2];
};

struct card deck[MAX_CARDS];
struct player players[MAX_PLAYERS];
int numPlayers = 0;
int pot = 0;
int curBet = 0;
int dealer = 0;
int smallBlind = 0;
int bigBlind = 0;
int communityCards[5];
int numCommunityCards = 0;
int round = 0;

void initializeDeck();
void shuffleDeck();
void dealHands();
void placeBlinds();
void flop();
void turn();
void river();
void resetRound();
void printHand(struct player p);
void printBoard();
void printPot();
void makeBet(struct player *p);
void checkBet();
void callBet(struct player *p);
void raiseBet(struct player *p, int amount);
void fold(struct player *p);
void endRound();
int winner();
void distributePot();
int getPlayerChoice();

int main() {
    int i, choice;
    printf("Welcome to the C Poker Game Example!\n");
    printf("How many players are there? (2-6): ");
    scanf("%d", &numPlayers);
    while(numPlayers < 2 || numPlayers > 6) {
        printf("Invalid number of players. Please enter a number between 2 and 6: ");
        scanf("%d", &numPlayers);
    }
    for(i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].chips = 1000;
        players[i].folded = 0;
        players[i].curBet = 0;
        players[i].hand[0].dealt = 0;
        players[i].hand[1].dealt = 0;
    }
    srand(time(NULL));
    initializeDeck();
    shuffleDeck();
    while(1) {
        printf("\n%s is the dealer!\n", players[dealer].name);
        resetRound();
        placeBlinds();
        dealHands();
        printf("\n");
        printBoard();
        printf("\n");
        checkBet();
        flop();
        printf("\n");
        printBoard();
        printf("\n");
        checkBet();
        turn();
        printf("\n");
        printBoard();
        printf("\n");
        checkBet();
        river();
        printf("\n");
        printBoard();
        printf("\n");
        checkBet();
        endRound();
        if(getPlayerChoice() == 1) {
            break;
        }
    }
    printf("Thanks for playing!\n");
    return 0;
}

void initializeDeck() {
    int i, j, val;
    char faces[13][10] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    char suits[4][10] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    for(i = 0; i < MAX_CARDS; i++) {
        strcpy(deck[i].face, faces[i % 13]);
        strcpy(deck[i].suit, suits[i / 13]);
        val = ((i % 13) + 2);
        if(val > 10) {
            val = 10;
        }
        deck[i].value = val;
        deck[i].dealt = 0;
    }
}

void shuffleDeck() {
    int i, j, r;
    struct card temp;
    for(i = MAX_CARDS - 1; i > 0; i--) {
        r = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealHands() {
    int i, j, cardNum = 0;
    for(i = 0; i < numPlayers; i++) {
        for(j = 0; j < 2; j++) {
            players[i].hand[j] = deck[cardNum];
            deck[cardNum].dealt = 1;
            cardNum++;
        }
    }
}

void placeBlinds() {
    int i;
    smallBlind = (dealer + 1) % numPlayers;
    bigBlind = (dealer + 2) % numPlayers;
    players[smallBlind].chips -= 10;
    players[smallBlind].curBet = 10;
    players[bigBlind].chips -= 20;
    players[bigBlind].curBet = 20;
    pot = 30;
    printf("\n%s is the small blind and has bet $10.\n", players[smallBlind].name);
    printf("%s is the big blind and has bet $20.\n", players[bigBlind].name);
    for(i = 0; i < numPlayers; i++) {
        if(i != smallBlind && i != bigBlind) {
            players[i].curBet = 0;
        }
    }
}

void flop() {
    int i, cardNum = 0;
    for(i = 0; i < 3; i++) {
        communityCards[i] = deck[MAX_PLAYERS * 2 + i].value;
        numCommunityCards++;
    }
}

void turn() {
    communityCards[3] = deck[MAX_PLAYERS * 2 + 3].value;
    numCommunityCards++;
}

void river() {
    communityCards[4] = deck[MAX_PLAYERS * 2 + 4].value;
    numCommunityCards++;
}

void resetRound() {
    int i;
    curBet = 0;
    round = 0;
    numCommunityCards = 0;
    pot = 0;
    for(i = 0; i < numPlayers; i++) {
        players[i].folded = 0;
        players[i].curBet = 0;
        players[i].hand[0].dealt = 0;
        players[i].hand[1].dealt = 0;
    }
    if(dealer == (numPlayers - 1)) {
        dealer = 0;
    } else {
        dealer++;
    }
}

void printHand(struct player p) {
    printf("%s's hand: %s of %s, %s of %s\n", p.name, p.hand[0].face, p.hand[0].suit, p.hand[1].face, p.hand[1].suit);
}

void printBoard() {
    int i;
    printf("Community Cards: ");
    for(i = 0; i < numCommunityCards; i++) {
        printf("%d of a kind%s", communityCards[i], i == numCommunityCards - 1 ? "." : ", ");
    }
    printf("\n");
    for(i = 0; i < numPlayers; i++) {
        printHand(players[i]);
    }
}

void printPot() {
    int i;
    printf("Pot: $%d\n", pot);
    for(i = 0; i < numPlayers; i++) {
        printf("%s has bet $%d.\n", players[i].name, players[i].curBet);
    }
}

void makeBet(struct player *p) {
    int maxBet = 0, choice, bet;
    maxBet = curBet;
    if(p->chips < maxBet) {
        maxBet = p->chips;
    }
    printf("%s, your turn to bet!\n", p->name);
    printf("You have %d chips and the current bet is $%d.\n", p->chips, curBet);
    printf("Would you like to (1) bet, (2) check, or (3) fold? ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("How much would you like to bet? (Maximum bet is $%d) ", maxBet);
            scanf("%d", &bet);
            while(bet > maxBet || bet < curBet) {
                printf("Invalid bet. Please enter a bet between %d and %d: ", curBet, maxBet);
                scanf("%d", &bet);
            }
            p->chips -= bet;
            p->curBet += bet;
            curBet = p->curBet;
            pot += p->curBet;
            break;
        case 2:
            if(curBet == 0) {
                printf("You checked.\n");
            } else {
                printf("You called the current bet of $%d.\n", curBet);
                p->chips -= curBet - p->curBet;
                p->curBet = curBet;
                pot += curBet - p->curBet;
            }
            break;
        case 3:
            fold(p);
            break;
        default:
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            makeBet(p);
            break;
    }
}

void checkBet() {
    int i, maxBet = 0;
    for(i = 0; i < numPlayers; i++) {
        if(!players[i].folded) {
            if(players[i].curBet > maxBet) {
                maxBet = players[i].curBet;
            }
        }
    }
    if(maxBet == curBet) {
        printf("All players have placed the same bet of $%d.\n", curBet);
    } else {
        printf("The current bet is $%d.\n", maxBet);
        curBet = maxBet;
    }
    printPot();
    for(i = (bigBlind + 1) % numPlayers; i != bigBlind; i = (i + 1) % numPlayers) {
        if(!players[i].folded) {
            if(players[i].curBet < curBet) {
                makeBet(&players[i]);
                if(players[i].curBet < curBet) {
                    i = (i - 1) % numPlayers;
                }
            }
        }
    }
}

void callBet(struct player *p) {
    if(curBet == 0) {
        printf("%s checked.\n", p->name);
    } else {
        printf("%s called the bet of $%d.\n", p->name, curBet);
        p->chips -= curBet - p->curBet;
        p->curBet = curBet;
        pot += curBet - p->curBet;
    }
}

void raiseBet(struct player *p, int amount) {
    printf("%s raised the bet to $%d.\n", p->name, curBet + amount);
    p->chips -= curBet + amount - p->curBet;
    p->curBet = curBet + amount;
    curBet = p->curBet;
    pot += p->curBet;
}

void fold(struct player *p) {
    printf("%s folded.\n", p->name);
    p->folded = 1;
}

void endRound() {
    int i, winningPlayer;
    while(1) {
        checkBet();
        for(i = 0; i < numPlayers; i++) {
            if(!players[i].folded) {
                makeBet(&players[i]);
            }
        }
        if(round == 3 || areAllBetsEqual()) {
            break;
        }
        round++;
    }
    winningPlayer = winner();
    if(winningPlayer == -1) {
        printf("There was a tie!\n");
        distributePot();
    } else {
        printf("%s wins the hand with a %d of a kind!\n", players[winningPlayer].name, communityCards[winningPlayer]);
        players[winningPlayer].chips += pot;
    }
}

int winner() {
    int i, maxVal = 0, maxIndex = -1, numMax = 0;
    for(i = 0; i < numPlayers; i++) {
        if(!players[i].folded) {
            if(communityCards[i] > maxVal) {
                maxVal = communityCards[i];
                maxIndex = i;
                numMax = 1;
            } else if(communityCards[i] == maxVal) {
                numMax++;
            }
        }
    }
    if(numMax == 1) {
        return maxIndex;
    }
    return -1;
}

void distributePot() {
    int i, numWinners = 0, winningPlayers[MAX_PLAYERS], chipsToSplit = 0, splitChipsPerPlayer = 0;
    for(i = 0; i < numPlayers; i++) {
        if(!players[i].folded) {
            chipsToSplit += players[i].curBet;
            winningPlayers[numWinners] = i;
            numWinners++;
        }
    }
    splitChipsPerPlayer = chipsToSplit / numWinners;
    for(i = 0; i < numWinners; i++) {
        players[winningPlayers[i]].chips += splitChipsPerPlayer;
    }
    printf("Each winning player gets %d chips.\n", splitChipsPerPlayer);
}

int getPlayerChoice() {
    int choice;
    printf("Play again? (1) Yes, (2) No ");
    scanf("%d", &choice);
    while(choice != 1 && choice != 2) {
        printf("Invalid choice. Please enter 1 or 2: ");
        scanf("%d", &choice);
    }
    return choice;
}

int areAllBetsEqual() {
    int i, cur = players[0].curBet;
    for(i = 1; i < numPlayers; i++) {
        if(players[i].folded) {
            continue;
        }
        if(players[i].curBet != cur) {
            return 0;
        }
    }
    return 1;
}