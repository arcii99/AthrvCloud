//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10

int player_pos[2];
int zombie_pos[2];

char map[MAP_SIZE][MAP_SIZE];

void init_map();
void draw_map();
void move_player(char direction);
void move_zombie();

int main()
{
    //Initialize player and zombie positions
    srand(time(NULL));
    player_pos[0] = rand() % MAP_SIZE;
    player_pos[1] = rand() % MAP_SIZE;
    zombie_pos[0] = rand() % MAP_SIZE;
    zombie_pos[1] = rand() % MAP_SIZE;

    //Initialize map
    init_map();

    //Main loop
    while(1)
    {
        //Draw the map
        draw_map();

        //Wait for user input
        char input;
        printf("\nEnter a direction to move (w, a, s, d): ");
        scanf(" %c", &input);

        //Move the player
        move_player(input);

        //Move the zombie
        move_zombie();

        //Check if the player has reached the exit
        if(player_pos[0] == 0 && player_pos[1] == MAP_SIZE-1)
        {
            printf("\nCongratulations! You have escaped the apocalypse!\n");
            break;
        }

        //Check if the zombie has caught the player
        if(zombie_pos[0] == player_pos[0] && zombie_pos[1] == player_pos[1])
        {
            printf("\nGame Over! You have been caught by a zombie!\n");
            break;
        }
    }

    return 0;
}

void init_map()
{
    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j < MAP_SIZE; j++)
        {
            //Randomly place obstacles and exit
            int random = rand() % 6;
            if(random == 0 && (i != player_pos[0] || j != player_pos[1]) && (i != zombie_pos[0] || j != zombie_pos[1]))
            {
                map[i][j] = '#';
            }
            else if(i == 0 && j == MAP_SIZE-1)
            {
                map[i][j] = 'E';
            }
            else
            {
                map[i][j] = '.';
            }
        }
    }
}

void draw_map()
{
    system("clear"); //Clear the console

    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j < MAP_SIZE; j++)
        {
            //Draw the player, zombie or obstacles
            if(i == player_pos[0] && j == player_pos[1])
            {
                printf("P ");
            }
            else if(i == zombie_pos[0] && j == zombie_pos[1])
            {
                printf("Z ");
            }
            else
            {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
}

void move_player(char direction)
{
    //Calculate new player position
    int new_pos[2];
    new_pos[0] = player_pos[0];
    new_pos[1] = player_pos[1];
    if(direction == 'w')
    {
        new_pos[0]--;
    }
    else if(direction == 'a')
    {
        new_pos[1]--;
    }
    else if(direction == 's')
    {
        new_pos[0]++;
    }
    else if(direction == 'd')
    {
        new_pos[1]++;
    }

    //Check if the new position is within the map and doesn't contain an obstacle
    if(new_pos[0] >= 0 && new_pos[0] < MAP_SIZE &&
       new_pos[1] >= 0 && new_pos[1] < MAP_SIZE &&
       map[new_pos[0]][new_pos[1]] != '#')
    {
        player_pos[0] = new_pos[0];
        player_pos[1] = new_pos[1];
    }
}

void move_zombie()
{
    //Calculate new zombie position
    int new_pos[2];
    new_pos[0] = zombie_pos[0];
    new_pos[1] = zombie_pos[1];
    int random = rand() % 4;
    if(random == 0)
    {
        new_pos[0]--;
    }
    else if(random == 1)
    {
        new_pos[1]--;
    }
    else if(random == 2)
    {
        new_pos[0]++;
    }
    else if(random == 3)
    {
        new_pos[1]++;
    }

    //Check if the new position is within the map and doesn't contain an obstacle or the player
    if(new_pos[0] >= 0 && new_pos[0] < MAP_SIZE &&
       new_pos[1] >= 0 && new_pos[1] < MAP_SIZE &&
       map[new_pos[0]][new_pos[1]] != '#' &&
       !(new_pos[0] == player_pos[0] && new_pos[1] == player_pos[1]))
    {
        zombie_pos[0] = new_pos[0];
        zombie_pos[1] = new_pos[1];
    }
}