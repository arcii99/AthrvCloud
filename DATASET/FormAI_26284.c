//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the traffic light colors
#define RED 1
#define YELLOW 2
#define GREEN 3

// Define a function to randomly generate a color based on its probability
int generateColor()
{
    int color;

    // Generate a random number between 1 and 10 inclusive
    int randomNumber = rand() % 10 + 1;

    // If the random number is less than or equal to 3, set color to green
    if (randomNumber <= 3)
    {
        color = GREEN;
    }
    // If the random number is greater than 3 but less than or equal to 7, set color to yellow
    else if (randomNumber > 3 && randomNumber <= 7)
    {
        color = YELLOW;
    }
    // If the random number is greater than 7, set color to red
    else
    {
        color = RED;
    }

    return color;
}

// Define a function to print the corresponding color based on the color code
void printColor(int color)
{
    switch (color)
    {
    case GREEN:
        printf("Green\n");
        break;
    case YELLOW:
        printf("Yellow\n");
        break;
    case RED:
        printf("Red\n");
        break;
    }
}

int main()
{
    // Initialize variables to keep track of the current and previous colors
    int currentColor = generateColor();
    int previousColor = 0;

    // Print the current color
    printf("Current color: ");
    printColor(currentColor);

    // Loop indefinitely
    while (1)
    {
        // Sleep for 2 seconds
        sleep(2);

        // Set the previous color to the current color
        previousColor = currentColor;

        // Generate a new color
        currentColor = generateColor();

        // Print the current color
        printf("Current color: ");
        printColor(currentColor);

        // Check if the previous color was green and the current color is not
        if (previousColor == GREEN && currentColor != GREEN)
        {
            // Print a warning message
            printf("Warning: Green light has turned off!\n");
        }
    }

    return 0;
}