//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void shuffle_words(char words[][MAX_WORD_LENGTH], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {
        "hello", "world", "programming", "language", "computer",
        "science", "software", "engineering", "algorithm", "database",
        "network", "security", "cyber", "internet", "web",
        "server", "client", "application", "mobile", "cloud",
        "system", "hardware", "peripheral", "input", "output",
        "memory", "storage", "display", "keyboard", "mouse",
        "printer", "scanner", "camera", "microphone", "speaker",
        "headset", "battery", "charger", "cable", "port",
        "browser", "file", "folder", "operating", "system",
        "version", "release", "update", "patch", "bug"
    };

    shuffle_words(words, MAX_WORDS);

    printf("Welcome to Typing Speed Test!\n\n");
    printf("Type each word shown on the screen and press Enter.\n");
    printf("You will get a score based on your typing speed and accuracy.\n");
    printf("Press Enter to start the test.\n");
    getchar();

    int total_words = 0;
    int correct_words = 0;
    int total_chars = 0;
    int correct_chars = 0;

    clock_t start_time = clock();

    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
        fflush(stdout);

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        } else {
            clear_input_buffer();
        }

        total_words++;
        total_chars += strlen(words[i]);

        if (strcmp(input, words[i]) == 0) {
            correct_words++;
            correct_chars += strlen(words[i]);
            printf("Correct!\n");
        } else {
            printf("Incorrect!\n");
        }
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nCongratulations! You have completed the test.\n");
    printf("Your typing speed: %.0f WPM (Words Per Minute)\n", (double)correct_words / elapsed_time * 60);
    printf("Your accuracy: %.0f%%\n", (double)correct_chars / total_chars * 100);

    return 0;
}