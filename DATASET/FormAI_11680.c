//FormAI DATASET v1.0 Category: Dice Roller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice()
{
    return rand() % 6 + 1;
}

void roll_multiple_dice(int num_dice)
{
    printf("Rolling %d dice...\n", num_dice);
    for (int i = 0; i < num_dice; i++)
    {
        int result = roll_dice();
        printf("Dice #%d: ", i+1);
        switch (result)
        {
            case 1:
                printf("The dice giggled and rolled to a stop on a creepy, smiling jack-o'-lantern face.\n");
                break;
            case 2:
                printf("The dice became a tiny version of you, complete with miniature dice that it rolled in its little, itty-bitty hands.\n");
                break;
            case 3:
                printf("The dice burst into song, serenading you with a tune about whales wearing party hats.\n");
                break;
            case 4:
                printf("The dice grew tentacles and sucked you into a surreal, Lovecraftian underworld.\n");
                break;
            case 5:
                printf("The dice exploded into a shower of glittering confetti, covering you in a rainbow of colors.\n");
                break;
            case 6:
                printf("The dice sprouted wings and took flight, carrying you soaring through the clouds like a majestic dragon.\n");
                break;
        }
    }
}

int main()
{
    srand(time(NULL));
    int num_dice;
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);
    roll_multiple_dice(num_dice);
    return 0;
}