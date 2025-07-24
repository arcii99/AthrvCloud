//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 20
#define GAME_TIME 30

int main()
{
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {"programming","keyboard","computer","algorithm","language","software","hardware","network","internet","database"};
    int word_count = 10;
    int random_index, i, j, correct_count = 0, incorrect_count = 0;
    char user_input;
    time_t start_time, end_time;
    double time_elapsed;

    printf("Type the words as fast as you can!!\n");
    printf("You have %d seconds\n", GAME_TIME);

    printf("Press Enter when you are ready....");

    while(1)
    {
        if(getchar() == '\n')
            break;
    }

    srand(time(0));

    time(&start_time);

    while(1)
    {
        random_index = rand() % word_count;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%s\n", words[random_index]);

        for(i=0; i<MAX_WORD_LENGTH; i++)
        {
            user_input = tolower(getchar());
            if(user_input == words[random_index][i])
            {
                printf("%c", user_input);
                correct_count++;
            }
            else
            {
                printf("*");
                incorrect_count++;
            }
        }

        if(correct_count == word_count * MAX_WORD_LENGTH)
            break;

        printf("Press Enter to continue...\n");

        fflush(stdin);

        while(1)
        {
            if(getchar() == '\n')
                break;
        }
    }

    time(&end_time);

    time_elapsed = difftime(end_time, start_time);

    printf("\n\nCongratulations!! You have typed all the words correctly!!\n");

    printf("Total time taken: %.2lf seconds\n", time_elapsed);

    printf("Total correct keystrokes: %d\n", correct_count);

    printf("Total incorrect keystrokes: %d\n", incorrect_count);

    printf("Your typing speed is: %.2lf words per minute\n", ((double)(correct_count/5))/(time_elapsed/60));
  
    return 0;
}