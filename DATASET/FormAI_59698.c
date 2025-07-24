//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEXT_LENGTH 1000

char text[MAX_TEXT_LENGTH];
char user_input[MAX_TEXT_LENGTH];

void generate_text() {
    const char alphanum[] =
	    "0123456789"
	    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	    "abcdefghijklmnopqrstuvwxyz";

    srand(time(NULL));
    for (int i = 0; i < MAX_TEXT_LENGTH - 1; ++i) {
        text[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    text[MAX_TEXT_LENGTH - 1] = '\0';
}

int main() {
    int idx = 0, correct_ctr = 0, incorrect_ctr = 0;
    double time_elapsed;
    clock_t start_time = clock();

    generate_text();
    printf("----Typing speed test----\n");
    printf("Type the following text as fast as you can: \n\n%s\n\n", text);

    while (1) {
        char c = getchar();

        if (c == '\n' || idx == MAX_TEXT_LENGTH - 1) {
            user_input[idx] = '\0';
            break;
        } else if (c == '\b' || c == 127) {
            if (idx != 0) {
                printf("\b \b", user_input[idx]);
                idx--;
            }
        } else {
            user_input[idx] = c;
            idx++;
        }
    }

    time_elapsed = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    for (int i = 0; i < MAX_TEXT_LENGTH; ++i) {
        if (user_input[i] == '\0') {
            break;
        } else if (user_input[i] == text[i]) {
            correct_ctr++;
        } else {
            incorrect_ctr++;
        }
    }
  
    printf("\n\nYou typed:\n%s\n", user_input);
    printf("\n----Results----\n");
    printf("Time elapsed: %.2f seconds\n", time_elapsed);
    printf("Typing speed: %.2f characters per minute\n", MAX_TEXT_LENGTH * 60 / (time_elapsed * 100));
    printf("%d characters correct\n", correct_ctr);
    printf("%d characters incorrect\n", incorrect_ctr);
    return 0;
}