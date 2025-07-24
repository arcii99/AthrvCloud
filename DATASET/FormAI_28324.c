//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: configurable
// C Typing Speed Test Example Program
// By [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, user_input, num_words;
    char words[10][20] = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur", "Adipiscing", "Elit", "Pharetra", "Sagittis"};
    time_t start, end;
    float time_taken, total_time = 0, average_time;
    
    printf("Welcome to the C Typing Speed Test!\n");
    printf("How many words would you like to type? ");
    scanf("%d", &num_words);

    for (i = 1; i <= num_words; i++)
    {
        srand(time(NULL));
        j = rand() % 10;
        printf("%s ", words[j]);
        time(&start);
        scanf("%s", &user_input);
        time(&end);
        time_taken = difftime(end, start);
        total_time = total_time + time_taken;
    }

    average_time = total_time / num_words;
    printf("\n\nCongratulations! You have completed the typing speed test.\n");
    printf("Your average typing time per word was %.2f seconds.\n", average_time);
    
    return 0;
}