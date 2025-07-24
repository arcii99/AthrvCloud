//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

void display(int a[10][10],int n,int score);     //function to display the matrix and score
void move_up(int a[10][10],int n,int *score);    //function to move up
void move_down(int a[10][10],int n,int *score);  //function to move down
void move_left(int a[10][10],int n,int *score);  //function to move left
void move_right(int a[10][10],int n,int *score); //function to move right
int check_win(int a[10][10],int n);              //function to check if 2048 is formed
void generate(int a[10][10],int n);              //function to generate number 2 randomly

void main()
{
    int n=4; //size of the game matrix
    int score=0; //initial score is zero
    srand(time(NULL)); //seeding for random number generation
    int a[10][10]; //game matrix
    generate(a,n); //generating first two random numbers
    generate(a,n);

    while(1) //continuous loop until broken by game over or win
    {
        display(a,n,score);                  //displaying the matrix and score
        printf("\nUse 'WASD' to move:");     
        char mov;
        scanf(" %c",&mov);                   //getting the move from user
        mov=toupper(mov);                    //converting to uppercase
        switch(mov)                          //checking user's move
        {
            case 'W': move_up(a,n,&score);
                      break;
            case 'A': move_left(a,n,&score);
                      break;
            case 'S': move_down(a,n,&score);
                      break;
            case 'D': move_right(a,n,&score);
                      break;
            default: printf("\nInvalid move! Try again."); //if invalid move is entered
                     break;
        }
        if(check_win(a,n)) //checking if 2048 is formed
        {
            display(a,n,score);
            printf("\n\n\t\tCongratulations! You win!");
            break;
        }
        if(score==-1) //checking if no moves possible
        {
            display(a,n,score);
            printf("\n\n\t\tBetter luck next time :(\n\n");
            break;
        }
        generate(a,n); //generating a random number after each move
    }

}

void generate(int a[10][10],int n)
{
    int r=rand()%n; //generating the row position
    int c=rand()%n; //generating the column position
    int val=rand()%2; //generating the value of the number to be generated (2 or 4)
    if(val==0) 
        val=2;
    else
        val=4;
    if(a[r][c]==0) //checking if the randomly generated position is empty
        a[r][c]=val;
    else
        generate(a,n); //if not then generating again
}

void display(int a[10][10],int n,int score)
{
    system("cls"); //clearing the console
    printf("\n\n\t\tWELCOME TO 2048");
    printf("\n\n\t\tScore: %d",score);
    printf("\n\t\t ---------------------\n");
    for(int i=0;i<n;i++)
    {
        printf("\t\t|");
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0)
                printf("     |"); //printing empty block
            else
                printf(" %4d|",a[i][j]); //printing the block with the number
        }
        printf("\n\t\t ---------------------\n");
    }
}

void move_up(int a[10][10],int n,int *score)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j][i]!=0) //if there is a number in the block
            {
                int r=j;
                while(r>0)
                {
                    if(a[r-1][i]==0) //if the block on top is empty
                    {
                        a[r-1][i]=a[r][i];
                        a[r][i]=0;
                        r--;
                    }
                    else if(a[r-1][i]==a[r][i]) //if the block on top has same number
                    {
                        a[r-1][i]*=2;
                        (*score)+=a[r-1][i]; //double the block value and add to score
                        a[r][i]=0;
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }
    if(flag==0) //if no move was made
        (*score)--;
}

void move_down(int a[10][10],int n,int *score)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(a[j][i]!=0) //if there is a number in the block
            {
                int r=j;
                while(r<n-1)
                {
                    if(a[r+1][i]==0) //if the block below is empty
                    {
                        a[r+1][i]=a[r][i];
                        a[r][i]=0;
                        r++;
                    }
                    else if(a[r+1][i]==a[r][i]) //if the block below has same number
                    {
                        a[r+1][i]*=2;
                        (*score)+=a[r+1][i]; //double the block value and add to score
                        a[r][i]=0;
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }
    if(flag==0) //if no move was made
        (*score)--;
}

void move_left(int a[10][10],int n,int *score)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=0) //if there is a number in the block
            {
                int c=j;
                while(c>0)
                {
                    if(a[i][c-1]==0) //if the block on the left is empty
                    {
                        a[i][c-1]=a[i][c];
                        a[i][c]=0;
                        c--;
                    }
                    else if(a[i][c-1]==a[i][c]) //if the block on the left has same number
                    {
                        a[i][c-1]*=2;
                        (*score)+=a[i][c-1]; //double the block value and add to score
                        a[i][c]=0;
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }
    if(flag==0) //if no move was made
        (*score)--;
}

void move_right(int a[10][10],int n,int *score)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(a[i][j]!=0) //if there is a number in the block
            {
                int c=j;
                while(c<n-1)
                {
                    if(a[i][c+1]==0) //if the block on the right is empty
                    {
                        a[i][c+1]=a[i][c];
                        a[i][c]=0;
                        c++;
                    }
                    else if(a[i][c+1]==a[i][c]) //if the block on the right has same number
                    {
                        a[i][c+1]*=2;
                        (*score)+=a[i][c+1]; //double the block value and add to score
                        a[i][c]=0;
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }
    if(flag==0) //if no move was made
        (*score)--;
}

int check_win(int a[10][10],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==2048) //if 2048 formed
                return 1;
        }
    }
    return 0;
}