//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void shuffle(char *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          char t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

void print_welcome_message()
{
    printf("\nWelcome to the Typing Speed Test Game!\n");
    printf("You will have to type a randomly generated string.\n");
    printf("Try to type it as fast as you can and press ENTER when you're done.\n");
}

void print_start_message()
{
    printf("\nAre you ready?\n");
    printf("Press ENTER to start the game.\n");
}

void play_game()
{
    char string[] = "This is a Typing Speed Test Game!";

    printf("\nType this string as fast as you can:\n");

    shuffle(string, strlen(string));

    printf("%s\n", string);

    char input[100];
    fgets(input, 100, stdin);

    int i;
    for(i = 0; i < strlen(input); i++)
    {
        if(input[i] == '\n')
        {
            input[i] = '\0';
            break;
        }
    }

    double time_spent = (double)(clock()) / CLOCKS_PER_SEC;

    if(strcmp(input, string) == 0)
    {
        printf("\nCongratulations! You typed the string correctly.\n");
    }
    else
    {
        printf("\nOops! You made a mistake while typing the string.\n");
    }

    printf("\nTime taken: %0.2f seconds\n", time_spent);
}

int main()
{
    print_welcome_message();
    print_start_message();
    getchar();
    play_game();

    return 0;
}