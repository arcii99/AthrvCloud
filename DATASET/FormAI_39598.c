//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int num_dice, num_sides, num_players, max_score, i, j, roll, total;
    printf("Welcome to the Dice Game!\n");
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &num_sides);
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    printf("Enter the maximum score required to win: ");
    scanf("%d", &max_score);

    int scores[num_players];

    printf("Rolling %d dice with %d sides %d times for %d players\n", num_dice, num_sides, max_score, num_players);

    srand(time(0));

    for(i=0; i<num_players; i++){
        scores[i] = 0;
    }

    while(1){
        for(i=0; i<num_players; i++){
            total = 0;
            printf("Player %d's turn. Press Enter to roll.", i+1);
            getchar();
            for(j=0; j<num_dice; j++){
                roll = rand()%num_sides + 1;
                printf("Player %d rolls a %d\n", i+1, roll);
                total += roll;
            }
            printf("Player %d scores %d for this round\n", i+1, total);
            scores[i] += total;
            if(scores[i]>=max_score){
                printf("Player %d wins!\n", i+1);
                return 0;
            }
        }
    }

    return 0;
}