//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    int words_per_min = 0;
    time_t start, end;
    char input[1000], temp;
    int i = 0, count = 0;
 
    // Generate Random String of words
    char *strings[] = {"typing", "speed", "test", "example", "program", "in", "c", "language", "coding", "multivariable", "style", "is", "fun", "and", "challenging", "for", "programmers"};
    srand(time(NULL));
    int n = rand() % (sizeof(strings) / sizeof(char *));
 
    // Display Random String 
    printf("The displayed string is:\n");
    printf("------------------------------\n");
    printf("%s\n", strings[n]);
    printf("------------------------------\n");
    printf("Type the above string:\n");

    // Get Current Time
    time(&start);

    gets(input);

    time(&end);

    // Calculate the time elapsed
    double time_elapsed = difftime(end, start);

    // Calculate words per minute
    i = 0;
    while (input[i] != '\0') {
        if (input[i] == ' ' || input[i] == '\n') {
            count++;
        }
        i++;
    }

    words_per_min = (int)(((double)count / time_elapsed) * 60);

    printf("You typed %d words in %.2lf seconds\n", count, time_elapsed);
    printf("Your typing speed is %d words per minute\n", words_per_min);

    return 0;
}