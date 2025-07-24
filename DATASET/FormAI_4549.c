//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char text[100] = "This is a typing speed test. Type as fast as you can!";
    int len = sizeof(text) / sizeof(text[0]);

    printf("Type the following sentence:\n\n%s\n\n", text);

    time_t start_time = time(NULL);
    char input[100];
    fgets(input, 100, stdin);
    time_t end_time = time(NULL);

    int correct = 0;
    int incorrect = 0;

    for (int i = 0; i < len; i++) {
        if (text[i] == input[i]) {
            correct++;
        } else {
            incorrect++;
        }
    }

    double time_taken = difftime(end_time, start_time);
    double typing_speed = (double)(correct * 60) / time_taken;

    printf("Your typing speed is %.2f words per minute\n", typing_speed);
    printf("You typed %d correct characters and %d incorrect characters\n", correct, incorrect);

    return 0;
}