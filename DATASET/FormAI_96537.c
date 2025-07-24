//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: relaxed
// A unique Rogue-like game with procedural generation
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20
#define MIN_TREASURE 5
#define MAX_TREASURE 15

char map[ROWS][COLS];
int player_x, player_y;
int treasure_count = 0, max_treasures;

void generate_map()
{
    srand(time(0));
    int i, j, num_treasures;
    max_treasures = rand()%(MAX_TREASURE-MIN_TREASURE+1) + MIN_TREASURE;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            if(i==0 || j==0 || i==ROWS-1 || j==COLS-1)
                map[i][j] = '#';
            else
                map[i][j] = '.';
        }
    }
    num_treasures = 0;
    while(num_treasures < max_treasures)
    {
        i = rand()%(ROWS-2)+1;
        j = rand()%(COLS-2)+1;
        if(map[i][j] == '.')
        {
            map[i][j] = '$';
            num_treasures++;
        }
    }
    player_x = rand()%(ROWS-2)+1;
    player_y = rand()%(COLS-2)+1;
    map[player_x][player_y] = '@';
}

void display_map()
{
    int i, j;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
}

void move_player(char direction)
{
    int new_x = player_x, new_y = player_y;
    switch(direction)
    {
        case 'w':
            new_x--;
            break;
        case 'a':
            new_y--;
            break;
        case 's':
            new_x++;
            break;
        case 'd':
            new_y++;
            break;
    }
    if(map[new_x][new_y] == '#')
        printf("You cannot move there!\n");
    else if(map[new_x][new_y] == '$')
    {
        printf("You found treasure!\n");
        treasure_count++;
        map[new_x][new_y] = '@';
        map[player_x][player_y] = '.';
        player_x = new_x;
        player_y = new_y;
    }
    else
    {
        map[new_x][new_y] = '@';
        map[player_x][player_y] = '.';
        player_x = new_x;
        player_y = new_y;
    }
}

int main()
{
    char choice, direction;
    generate_map();
    printf("Welcome to the rogue-like game!\n");
    printf("You have to find %d treasures.\n", max_treasures);
    while(treasure_count < max_treasures)
    {
        printf("Treasures found: %d/%d\n", treasure_count, max_treasures);
        printf("Enter w for up, a for left, s for down, d for right: ");
        scanf(" %c", &direction);
        move_player(direction);
        display_map();
    }
    printf("Congratulations! You found all the treasures!\n");
    return 0;
}