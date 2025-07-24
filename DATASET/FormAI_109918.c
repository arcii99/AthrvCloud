//FormAI DATASET v1.0 Category: Poker Game ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function prototypes
void shuffle(int *deck, int size);
void print_hand(int *hand, int size);
int evaluate_hand(int *hand, int size);
int get_high_card(int *hand, int size);
int get_pair(int *hand, int size);
int get_two_pair(int *hand, int size);
int get_three_of_a_kind(int *hand, int size);
int get_straight(int *hand, int size);
int get_flush(int *hand, int size);
int get_full_house(int *hand, int size);
int get_four_of_a_kind(int *hand, int size);
int get_straight_flush(int *hand, int size);
void deal(int *deck, int size, int **player_hands, int num_players, int hand_size);
void determine_winner(int **player_hands, int num_players, int hand_size);

//main function
int main() {
    int num_players=3;
    int hand_size=5;
    int deck[52];
    int *player_hands[num_players];
    srand(time(NULL));

    //initialize deck
    for(int i=0;i<52;i++){
        deck[i]=i+1;
    }

    //shuffle deck
    shuffle(deck,52);

    //allocate memory for player hands
    for(int i=0;i<num_players;i++){
        player_hands[i]=(int*)malloc(hand_size*sizeof(int));
    }

    //deal cards to players
    deal(deck,52,player_hands,num_players,hand_size);

    //print each player's hand
    for(int i=0;i<num_players;i++){
        printf("Player %d hand:\n",i+1);
        print_hand(player_hands[i],hand_size);
        printf("\n");
    }

    //determine winner
    determine_winner(player_hands,num_players,hand_size);

    //free memory for player hands
    for(int i=0;i<num_players;i++){
        free(player_hands[i]);
    }

    return 0;
}

//shuffle function
void shuffle(int *deck, int size){
    int temp;
    for(int i=0;i<size;i++){
        int random_index=rand()%size;
        temp=deck[i];
        deck[i]=deck[random_index];
        deck[random_index]=temp;
    }
}

//print_hand function
void print_hand(int *hand, int size){
    for(int i=0;i<size;i++){
        int suit=(hand[i]-1)/13;
        int rank=(hand[i]-1)%13;
        char suit_char;
        char rank_char;

        switch(suit){
            case 0:
                suit_char='C';
                break;
            case 1:
                suit_char='D';
                break;
            case 2:
                suit_char='H';
                break;
            case 3:
                suit_char='S';
                break;
        }

        switch(rank){
            case 0:
                rank_char='A';
                break;
            case 9:
                rank_char='T';
                break;
            case 10:
                rank_char='J';
                break;
            case 11:
                rank_char='Q';
                break;
            case 12:
                rank_char='K';
                break;
            default:
                rank_char=rank+'1';
        }

        printf("%c%c ",rank_char,suit_char);
    }
}

//evaluate_hand function
int evaluate_hand(int *hand, int size){
    if(get_straight_flush(hand,size)!=0){
        return 9;
    }
    else if(get_four_of_a_kind(hand,size)!=0){
        return 8;
    }
    else if(get_full_house(hand,size)!=0){
        return 7;
    }
    else if(get_flush(hand,size)!=0){
        return 6;
    }
    else if(get_straight(hand,size)!=0){
        return 5;
    }
    else if(get_three_of_a_kind(hand,size)!=0){
        return 4;
    }
    else if(get_two_pair(hand,size)!=0){
        return 3;
    }
    else if(get_pair(hand,size)!=0){
        return 2;
    }
    else{
        return 1;
    }
}

//get_high_card function
int get_high_card(int *hand, int size){
    int high_card=0;
    for(int i=0;i<size;i++){
        if(hand[i]%13>high_card){
            high_card=hand[i]%13;
        }
    }
    return high_card;
}

//get_pair function
int get_pair(int *hand, int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(hand[i]%13==hand[j]%13){
                return hand[i]%13;
            }
        }
    }
    return 0;
}

