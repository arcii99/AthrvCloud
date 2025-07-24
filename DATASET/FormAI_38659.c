//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL)); // sets seed for random number generator

    // initialize variables
    int rows = 20;
    int columns = 20;
    int pixelSize = 10;
    int pixelColor;
    char pixelChar;
    char pixelArt[rows][columns];

    // loop through each pixel in array and randomly generate a color and character
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            pixelColor = rand() % 7; // generate random number between 0 and 6
                        
            // assign corresponding character to each color
            switch(pixelColor)
            {
                case 0:
                    pixelChar = ' ';
                    break;
                case 1:
                    pixelChar = '.';
                    break;
                case 2:
                    pixelChar = '+';
                    break;
                case 3:
                    pixelChar = '*';
                    break;
                case 4:
                    pixelChar = 'X';
                    break;
                case 5:
                    pixelChar = '#';
                    break;
                case 6:
                    pixelChar = '@';
                    break;
                default:
                    pixelChar = ' ';
                    break;
            }
            
            // set pixel in array to generated character
            pixelArt[i][j] = pixelChar;
        }
    }
    
    // print out generated pixel art
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            for(int k = 0; k < pixelSize; k++)
            {
                printf("%c", pixelArt[i][j]);
            }
        }
        printf("\n");
    }
}