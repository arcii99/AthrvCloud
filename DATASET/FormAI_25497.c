//FormAI DATASET v1.0 Category: QR code generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_SIZE 25

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time
    int qrCode[QR_SIZE][QR_SIZE];
    int currentRow = 0;
    int currentCol = 0;
    int direction = 0; // 0 for right, 1 for down, 2 for left, 3 for up
    
    // Initialize all elements of the qrCode to 0
    for(int i = 0; i < QR_SIZE; i++)
    {
        for(int j = 0; j < QR_SIZE; j++)
        {
            qrCode[i][j] = 0;
        }
    }
    
    // Generate the QR code with a random pattern
    while(currentRow < QR_SIZE && currentCol < QR_SIZE)
    {
        // Mark the current position with a 1
        qrCode[currentRow][currentCol] = 1;
        
        // Check which direction we are currently moving in and move to the next corresponding cell
        switch(direction)
        {
            case 0: // Right
                if(currentCol + 1 >= QR_SIZE || qrCode[currentRow][currentCol + 1] == 1)
                {
                    direction = 1; // Change direction to down
                    currentRow++;
                } else {
                    currentCol++;
                }
                break;
            case 1: // Down
                if(currentRow + 1 >= QR_SIZE || qrCode[currentRow + 1][currentCol] == 1)
                {
                    direction = 2; // Change direction to left
                    currentCol--;
                } else {
                    currentRow++;
                }
                break;
            case 2: // Left
                if(currentCol - 1 < 0 || qrCode[currentRow][currentCol - 1] == 1)
                {
                    direction = 3; // Change direction to up
                    currentRow--;
                } else {
                    currentCol--;
                }
                break;
            case 3: // Up
                if(currentRow - 1 < 0 || qrCode[currentRow - 1][currentCol] == 1)
                {
                    direction = 0; // Change direction to right
                    currentCol++;
                } else {
                    currentRow--;
                }
                break;
        }
    }
    
    // Print the generated QR code
    for(int i = 0; i < QR_SIZE; i++)
    {
        for(int j = 0; j < QR_SIZE; j++)
        {
            printf("%d ", qrCode[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}