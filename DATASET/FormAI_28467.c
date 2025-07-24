//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Typing Speed Test. Press Enter to start!");
    char start = getchar();
    if (start == '\n') {
        printf("Clock starts NOW: \n\n");
        time_t start_time = time(NULL);
        char input[100];
        fgets(input, 100, stdin);
        time_t end_time = time(NULL);
        double time_taken = difftime(end_time, start_time);
        int words_typed = 0;
        for (int i = 0; input[i] != '\n'; i++) {
            if (input[i] == ' ') {
                words_typed++;
            }
        }
        printf("Congratulations, you typed %d words in %.2f seconds. Your typing speed is ", words_typed+1, time_taken);
        if (time_taken < 5.0) {
            printf("Out of this world!");
        } else if (time_taken >= 5.0 && time_taken < 10.0) {
            printf("Faster than a cheetah!");
        } else if (time_taken >= 10.0 && time_taken < 20.0) {
            printf("A bit faster than average.");
        } else if (time_taken >= 20.0 && time_taken < 30.0) {
            printf("Just about average.");
        } else if (time_taken >= 30.0 && time_taken < 40.0) {
            printf("Slower than average, but that's okay.");
        } else if (time_taken >= 40.0 && time_taken < 60.0) {
            printf("A bit slow, but you can improve.");
        } else {
            printf("You might wanna consider typing lessons.");
        }
    } else {
        printf("Sorry, I didn’t get that. Please try again.");
    }
    return 0;
}