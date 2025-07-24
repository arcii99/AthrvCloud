//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int correct_count = 0, wrong_count = 0, total_count = 0;
    char input;
    time_t t;
    
    srand((unsigned) time(&t));
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a random string of characters to type correctly.\n");
    printf("Press enter to start the test!\n");
    getchar();
    
    while(1)
    {
        char test_string[30];
        int i, j;
        
        for(i = 0; i < 30; i++)
        {
            test_string[i] = rand() % 26 + 65; // Generates a random uppercase letter
        }
        
        printf("Type this: ");
        for(j = 0; j < 30; j++)
        {
            printf("%c", test_string[j]);
        }
        printf("\n");
        
        for(j = 0; j < 30; j++)
        {
            input = getchar();
            if(input == test_string[j]) // If input matches the generated character
            {
                correct_count++;
            }
            else
            {
                wrong_count++;
            }
            total_count++;
        }
        
        printf("-------------------------\n");
        printf("Results for that round:\n");
        printf("Correct count: %d\n", correct_count);
        printf("Wrong count: %d\n", wrong_count);
        printf("Total count: %d\n", total_count);
        printf("-------------------------\n");
        printf("Press enter to continue or 'q' to quit.\n");
        
        input = getchar();
        if(input == 'q') // If user decides to quit the test
        {
            break;
        }
        printf("\n\n");
    }
    
    printf("Thank you for taking the Typing Speed Test!\n");
    return 0;
}