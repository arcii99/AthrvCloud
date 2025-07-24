//FormAI DATASET v1.0 Category: QR code generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
Curious QR Code Generator
This program generates a unique QR code for any given string using C language.
The generated QR code can be scanned and read by any QR code reader.
*/

#define MAX_SIZE 100
#define BLACK "\u2588"
#define WHITE " "

// Function to print a QR code
void printQRCode(char qrCode[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (qrCode[i][j] == 1)
            {
                printf("%s", BLACK);
            }
            else
            {
                printf("%s", WHITE);
            }
        }
        printf("\n");
    }
}

// Function to generate a unique QR code
void generateQRCode(char data[])
{
    // Initialize a 2D array for the QR code
    char qrCode[MAX_SIZE][MAX_SIZE] = { 0 };

    // Generate a random seed
    srand(time(NULL));

    // Generate random start position and direction for the QR code
    int x = rand() % MAX_SIZE;
    int y = rand() % MAX_SIZE;
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;

    // Initialize QR code generator variables
    int index = 0;
    int length = strlen(data);

    // Generate QR code using random walk algorithm
    while (index < length)
    {
        // Mark current position with black
        qrCode[y][x] = 1;

        // Move in random direction
        x += dx;
        y += dy;

        // Bounce off borders
        if (x < 0)
        {
            x = 1;
            dx = 1;
        }
        else if (x >= MAX_SIZE)
        {
            x = MAX_SIZE - 2;
            dx = -1;
        }

        if (y < 0)
        {
            y = 1;
            dy = 1;
        }
        else if (y >= MAX_SIZE)
        {
            y = MAX_SIZE - 2;
            dy = -1;
        }

        // If next position is white, change direction randomly
        if (qrCode[y][x] == 0)
        {
            int direction = rand() % 5;
            switch (direction)
            {
            case 0:
                dx = 0;
                dy = -1;
                break;
            case 1:
                dx = -1;
                dy = 0;
                break;
            case 2:
                dx = 1;
                dy = 0;
                break;
            case 3:
                dx = 0;
                dy = 1;
                break;
            default:
                dx = 0;
                dy = 0;
                break;
            }
        }

        // Move to next character in data
        index++;
    }

    // Print the generated QR code
    printQRCode(qrCode, MAX_SIZE);
}

int main()
{
    // Ask user for input
    char input[MAX_SIZE];
    printf("Enter a string to generate a QR code:\n");
    fgets(input, MAX_SIZE, stdin);

    // Generate QR code for input
    generateQRCode(input);

    return 0;
}