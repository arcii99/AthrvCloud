//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_chars = 100;
    char typing_string[num_chars];
    char user_input[num_chars];
    int time_limit = 10;
    time_t start_time, end_time;
    double time_diff;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following string as quickly and accurately as possible:\n");

    // Generate random typing string
    for (int i = 0; i < num_chars; i++) {
        int rand_num = rand() % 26;
        typing_string[i] = 'a' + rand_num;
        printf("%c", typing_string[i]);
    }

    printf("\nPress any key to start...");
    getchar();

    printf("\n10 seconds left...\n");
    start_time = time(NULL);

    // Get user input
    fgets(user_input, num_chars, stdin);

    end_time = time(NULL);
    time_diff = difftime(end_time, start_time);

    printf("Time taken: %.2f seconds\n", time_diff);

    // Calculate accuracy
    int num_correct = 0;
    for (int i = 0; i < num_chars; i++) {
        if (user_input[i] == typing_string[i]) {
            num_correct++;
        }
    }

    double accuracy = (double)num_correct / num_chars * 100;
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}