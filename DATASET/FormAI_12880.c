//FormAI DATASET v1.0 Category: Memory Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));     // Seed for random number generator
    int numArray[6][6];  // 6x6 memory game board   
    int i, j, num=1, row1, col1, row2, col2, count=0;
    
    // Fill the board with random numbers from 1 to 18, two of each number
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            numArray[i][j] = num;
            if(num == 18) 
            {
                num = 1;    // Reset num to 1 after reaching 18
            }
            else 
            {
                num++;
            }       
        }
    }
    
    // Shuffle the numbers on the board
    int temp, x, y;
    for(i=0;i<36;i++)
    {
        x = rand() % 6;     // Random row
        y = rand() % 6;     // Random column
        
        // Swap the positions of two numbers on the board
        temp = numArray[x][y];
        numArray[x][y] = numArray[i/6][i%6];
        numArray[i/6][i%6] = temp;
    }
    
    printf("Welcome to the Memory Game!\n");
    
    // Loop until all pairs have been found
    while(count < 18)
    {
        printf("Enter the position of the first number (row column): ");
        scanf("%d %d", &row1, &col1);
        
        // Check if the position is valid
        if(row1 < 0 || row1 > 5 || col1 < 0 || col1 > 5)
        {
            printf("Invalid position! Try again.\n");
            continue;
        }
        
        // Check if the position has already been revealed
        if(numArray[row1][col1] == 0)
        {
            printf("That number has already been revealed! Try again.\n");
            continue;
        }
        
        printf("%d\n", numArray[row1][col1]);
        printf("Enter the position of the second number (row column): ");
        scanf("%d %d", &row2, &col2);
        
        // Check if the position is valid
        if(row2 < 0 || row2 > 5 || col2 < 0 || col2 > 5)
        {
            printf("Invalid position! Try again.\n");
            continue;
        }
        
        // Check if the position has already been revealed
        if(numArray[row2][col2] == 0)
        {
            printf("That number has already been revealed! Try again.\n");
            continue;
        }
        
        printf("%d\n", numArray[row2][col2]);
        
        // Check if the two revealed numbers match
        if(numArray[row1][col1] == numArray[row2][col2])
        {
            printf("Congratulations! You found a pair.\n");
            numArray[row1][col1] = 0;
            numArray[row2][col2] = 0;
            count++;
        }
        else
        {
            printf("Sorry, those numbers don't match. Try again.\n");
        }
    }
    
    printf("Game over! You found all pairs in %d tries.\n", count*2);
    
    return 0;
}