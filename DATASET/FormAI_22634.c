//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 128 // Maximum characters to be considered

// Function to retrieve user input string securely
void get_input_string(char *input_string, size_t max_len) {
    printf("Enter a string of maximum length %zu: ", max_len - 1);
    fgets(input_string, max_len, stdin);
    // Removing the trailing newline character from the input string
    input_string[strcspn(input_string, "\n")] = '\0';
}

// Function to count the frequency of each character in the input string
void count_char_freq(char *input_string, int *char_freq_arr) {
    size_t input_str_len = strlen(input_string);
    for (size_t i = 0; i < input_str_len; ++i) {
        int char_val = input_string[i];
        if (char_val >= 0 && char_val <= MAX_CHARS) {
            ++char_freq_arr[char_val];
        }
    }
}

// Function to print the character frequency count
void print_char_freq(int *char_freq_arr, size_t arr_len) {
    printf("Character frequency count:\n");
    for (int i = 0; i < arr_len; ++i) {
        if (char_freq_arr[i] > 0) {
            if (isprint(i)) {
                printf("'%c' or 0x%02x: %d\n", i, i, char_freq_arr[i]);
            }
            else {
                printf("0x%02x: %d\n", i, char_freq_arr[i]);
            }
        }
    }
}

int main() {
    // Securely retrieving the input string
    char input_string[101] = {0}; // Maximum input string length set to 100
    get_input_string(input_string, sizeof(input_string));

    // Initializing the character frequency count array
    int char_freq_arr[MAX_CHARS] = {0};

    // Counting the frequency of each character in the input string
    count_char_freq(input_string, char_freq_arr);

    // Printing the character frequency count
    print_char_freq(char_freq_arr, MAX_CHARS);

    return 0;
}