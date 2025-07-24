//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num[75];
    int called[75] = {0};
    int card[5][5];
    int count = 0;
    int i, j, random, x;
    char play_again = 'Y';
    
    printf("Welcome to the Bingo Simulator! Get ready for some fun!\n");
    
    //initialize the array 'num' with values from 1 to 75
    for(i = 0; i < 75; i++)
    {
        num[i] = i+1;
    }
    
    //shuffle the array 'num'
    srand(time(NULL));
    for(i = 0; i < 75; i++)
    {
        random = rand() % 75;
        x = num[i];
        num[i] = num[random];
        num[random] = x;
    }
    
    //display the shuffled array 'num'
    printf("\nShuffled Array:\n");
    for(i = 0; i < 75; i++)
    {
        printf("%d ", num[i]);
    }
    
    //generate and display the Bingo card
    printf("\n\nBingo Card:\n");
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(i == 2 && j == 2) //the center of the card is a free space
            {
                card[i][j] = -1;
                printf(" F ");
            }
            else
            {
                card[i][j] = num[count];
                printf("%2d ", card[i][j]);
                count++;
            }
        }
        printf("\n");
    }
    
    //game loop
    while(play_again == 'Y' || play_again == 'y')
    {
        int bingo = 0;
        int total_numbers = 0;
        int number;
        
        printf("\nPress ENTER to generate the next number:\n");
        getchar();
        
        //generate a random number from the shuffled array 'num'
        do
        {
            random = rand() % 75;
            number = num[random];
        } while(called[random] != 0); //make sure the number has not been called before
        called[random] = 1;
        
        printf("\nThe next number is: %d\n", number);
        
        //check if the number appears in the Bingo card and mark it as called
        for(i = 0; i < 5; i++)
        {
            for(j = 0; j < 5; j++)
            {
                if(card[i][j] == number)
                {
                    card[i][j] = -1;
                    printf("*%2d* ", number);
                }
                else
                {
                    printf("%3d ", card[i][j]);
                }
            }
            printf("\n");
        }
        
        //check if there is a Bingo
        for(i = 0; i < 5; i++)
        {
            int row = 0, column = 0, diagonal_1 = 0, diagonal_2 = 0;
            for(j = 0; j < 5; j++)
            {
                if(card[i][j] == -1) row++;
                if(card[j][i] == -1) column++;
                if(card[j][j] == -1 && i == j) diagonal_1++;
                if(card[j][4-j] == -1 && i+j == 4) diagonal_2++;
            }
            if(row == 5 || column == 5 || diagonal_1 == 5 || diagonal_2 == 5)
            {
                bingo = 1;
                printf("\nBingo!\n");
                break;
            }
        }
        total_numbers++;
        
        //ask the player if they want to play again
        if(bingo)
        {
            printf("You called %d numbers.\n", total_numbers);
            printf("Do you want to play again? (Y/N): ");
            scanf(" %c", &play_again);
            
            if(play_again == 'Y' || play_again == 'y')
            {
                count = 0;
                printf("\n\nNew Game:\n");
                for(i = 0; i < 75; i++)
                {
                    called[i] = 0;
                }
                for(i = 0; i < 5; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        if(i == 2 && j == 2)
                        {
                            card[i][j] = -1;
                        }
                        else
                        {
                            card[i][j] = num[count];
                            count++;
                        }
                    }
                }
                printf("\nBingo Card:\n");
                for(i = 0; i < 5; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        printf("%3d ", card[i][j]);
                    }
                    printf("\n");
                }
            }
        }
    }
    printf("\nThank you for playing the Bingo Simulator!\n");
    return 0;
}