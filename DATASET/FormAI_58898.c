//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20 // number of rows
#define COL 60 // number of columns

void draw_board(char board[ROW][COL]) // function to draw the board
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            printf("%c", board[i][j]); // print each cell of the board
        }
        printf("\n"); // move to the next row
    }
}

void update_board(char board[ROW][COL], int player_pos, int enemy_pos) // function to update the board
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(i == 0 || i == ROW-1) // top and bottom walls
            {
                board[i][j] = '-';
            }
            else if(j == 0 || j == COL-1) // left and right walls
            {
                board[i][j] = '|';
            }
            else if(j == player_pos && i == ROW-2) // player position
            {
                board[i][j] = 'P';
            }
            else if(j == enemy_pos && i == 1) // enemy position
            {
                board[i][j] = 'E';
            }
            else // empty cell
            {
                board[i][j] = ' ';
            }
        }
    }
}

int main()
{
    char board[ROW][COL]; // initialize board

    int player_pos = COL / 2; // initialize player position
    int enemy_pos = rand() % (COL-2) + 1; // initialize enemy position randomly

    update_board(board, player_pos, enemy_pos); // update board
    draw_board(board); // draw board

    char move; // initialize movement variable
    int score = 0; // initialize score

    while(1)
    {
        printf("Score: %d\n", score); // print score
        printf("Move left(L) or right(R): "); // prompt user for movement

        scanf(" %c", &move); // capture user input

        if(move == 'L') // move player left
        {
            if(player_pos > 1) // check if player is at far left
            {
                player_pos--;
            }
        }
        else if(move == 'R') // move player right
        {
            if(player_pos < COL-2) // check if player is at far right
            {
                player_pos++;
            }
        }

        enemy_pos = rand() % (COL-2) + 1; // move enemy randomly

        update_board(board, player_pos, enemy_pos); // update board
        draw_board(board); // draw board

        if(player_pos == enemy_pos) // if player and enemy collide, game over
        {
            printf("Game Over. Score: %d\n", score); // print final score
            break; // break out of game loop
        }

        score++; // increment score
    }

    return 0;
}