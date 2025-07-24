//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int time_limit = 60, i, correct = 0, incorrect = 0;
    char input;
    time_t start_time, end_time, curr_time;
    srand(time(0));
 
    printf("Welcome to the C Typing Speed Test!\n");
    printf("You have 60 seconds to type as many correct characters as possible.\n");
    printf("Press Enter to start the test.\n");
    fflush(stdin);
    getchar();
 
    printf("Test starts now...\n");
    start_time = time(NULL);
 
    while ((curr_time = time(NULL)) - start_time <= time_limit) {
        char c = 'a' + rand() % 26;
        printf("%c", c);
        fflush(stdout);
 
        if ((input = getchar()) == c) {
            correct++;
            printf("%c", input);
        } else {
            incorrect++;
            printf("\b \b");  // erase incorrect character
        }
    }
 
    printf("\n\nTime's up! You typed %d correct characters in %d seconds.\n", correct, time_limit);
    printf("You made %d incorrect keystrokes.\n", incorrect);
 
    return 0;
}