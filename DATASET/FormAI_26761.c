//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printIntro();
void enterShip();
void exploreSpace();
void meetRomeo();
void meetJuliet();

// Global variables
int shipLocation = 0; // 0 = Earth, 1 = Space

int main()
{
    printIntro();
    enterShip();
    exploreSpace();
    meetRomeo();
    meetJuliet();

    return 0;
}

void printIntro()
{
    printf("Welcome to Romeo and Juliet: Procedural Space Adventure!\n\n");
    printf("In this adventure, you will take on the role of Romeo, a space explorer who secretly loves Juliet, a fellow space explorer.\n");
    printf("You must navigate the depths of space, avoiding asteroids and alien encounters, in order to reunite with your true love.\n\n");
}

void enterShip()
{
    printf("You are standing outside of your space ship, ready to embark on your journey. Do you enter the ship? (y/n)\n");
    char response = getchar();
    if (response == 'y')
    {
        printf("You enter the ship and begin the launch sequence.\n\n");
        shipLocation = 1; // Set ship location to space
    }
    else
    {
        printf("You decide not to enter the ship and your love for Juliet remains unrequited.\n\n");
        exit(0); // End program
    }
}

void exploreSpace()
{
    printf("You navigate your ship through the asteroid field, dodging debris and scanning for any signs of life.\n");
    printf("Suddenly, your ship's sensors pick up a strange energy signature nearby. Do you investigate? (y/n)\n");
    char response = getchar();
    if (response == 'y')
    {
        printf("As you approach the source of the energy signal, you realize that it is an alien spacecraft!\n");
        printf("The alien spaceship is heavily armed and begins firing at you. Do you fight back? (y/n)\n");
        response = getchar();
        if (response == 'y')
        {
            printf("You engage the alien spacecraft and after a tough battle, emerge victorious.\n");
            printf("You continue on your journey, closer to your beloved Juliet.\n\n");
        }
        else
        {
            printf("You attempt to flee, but the alien spaceship is too fast and destroys your ship.\n");
            printf("Your love for Juliet remains unrequited.\n\n");
            exit(0); // End program
        }
    }
    else
    {
        printf("You decide to stay clear of the energy signature and continue on your journey.\n\n");
    }
}

void meetRomeo()
{
    printf("After many more hours of space travel, you come across a ship that looks remarkably similar to yours.\n");
    printf("You hail the other ship and who should answer but Romeo himself!\n");
    printf("He looks at you with a mixture of surprise and joy. He's been searching for Juliet too.\n");
    printf("Together, you continue your journey, bonded by your mutual love for Juliet.\n\n");
}

void meetJuliet()
{
    printf("Finally, after what seems like an eternity, you come across Juliet's ship.\n");
    printf("At first, she doesn't recognize you, but as you draw closer, she sees that it's Romeo.\n");
    printf("They embrace and you realize that this impossible love story has finally come to a happy conclusion.\n");
    printf("Congratulations! You have successfully completed Romeo and Juliet: Procedural Space Adventure!\n");
}