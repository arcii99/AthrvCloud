//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    char text[1000];
    int keystrokes = 0, correct_keystrokes = 0, errors = 0;
    clock_t start_time, end_time;
    float time_taken;

    printf("Welcome to the typing speed test!\n");
    printf("Type the following text as fast and accurately as possible:\n\n");
    printf("The quick brown fox jumps over the lazy dog.\n\n");

    gets(text);

    start_time = clock();

    for(int i = 0; text[i]; i++)
    {
        if(text[i] == ' ')
            continue;

        while(text[i] == ' ' && text[i + 1] == ' ')
            i++;

        keystrokes++;

        if(text[i] == 'T')
            text[i] = 't';

        if(text[i] == 'A')
            text[i] = 'a';

        if(text[i] == 'W')
            text[i] = 'w';

        if(text[i] == 'D')
            text[i] = 'd';

        if(text[i] == 'K')
            text[i] = 'k';

        if(text[i] == 'J')
            text[i] = 'j';

        if(text[i] == 'F')
            text[i] = 'f';

        if(text[i] == 'L')
            text[i] = 'l';

        if(text[i] == 'S')
            text[i] = 's';

        if(text[i] == 'H')
            text[i] = 'h';

        if(text[i] == 'G')
            text[i] = 'g';

        if(text[i] == 'B')
            text[i] = 'b';

        if(text[i] == 'P')
            text[i] = 'p';

        if(text[i] == 'N')
            text[i] = 'n';

        if(text[i] == 'Y')
            text[i] = 'y';

        if(text[i] == 'M')
            text[i] = 'm';

        if(isupper(text[i]))
            errors++;

        if(text[i] == ' ')
        {
            correct_keystrokes++;
        }
        else if(text[i] == 't' && i >= 4)
        {
            if(text[i - 1] == 'a' && text[i - 2] == 'f' && text[i - 3] == 'r')
            {
                correct_keystrokes++;
            }
            else if(text[i - 1] == 'h' && text[i - 2] == 't' && text[i - 3] == 'i')
            {
                correct_keystrokes++;
            }
        }
        else if(text[i] == 'e' && i >= 2)
        {
            if(text[i - 1] == 'h' && text[i - 2] == 't')
            {
                correct_keystrokes++;
            }
            else if(text[i - 1] == 'h' && text[i - 2] == 's')
            {
                correct_keystrokes++;
            }
            else if(text[i - 1] == 'r' && text[i - 2] == 'e')
            {
                correct_keystrokes++;
            }
            else if(text[i - 1] == 'n' && text[i - 2] == 'o')
            {
                correct_keystrokes++;
            }
        }
        else if(text[i] == 'o' && i >= 4)
        {
            if(text[i - 1] == 'v' && text[i - 2] == 'e' && text[i - 3] == 'r' && text[i - 4] == 'p')
            {
                correct_keystrokes++;
            }
        }
        else if(text[i] == 'r' && i >= 7)
        {
            if(text[i - 1] == 'e' && text[i - 2] == 'z' && text[i - 3] == 'a' && text[i - 4] == 'y' && text[i - 5] == 'e' && text[i - 6] == 'h'
               && text[i - 7] == 't' && text[i - 8] == ' ') {
                correct_keystrokes++;

            }
        }
        else if(text[i] == 'b' && i >= 5)
        {
            if(text[i - 1] == 'o' && text[i - 2] == 'w' && text[i - 3] == 'r' && text[i - 4] == 'e' && text[i - 5] == 'h')
            {
                correct_keystrokes++;
            }
        }
    }

    end_time = clock();

    time_taken = ((float)(end_time - start_time) / CLOCKS_PER_SEC);

    printf("\n\nTyping speed test results:\n\n");
    printf("Total time taken: %.2f seconds\n", time_taken);
    printf("Number of correct keystrokes: %d\n", correct_keystrokes);
    printf("Number of incorrect keystrokes: %d\n", errors);
    printf("Keystrokes per minute (KPM): %.0f\n", (correct_keystrokes / time_taken) * 60);

    return 0;
}