//FormAI DATASET v1.0 Category: Poker Game ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*To simulate a deck of cards, the cards array will
contain the cards in the deck.*/

char *cards[]={"Ace of Hearts", "2 of Hearts", "3 of Hearts", "4 of Hearts", "5 of Hearts",
              "6 of Hearts", "7 of Hearts", "8 of Hearts", "9 of Hearts", "10 of Hearts",
              "Jack of Hearts", "Queen of Hearts", "King of Hearts", "Ace of Diamonds", 
              "2 of Diamonds", "3 of Diamonds", "4 of Diamonds", "5 of Diamonds", "6 of Diamonds",
              "7 of Diamonds", "8 of Diamonds", "9 of Diamonds", "10 of Diamonds", "Jack of Diamonds",
              "Queen of Diamonds", "King of Diamonds", "Ace of Spades", "2 of Spades", "3 of Spades",
              "4 of Spades", "5 of Spades", "6 of Spades", "7 of Spades", "8 of Spades", "9 of Spades",
              "10 of Spades", "Jack of Spades", "Queen of Spades", "King of Spades", "Ace of Clubs",
              "2 of Clubs", "3 of Clubs", "4 of Clubs", "5 of Clubs", "6 of Clubs", "7 of Clubs",
              "8 of Clubs", "9 of Clubs", "10 of Clubs", "Jack of Clubs", "Queen of Clubs", "King of Clubs"};

