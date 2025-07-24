//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    int i, correct = 0, incorrect = 0;
    char input[100];
    const char* text = "The quick brown fox jumps over the lazy dog.";
    time_t start_time, end_time;
    
    printf("Type the following line: %s\n", text);
    time(&start_time); // Get starting time
    
    for (i = 0; i < strlen(text); i++) {
        scanf("%c", &input[i]);
        
        if (input[i] == text[i]) {
            correct++;
        }
        else {
            incorrect++;
        }
    }
    
    time(&end_time); // Get ending time
    double elapsed_time = difftime(end_time, start_time);
    double typing_speed = (double)strlen(text) / elapsed_time * 60;
    
    printf("\nYour typing speed is %.2f words per minute.\n", typing_speed);
    printf("You typed %d characters correctly and %d characters incorrectly.\n", correct, incorrect);
    
    return 0;
}