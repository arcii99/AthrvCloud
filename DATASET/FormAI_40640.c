//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAP_SIZE 10
#define NUM_ENEMIES 5
#define MAX_HEALTH 100

int player_health = MAX_HEALTH;
int player_pos[2] = {0, 0};
int enemy_pos[NUM_ENEMIES][2];
bool map[MAP_SIZE][MAP_SIZE] = {false};

void initialize_map()
{
    // randomly place enemies on the map
    for(int i = 0; i < NUM_ENEMIES; i++)
    {
        int x = rand() % MAP_SIZE;
        int y = rand() % MAP_SIZE;
        while(map[x][y])
        {
            x = rand() % MAP_SIZE;
            y = rand() % MAP_SIZE;
        }
        map[x][y] = true;
        enemy_pos[i][0] = x;
        enemy_pos[i][1] = y;
    }
}

void print_map()
{
    printf("Map:\n");
    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j < MAP_SIZE; j++)
        {
            if(player_pos[0] == i && player_pos[1] == j)
                printf("P ");
            else
            {
                bool is_enemy = false;
                for(int k = 0; k < NUM_ENEMIES; k++)
                {
                    if(enemy_pos[k][0] == i && enemy_pos[k][1] == j)
                    {
                        printf("E ");
                        is_enemy = true;
                        break;
                    }
                }
                if(!is_enemy)
                    printf(". ");
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(42);
    initialize_map();
    print_map();

    char move;
    while(true)
    {
        printf("Enter move (w = up, a = left, s = down, d = right): ");
        scanf(" %c", &move);

        switch(move)
        {
            case 'w':
                if(player_pos[0] > 0)
                    player_pos[0]--;
                break;
            case 'a':
                if(player_pos[1] > 0)
                    player_pos[1]--;
                break;
            case 's':
                if(player_pos[0] < MAP_SIZE - 1)
                    player_pos[0]++;
                break;
            case 'd':
                if(player_pos[1] < MAP_SIZE - 1)
                    player_pos[1]++;
                break;
            default:
                printf("Invalid move!\n");
                continue;
        }

        // check for enemy encounters
        for(int k = 0; k < NUM_ENEMIES; k++)
        {
            if(enemy_pos[k][0] == player_pos[0] && enemy_pos[k][1] == player_pos[1])
            {
                printf("You encountered an enemy!\n");
                int damage = rand() % 10 + 1;
                player_health -= damage;
                printf("You took %d damage. Your health is now %d\n", damage, player_health);
                if(player_health <= 0)
                {
                    printf("GAME OVER!\n");
                    exit(0);
                }
                break; // can only encounter one enemy at a time
            }
        }

        print_map();
    }

    return 0;
}