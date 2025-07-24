//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: complete
#include<stdio.h>
#include<string.h>

void instructions();
void villageScene();
void castleScene();
void caveScene();
void forestScene();
void battle();

int main()
{
    char playerName[20];

    printf("Enter your name: ");
    fgets(playerName, 20, stdin);
    playerName[strcspn(playerName, "\n")] = 0;

    instructions();

    printf("\nWelcome to the adventure, %s!\n\n", playerName);

    villageScene();

    return 0;
}

void instructions()
{
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("In this game, you will be exploring different locations and completing tasks.\n");
    printf("You will encounter different obstacles and enemies, and you must make choices to progress through the game.\n");
    printf("To play the game, use the following commands:\n");
    printf("   'go' followed by a location name to move to a different location\n");
    printf("   'look' to see your surroundings and available paths/options\n");
    printf("   'take' followed by an item name to add it to your inventory\n");
    printf("   'inventory' to see the items in your inventory\n");
    printf("   'fight' to start a battle with an enemy\n");
    printf("   'help' to see these instructions again\n");
    printf("\nGood luck and have fun!\n\n");
}

void villageScene()
{
    printf("You find yourself in a small village surrounded by fields.\n");
    printf("To the north lies a castle, to the east a forest, and to the south a cave.\n");
    printf("What would you like to do?\n");

    char input[10];

    while (1)
    {
        printf("> ");
        fgets(input, 10, stdin);

        if (strncmp(input, "help", 4) == 0)
        {
            instructions();
        }
        else if (strncmp(input, "look", 4) == 0)
        {
            printf("You are in a village surrounded by fields.\n");
            printf("To the north is a castle with high walls and a drawbridge.\n");
            printf("To the east is a dense forest with a narrow path winding through it.\n");
            printf("To the south is a dark cave entrance with bats flying overhead.\n");
            printf("What would you like to do?\n");
        }
        else if (strncmp(input, "go", 2) == 0)
        {
            if (strncmp(input + 3, "castle", 6) == 0)
            {
                castleScene();
                break;
            }
            else if (strncmp(input + 3, "forest", 6) == 0)
            {
                forestScene();
                break;
            }
            else if (strncmp(input + 3, "cave", 4) == 0)
            {
                caveScene();
                break;
            }
            else
            {
                printf("Invalid location.\n");
            }
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
}

void castleScene()
{
    printf("You have arrived at the castle gates.\n");
    printf("The castle walls are high and imposing, and the drawbridge is currently lowered.\n");
    printf("What would you like to do?\n");

    char input[10];

    while (1)
    {
        printf("> ");
        fgets(input, 10, stdin);

        if (strncmp(input, "help", 4) == 0)
        {
            instructions();
        }
        else if (strncmp(input, "look", 4) == 0)
        {
            printf("You are standing outside the castle gates.\n");
            printf("The drawbridge is lowered, allowing access across the moat into the castle.\n");
            printf("To the south lies the village, and to the west is a dense forest.\n");
            printf("What would you like to do?\n");
        }
        else if (strncmp(input, "go", 2) == 0)
        {
            if (strncmp(input + 3, "village", 7) == 0)
            {
                villageScene();
                break;
            }
            else if (strncmp(input + 3, "forest", 6) == 0)
            {
                forestScene();
                break;
            }
            else
            {
                printf("Invalid location.\n");
            }
        }
        else if (strncmp(input, "fight", 5) == 0)
        {
            battle();
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
}

void caveScene()
{
    printf("You enter the dark, musty cave.\n");
    printf("The ceiling is low and the walls are jagged.\n");
    printf("What would you like to do?\n");

    char input[10];

    while (1)
    {
        printf("> ");
        fgets(input, 10, stdin);

        if (strncmp(input, "help", 4) == 0)
        {
            instructions();
        }
        else if (strncmp(input, "look", 4) == 0)
        {
            printf("You are in a dark, musty cave.\n");
            printf("The walls are jagged and the ceiling is low.\n");
            printf("There are two paths to the east and west.\n");
            printf("What would you like to do?\n");
        }
        else if (strncmp(input, "go", 2) == 0)
        {
            if (strncmp(input + 3, "forest", 6) == 0)
            {
                forestScene();
                break;
            }
            else if (strncmp(input + 3, "castle", 6) == 0)
            {
                castleScene();
                break;
            }
            else
            {
                printf("Invalid location.\n");
            }
        }
        else if (strncmp(input, "fight", 5) == 0)
        {
            battle();
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
}

void forestScene()
{
    printf("You enter the dense forest.\n");
    printf("The narrow path winds through the trees.\n");
    printf("What would you like to do?\n");

    char input[10];

    while (1)
    {
        printf("> ");
        fgets(input, 10, stdin);

        if (strncmp(input, "help", 4) == 0)
        {
            instructions();
        }
        else if (strncmp(input, "look", 4) == 0)
        {
            printf("You are in a dense forest.\n");
            printf("The trees tower above you, casting shadows on the forest floor.\n");
            printf("To the east lies a dark cave, and to the west is the castle.\n");
            printf("What would you like to do?\n");
        }
        else if (strncmp(input, "go", 2) == 0)
        {
            if (strncmp(input + 3, "cave", 4) == 0)
            {
                caveScene();
                break;
            }
            else if (strncmp(input + 3, "castle", 6) == 0)
            {
                castleScene();
                break;
            }
            else
            {
                printf("Invalid location.\n");
            }
        }
        else if (strncmp(input, "fight", 5) == 0)
        {
            battle();
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
}

void battle()
{
    printf("You have encountered a fierce enemy!\n");
    printf("What would you like to do?\n");

    char input[10];

    while (1)
    {
        printf("> ");
        fgets(input, 10, stdin);

        if (strncmp(input, "help", 4) == 0)
        {
            instructions();
        }
        else if (strncmp(input, "fight", 5) == 0)
        {
            printf("You engage in battle with the enemy!\n");
            printf("You attack the enemy and deal 10 damage.\n");
            printf("The enemy attacks you and deals 5 damage.\n");
            printf("What would you like to do?\n");
        }
        else if (strncmp(input, "inventory", 9) == 0)
        {
            printf("You have no items in your inventory.\n");
            printf("What would you like to do?\n");
        }
        else if (strncmp(input, "run", 3) == 0)
        {
            printf("You attempt to run away from the battle...\n");
            printf("You successfully escape from the enemy!\n");
            printf("What would you like to do?\n");
            break;
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
}