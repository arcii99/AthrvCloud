//FormAI DATASET v1.0 Category: Table Game ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    char player1[20], player2[20];
    int p1_score=0, p2_score=0;
    int round=1;
    
    printf("Welcome to the Romeo and Juliet Table Game!\n");
    printf("Enter Player 1 name: ");
    scanf("%s", player1);
    printf("Enter Player 2 name: ");
    scanf("%s", player2);
    printf("Let's begin!\n");

    while(round<=10)
    {
        printf("Round %d\n", round);
        printf("%s, it's your turn.\n", player1);
        int p1_number = rand()%6 + 1;
        printf("%s rolled: %d\n", player1, p1_number);

        printf("%s, it's your turn.\n", player2);
        int p2_number = rand()%6 + 1;
        printf("%s rolled: %d\n", player2, p2_number);

        if(p1_number>p2_number){
            printf("%s wins this round!\n\n", player1);
            p1_score++;
        }
        else if(p1_number<p2_number){
            printf("%s wins this round!\n\n", player2);
            p2_score++;
        }
        else{
            printf("It's a tie!\n\n");
        }
        round++;
    }

    printf("--------------------\n");
    printf("Final Scores:\n");
    printf("%s: %d\n", player1, p1_score);
    printf("%s: %d\n", player2, p2_score);

    if(p1_score>p2_score){
        printf("%s wins the game!\n", player1);
    }
    else if(p1_score<p2_score){
        printf("%s wins the game!\n", player2);
    }
    else{
        printf("It's a tie!\n");
    }

    return 0;
}