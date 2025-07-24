//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 5
#define MAX_STRING_LENGTH 50
#define MAX_TIME 30

int main()
{
    char words[MAX_WORDS][MAX_STRING_LENGTH] = {"elephant", "moon", "computer", "banana", "umbrella"};
    int i, j, random;
    char input[MAX_STRING_LENGTH];
    int total_words = 0, correct_words = 0;
    time_t start_time, end_time;
    
    srand(time(NULL));
    
    printf("\tC Typing Speed Test\n\n");
    printf("Enter the following words:\n\n");
    
    start_time = time(NULL);
    
    while (difftime(time(NULL), start_time) < MAX_TIME)
    {
        random = rand() % MAX_WORDS;
        printf("%s ", words[random]);
        scanf("%s", input);
        total_words++;
        
        if (strcmp(input, words[random]) == 0)
        {
            correct_words++;
        }
    }
    
    end_time = time(NULL);
    
    printf("\n\nResults:\n\n");
    printf("Total words: %d\n", total_words);
    printf("Correct words: %d\n", correct_words);
    printf("Incorrect words: %d\n", total_words - correct_words);
    printf("Time taken: %d seconds\n", (int)difftime(end_time, start_time));
    printf("Words per minute: %.0f\n", ((float)correct_words / (float)difftime(end_time, start_time)) * 60);
    
    return 0;
}