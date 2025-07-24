//FormAI DATASET v1.0 Category: Memory Game ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 8   //Size of the game board
#define MAX 10000 //Maximum number of players
#define MIN 1    //Minimum number of players

//Function to initialize the game board
void init(char board[][SIZE])
{
    int i,j;

    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            board[i][j]='_';   //Assigning underscore to all cells
        }
    }
}

//Function to print the game board
void print_board(char board[][SIZE])
{
    int i,j;

    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");  //New line after each row
    }
}

int main()
{
    int choice[MAX],n,i,j,k=0;
    char board[SIZE][SIZE];
    char cards[SIZE*SIZE/2];
    int matched[SIZE*SIZE/2];
    int p=0,turns=0;

    //Seed for random function
    srand(time(0));

    //Initializing the board and cards
    init(board);

    for(i=0;i<SIZE*SIZE/2;i++)
    {
        cards[i]='A'+i;         //Assigning characters to cards
        matched[i]=0;           //Assigning 0 to matched cards
    }

    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(k==SIZE*SIZE/2)      //Stopping the loop when all cards are placed on the board
            {
                break;
            }

            if(board[i][j]!='_')
            {
                continue;           //Skipping the cell if it's already occupied
            }

            int index=rand()%SIZE*SIZE/2;  //Random index to select card

            while(1)
            {
                if(matched[index]==0)
                {
                    board[i][j]=cards[index];  //Placing the card on the board
                    matched[index]=1;          //Marking the card as matched
                    k++;                        //Counting the cards placed
                    break;
                }
                else
                {
                    index=rand()%SIZE*SIZE/2;   //Selecting another card
                }
            }           
        }
    }

    //Getting number of players
    while(1)
    {
        printf("Enter number of players (1-%d): ",MAX);
        scanf("%d",&n);

        if(n>=MIN && n<=MAX)
        {
            break;
        }
        else
        {
            printf("Invalid Input\n");
        }
    }

    //Getting player's choice
    while(1)
    {
        printf("\nTurn %d:\n",++turns);
        print_board(board);

        for(i=0;i<n;i++)
        {
            printf("Player %d, enter your choice (row column): ",i+1);
            scanf("%d %d",&choice[p],&choice[p+1]);  //Choice array stores the choices of all players
            p+=2;                                    //Incrementing p by 2 for next player's choice
        }

        if(p>=SIZE*SIZE*2)
        {
            printf("\nGame over!\n");
            break;
        }

        //Checking for matches
        for(i=0;i<n;i++)
        {
            int r=choice[2*i];
            int c=choice[2*i+1];

            if(board[r][c]=='_')
            {
                printf("Player %d, this cell is empty\n",i+1);
            }
            else
            {
                printf("Player %d, you chose %c\n",i+1,board[r][c]);

                for(j=0;j<SIZE*SIZE/2;j++)
                {
                    if(matched[j]==0)     //Checking only unmatched cards
                    {
                        if(board[r][c]==cards[j])
                        {
                            board[r][c]='_';                //Hiding the card
                            printf("MATCH!\n");
                            matched[j]=1;                   //Marking the card as matched
                            break;
                        }
                    }
                }

                if(j==SIZE*SIZE/2)
                {
                    printf("NO MATCH!\n");     //If no match found
                }
            }           
        }
    }

    return 0;
}