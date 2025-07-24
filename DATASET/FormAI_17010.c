//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Declare variables
    int input_num, checksum = 0, digit_count = 0;
    bool is_valid_input = true;

    printf("Please enter a number to calculate its checksum:\n");

    // Read user input and validate that it is a positive integer
    if(scanf("%d", &input_num) != 1 || input_num < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        is_valid_input = false;
    }

    // If the input is valid, calculate the checksum
    if(is_valid_input) {
        // Loop through each digit in the input number and add it to the checksum
        while(input_num > 0) {
            int digit = input_num % 10;
            checksum += digit;
            input_num /= 10;
            digit_count++;
        }

        // Output the checksum and number of digits
        printf("Checksum: %d\n", checksum);
        printf("Number of digits: %d\n", digit_count);
    }

    return 0;
}