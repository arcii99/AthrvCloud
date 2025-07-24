//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main()
{
    int num_chars = 0;
    char c, input;
    double time_spent;
    clock_t start, end;
    
    printf("Type the following sentence:\n");
    printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
    printf("Type your answer and press enter:\n");
    
    start = clock();
    while((c = getchar()) != '\n')
    {
        //Ignore uppercase/lowercase differences and non-alphabetic characters
        if(isalpha(c))
        {
            num_chars++;
        }
    }
    end = clock();
    time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    //Calculate typing speed in words per minute (WPM)
    double wpm = ((double)num_chars / 5) / (time_spent / 60);
    
    printf("Your typing speed is %.2f WPM\n", wpm);
    printf("Press any key to exit");
    input = getchar();
    return 0;
}