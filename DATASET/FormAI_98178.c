//FormAI DATASET v1.0 Category: Poker Game ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TRUE 1
#define FALSE 0

// structure for a card
typedef struct card{
    int number;
    char *suit;
} Card;

// structure for a player
typedef struct player{
    char *name;
    int money;
    Card hand[2];
} Player;

// global variables
Player players[2];
int pot = 0;
int turn = 1;
Card community_cards[5];

// function prototypes
void initialize_deck(Card deck[]);
void shuffle_deck(Card deck[]);
void deal_cards(Card deck[], Player *players, int num_players);
void print_cards(Player player);
void print_community_cards();
int get_bet(Player *player);
void deal_flop(Card deck[], Card community_cards[]);
void deal_turn(Card deck[], Card community_cards[]);
void deal_river(Card deck[], Card community_cards[]);
void determine_winner(Player players[], Card community_cards[], int num_players);
void print_winners(Player players[], int winners[], int num_winners);

int main(){
    // initialize deck
    Card deck[52];
    initialize_deck(deck);

    // shuffle deck
    srand((unsigned int)time(NULL));
    int i, j;
    for(i = 0; i < 52; i++){
        j = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // deal cards
    int num_players = 2;
    deal_cards(deck, players, num_players);

    // take bets
    pot = 0;
    for(i = 0; i < num_players; i++){
        players[i].money -= get_bet(&players[i]);
        pot += players[i].money;
    }

    // deal flop
    deal_flop(deck, community_cards);

    // take bets
    turn++;
    for(i = 0; i < num_players; i++){
        if(players[i].money == 0) continue;
        players[i].money -= get_bet(&players[i]);
        pot += players[i].money;
    }

    // deal turn
    deal_turn(deck, community_cards);

    // take bets
    turn++;
    for(i = 0; i < num_players; i++){
        if(players[i].money == 0) continue;
        players[i].money -= get_bet(&players[i]);
        pot += players[i].money;
    }

    // deal river
    deal_river(deck, community_cards);

    // take bets
    turn++;
    for(i = 0; i < num_players; i++){
        if(players[i].money == 0) continue;
        players[i].money -= get_bet(&players[i]);
        pot += players[i].money;
    }

    // determine winner
    determine_winner(players, community_cards, num_players);

    // print winners
    int winners[num_players];
    int num_winners = 0;
    for(i = 0; i < num_players; i++){
        if(players[i].money > 0){
            winners[num_winners] = i;
            num_winners++;
        }
    }
    print_winners(players, winners, num_winners);

    return 0;
}

void initialize_deck(Card deck[]){
    int i;
    for(i = 0; i < 52; i++){
        deck[i].number = (i % 13) + 2;
        switch(i / 13){
            case 0:
                deck[i].suit = "hearts";
                break;
            case 1:
                deck[i].suit = "diamonds";
                break;
            case 2:
                deck[i].suit = "clubs";
                break;
            case 3:
                deck[i].suit = "spades";
                break;
        }
    }
}

void shuffle_deck(Card deck[]){
    int i, j;
    for(i = 0; i < 52; i++){
        j = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(Card deck[], Player *players, int num_players){
    int i, j;
    for(i = 0; i < num_players; i++){
        printf("Player %d, enter your name: ", i+1);
        players[i].name = (char*)malloc(sizeof(char)*256);
        scanf("%s", players[i].name);
        players[i].money = 100;
        players[i].hand[0] = deck[i*2];
        players[i].hand[1] = deck[i*2+1];
    }
}

void print_cards(Player player){
    printf("%s's hand:\n", player.name);
    printf("%d of %s\n", player.hand[0].number, player.hand[0].suit);
    printf("%d of %s\n", player.hand[1].number, player.hand[1].suit);
}

void print_community_cards(){
    int i;
    printf("Community cards:\n");
    for(i = 0; i < turn; i++){
        printf("%d of %s\n", community_cards[i].number, community_cards[i].suit);
    }
}

int get_bet(Player *player){
    char choice;
    int bet;
    printf("%s's turn:\n", player->name);
    print_cards(*player);
    printf("Pot: %d\n", pot);
    printf("Your money: %d\n", player->money);
    printf("Enter 'f' to fold, 'c' to check, or 'b' to bet: ");
    scanf(" %c", &choice);
    switch(choice){
        case 'f':
            printf("%s has folded\n", player->name);
            return 0;
        case 'c':
            printf("%s has checked\n", player->name);
            return 0;
        case 'b':
            printf("Enter your bet: ");
            scanf("%d", &bet);
            while(bet > player->money){
                printf("You don't have that much money\n");
                printf("Enter your bet: ");
                scanf("%d", &bet);
            }
            printf("%s has bet %d\n", player->name, bet);
            return bet;
        default:
            printf("Invalid choice, try again\n");
            return get_bet(player);
    }
}

void deal_flop(Card deck[], Card community_cards[]){
    int i;
    printf("Dealing flop...\n");
    for(i = 0; i < 3; i++){
        community_cards[i] = deck[2+i];
    }
    print_community_cards();
}

void deal_turn(Card deck[], Card community_cards[]){
    printf("Dealing turn...\n");
    community_cards[3] = deck[5];
    print_community_cards();
}

void deal_river(Card deck[], Card community_cards[]){
    printf("Dealing river...\n");
    community_cards[4] = deck[6];
    print_community_cards();
}

void determine_winner(Player players[], Card community_cards[], int num_players){
    int i, j, k, l;
    int max_score = 0;
    int score;
    int winner = -1;
    for(i = 0; i < num_players; i++){
        if(players[i].money == 0) continue;
        for(j = 0; j < 5; j++){
            for(k = j+1; k < 5; k++){
                Card temp[7];
                for(l = 0; l < 2; l++){
                    temp[l] = players[i].hand[l];
                }
                for(l = 0; l < 5; l++){
                    if(l != j && l != k){
                        temp[l+2] = community_cards[l];
                    }
                }
                score = get_score(temp, 7);
                if(score > max_score){
                    max_score = score;
                    winner = i;
                }
            }
        }
    }
    players[winner].money += pot;
    printf("%s has won the pot of %d!\n", players[winner].name, pot);
}

void print_winners(Player players[], int winners[], int num_winners){
    int i;
    printf("Winner(s):\n");
    for(i = 0; i < num_winners; i++){
        printf("%s\n", players[winners[i]].name);
    }
}

int get_score(Card hand[], int size){
    int i, j;
    int score = 0;
    for(i = 0; i < size; i++){
        for(j = i+1; j < size; j++){
            if(hand[i].number == hand[j].number){
                score++;
            }
        }
    }
    return score;
}