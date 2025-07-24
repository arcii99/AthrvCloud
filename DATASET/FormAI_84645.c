//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_NAME_LEN 20
#define MAX_NUM_TESTS 10
#define MAX_TIME_SEC 30

int main()
{
    char name[MAX_NAME_LEN];
    int score[MAX_NUM_TESTS], total_score = 0, num_tests = 0;
    clock_t start_time, end_time;
    double time_taken;
    
    printf("Welcome to the Typing Speed Test Program!\n");
    printf("Please enter your name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0;
    printf("\nHi %s, let's begin the test!\n", name);
    
    while(num_tests < MAX_NUM_TESTS && time_taken < MAX_TIME_SEC)
    {
        char test_word[MAX_NAME_LEN];
        char user_input[MAX_NAME_LEN];
        int i;
        
        printf("\nType the following word:\n");
        generate_test_word(test_word); //generates a random word to type
        printf("%s\n", test_word);
        start_time = clock();
        fgets(user_input, MAX_NAME_LEN, stdin);
        user_input[strcspn(user_input, "\n")] = 0;
        end_time = clock();
        
        if(strcmp(user_input, test_word) == 0) //user typed the word correctly
        {
            time_taken += (double)(end_time - start_time) / CLOCKS_PER_SEC;
            score[num_tests] = 10 - (int)(time_taken * 2);
            if(score[num_tests] < 0)
                score[num_tests] = 0;
            printf("Correct! Score: %d\n", score[num_tests]);
            num_tests++;
            total_score += score[num_tests-1];
        }
        else //user typed the word incorrectly
        {
            printf("Incorrect!\n");
        }
    }
    
    printf("\nTest Results:\n");
    printf("Total Time Taken: %.2lf seconds\n", time_taken);
    printf("Number of Tests Taken: %d\n", num_tests);
    printf("Total Score: %d\n", total_score);
    if(num_tests > 0)
        printf("Average Score: %.2lf\n", (double)total_score / num_tests);
    
    return 0;
}

void generate_test_word(char *test_word)
{
    char *words[] = {"hello", "world", "typing", "speed", "test", "computer", "science", "programming", "language", "algorithm"};
    int num_words = sizeof(words) / sizeof(words[0]);
    int index = rand() % num_words;
    strcpy(test_word, words[index]);
}