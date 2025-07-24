//FormAI DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

void play(int player)
{
    int num;
    printf("Player %d, enter a number: ", player);
    scanf("%d", &num);
    if (num > 0)
    {
        printf("Player %d entered %d\n",player, num);
        play(player == 1 ? 2 : 1);
    }
    else
    {
        printf("Player %d entered 0. Game Over!\n", player);
        exit(0);
    }
}

int main()
{
    printf("Game started!\n");
    play(1);
    return 0;
}