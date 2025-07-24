//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Ephemeral Game: Escape the Maze
//Player has to escape the maze by finding the key and reaching the exit point
//Player has limited moves to complete the task
//If player is unable to escape the maze with limited moves, game ends

int main()
{
    srand(time(0));
    int n=10,m=10; //size of maze
    int i,j,k,flag=0,p=0,q=0,moves=20,key=0;
    char maze[n][m],input;
    int exit_row,exit_col,key_row,key_col;
    //Generating the maze
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(rand()%4==0)
                maze[i][j]='X'; //block obstacles randomly
            else
                maze[i][j]=' ';
        }
    }
    //Placing exit point
    exit_row=rand()%n;
    exit_col=m-1;
    maze[exit_row][exit_col]='E';
    //Placing key
    key_row=rand()%n;
    key_col=rand()%m;
    maze[key_row][key_col]='K';
    //Placing player
    while(maze[p][q]=='X' || maze[p][q]=='K' || maze[p][q]=='E') //so that player is not placed at blocked obstacle or key or exit point
    {
        p=rand()%n;
        q=rand()%m;
    }
    maze[p][q]='P';
    //Printing the maze
    printf("MOVE USING W A S D KEYS\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }
    //Gameplay
    while(moves--) //remaining moves
    {
        printf("\nEnter your move: ");
        scanf(" %c",&input);
        if(input=='s' && p!=n-1 && maze[p+1][q]!='X') //downward move
        {
            maze[p][q]=' '; //player moves out of current position
            p++;
        }
        else if(input=='w' && p!=0 && maze[p-1][q]!='X') //upward move
        {
            maze[p][q]=' ';
            p--;
        }
        else if(input=='a' && q!=0 && maze[p][q-1]!='X') //leftward move
        {
            maze[p][q]=' ';
            q--;
        }
        else if(input=='d' && q!=m-1 && maze[p][q+1]!='X') //rightward move
        {
            maze[p][q]=' ';
            q++;
        }
        else
        {
            printf("\nINVALID MOVE! TRY AGAIN.\n");
            continue; //skip the remaining code of this iteration and jump to next iteration of the loop
        }
        //Checking if player gets the key or reaches the exit point
        if(maze[p][q]=='K')
        {
            key=1;
            printf("\nWELL DONE! YOU GOT THE KEY.\n");
        }
        if(maze[p][q]=='E' && key==1)
        {
            flag=1; //player escapes the maze
            break;
        }
        //Placing player in new position
        maze[p][q]='P';
        //Printing the maze
        system("clear"); //clearing console screen
        printf("MOVE USING W A S D KEYS\n\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%c ",maze[i][j]);
            }
            printf("\n");
        }
        printf("MOVES REMAINING: %d\n",moves);
    }
    //Checking if player was able to escape the maze or not
    if(flag==1)
        printf("\nCONGRATULATIONS! YOU ESCAPED THE MAZE.\n");
    else
        printf("\nSORRY! YOU COULD NOT ESCAPE THE MAZE WITHIN GIVEN MOVES.\n");
    return 0;
}