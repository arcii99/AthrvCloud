//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog";
    int text_length = strlen(text);
    char typed_text[100];
    time_t start_time, end_time;
    int seconds;
    int characters_typed = 0;
    int mistakes = 0;
    int typing_speed = 0;
    
    printf("Welcome to the Typing Speed Test\n");
    printf("You will be given the following text to type:\n");
    printf("%s\n", text);
    printf("Press enter to start typing\n");
    getchar();
    
    time(&start_time);
    
    while (1) {
        printf("\nType the text exactly as you see it:\n");
        fgets(typed_text, sizeof(typed_text), stdin);
        
        characters_typed = strlen(typed_text) - 1;
        
        if (typed_text[characters_typed] == '\n') {
            typed_text[characters_typed] = '\0';
        }
        
        if (strcmp(typed_text, text) == 0) {
            printf("\nCongratulations! You have typed the text correctly\n");
            time(&end_time);
            seconds = (int) difftime(end_time, start_time);
            printf("It took you %d seconds to type the text\n", seconds);
            typing_speed = (characters_typed * 60) / seconds;
            printf("Your typing speed is %d characters per minute\n", typing_speed);
            break;
        } else {
            printf("\nOops! You have typed the text incorrectly\n");
            mistakes++;
        }
    }
    
    printf("\nYou made %d mistake(s)\n", mistakes);
    
    return 0;
}