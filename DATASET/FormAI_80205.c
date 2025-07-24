//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define MAX_TIME_LIMIT 60

void clear_buffer() { // clear the input buffer
    while (getchar() != '\n');
}

int main() {
    char typing_string[MAX_STRING_LENGTH];
    char input_string[MAX_STRING_LENGTH];
    clock_t start_time, end_time;
    double time_elapsed;

    printf("*** Welcome to the Typing Speed Test! ***\n");
    printf("Please enter the following string:\n");
    scanf("%[^\n]s", typing_string); // reads until a newline character is encountered
    clear_buffer(); // clear the buffer after reading input string
    printf("\n");

    printf("Type the string as fast and accurately as possible\n");
    printf("Press Enter key when finished...\n\n");

    start_time = clock(); // start the timer

    while (1) {
        fgets(input_string, MAX_STRING_LENGTH, stdin);
        input_string[strlen(input_string)-1] = '\0'; // remove the newline character from the input string

        if (strcmp(input_string, typing_string) == 0) { // if the input is correct
            printf("\nCongratulations!!! You completed the typing test in %0.2f seconds\n", time_elapsed);
            break;
        }

        printf("Incorrect input! Try again...\n");
    }

    end_time = clock(); // stop the timer
    time_elapsed = ((double)(end_time-start_time))/CLOCKS_PER_SEC;

    return 0;
}