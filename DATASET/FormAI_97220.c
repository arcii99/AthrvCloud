//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Ada Lovelace
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char *str = "Lorem Ipsum is simply dummy text of the printing and typesetting industry.";
    int length = strlen(str);
    char input[length];
    int correct = 0, wrong = 0, seconds = 0, index = 0;
    printf("Type the following text:\n\n%s\n", str);
    time_t start = time(NULL);
    while (index < length)
    {
        char letter = getchar();
        if (isalpha(letter))
        {
            if (letter == str[index])
            {
                correct++;
            }
            else
            {
                wrong++;
            }
            input[index] = letter;
            index++;
        }
    }
    time_t end = time(NULL);
    seconds = end - start;
    double wpm = (double)length / 5.0 / ((double)seconds / 60.0);
    printf("\n\nYou typed:\n%s\n", input);
    printf("Time taken: %d seconds\n", seconds);
    printf("Correctly typed characters: %d\n", correct);
    printf("Incorrectly typed characters: %d\n", wrong);
    printf("Words Per Minute: %.2f\n", wpm);
    return 0;
}