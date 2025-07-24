//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10


int lives = 3;
int score = 0;
int level = 1;
int speed = 250;
int wave = 1;
int waveScore = 0;
int gameOver = 0;

struct player
{
    int pos;
    char sym;
};

struct player user; //initialize user

struct enemy
{
    int x, y;
    char sym;
    int isAlive;
};

struct enemy enemyArray[ROWS][COLS]; //initialize enemy array

void printField()
{
    system("clear"); //clear console

    printf("Lives: %d\tScore: %d\tLevel: %d\n", lives, score, level); //print user stats

    printf("__________________________\n"); //boundary for top of game field

    for (int i = 0; i < ROWS; i++)
    {
        printf("|");

        for (int j = 0; j < COLS; j++)
        {
            printf(" %c ", enemyArray[i][j].sym);
        }

        printf("|\n");
    }

    printf("|");
    for (int i = 0; i < COLS; i++)
    {
        if (user.pos == i)
        {
            printf(" %c ", user.sym); //print user symbol
        }
        else
        {
            printf("   ");
        }
    }
    printf("|\n");

    printf("__________________________\n"); //boundary for bottom of game field

}

void moveEnemies()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (enemyArray[i][j].isAlive)
            {
                enemyArray[i][j].x += wave; //move enemies in x direction

                if (enemyArray[i][j].x == ROWS - 1)
                {
                    lives--;
                    enemyArray[i][j].isAlive = 0; //destroy enemy if it reaches user
                }
            }
        }
    }
}

void updateWaveScore()
{
    waveScore++;

    if (waveScore % 10 == 0)
    {
        wave++;
        if (speed > 50)
        {
            speed -= 50;
        }
        level++;
    }
}

void gameOverScreen()
{
    system("clear"); //clear console
    printf("__________________________\n");
    printf("         GAME OVER\n");
    printf("__________________________\n\n");

    printf("Final Score: %d\n", score);

    printf("__________________________\n");

    exit(0);
}

int main()
{
    srand(time(NULL)); //initialize random seed

    user.pos = COLS / 2; //initialize user position
    user.sym = 'A';

    for (int i = 0; i < ROWS; i++) //initialize enemy array
    {
        for (int j = 0; j < COLS; j++)
        {
            enemyArray[i][j].x = i;
            enemyArray[i][j].y = j;
            enemyArray[i][j].sym = 'x';
            enemyArray[i][j].isAlive = 1;
        }
    }

    while (!gameOver)
    {
        printField();

        moveEnemies();

        char input = getchar();

        if (input == 'a' && user.pos > 0) //move user left
        {
            user.pos--;
        }
        else if (input == 'd' && user.pos < COLS - 1) //move user right
        {
            user.pos++;
        }
        else if (input == 'q') //exit game
        {
            gameOverScreen();
        }

        for (int i = 0; i < ROWS; i++) //check for collisions with enemies
        {
            for (int j = 0; j < COLS; j++)
            {
                if (enemyArray[i][j].isAlive && enemyArray[i][j].x == ROWS - 1 && user.pos == enemyArray[i][j].y)
                {
                    lives--;
                    enemyArray[i][j].isAlive = 0;
                }
                else if(enemyArray[i][j].isAlive && enemyArray[i][j].x == ROWS - 1)
                {
                    score++;
                    enemyArray[i][j].isAlive = 0;
                    updateWaveScore();

                    if (score == ROWS * COLS)
                    {
                        printf("__________________________\n");
                        printf("      CONGRATULATIONS!\n");
                        printf("   YOU HAVE BEATEN THE GAME\n");
                        printf("__________________________\n");

                        exit(0);
                    }
                }
            }
        }

        if (lives == 0) //game over scenario
        {
            gameOver = 1;
            gameOverScreen();
        }

        usleep(speed * 1000); //pause game
    }

    return 0;
}