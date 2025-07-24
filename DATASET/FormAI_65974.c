//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_CHARS 80
#define MAX_LINES 10

int main() {
    char lines[MAX_LINES][MAX_LINE_CHARS+1];
    char input_line[MAX_LINE_CHARS+1];
    int line_times[MAX_LINES];
    int num_lines;
    clock_t start_time, end_time;
    int num_chars_typed, elapsed_time;
    float typing_speed;

    // Read in lines from file or user input
    // ...

    // Automatically determine number of lines to test
    num_lines = sizeof(lines) / sizeof(lines[0]);

    // Randomize order of lines to test
    srand(time(NULL));
    for (int i = 0; i < num_lines; i++) {
        int j = rand() % (i+1);
        char temp_line[MAX_LINE_CHARS+1];
        int temp_time;

        strcpy(temp_line, lines[i]);
        strcpy(lines[i], lines[j]);
        strcpy(lines[j], temp_line);

        temp_time = line_times[i];
        line_times[i] = line_times[j];
        line_times[j] = temp_time;
    }

    // Prompt user to begin typing test
    printf("Press enter to begin typing test.\n");
    getchar();

    // Begin test
    num_chars_typed = 0;
    start_time = clock();
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
        fgets(input_line, MAX_LINE_CHARS+1, stdin);
        line_times[i] = (int) (clock() - start_time) / CLOCKS_PER_SEC;
        num_chars_typed += strlen(input_line);
        if (i < num_lines-1) {
            printf("Press enter to continue.\n");
            getchar();
        }
    }
    end_time = clock();
    elapsed_time = (int) (end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate typing speed
    typing_speed = ((float) num_chars_typed / elapsed_time) * 60 / 5;

    // Display results
    printf("\n\n");
    printf("You typed %d characters in %d seconds.\n", num_chars_typed, elapsed_time);
    printf("Your typing speed is %.1f words per minute.\n", typing_speed);
    printf("\n\n");

    return 0;
}