//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define MIN_WORDS 10
#define MAX_WORDS 15

int get_typing_speed();

int main()
{
    int speed = get_typing_speed();
    printf("\nYour typing speed is %d wpm!\n", speed);
    return 0;
}

int get_typing_speed()
{
    char sentence[] = "The quick brown fox jumps over the lazy dog.";
    int len_sentence = sizeof(sentence) / sizeof(char) - 1;
    int words = 0;
    double time_spent;
    int correct_words = 0;
    
    srand(time(NULL));
    int rand_index = rand() % (len_sentence - 14);
    char *start = &sentence[rand_index];
    char input[100];
    
    printf("Type the following sentence:\n\n%s\n\n", start);
    printf("Press Enter to start!");
    getchar();
    
    clock_t begin = clock();

    while (words < MIN_WORDS)
    {
        printf("> ");
        fgets(input, 100, stdin);
        char *str = input;
        while (*str)
        {
            if (isspace(*str))
            {
                words++;
            }
            str++;
        }
        if (words >= MIN_WORDS)
        {
            printf("\nKeep typing until you see the message.\n");
            printf("Press Enter when you're done!\n");
            getchar();
            correct_words = 0;
            words = 0;
            begin = clock();
        }
    }
    
    while (words < MAX_WORDS)
    {
        printf("> ");
        fgets(input, 100, stdin);
        
        if (fgets(input, 100, stdin))
        {
            char *token = strtok(input, " ");
            while (token != NULL)
            {
                if (strncmp(start, token, strlen(token) - 1) == 0)
                {
                    correct_words++;
                }
                words++;
                token = strtok(NULL, " ");
            }
        }
    }
    
    clock_t end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("\nYou typed: %d correct words out of %d words.\n", correct_words, words);
    printf("It took you %.1lf seconds.\n", time_spent);
    double wpm = (double)(correct_words / 5.0) / (time_spent / 60.0);
    return (int)wpm;
}