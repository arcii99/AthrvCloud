//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: distributed
// Distributed Typing Speed Test 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_TEXT_LENGTH 500
#define NUM_TESTS 5

// Function Prototypes
void generate_text(char *, int);
int test_typing_speed(char *, char *);
void print_results(int, int);

int main()
{
    srand(time(NULL));  // initialize random seed

    char original_text[MAX_TEXT_LENGTH];
    char typed_text[MAX_TEXT_LENGTH];
    int total_accuracy = 0;
    int total_time = 0;

    for(int i=0; i<NUM_TESTS; i++)
    {
        generate_text(original_text, MAX_TEXT_LENGTH);
        printf("Type the following text:\n%s\n", original_text);
        clock_t start_time = clock();
        scanf("%[^\n]s", typed_text);
        clock_t end_time = clock();
        fflush(stdin);  // clear input buffer
        int typing_speed = test_typing_speed(original_text, typed_text);
        total_accuracy += typing_speed;
        total_time += end_time - start_time;
    }

    int average_accuracy = total_accuracy / NUM_TESTS;
    int average_time = total_time / NUM_TESTS;
    print_results(average_accuracy, average_time);

    return 0;
}

// Function to generate random text containing only lowercase letters and spaces
void generate_text(char *str, int length)
{
    for(int i=0; i<length-1; i++)
    {
        int random_char = rand() % 27;  // 26 letters + 1 space
        if(random_char == 26)
        {
            str[i] = ' ';
        }
        else
        {
            str[i] = 'a' + random_char;
        }
    }
    str[length-1] = '\0';
}

// Function to compare original text with typed text and return typing speed (accuracy)
int test_typing_speed(char *original_text, char *typed_text)
{
    int accuracy = 0;
    int mistakes = 0;
    int i=0;
    while(original_text[i] != '\0' && typed_text[i] != '\0')
    {
        if(original_text[i] == typed_text[i])
        {
            accuracy++;
        }
        else
        {
            mistakes++;
        }
        i++;
    }
    return (accuracy * 100) / (accuracy + mistakes);  // accuracy percentage
}

// Function to print test results
void print_results(int accuracy, int time)
{
    printf("Typing Speed Test Results:\n");
    printf("Average Typing Accuracy: %d%%\n", accuracy);
    printf("Average Typing Time: %d milliseconds\n", time);
}