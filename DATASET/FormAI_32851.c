//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int);
void print_board(int[][10]);
void place_ships(int[][10]);
void play_game(int[][10]);

int main()
{
    int board[10][10] = {0};
    srand(time(NULL));
    printf("\nWelcome to Battleship game\n\n");
    printf("Rules:\n1. There are 5 ships, each taking up 2 blocks on the board\n2. You will have 10 attempts to sink all 5 ships\n3. Enter the coordinates in the format row,column (eg. 3,4)\n\n");
    printf("Press any key to continue......\n");
    getchar();
    place_ships(board);
    play_game(board);
    return 0;
}

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;
    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while((now-then) < pause)
    {
        now = clock();
    }
}

void print_board(int board[][10])
{
    printf("\n\n");
    for(int i=0; i<10; i++)
    {
        printf(" %d",i);
    }
    printf("\n");
    for(int i=0; i<10; i++)
    {
        printf("%d",i);
        for(int j=0; j<10; j++)
        {
            if(board[i][j]==0)
            {
                printf(" ~");
            }
            else if(board[i][j]==1)
            {
                printf(" O");
            }
            else if(board[i][j]==2)
            {
                printf(" X");
            }
        }
        printf("\n");
    }
}

void place_ships(int board[][10])
{
    int count=0, x, y, horizontal;
    while(count<5)
    {
        x = rand()%10;
        y = rand()%10;
        horizontal = rand()%2;
        if(horizontal==0)  //vertical placement
        {
            if(x<9 && board[x][y]==0 && board[x+1][y]==0)
            {
                board[x][y]=1;
                board[x+1][y]=1;
                count++;
            }
        }
        else  //horizontal placement
        {
            if(y<9 && board[x][y]==0 && board[x][y+1]==0)
            {
                board[x][y]=1;
                board[x][y+1]=1;
                count++;
            }
        }
    }
}

void play_game(int board[][10])
{
    int attempts = 10;
    int hits=0, x, y;
    while(attempts>0 && hits<5)
    {
        print_board(board);
        printf("\nAttempts left: %d\n",attempts);
        printf("Enter the coordinates for your shot: ");
        scanf("%d,%d",&x,&y);
        if(x<0 || x>9 || y<0 || y>9)
        {
            printf("Invalid coordinates\n");
            delay(2000);
            continue;
        }
        if(board[x][y]==0)
        {
            printf("Miss!!\n");
            board[x][y]=2;
            attempts--;
            delay(1000);
        }
        else if(board[x][y]==1)
        {
            printf("Hit!!\n");
            board[x][y]=2;
            hits++;
            attempts--;
            delay(1000);
        }
        else if(board[x][y]==2)
        {
            printf("You already shot there\n");
            delay(2000);
        }
    }
    if(hits==5)
    {
        print_board(board);
        printf("You won!!\n");
    }
    else
    {
        printf("You lost!!\n");
    }
}