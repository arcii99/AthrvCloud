//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize random seed
    srand(time(NULL));

    // define game variables
    int shipHealth = 100;
    int alienHealth = 100;
    int distance = 0;
    int laserCharge = 0;
    int shieldCharge = 0;

    // game loop
    while (shipHealth > 0 && alienHealth > 0 && distance < 1000)
    {
        // print game status
        printf("Ship health: %d\n", shipHealth);
        printf("Alien health: %d\n", alienHealth);
        printf("Distance from Earth: %d\n", distance);
        printf("Laser charge level: %d\n", laserCharge);
        printf("Shield charge level: %d\n", shieldCharge);

        // player options
        printf("Choose your action:\n");
        printf("1. Fire laser\n");
        printf("2. Charge laser\n");
        printf("3. Activate shield\n");
        printf("4. Move forward\n");

        int choice;
        scanf("%d", &choice);

        // handle player choice
        switch (choice)
        {
            case 1:
                if (laserCharge >= 30)
                {
                    printf("Laser fired!\n");
                    alienHealth -= rand() % 50 + 1;
                    laserCharge -= 30;
                }
                else
                {
                    printf("Laser charge too low!\n");
                }
                break;
            case 2:
                printf("Laser charging...\n");
                laserCharge += rand() % 20 + 10;
                break;
            case 3:
                printf("Shield activated!\n");
                shieldCharge = 100;
                break;
            case 4:
                int distanceMoved = rand() % 100 + 1;
                printf("Ship moved forward %d kilometers.\n", distanceMoved);
                distance += distanceMoved;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        // alien actions
        int alienAction = rand() % 4 + 1;

        switch (alienAction)
        {
            case 1:
            case 2:
                printf("Alien attacks with claws!\n");
                shipHealth -= rand() % 30 + 1;
                break;
            case 3:
                printf("Alien attacks with laser eyes!\n");
                shipHealth -= rand() % 50 + 1;
                break;
            case 4:
                printf("Alien charges up for next attack...\n");
                alienHealth += rand() % 10 + 5;
                break;
            default:
                break;
        }

        // reduce shield charge
        if (shieldCharge > 0)
        {
            shieldCharge -= rand() % 10 + 1;
        }
    }

    // determine game outcome
    if (shipHealth <= 0)
    {
        printf("Your ship was destroyed! Game over.");
    }
    else if (alienHealth <= 0)
    {
        printf("You defeated the alien! Congratulations!");
    }
    else if (distance >= 1000)
    {
        printf("You reached the edge of space! Game over.");
    }

    return 0;
}