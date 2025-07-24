//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define GAME_WIDTH 50
#define GAME_HEIGHT 30
#define GAME_SPEED 200000

typedef struct
{
    int x;
    int y;
    bool active;
} Projectile;

typedef struct
{
    int x;
    int y;
    int health;
    bool active;
} Alien;

typedef struct
{
    int x;
    int y;
} Player;

// Function to read keyboard input without blocking
void read_input(char *c)
{
    struct termios orig_term_attr;
    struct termios new_term_attr;

    tcgetattr(STDIN_FILENO, &orig_term_attr);
    new_term_attr = orig_term_attr;
    new_term_attr.c_lflag &= ~(ICANON | ECHO);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_term_attr);

    *c = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &orig_term_attr);
}

// Function to initialize aliens
void init_aliens(Alien aliens[GAME_HEIGHT / 2][GAME_WIDTH / 2])
{
    int i, j;
    for (i = 0; i < GAME_HEIGHT / 2; i++)
    {
        for (j = 0; j < GAME_WIDTH / 2; j++)
        {
            aliens[i][j].x = j * 2;
            aliens[i][j].y = i * 2;
            aliens[i][j].health = 1;
            aliens[i][j].active = true;
        }
    }
}

int main()
{
    srand(time(NULL));
    Alien aliens[GAME_HEIGHT / 2][GAME_WIDTH / 2];
    Projectile bullets[GAME_HEIGHT];
    Player player;
    player.x = GAME_WIDTH / 2;
    player.y = GAME_HEIGHT - 1;

    int i, j, k, num_bullets = 0, num_aliens = (GAME_HEIGHT / 2) * (GAME_WIDTH / 2);
    char input = '\0';

    init_aliens(aliens);

    // Main game loop
    while (true)
    {
        // Clear screen
        system("clear");

        // Draw game objects
        for (i = 0; i < GAME_HEIGHT; i++)
        {
            for (j = 0; j < GAME_WIDTH; j++)
            {
                if (i == player.y && j >= player.x - 1 && j <= player.x + 1)
                {
                    printf("^");
                }
                else
                {
                    bool alien_drawn = false;
                    for (k = 0; k < num_aliens; k++)
                    {
                        if (aliens[k / (GAME_WIDTH / 2)][k % (GAME_WIDTH / 2)].active && aliens[k / (GAME_WIDTH / 2)][k % (GAME_WIDTH / 2)].x == j && aliens[k / (GAME_WIDTH / 2)][k % (GAME_WIDTH / 2)].y == i)
                        {
                            printf("O");
                            alien_drawn = true;
                            break;
                        }
                    }
                    if (!alien_drawn)
                    {
                        bool bullet_drawn = false;
                        for (k = 0; k < num_bullets; k++)
                        {
                            if (bullets[k].active && bullets[k].x == j && bullets[k].y == i)
                            {
                                printf("|");
                                bullet_drawn = true;
                                break;
                            }
                        }
                        if (!bullet_drawn)
                        {
                            printf(" ");
                        }
                    }
                }
            }
            printf("\n");
        }

        // Handle player input
        read_input(&input);
        if (input == 'a')
        {
            if (player.x > 1)
            {
                player.x--;
            }
        }
        else if (input == 'd')
        {
            if (player.x < GAME_WIDTH - 2)
            {
                player.x++;
            }
        }
        else if (input == ' ')
        {
            if (num_bullets < GAME_HEIGHT)
            {
                bullets[num_bullets].x = player.x;
                bullets[num_bullets].y = player.y - 1;
                bullets[num_bullets].active = true;
                num_bullets++;
            }
        }

        // Move bullets and handle collisions with aliens
        for (i = 0; i < num_bullets; i++)
        {
            if (bullets[i].active)
            {
                bullets[i].y--;
                if (bullets[i].y < 0)
                {
                    bullets[i].active = false;
                }
                for (j = 0; j < num_aliens; j++)
                {
                    if (aliens[j / (GAME_WIDTH / 2)][j % (GAME_WIDTH / 2)].active && aliens[j / (GAME_WIDTH / 2)][j % (GAME_WIDTH / 2)].x == bullets[i].x && aliens[j / (GAME_WIDTH / 2)][j % (GAME_WIDTH / 2)].y == bullets[i].y)
                    {
                        aliens[j / (GAME_WIDTH / 2)][j % (GAME_WIDTH / 2)].health--;
                        if (aliens[j / (GAME_WIDTH / 2)][j % (GAME_WIDTH / 2)].health == 0)
                        {
                            aliens[j / (GAME_WIDTH / 2)][j % (GAME_WIDTH / 2)].active = false;
                            num_aliens--;
                        }
                        bullets[i].active = false;
                    }
                }
            }
        }

        // Move aliens and handle collisions with player
        for (i = 0; i < num_aliens; i++)
        {
            if (aliens[i / (GAME_WIDTH / 2)][i % (GAME_WIDTH / 2)].active)
            {
                aliens[i / (GAME_WIDTH / 2)][i % (GAME_WIDTH / 2)].y++;
                if (aliens[i / (GAME_WIDTH / 2)][i % (GAME_WIDTH / 2)].y == player.y && aliens[i / (GAME_WIDTH / 2)][i % (GAME_WIDTH / 2)].x >= player.x - 1 && aliens[i / (GAME_WIDTH / 2)][i % (GAME_WIDTH / 2)].x <= player.x + 1)
                {
                    printf("Game Over!\n");
                    return 0;
                }
            }
        }

        // Sleep to control game speed
        usleep(GAME_SPEED);
    }

    return 0;
}