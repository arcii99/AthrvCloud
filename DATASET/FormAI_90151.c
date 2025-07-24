//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function prototypes
void title_screen();
void prologue();
void random_planet();
void space_battle();

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Title screen
    title_screen();
    
    // Prologue
    prologue();
    
    // Random planet
    random_planet();
    
    // Space battle
    space_battle();
    
    printf("Congratulations! You have completed the space adventure!\n");
    
    return 0;
}

// Prints the title screen
void title_screen()
{
    printf("******************\n");
    printf("** SPACE ADVENTURE **\n");
    printf("******************\n\n");
}

// Prints the prologue
void prologue()
{
    printf("You are a space adventurer, traveling through the galaxy in search of riches and adventure.\n");
    printf("Your ship is the fastest in the galaxy, equipped with powerful weapons and shields.\n");
    printf("As you travel through space, you receive a distress signal from a nearby planet...\n\n");
}

// Generates a random planet for the player to explore
void random_planet()
{
    // Generate a random number between 1 and 4
    int planet_choice = rand()%4 + 1;
    
    printf("You have arrived at planet %d!\n", planet_choice);
    
    switch(planet_choice)
    {
        case 1:
            printf("This planet is covered in ice and snow. There may be hidden treasures buried beneath the ice...\n");
            break;
        case 2:
            printf("This planet is a desert wasteland. The scorching heat will be a challenge to overcome...\n");
            break;
        case 3:
            printf("This planet is a lush forest world, full of dangerous predators and hidden caves...\n");
            break;
        case 4:
            printf("This planet is a volcanic hellscape. The extreme heat and deadly lava flows will test your skills...\n");
            break;
    }
    
    printf("\n");
}

// Simulates a space battle with an alien ship
void space_battle()
{
    printf("As you leave the planet, you are attacked by an alien ship!\n");
    printf("You must use your ship's weapons and shields to defeat the alien.\n");
    
    // Player's ship health
    int player_health = 100;
    
    // Alien ship health
    int alien_health = 50;
    
    // Loop until one ship's health reaches 0
    while(player_health > 0 && alien_health > 0)
    {
        printf("Your ship health: %d\n", player_health);
        printf("Alien ship health: %d\n\n", alien_health);
        
        // Player attacks first
        int player_attack = rand()%20 + 10;
        printf("You fire your ship's weapons and deal %d damage to the alien!\n", player_attack);
        alien_health -= player_attack;
        
        // Check if alien ship has been destroyed
        if(alien_health <= 0)
        {
            printf("The alien ship has been destroyed! You have emerged victorious!\n");
            return;
        }
        
        // Alien attacks next
        int alien_attack = rand()%15 + 5;
        printf("The alien ship fires its weapons and deals %d damage to your ship!\n", alien_attack);
        player_health -= alien_attack;
        
        // Check if player's ship has been destroyed
        if(player_health <= 0)
        {
            printf("Your ship has been destroyed! Game over.\n");
            exit(0);
        }
    }
}