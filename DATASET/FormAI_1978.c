//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//The duration of the test in seconds
#define DURATION 60

//The maximum length of the character array for the input from the user
#define MAX_INPUT_LENGTH 1000

//The minimum and maximum length of the randomly generated strings
#define MIN_STRING_LENGTH 3
#define MAX_STRING_LENGTH 7

//The number of strings to be included in the test
#define NUM_STRINGS 10

//Function to generate a random string
void generateString(char* str, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        int index = rand() % (sizeof(charset) - 1);
        str[i] = charset[index];
    }
    str[length] = '\0';
}

int main() {
    srand(time(NULL));

    char strings[NUM_STRINGS][MAX_STRING_LENGTH + 1]; //The array to hold randomly generated strings
    for (int i = 0; i < NUM_STRINGS; i++) {
        int length = rand() % (MAX_STRING_LENGTH - MIN_STRING_LENGTH + 1) + MIN_STRING_LENGTH; //Generate a random length for the string
        generateString(strings[i], length); //Generate a random string of the given length
    }

    printf("Welcome to the typing speed test!\n");
    printf("You will have %d seconds to type as many random strings as you can.\n", DURATION);
    printf("Press Enter to start the test.\n");

    getchar(); //Wait for user input

    time_t start_time, current_time;
    time(&start_time);

    int num_correct = 0;
    int num_incorrect = 0;
    int num_total = 0;
    char input[MAX_INPUT_LENGTH];

    while (difftime(current_time, start_time) < DURATION) {
        int string_index = rand() % NUM_STRINGS; //Select a random string from the array
        printf("%s\n", strings[string_index]);

        fgets(input, MAX_INPUT_LENGTH, stdin); //Get user input

        //Remove the newline character from the input
        int input_length = strlen(input);
        if (input[input_length - 1] == '\n') {
            input[input_length - 1] = '\0';
        }

        if (strcmp(input, strings[string_index]) == 0) { //Check if the input matches the selected string
            printf("Correct!\n");
            num_correct++;
        }
        else {
            printf("Incorrect.\n");
            num_incorrect++;
        }

        num_total++;
        time(&current_time);
    }

    //Calculate the results of the test
    int num_chars = num_correct + num_incorrect;
    double accuracy = (double)num_correct / num_total * 100;
    double wpm = (double)num_chars / 5 / DURATION * 60;

    printf("Test completed!\n");
    printf("Number of correct strings: %d\n", num_correct);
    printf("Number of incorrect strings: %d\n", num_incorrect);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing speed: %.2f WPM (words per minute)\n", wpm);

    return 0;
}