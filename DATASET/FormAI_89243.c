//FormAI DATASET v1.0 Category: Data validation ; Style: active
#include <stdio.h>
#include <stdbool.h> // for bool data type

// Function prototype
bool is_valid_input(char s[]);

int main() {
    char input[20];

    printf("Please enter a number: ");
    scanf("%s", input);

    // Check if the input is valid
    if(is_valid_input(input)) {
        int num = atoi(input); // Convert string to integer

        printf("Your number is: %d\n", num);
    } else {
        printf("Invalid input! Please enter a positive integer number.\n");
    }

    return 0;
}

bool is_valid_input(char s[]) {
    int i = 0;

    // Check if the string is not empty
    if(s[i] == '\0') {
        return false;
    }

    // Check if the string contains only digits
    while(s[i] != '\0') {
        if(s[i] < '0' || s[i] > '9') {
            return false;
        }
        i++;
    }

    // Check if the number is positive
    if(s[0] == '0') {
        return false;
    }

    return true;
}