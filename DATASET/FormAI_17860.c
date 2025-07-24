//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char arr[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}[]:<>,.?/'\"\\|"; // Array of all allowed characters
    int n = 50; // Number of characters to be typed
    int score = 0, time_taken; // Variables to store score and time taken
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following characters:\n");

    for(int i=0; i<n; i++) // Generating random characters to be typed
    {
        printf("%c", arr[rand() % strlen(arr)]);
    }
    
    printf("\n");
    clock_t start = clock(); // Starting the timer
    
    char input[n];
    gets(input); // Getting user input
    
    clock_t end = clock(); // Stopping the timer
    time_taken = (end - start) * 1000 / CLOCKS_PER_SEC; // Calculating time taken in milliseconds
    
    for(int i=0; i<n; i++) // Checking user input
    {
        if(input[i] == arr[i])
        {
            score++;
        }
    }
    
    printf("Your score: %d/%d\n", score, n);
    printf("Time taken: %d milliseconds\n", time_taken);

    return 0;
}