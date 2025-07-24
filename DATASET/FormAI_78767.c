//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char user_input;
    srand(time(NULL)); // seed the random number generator

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Type 'q' to quit or any other key to continue: ");
    scanf("%c", &user_input);

    while (user_input != 'q') {
        int random_num = rand() % 5; // generate a random number between 0 and 4
        printf("\n");

        switch(random_num) {
            case 0:
                printf("You will find success in your career.\n");
                break;
            case 1:
                printf("You will meet someone special within the next month.\n");
                break;
            case 2:
                printf("You may face difficult challenges, but they will make you stronger.\n");
                break;
            case 3:
                printf("Unexpected good news is coming your way.\n");
                break;
            case 4:
                printf("Your hard work will pay off soon.\n");
                break;
            default:
                printf("Error: Invalid random number generated.\n");
                break;
        }

        printf("Type 'q' to quit or any other key to continue: ");
        scanf(" %c", &user_input); // add a space before %c to clear any whitespace characters
    }

    printf("\nThank you for using the Automated Fortune Teller!\n");

    return 0;
}