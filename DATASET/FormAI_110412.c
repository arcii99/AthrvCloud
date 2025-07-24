//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));  // Initialize random seed
    
    char user_input;
    printf("Welcome to the Automated Fortune Teller. Press 'y' to start or any other key to exit.\n");

    scanf("%c", &user_input);

    // Loop to continue the game until user exits
    while(user_input == 'y') {
        printf("Thinking...\n");

        // Get random number to determine fortune message
        int fortune_number = generate_random_number(1, 5);

        switch(fortune_number) {
            case 1:
                printf("Your future looks bright!\n");
                break;
            case 2:
                printf("Be cautious in your financial decisions.\n");
                break;
            case 3:
                printf("You will find success in your career.\n");
                break;
            case 4:
                printf("Love is in the air!\n");
                break;
            default:
                printf("Your hard work will pay off in the near future.\n");
        }

        printf("Press 'y' to play again or any other key to exit.\n");
        getchar();  // Remove newline character from input buffer
        scanf("%c", &user_input);
    }

    printf("Thank you for using the Automated Fortune Teller.\n");
    return 0;
}