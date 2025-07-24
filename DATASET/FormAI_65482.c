//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char i, j;
    int arr[5][5];
    srand(time(NULL));
    
    printf("\nWelcome to the Surrealist BINGO Simulator!\n\n");
    printf("B | I | N | G | O\n");
    printf("---------------\n");
    
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(i == 2 && j == 2)
            {
                arr[i][j] = 0;
                printf(" | ");
            }
            else
            {
                arr[i][j] = rand() % 100;
                printf("%d| ", arr[i][j]);
            }
            
            if(j == 4)
            {
                printf("\n---------------\n");
            }
        }
    }
    
    return 0;
}