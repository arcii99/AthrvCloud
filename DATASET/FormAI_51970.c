//FormAI DATASET v1.0 Category: Table Game ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Surrealist Style C Table Game Example Program
int main()
{
    int i, j;
    char players[4][10] = {"Alice", "Bob", "Charlie", "David"};
    char verbs[4][10] = {"juggles", "eats", "paints", "skips"};
    char objects[4][10] = {"oranges", "burritos", "rainbows", "butterflies"};
    char adjectives[4][10] = {"spicy", "happy", "gigantic", "invisible"};
    char adverbs[4][10] = {"awkwardly", "bravely", "mysteriously", "quickly"};

    srand(time(0));
    printf("\t\t\t*** The Surrealist Table Game! ***\n\n");
    printf("Four friends, Alice, Bob, Charlie and David,\n");
    printf(" are sitting around a table and playing a surrealist word game.\n");
    printf("They take turns making sentences using random words from different categories.\n");
    printf("Let's see what kind of weird and wonderful sentences they come up with!\n\n");

    //Loop for each turn of the game
    for (i=0; i<10; i++)
    {
        printf("ROUND %d:\n", i+1);
        
        //Loop for each player's turn
        for (j=0; j<4; j++)
        {
            printf("Player %s ", players[j]);
            printf("%s ", verbs[rand()%4]);
            printf("%s ", objects[rand()%4]);
            printf("that is %s ", adjectives[rand()%4]);
            printf("%s.\n", adverbs[rand()%4]);
        }
        printf("\n");
    }

    printf("The game is over!\n");
    return 0;
}