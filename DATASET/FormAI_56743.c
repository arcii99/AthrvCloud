//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[50];
    printf("Hello there! I am your automated fortune teller. What is your name?\n");
    scanf("%s", name);
    printf("\nHi %s! Let's see what the future holds for you today.\n", name);

    // Setting up random number generator
    srand(time(NULL));

    // Generating random number between 1 and 5
    int fortune_number = rand() % 5 + 1;

    // Switch statement for different fortune results
    switch(fortune_number) {
        case 1:
            printf("\nGreat news %s! Today, you will have the opportunity to make new friends and expand your social circle.\n", name);
            break;
        case 2:
            printf("\nYou will face a small problem today, %s. But don't worry, you have the intelligence and the resources to overcome it.\n", name);
            break;
        case 3:
            printf("\nToday, you will receive some unexpected good news, %s! This will brighten up your day and increase your confidence.\n", name);
            break;
        case 4:
            printf("\nYou will need to make a decision today, %s. It may seem like a tough one, but trust your instincts and you will choose the right path.\n", name);
            break;
        case 5:
            printf("\nYour hard work and dedication will pay off today, %s! You will receive recognition for your efforts and this will motivate you to keep going.\n", name);
            break;
        default:
            printf("\nOh no %s, something went wrong and I couldn't predict your fortune. Please try again later!\n", name);
    }
    printf("\nThank you for using the automated fortune teller. Have a wonderful day, %s!\n", name);
    return 0;
}