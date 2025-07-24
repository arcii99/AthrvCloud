//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define SIZE 1000

// Function to generate a random character
char genRandChar() {
    return 'a' + rand() % 26;
}

// Function to calculate the typing speed
void calculateTypingSpeed(clock_t start_time, clock_t end_time, int typed_chars) {
    double seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double typing_speed = ((double)typed_chars / seconds) / 5;
    printf("\n\nYou typed %d characters in %.2f seconds\n", typed_chars, seconds);
    printf("Your typing speed is %.2f words per minute\n", typing_speed);
}

// Function to clear the input buffer
void clearInputBuffer(void) {
    while (getchar() != '\n') {
        // do nothing
    }
}

int main() {
    char input_char, random_char;
    int typed_chars = 0;
    clock_t start_time, end_time;
    srand(time(NULL));

    printf("\nWelcome to the Typing Speed Test Program!\n");
    printf("Type the character shown as fast as you can. Press 'Enter' to continue.\n\n");

    // Wait for user to start the test
    getchar();

    // Generate random characters and take input from user until 1000 characters are typed
    do {
        random_char = genRandChar();
        printf("%c ", random_char);
        input_char = toupper(getchar());
        clearInputBuffer();
        typed_chars += (input_char == random_char);
    } while (typed_chars < SIZE);

    // Calculate the typing speed
    end_time = clock();
    calculateTypingSpeed(start_time, end_time, typed_chars);

    printf("\nThank you for using the Typing Speed Test Program!\n");

    return 0;
}