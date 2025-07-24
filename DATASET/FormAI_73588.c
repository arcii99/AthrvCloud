//FormAI DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>

void cheer() // Custom function to cheer up the user
{
    printf("Yay! You're doing great!\n");
    printf("Keep up the good work!\n");
    printf("You've got this!\n");
}

int main()
{
    int x, y, z;
    
    printf("Enter two integers:\n");
    if(scanf("%d%d", &x, &y) != 2) // If input does not contain two integers
    {
        fprintf(stderr, "Uh oh! You didn't enter two integers :(\n");
        cheer(); // Call custom function to cheer up the user
        return 1; // Return non-zero value to indicate error
    }
    else // If input contains two integers
    {
        if(y == 0) // If second integer is zero
        {
            fprintf(stderr, "Oops! Division by zero is not allowed :(\n");
            cheer(); // Call custom function to cheer up the user
            return 1; // Return non-zero value to indicate error
        }
        
        z = x / y; // Divide x by y and assign the result to z
        printf("%d / %d = %d\n", x, y, z);
        
        cheer(); // Call custom function to cheer up the user
        return 0; // Return zero value to indicate successful program execution
    }
}