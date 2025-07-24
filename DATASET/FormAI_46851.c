//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize the random seed
    
    printf("Ask me a question, or type 'quit' to exit the program.\n");

    char input[100];
    while (1) // keep looping until the user types 'quit'
    {
        fgets(input, 100, stdin); // read user input
        
        if (strcmp(input, "quit\n") == 0) // if user types 'quit', exit
        {
            printf("Goodbye!\n");
            break;
        }

        int rand_num = rand() % 4; // generate a random number between 0 and 3
        
        switch (rand_num)
        {
            case 0:
                printf("The answer is yes.\n");
                break;
            case 1:
                printf("The answer is no.\n");
                break;
            case 2:
                printf("I am unable to answer that at this time.\n");
                break;
            case 3:
                printf("The stars are not aligned for me to answer that.\n");
                break;
        }
    }
    
    return 0;
}