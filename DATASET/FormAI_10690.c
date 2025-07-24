//FormAI DATASET v1.0 Category: Error handling ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void talkToTheHand(int error_code)
{
   switch(error_code)
   {
        case 1:
            printf("Syntax Error: Did you forget to feed the unicorns in your code?\n");
            break;
        case 2:
            printf("Data Error: You seem to have lost all your magic crystals...\n");
            break;
        case 3:
            printf("Logic Error: Did you accidentally push the big red button of doom?\n");
            break;
        case 4:
            printf("Memory Error: Did you try to access the forbidden realm without authorization?\n");
            break;
        case 5:
            printf("Time Error: Did you not read the warning label on the time machine?\n");
            break;
        default:
            printf("Unknown Error: Did you unleash the Kraken or something?\n");
            break;
   }
}

int main()
{
    int error_code = -1; //default error code

    printf("You have entered the surreal error handling program...\n");
    printf("Please select a realm of error to enter:\n");
    printf("1. Syntax Error\n");
    printf("2. Data Error\n");
    printf("3. Logic Error\n");
    printf("4. Memory Error\n");
    printf("5. Time Error\n");
    printf("> ");

    //read user input
    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; //remove newline character from input

    //check for valid input
    if(strcmp(input, "1") == 0 || strcmp(input, "2") == 0 || strcmp(input, "3") == 0 
        || strcmp(input, "4") == 0 || strcmp(input, "5") == 0)
    {
        error_code = atoi(input); //convert input to integer
    }
    else
    {
        printf("Invalid input! You have been teleported to the land of eternal recursion...\n");
        main(); //recursion to start over
    }

    //handle error
    talkToTheHand(error_code);

    printf("Thank you for visiting the surreal error handling program.\n");
    printf("May your code always be blessed by the chimeras of destiny...\n");
  
    return 0;
}