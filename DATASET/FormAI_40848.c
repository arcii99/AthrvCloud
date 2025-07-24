//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char bingo[5][5] = {{' ', 'B', 'I', 'N', 'G'},
                        {'1', '-', '-', '-', '-'},
                        {'2', '-', '-', '-', '-'},
                        {'3', '-', '-', '-', '-'},
                        {'4', '-', '-', '-', '-'}};
    int i=0,j=0,rand_num=0,found=0,count=0,bingo_num=0;    
    printf("Bingo Game Starts!!\nCross off the numbers as they are called!\n\n");
    while(count < 25)
    {
        srand(time(NULL)); //random number generator using time as seed
        rand_num = rand() % 75 + 1; //generating random number from 1 to 75
        found = 0;
        for(i = 1; i <= 4; i++)
        {
            for(j = 1; j <=4; j++)
            {
                if(bingo[i][j] == 'X') //checking if the random number already crossed off or not
                {
                    found++;
                }
                if((bingo[i][j] == (rand_num/10 + '0'))&&(bingo[i][j+1] == (rand_num%10 + '0'))) //checking if the number exists in the bingo card
                {
                    bingo[i][j] = 'X'; //crossing off the number if found
                    count++;
                    found++;
                }
            }
        }           
        if(found == 0)//if the number not exists in the card
        {
            printf("%d is not in the card\n", rand_num);
            continue;
        }
        else if(found > 1)//if the number is already crossed off
        {
            printf("%d is already crossed off\n", rand_num);
            continue;
        }
        else //if the number found and not crossed off
        {
            printf("The number is %d\n", rand_num);
            //printing the updated bingo card
            for(i = 0; i <= 4; i++)
            {
                printf("\n");
                for(j = 0; j <=4; j++)
                {
                    printf("%c  ", bingo[i][j]);
                }
            }
            printf("\n\n");
        }
        //Checking for Bingo
        //Row check
        for(i = 1; i <=4; i++)
        {
            for(j = 1; j <=4; j++)
            {
                if(bingo[i][j] != 'X')
                {
                    break;
                }
            }
            if(j == 5)
            {
                bingo_num++;
            }
        }
        //Column check
        for(i = 1; i <=4; i++)
        {
            for(j = 1; j <=4; j++)
            {
                if(bingo[j][i] != 'X')
                {
                    break;
                }
            }
            if(j == 5)
            {
                bingo_num++;
            }
        }
        //Diagonal check
        if(bingo[1][1] == 'X' && bingo[2][2] == 'X' && bingo[3][3] == 'X' && bingo[4][4] == 'X')
        {
            bingo_num++;
        }
        if(bingo[1][4] == 'X' && bingo[2][3] == 'X' && bingo[3][2] == 'X' && bingo[4][1] == 'X')
        {
            bingo_num++;
        }
        if(bingo_num > 0)
        {
            printf("BINGO!!\nYou got %d bingo in this game.\n", bingo_num);
            break;
        }
    }
    if(count == 25)//if no Bingo achieved in the current game.
    {
        printf("Game over! Try again for Bingo!\n");
    }
    return 0;
}