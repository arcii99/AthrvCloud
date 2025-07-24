//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be presented with a random paragraph to type.\n");
    printf("After typing the paragraph, you will receive your typing speed.\n");
    printf("Are you ready to start? (press enter to continue)\n");
    
    getchar();
    
    char paragraph[500] = "Peace is a state of mind that comes from within. It is the ability to remain calm and composed even when things are not going our way. When we are at peace, we are free from anxiety, worry, and stress. We can see things clearly and make sound decisions. In a world that can be chaotic and unpredictable, peace is a precious gift that we should strive to cultivate within ourselves.";
    
    printf("\n\n%s\n\n", paragraph);
    time_t start_time, end_time;
    time(&start_time);
    
    char user_input[500];
    fgets(user_input, 500, stdin);
    
    time(&end_time);
    double time_diff = difftime(end_time, start_time);
    
    int total_chars = strlen(paragraph);
    int correct_chars = 0;
    for(int i=0; i<total_chars; i++) {
        if(paragraph[i] == user_input[i]) {
            correct_chars++;
        }
    }
    int typing_speed = (correct_chars/5) / (time_diff/60);
    
    printf("\n\nYou typed the paragraph in %.f seconds.\n", time_diff);
    printf("Your typing speed is %d words per minute.\n", typing_speed);
    
    return 0;
}