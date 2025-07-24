//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int score = 0;  // Score variable to keep track of the typing speed test
    char input[100];  // Character array to store the user's input
    char test[100] = "This is a typing speed test program. Welcome.";  // The string that the user will type
    printf("The test is ready. Type the sentence below as fast as you can.\n%s\n", test); // Prompting the user to type the sentence
    clock_t start_time = clock(); // Starting the timer
    gets(input); // Taking the user's input
    clock_t end_time = clock(); // Stopping the timer
    double time_used = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calculating the time used to type
    for(int i = 0; input[i] != '\0'; i++) // Looping through the user's input and comparing it with the actual sentence
    {
        if(input[i] == test[i])
        {
            score++; // Increasing the score for each character match
        }
    }
    printf("Your typing speed test score is %d. You took %lf seconds to type.\n", score, time_used); // Displaying the score and time taken to type
    return 0; // Returning 0 to indicate successful completion of the program
}