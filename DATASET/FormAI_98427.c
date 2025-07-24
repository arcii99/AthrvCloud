//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
void printInstructions();
void drawScene(char scene[][80]);
int getRandom(int min, int max);
void playGame(char scene[][80], int julietX, int romeoX, int letterX);

int main(void)
{
    char scene[5][80] = {
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
        "x                                                                             x",
        "x                                                                             x",
        "x                                                                             x",
        "x                                                                             x"
    };
    int julietX = 40;
    int romeoX = 45;
    int letterX = getRandom(1, 70);

    //print instructions 
    printf("Welcome to Romeo And Juliet Game!\n");
    printf("Help Romeo to get to Juliet and deliver the letter. Avoid obstacles!\n");
    printf("Press any key to continue...\n");
    getchar();
    system("clear");

    //draw initial scene
    drawScene(scene);

    //play game
    playGame(scene, julietX, romeoX, letterX);

    return 0;
}

void printInstructions()
{
    printf("How To Play:\n");
    printf("Enter 'a' to move left\n");
    printf("Enter 'd' to move right\n");
    printf("Enter 'q' to quit game\n");
}

void drawScene(char scene[][80])
{
    system("clear");

    for(int i=0; i<5; i++)
    {
        printf("%s\n", scene[i]);
    }
}

int getRandom(int min, int max)
{
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}

void playGame(char scene[][80], int julietX, int romeoX, int letterX)
{
    char input;
    int gameover = 0;

    while(!gameover)
    {
        //print instructions
        printInstructions();

        //update scene
        scene[3][letterX] = 'L';
        scene[1][julietX] = 'J';
        scene[2][romeoX] = 'R';

        //draw scene
        drawScene(scene);

        //get user input
        input = getchar();

        //move romeo
        if(input == 'a' && romeoX > 1)
        {
            romeoX--;
        }
        else if(input == 'd' && romeoX < 78)
        {
            romeoX++;
        }

        //check collision with letter
        if(romeoX == letterX)
        {
            printf("Romeo has delivered the letter to Juliet!\n");
            gameover = 1;
        }
        else if(scene[3][romeoX] == 'L')
        {
            printf("Romeo hit the obstacle and lost the letter!\n");
            gameover = 1;
        }

        //clear input buffer
        while((input = getchar()) != '\n' && input != EOF);

        //clear scene
        for(int i=0; i<80; i++)
        {
            scene[1][i] = ' ';
            scene[2][i] = ' ';
            scene[3][i] = ' ';
        }
    }
}