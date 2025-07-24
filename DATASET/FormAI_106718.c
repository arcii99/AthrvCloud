//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Alan Touring
// C Typing Speed Test Program
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int i, n, score = 0, duration;
    char c, ch;

    printf("Welcome to the C Typing Speed Test program!\n");
    printf("Type as many characters as you can in 30 seconds.\n");
    printf("Ready? Press Enter to start the game.\n");
    getchar();

    time_t start_time = time(NULL);

    for(i = 0; i < 30; i++)
    {
        printf("Type the character: ");
        srand(time(NULL));
        c = 'a' + rand() % 26;
        printf("%c\n", c);

        do
        {
            ch = getchar();
            if (isalpha(ch))
            {
                if(ch == c)
                {
                    score++;
                }
            }
        } while(ch != '\n' && ch != EOF);
    }

    time_t end_time = time(NULL);
    duration = end_time - start_time;

    printf("Time's up!\n");
    printf("Your typing speed was %d characters per minute.\n", (score * 60) / duration);

    return 0;
}