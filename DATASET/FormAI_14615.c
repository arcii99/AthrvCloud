//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

// Function to read character input without waiting until the enter key is pressed
char getch()
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return (buf);
}

// Function to display the game board
void display(bool board[20][50], int playerPos)
{
    system("clear");
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (i == 0 && j == playerPos)
                printf("^");
            else if (board[i][j])
                printf("X");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    bool board[20][50] = {false};
    int playerPos = 24;
    int score = 0;
    int delay = 1000000;
    int alienSpeed = 5;
    int alienPos = rand() % 49;
    printf("Welcome to Happy Space Invaders!\n\n");
    printf("Instructions:\n\n");
    printf("Use the left (<-) and right (->) arrow keys to move your spaceship (^).\n");
    printf("Dodge the aliens (X) and earn points for every alien you avoid!\n\n");
    printf("Press any key to start the game...\n");
    getch();
    while (true)
    {
        // Move the aliens down
        for (int i = 19; i >= 0; i--)
        {
            for (int j = 0; j < 50; j++)
            {
                if (board[i][j] && i != 19)
                {
                    board[i][j] = false;
                    board[i + 1][j] = true;
                }
            }
        }
        // Move the player
        char input = getch();
        if (input == '-')
            break;
        else if (input == '<' && playerPos > 0)
            playerPos--;
        else if (input == '>' && playerPos < 49)
            playerPos++;
        // Add a new alien
        if (rand() % 100 < alienSpeed)
            board[0][alienPos] = true;
        // Display the game board and update the score
        display(board, playerPos);
        if (board[19][playerPos])
        {
            printf("Game over! Your score: %d\n", score);
            break;
        }
        else
            score++;
        usleep(delay);
    }
    return 0;
}