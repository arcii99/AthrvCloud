//FormAI DATASET v1.0 Category: Poker Game ; Style: paranoid
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int deck[52];
    int i,j,k,temp;

    // Initialize Deck
    for(i=0;i<52;i++)
        deck[i]=i+1;

    // Shuffle Deck 
    srand(time(NULL));
    for(i=0;i<52;i++)
    {
        j=rand()%52;
        k=rand()%52;
        temp=deck[j];
        deck[j]=deck[k];
        deck[k]=temp;
    }
    
    // Introduce the game
    printf("Welcome to the Paranoid Poker Game!\n");
    printf("You are playing against a highly advanced AI.\n");
    printf("Be careful - it's watching your every move.\n\n");
    
    // Deal Cards
    int user_cards[5], ai_cards[5];
    for(i=0;i<5;i++)
    {
        user_cards[i] = deck[i*2];
        ai_cards[i] = deck[i*2 + 1];
    }

    // Display User's Cards
    printf("Your Cards: ");
    for(i=0;i<5;i++)
        printf("%d ", user_cards[i]);
    printf("\n");

    // Decision Time
    int replace_cards[5];
    printf("Enter the numbers of the cards you want to replace: ");
    for(i=0;i<5;i++)
    {
        scanf("%d", &replace_cards[i]);
        for(j=0;j<i;j++)
        {
            if(replace_cards[j] == replace_cards[i])
            {
                printf("Duplicate card numbers entered. Try again.\n");
                i--;
                break;
            }
        }
    }

    // Replace User's Cards
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(user_cards[j] == replace_cards[i])
            {
                user_cards[j] = ai_cards[i];
                ai_cards[i] = deck[10-i-j];
                break;
            }
        }
    }

    // Display New Hands
    printf("\nYour New Cards: ");
    for(i=0;i<5;i++)
        printf("%d ", user_cards[i]);
    printf("\nAI's New Cards: ");
    for(i=0;i<5;i++)
        printf("%d ", ai_cards[i]);

    // Determine Winner
    printf("\n\nDetermining Winner...");
    int user_score = 0, ai_score = 0;
    for(i=0;i<5;i++)
    {
        int user_card_number = (user_cards[i]-1) % 13 + 1;
        int ai_card_number = (ai_cards[i]-1) % 13 + 1;
        if(user_card_number > ai_card_number)
            user_score++;
        else if(ai_card_number > user_card_number)
            ai_score++;
    }

    if(user_score > ai_score)
        printf("\n\nCongratulations! You have beaten the AI!");
    else if(ai_score > user_score)
        printf("\n\nSorry, the AI has defeated you.");
    else
        printf("\n\nIt's a tie.");

    return 0;
}