//FormAI DATASET v1.0 Category: Binary Converter ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_BINARY_LENGTH 32 // Maximum length of binary string
#define PARANOIA_LEVEL 3 // Maximum number of attempts for any step

void clear_input_buffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int read_binary(int* binary_num) {
    char binary_string[MAX_BINARY_LENGTH];
    int attempt = 0;

    do {
        attempt++;
        if (attempt > PARANOIA_LEVEL) {
            printf("Too many attempts, exiting...\n");
            return -1;
        }

        printf("Enter a binary number: ");
        if (fgets(binary_string, MAX_BINARY_LENGTH, stdin) == NULL) {
            printf("Invalid input\n");
            continue;
        }

        /* Remove trailing newline character */
        binary_string[strcspn(binary_string, "\n")] = '\0';

        /* Check if string contains only 0s and 1s */
        int is_valid = 1;
        for (unsigned int i = 0; i < strlen(binary_string); i++) {
            if (binary_string[i] != '0' && binary_string[i] != '1') {
                is_valid = 0;
                break;
            }
        }

        if (!is_valid) {
            printf("Invalid input\n");
            continue;
        }

        /* Convert binary string to int */
        *binary_num = strtol(binary_string, NULL, 2);
        return 0;
    } while (1);
}

void convert_decimal_to_binary(int decimal_num, char* binary_string) {
    char temp_string[MAX_BINARY_LENGTH];
    int index = 0;
    do {
        if (index >= MAX_BINARY_LENGTH) {
            printf("Error: Binary string length exceeded limit of %d\n", MAX_BINARY_LENGTH);
            binary_string[0] = '\0';
            return;
        }

        if (decimal_num % 2 == 0) {
            temp_string[index] = '0';
        } else {
            temp_string[index] = '1';
        }
        decimal_num /= 2;
        index++;
    } while(decimal_num > 0);

    /* Reverse the string to get the correct binary representation */
    for (int i = 0; i < index; i++) {
        binary_string[i] = temp_string[index - i - 1];
    }
    binary_string[index] = '\0';
}

int main() {
    int decimal_num;
    char binary_string[MAX_BINARY_LENGTH];

    if (read_binary(&decimal_num) != 0) {
        return -1;
    }

    convert_decimal_to_binary(decimal_num, binary_string);

    printf("Binary representation: %s\n", binary_string);

    return 0;
}