int main()
{
    int i, j, k, l, m, n;
    int bet=0, call=0, raise=0, opt=0;
    int player_card1=0, player_card2=0, dealer_card1=0, dealer_card2=0, flop1=0, flop2=0, flop3=0, turn=0, river=0, dealer_score=0, player_score=0, player_turn=1, pot=0;
    int player_fold=0, dealer_fold=0;
    char c;
    srand(time(0));
    
    printf("\nWelcome to C Poker!\n\n");
    
    while(1)
    {
        //game reset
        dealer_fold=0, player_fold=0, bet=0, call=0, raise=0, player_score=0, dealer_score=0, player_turn=1, pot=0;
        player_card1=rand()%52, player_card2=rand()%52;
        while(player_card2==player_card1)//If both cards are same
            player_card2=rand()%52;
        dealer_card1=rand()%52, dealer_card2=rand()%52;
        while(dealer_card2==dealer_card1||dealer_card1==player_card1||dealer_card1==player_card2||dealer_card2==player_card1||dealer_card2==player_card2)//If any card gets repeated
            dealer_card2=rand()%52;
        flop1=rand()%52, flop2=rand()%52, flop3=rand()%52;
        while(flop2==flop1||flop2==flop3||flop2==player_card1||flop2==player_card2||flop2==dealer_card1||flop2==dealer_card2||flop1==player_card1||flop1==player_card2||flop1==dealer_card1||flop1==dealer_card2||flop3==player_card1||flop3==player_card2||flop3==dealer_card1||flop3==dealer_card2)
            flop2=rand()%52;
        flop1=rand()%52;
        while(flop3==flop1||flop3==flop2||flop3==player_card1||flop3==player_card2||flop3==dealer_card1||flop3==dealer_card2||flop1==player_card1||flop1==player_card2||flop1==dealer_card1||flop1==dealer_card2||flop2==player_card1||flop2==player_card2||flop2==dealer_card1||flop2==dealer_card2)
            flop3=rand()%52;
        flop1=rand()%52;
        while(turn==river||turn==flop1||turn==flop2||turn==flop3||turn==player_card1||turn==player_card2||turn==dealer_card1||turn==dealer_card2)
            turn=rand()%52;
        flop1=rand()%52;
        while(river==turn||river==flop1||river==flop2||river==flop3||river==player_card1||river==player_card2||river==dealer_card1||river==dealer_card2)
            river=rand()%52;
        
        //display cards
        printf("\n\nPlayers cards:\n");
        printf("%s\n%s\n\n", cards[player_card1], cards[player_card2]);
        printf("Flop:\n");
        printf("%s\n%s\n%s\n\n", cards[flop1], cards[flop2], cards[flop3]);
        
        //**********PLAYER's TURN*********
        while(player_turn==1)
        {
            printf("Player's turn:");
            if(raise==0&&call==0)//only bet option is available
            {
                printf("\n\nWhat is your bet? ");
                scanf("%d", &bet);
                call=bet;
                pot+=bet;
                raise=1;
            }
            else if(raise==1)//all options are available
            {
                printf("\n\nYour options are: \n 1. Fold\n 2. Call %d\n 3. Raise\n\nWhat is your choice? ", call);
                scanf("%d", &opt);
                switch(opt)
                {
                    case 1: player_fold=1;
                            player_turn=0;
                            dealer_score+=pot;
                            pot=0;
                            break;
                    case 2: if(call<=dealer_score)//player doesn't have enough money to call
                                player_fold=1, player_turn=0, dealer_score+=pot, pot=0;
                            else
                                pot+=call;
                                player_score+=call;
                                player_turn=0;
                            break;
                    case 3: printf("\n\nWhat's your raise?");
                            scanf("%d", &bet);
                            pot+=call+bet;
                            player_score+=call+bet;
                            call+=bet;
                            break;
                }
            }
            
            //checking if player has enough to raise
            if(player_score+call>dealer_score)
            {
                opt=2;
                player_turn=0;
                printf("\n\nYour options are: \n 1. Fold\n 2. Call %d\n\nWhat is your choice? ", dealer_score-player_score);
                scanf("%d", &opt);
                switch(opt)
                {
                    case 1: player_fold=1;
                            dealer_score+=pot;
                            pot=0;
                            break;
                    case 2: pot+=dealer_score-player_score;
                            player_score=dealer_score;
                            player_turn=0;
                            break;
                }
            }
            
            if(player_score==dealer_score)
            {
                printf("\n\nDo you want to check or raise? (1/2)");
                scanf("%d", &opt);
                if(opt==2)
                {
                    printf("\n\nWhat's your raise?");
                    scanf("%d", &bet);
                    pot+=dealer_score+bet;
                    player_score+=bet;
                    call+=bet;
                    raise++;
                }
                player_turn=0;
            }
        }
        
        //player has folded
        if(player_fold==1)
        {
            printf("\n\nPlayer has folded.");
            continue;
        }
        
        //**********DEALER's TURN*********
        printf("\n\nDealer's cards:");
        printf("\n%s\n%s\n\n", cards[dealer_card1], cards[dealer_card2]);
        printf("Flop:\n");
        printf("%s\n%s\n%s\n", cards[flop1], cards[flop2], cards[flop3]);
        if(turn==0)
        {
            printf("\nTurn:");
            printf("\n%s\n", cards[turn]);
        }
        if(river==0)
        {
            printf("\n\nRiver:");
            printf("\n%s\n", cards[river]);
        }
        
        while(dealer_score<player_score)
        {
            if(dealer_fold==1)//if dealer folds
                break;
            printf("\n\nDealer's turn:");
            if(raise==1&&dealer_score<player_score)
            {
                if((dealer_score+call)>=player_score)//dealer cannot afford to call
                {
                    opt=1;
                }
                else
                {
                    opt=rand()%3;
                }
                switch(opt)
                {
                    case 0: dealer_fold=1;
                            printf("\n\nDealer has folded.");
                            player_score+=pot;
                            pot=0;
                            break;
                    case 1: dealer_score+=call;
                            pot+=call;
                            break;
                    case 2: bet=(rand()%20)*5;
                            if(dealer_score+bet>player_score)
                                dealer_fold=1, printf("\n\nDealer has folded."), player_score+=pot, pot=0;
                            else
                                dealer_score+=call+bet, pot+=call+bet, call+=bet;
                }
            }
            else if(raise==0&&dealer_score<player_score)
            {
                bet=rand()%100;
                if(bet<25)
                    dealer_fold=1, printf("\n\nDealer has folded."), player_score+=pot, pot=0;
                else
                    dealer_score+=bet, pot+=bet, call=bet, raise=1;
            }
            
            //checking if player has enough to raise
            if(player_score+call>dealer_score)
            {
                if(dealer_score>=player_score)
                    break;
                printf("\n\nDealer cannot afford to raise.\n\nDealer calls %d", player_score-dealer_score);
                dealer_score=player_score;
                pot+=call;
            }
            else
                printf("\n\nDealer calls %d", call);
            
            //displaying dealer's cards
            printf("\nDealer's cards:");
            if(dealer_score>=player_score)
                printf("\n%s\n%s", cards[dealer_card1], cards[dealer_card2]);
            else if(raise>1&&dealer_fold==0)
            {
                if(turn==0)
                {
                    turn=rand()%52;
                    while(turn==flop1||turn==flop2||turn==flop3||turn==player_card1||turn==player_card2||turn==dealer_card1||turn==dealer_card2)
                        turn=rand()%52;
                    printf("\nTurn:");
                    printf("\n%s\n", cards[turn]);
                }
                else if(river==0)
                {
                    river=rand()%52;
                    while(river==turn||river==flop1||river==flop2||river==flop3||river==player_card1||river==player_card2||river==dealer_card1||river==dealer_card2)
                        river=rand()%52;
                    printf("\n\nRiver:");
                    printf("\n%s\n", cards[river]);
                }
            }
        }
        
        if(dealer_fold)
            printf("\n\nPlayer wins!\n\n");
        else if(player_score>dealer_score)
            printf("\n\nPlayer wins!\n\n");
        else
            printf("\n\nDealer wins!\n\n");
        
        printf("Do you want to play again?(Y/N)");
        scanf(" %c", &c);
        if(c=='n'||c=='N')
            break;
    }
    return 0;
}