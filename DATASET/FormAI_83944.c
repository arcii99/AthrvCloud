//FormAI DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initializing random number generator with current time
    int x = rand() % 3; // generating a random integer between 0 to 2
    int error_code = 0; // initializing error code variable with 0
  
    if (x == 0) // simulating a failure scenario
    {
        printf("ERROR: Failed to read the input data.\n");
        error_code = 1; // setting error code to 1
    }
    else if (x == 1)
    {
        printf("ERROR: Failed to perform the computation.\n");
        error_code = 2; // setting error code to 2
    }
    else if (x == 2)
    {
        printf("ERROR: Failed to write the output data.\n");
        error_code = 3; // setting error code to 3
    }
  
    if (error_code != 0) // if any error occurred
    {
        printf("Do you want to retry (y/n) ? ");
        char choice;
        scanf(" %c", &choice); // taking input from user
        
        if (choice == 'y') // if user wants to retry
        {
            printf("Retrying...\n");
            main(); // recursively calling main function to retry
        }
        else // if user does not want to retry
        {
            printf("Exiting program with error code %d.\n", error_code);
            return error_code; // returning error code from program
        }
    }
    else // if no error occurred
    {
        printf("Program executed successfully.\n");
        return 0; // returning success code from program
    }
}