//get_two_pair function
int get_two_pair(int *hand, int size){
    int pair1=0;
    int pair2=0;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(hand[i]%13==hand[j]%13){
                if(pair1==0){
                    pair1=hand[i]%13;
                }
                else{
                    pair2=hand[i]%13;
                }
            }
        }
    }
    if(pair1!=0&&pair2!=0){
        return pair2*100+pair1;
    }
    else{
        return 0;
    }
}

//get_three_of_a_kind function
int get_three_of_a_kind(int *hand, int size){
    for(int i=0;i<size-2;i++){
        for(int j=i+1;j<size-1;j++){
            for(int k=j+1;k<size;k++){
                if(hand[i]%13==hand[j]%13&&hand[j]%13==hand[k]%13){
                    return hand[i]%13;
                }
            }
        }
    }
    return 0;
}

//get_straight function
int get_straight(int *hand, int size){
    int is_straight=1;
    for(int i=0;i<size-1;i++){
        if((hand[i]+1)%13!=hand[i+1]%13){
            is_straight=0;
            break;
        }
    }
    if(is_straight==1){
        return hand[size-1]%13;
    }
    else{
        return 0;
    }
}

//get_flush function
int get_flush(int *hand, int size){
    int count[4]={0};
    for(int i=0;i<size;i++){
        count[(hand[i]-1)/13]++;
    }
    for(int i=0;i<4;i++){
        if(count[i]>=5){
            return hand[size-1]%13;
        }
    }
    return 0;
}

//get_full_house function
int get_full_house(int *hand, int size){
    int pair=get_pair(hand,size);
    int three_of_a_kind=get_three_of_a_kind(hand,size);
    if(pair!=0&&three_of_a_kind!=0){
        return three_of_a_kind*100+pair;
    }
    else{
        return 0;
    }
}

//get_four_of_a_kind function
int get_four_of_a_kind(int *hand, int size){
    for(int i=0;i<size-3;i++){
        for(int j=i+1;j<size-2;j++){
            for(int k=j+1;k<size-1;k++){
                for(int l=k+1;l<size;l++){
                    if(hand[i]%13==hand[j]%13&&hand[j]%13==hand[k]%13&&hand[k]%13==hand[l]%13){
                        return hand[i]%13;
                    }
                }
            }
        }
    }
    return 0;
}

//get_straight_flush function
int get_straight_flush(int *hand, int size){
    int is_flush=get_flush(hand,size);
    int is_straight=get_straight(hand,size);
    if(is_flush!=0&&is_straight!=0){
        return is_straight;
    }
    else{
        return 0;
    }
}

//deal function
void deal(int *deck, int size, int **player_hands, int num_players, int hand_size){
    int card_index=0;
    for(int i=0;i<hand_size;i++){
        for(int j=0;j<num_players;j++){
            player_hands[j][i]=deck[card_index];
            card_index++;
        }
    }
}

//determine_winner function
void determine_winner(int **player_hands, int num_players, int hand_size){
    int max_eval=0;
    int winner=0;
    for(int i=0;i<num_players;i++){
        int eval=evaluate_hand(player_hands[i],hand_size);
        if(eval>max_eval){
            max_eval=eval;
            winner=i+1;
        }
        else if(eval==max_eval){
            int high_card1=get_high_card(player_hands[i],hand_size);
            int high_card2=get_high_card(player_hands[winner-1],hand_size);
            if(high_card1>high_card2){
                winner=i+1;
            }
        }
    }
    printf("Player %d wins with ",winner);
    switch(max_eval){
        case 1:
            printf("high card.\n");
            break;
        case 2:
            printf("a pair.\n");
            break;
        case 3:
            printf("two pairs.\n");
            break;
        case 4:
            printf("three of a kind.\n");
            break;
        case 5:
            printf("a straight.\n");
            break;
        case 6:
            printf("a flush.\n");
            break;
        case 7:
            printf("a full house.\n");
            break;
        case 8:
            printf("four of a kind.\n");
            break;
        case 9:
            printf("a straight flush.\n");
            break;
    }
}