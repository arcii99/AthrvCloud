//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: high level of detail
#include <stdio.h>  // Importing standard input/output library
#include <stdlib.h> // Importing standard library

int main()
{
    char signal; // Declares a character type variable named `signal`
    printf("Enter signal color (R: Red, Y: Yellow, G: Green): ");
    scanf("%c", &signal); // Prompt the user to enter a signal color and store it in the `signal` variable.
    if (signal == 'R') // if signal is red, print a message
    {
        printf("STOP! The signal is RED.\n");
    }
    else if (signal == 'Y') // if signal is yellow, print a message
    {
        printf("Get ready to STOP! The signal is YELLOW.\n");
    }
    else if (signal == 'G') // if signal is green, print a message
    {
        printf("GO! The signal is GREEN.\n");
    }
    else // if the user entered an invalid signal, print an error message
    {
        printf("Invalid signal. Please enter R, Y, or G only.\n");
    }

    return 0;
}