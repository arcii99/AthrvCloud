//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char userInput[100], randomText[100];
    int errors = 0, i;
    double timeSpent;
    time_t start, finish;

    printf("Welcome to C Typing Speed Test.\n\n");
    printf("You will be given a random sentence and you must type it as fast as possible without errors.\n\n");
    printf("Press Enter to begin.\n");
    getchar();

    // Generate random text
    srand(time(NULL));
    for(i = 0; i < 100; i++){
        randomText[i] = (char)(rand() % 26 + 'a');
    }

    printf("Type the following sentence:\n\n%s\n\n", randomText);
    start = time(NULL);
    gets(userInput);
    finish = time(NULL);

    // Calculate time spent
    timeSpent = (double)(finish - start) / CLOCKS_PER_SEC;

    // Check for errors
    for(i = 0; i < 100; i++){
        if(randomText[i] != userInput[i]){
            errors++;
        }
    }

    // Display results
    printf("\n\nTime spent: %.2f seconds\n", timeSpent);
    printf("Errors: %d", errors);

    return 0;
}