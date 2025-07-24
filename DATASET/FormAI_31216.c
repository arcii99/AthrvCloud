//FormAI DATASET v1.0 Category: Poker Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int deck[]){
    int i, j, tmp;
    for(i=0; i<52; i++){
        j = rand()%52;
        tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
}

void display(int hand[]){
    int i;
    for(i=0; i<5; i++){
        switch(hand[i]){
            case 1: printf("2 ");
                    break;
            case 2: printf("3 ");
                    break;
            case 3: printf("4 ");
                    break;
            case 4: printf("5 ");
                    break;
            case 5: printf("6 ");
                    break;
            case 6: printf("7 ");
                    break;
            case 7: printf("8 ");
                    break;
            case 8: printf("9 ");
                    break;
            case 9: printf("10 ");
                    break;
            case 10: printf("J ");
                    break;
            case 11: printf("Q ");
                    break;
            case 12: printf("K ");
                    break;
            case 13: printf("A ");
                    break;
            default: break;
        }
    }
    printf("\n");
}

int get_score(int hand[]){
    int i, j, score = 0, aces = 0;
    for(i=0; i<5; i++){
        if(hand[i]<9) score += (hand[i]+2);
        else if(hand[i]<13) score += 10;
        else {
            score += 11;
            aces++;
        }
    }
    for(i=0; i<aces; i++){
        if(score>21) score -= 10;
    }
    return score;
}

int main(){
    int deck[52], hand[5], dealer_hand[5], i, score, dealer_score, player_money = 100, bet;
    srand(time(NULL));
    while(player_money>0){
        for(i=0; i<52; i++) deck[i] = i%13;
        shuffle(deck);
        hand[0] = deck[0]; dealer_hand[0] = deck[1];
        hand[1] = deck[2]; dealer_hand[1] = deck[3];
        score = get_score(hand);
        printf("Your hand: ");
        display(hand);
        while(1){
            printf("Enter bet: ");
            scanf("%d", &bet);
            if(bet>player_money) printf("You don't have enough money. ");
            else break;
        }
        player_money -= bet;
        printf("Dealer's hand: X ");
        display(dealer_hand+1);
        if(score==21){
            printf("Blackjack! You win %d dollars.\n", bet*2);
            player_money += bet*3;
            continue;
        }
        while(1){
            printf("Do you want to hit or stand? (h/s) ");
            char input;
            scanf(" %c", &input);
            if(input=='h'){
                hand[2] = deck[4];
                printf("Your hand: ");
                display(hand);
                score = get_score(hand);
                if(score>21){
                    printf("Busted! You lose %d dollars.\n", bet);
                    break;
                }
            } else break;
        }
        dealer_hand[1] = deck[3];
        dealer_score = get_score(dealer_hand);
        printf("Dealer's hand: ");
        display(dealer_hand);
        while(dealer_score<=16){
            dealer_hand[2] = deck[4];
            dealer_score = get_score(dealer_hand);
            printf("Dealer hits\n");
            printf("Dealer's hand: ");
            display(dealer_hand);
            if(dealer_score>21){
                printf("Dealer busts! You win %d dollars.\n", bet*2);
                player_money += bet*3;
                goto round_over;
            }
        }
        if(score>dealer_score || dealer_score>21){
            printf("You win %d dollars.\n", bet*2);
            player_money += bet*3;
        } else if(score==dealer_score){
            printf("Push! Your bet is returned.\n");
            player_money += bet;
        } else {
            printf("You lose %d dollars.\n", bet);
        }
        round_over:
        printf("You have %d dollars. ", player_money);
        printf("Do you want to continue playing? (y/n) ");
        char input2;
        scanf(" %c", &input2);
        if(input2=='n') break;
    }
    printf("Thanks for playing!\n");
    return 0;
}