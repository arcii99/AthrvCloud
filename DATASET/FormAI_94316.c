//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // set the seed based on the current time

    int length, num_special_chars, num_numbers;
    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired password length (must be at least 8): ");
    scanf("%d", &length);

    if (length < 8) {
        printf("Sorry, the password length must be at least 8.\n");
        return 1; // exit the program with an error code
    }

    printf("How many special characters should be included? (0-3): ");
    scanf("%d", &num_special_chars);

    printf("How many numbers should be included? (0-%d): ", length - num_special_chars - 2);
    scanf("%d", &num_numbers);

    // calculate the number of letters needed to fill the password
    int num_letters = length - num_special_chars - num_numbers;

    char password[length + 1];

    // generate random letters
    for (int i = 0; i < num_letters; i++) {
        password[i] = 'a' + rand() % 26;
    }

    // generate random special characters
    for (int i = 0; i < num_special_chars; i++) {
        char special_chars[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')' };
        int index = rand() % 10;
        password[num_letters + i] = special_chars[index];
    }

    // generate random numbers
    for (int i = 0; i < num_numbers; i++) {
        password[num_letters + num_special_chars + i] = '0' + rand() % 10;
    }

    // shuffle the password using the Fisher-Yates algorithm
    for (int i = length - 1; i >= 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[length] = '\0'; // add null terminator

    printf("Your Secure Password is: %s\n", password);

    return 0; // exit the program with success
}