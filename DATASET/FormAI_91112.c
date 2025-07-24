//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <time.h>

int main() {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int expected_key, key, correct_count = 0, incorrect_count = 0;
    float elapsed_time;
    time_t start_time, end_time;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Instructions:\n");
    printf("1) Type the letter shown on the screen.\n");
    printf("2) Press Enter to submit.\n");
    printf("3) Type as many letters as you can in 30 seconds.\n\n");

    printf("Press Enter to start the test.");
    getchar();

    start_time = time(NULL);

    for (int i = 0; i < 30; i++) {
        int random_index = rand() % 26;
        printf("%c ", alphabet[random_index]);
        fflush(stdout);

        expected_key = alphabet[random_index];
        key = getchar();
        if (key == expected_key) {
            correct_count++;
        } else {
            incorrect_count++;
        }
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("\n\nTime taken: %.2f seconds\n", elapsed_time);
    printf("Total correct: %d\n", correct_count);
    printf("Total incorrect: %d\n", incorrect_count);

    float accuracy = (float) correct_count / (float) (correct_count + incorrect_count) * 100;
    printf("Accuracy: %.2f%%", accuracy);

    return 0;
}