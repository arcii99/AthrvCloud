//FormAI DATASET v1.0 Category: Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char username[20];
    char password[20];
    int attempts_left = 5;
    int is_logged_in = 0;

    printf("Welcome to the secure login system!\n");

    while (attempts_left > 0 && !is_logged_in) {
        printf("Please enter your username (max 20 characters):\n");
        fgets(username, 20, stdin);
        username[strcspn(username, "\n")] = 0;

        printf("Please enter your password (max 20 characters):\n");
        fgets(password, 20, stdin);
        password[strcspn(password, "\n")] = 0;

        // Perform secure authentication check
        if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
            is_logged_in = 1;
        } else {
            printf("Invalid username or password! Attempts left: %d\n", attempts_left - 1);
            attempts_left--;
        }
        // Important: Clear input buffer to prevent unauthorized access
        clear_input_buffer();
    }

    if (is_logged_in) {
        printf("Successful login!\n");

        // Play game
        int target_number = rand() % 100 + 1;
        int guess;
        int is_game_over = 0;

        printf("Guess the number between 1 and 100!\n");

        while (!is_game_over) {
            printf("Enter your guess:\n");
            scanf("%d", &guess);
            clear_input_buffer();

            if (guess == target_number) {
                printf("Congratulations, you guessed the number!\n");
                is_game_over = 1;
            } else if (guess < target_number) {
                printf("Your guess is too low. Try again.\n");
            } else {
                printf("Your guess is too high. Try again.\n");
            }
        }
    } else {
        printf("You have been locked out of the system!\n");
    }

    return 0;
}