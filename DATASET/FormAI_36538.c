//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 1000

int main()
{
    char typed_text[MAX_LEN], random_text[MAX_LEN];
    int i, correct_count = 0, error_count = 0;
    float accuracy, typing_speed;
    clock_t start_time, end_time;

    //Generate random text for typing test
    srand(time(0));
    for(i = 0; i < MAX_LEN; i++)
    {
        random_text[i] = (rand() % 26) + 'a'; //Generate random lowercase letter
    }
    random_text[MAX_LEN - 1] = '\0'; //Terminate the string

    printf("Welcome to the Typing Speed Test\n\n");
    printf("Type the following text as fast and accurately as possible:\n\n%s\n", random_text);
    printf("Press Enter to start...");
    getchar();

    //Record start time
    start_time = clock();

    //Get user input for typing test
    printf("\n");
    fgets(typed_text, MAX_LEN, stdin);
    typed_text[strlen(typed_text) - 1] = '\0'; //Remove newline character from input

    //Record end time
    end_time = clock();

    //Compare typed text with random text for accuracy and statistics
    for(i = 0; i < strlen(random_text); i++)
    {
        if(random_text[i] == typed_text[i])
        {
            correct_count++;
        }
        else
        {
            error_count++;
        }
    }

    accuracy = ((float)correct_count / strlen(random_text)) * 100;
    typing_speed = ((float)strlen(random_text) / ((end_time - start_time) / (float)CLOCKS_PER_SEC)) * 60;

    printf("\n");
    printf("Results:\n");
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing speed: %.2f WPM (words per minute)\n", typing_speed);
    printf("Number of errors: %d\n", error_count);

    return 0;
}