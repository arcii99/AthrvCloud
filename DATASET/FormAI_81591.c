//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1000

int main() {
    char text[MAX_TEXT_LENGTH], user_input[MAX_TEXT_LENGTH];
    float elapsed_time, typing_speed;
    time_t start_time, end_time;
    int i = 0, correct_char = 0;
    
    printf("WELCOME TO THE TYPING TEST!\n\n");
    
    // loading text from a file
    FILE *file;
    file = fopen("typing_text.txt", "r");
    if (file == NULL) {
        printf("Error! Could not open file.\n");
        exit(1);
    }
    fgets(text, MAX_TEXT_LENGTH, file);
    fclose(file);
    
    printf("Type the following text as fast and accurately as you can:\n\n%s\n\n", text);
    
    time(&start_time); // starting timer
    
    // getting user input
    while(text[i] != '\0' && i < MAX_TEXT_LENGTH) {
        user_input[i] = getchar();
        if (user_input[i] == text[i]) {
            correct_char++;
        }
        i++;
    }
    
    time(&end_time); // ending timer
    
    elapsed_time = difftime(end_time, start_time);
    typing_speed = ((float)correct_char / elapsed_time) * 60;
    
    printf("\n\nCongratulations! You typed:\n%s\n\n", user_input);
    printf("Elapsed time: %.2f seconds.\n", elapsed_time);
    printf("Typing speed: %.2f characters per minute.\n", typing_speed);
    
    return 0;
}