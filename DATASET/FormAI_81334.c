//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char playerName[20];
    char decision[10];
    char potion[10];
    char weapon[10];
    int health = 100;
    int strength = 10;
    int poison = 0;
    int enemyHealth = 100;
    int potionUsed = 0;

    printf("Welcome to the Romeo and Juliet Adventure Game!\n\n");
    printf("What is your name?\n");
    scanf("%s", playerName);
    printf("\n");

    printf("%s, you are a young adventurer who has just arrived in Verona.\n", playerName);
    printf("You are seeking a legendary treasure hidden somewhere in the city.\n");
    printf("As you walk through the streets, you come across a beautiful woman.\n");
    printf("She introduces herself as Juliet, and asks for your help.\n\n");

    printf("Do you accept her offer? (Yes/No)\n");
    scanf("%s", decision);
    printf("\n");

    if(strcmp(decision,"Yes")==0)
    {
        printf("Juliet explains that her family is in a feud with the Capulet family,\n");
        printf("and they have kidnapped her cousin Tybalt.\n");
        printf("She wants you to help rescue him from the Capulet estate.\n\n");

        printf("Juliet hands you a potion that will temporarily weaken the guard dogs,\n");
        printf("and a sword to defend yourself.\n\n");

        strcpy(potion,"yes");
        strcpy(weapon,"sword");

        printf("Do you drink the potion before entering the estate? (Yes/No)\n");
        scanf("%s", decision);
        printf("\n");

        if(strcmp(decision,"Yes")==0)
        {
            poison = 1;
            printf("You drink the potion, and feel a rush of energy.\n");
            printf("You are now ready to face the guard dogs.\n\n");
        }
        else
        {
            printf("You decide to save the potion for later.\n");
            printf("You enter the estate and are immediately attacked by the guard dogs.\n\n");
        }

        while(enemyHealth>0 && health>0)
        {
            printf("Enemy Health: %d\n", enemyHealth);
            printf("Your Health: %d\n\n", health);
            printf("What do you want to do? (Attack/Drink Potion)\n");
            scanf("%s", decision);
            printf("\n");

            if(strcmp(decision,"Attack")==0)
            {
                printf("You attack the guard dog with your %s!\n", weapon);
                enemyHealth -= strength;

                if(poison==1)
                {
                    printf("The guard dog is poisoned!\n");
                    enemyHealth -= 10;
                    poison = 0;
                }

                printf("The guard dog bites you in retaliation!\n");
                health -= 10;
            }
            else
            {
                if(potionUsed==0)
                {
                    printf("You drink the potion and feel rejuvenated!\n");
                    health += 20;
                    potionUsed = 1;
                }
                else
                {
                    printf("You have already used your potion.\n");
                }
            }
        }

        if(enemyHealth<=0)
        {
            printf("You have defeated the guard dogs and saved Tybalt!\n\n");
            printf("Juliet is overjoyed and thanks you for your bravery.\n");
            printf("As a reward, she gives you the clue to the location of the treasure.\n");
            printf("You continue on your journey, prepared for whatever dangers may come your way.\n");
        }
        else
        {
            printf("You were defeated by the guard dogs.\n");
            printf("Juliet is heartbroken and ashamed that she asked for your help.\n");
            printf("You leave Verona, defeated and disappointed.\n");
        }
    }
    else
    {
        printf("You decline Juliet's offer and continue on your journey.\n");
        printf("Without her help, you must find the treasure on your own.\n");
        printf("You search the city for days, but find no trace of the treasure.\n");
        printf("You eventually leave Verona, empty-handed and disillusioned.\n");
    }

    return 0;
}