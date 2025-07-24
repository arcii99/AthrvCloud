//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define TEST_ITERATIONS 5

int get_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_random_string(char *str, int length) {
    for (int i = 0; i < length; i++) {
        int ascii_code = get_random_int(65, 90);
        str[i] = (char) ascii_code;
    }
    str[length] = '\0';
}

int main() {
    srand(time(NULL));  // Initialize random number generator

    printf("Welcome to the C Typing Speed Test!\n\n");

    for (int i = 1; i <= TEST_ITERATIONS; i++) {
        char random_string[MAX_LENGTH + 1] = "";
        generate_random_string(random_string, MAX_LENGTH);

        printf("Test %d\n", i);
        printf("Type the following string as fast as you can:\n%s\n\n", random_string);

        // Prompt user for input
        char user_input[MAX_LENGTH + 1] = "";
        printf("Type here: ");
        scanf("%[^\n]", user_input);

        // Clear input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        // Calculate typing speed
        int length_difference = strlen(random_string) - strlen(user_input);
        int num_errors = 0;
        int num_correct = 0;
        for (int j = 0; j < strlen(user_input); j++) {
            if (user_input[j] == random_string[j]) {
                num_correct++;
            } else {
                num_errors++;
            }
        }
        int num_characters_typed = strlen(user_input);
        int num_total_characters = strlen(random_string);
        int accuracy = (num_correct * 100) / num_total_characters;
        int time_taken = (int) (clock() / (CLOCKS_PER_SEC / 60));
        int speed = (num_characters_typed / 5) / time_taken;

        printf("\nResults\n");
        printf("String Length: %d\n", num_total_characters);
        printf("Characters Typed: %d\n", num_characters_typed);
        printf("Errors: %d\n", num_errors);
        printf("Accuracy: %d%%\n", accuracy);
        printf("Time Taken: %d seconds\n", time_taken);
        printf("Typing Speed: %d words per minute\n\n", speed);
    }

    return 0;
}