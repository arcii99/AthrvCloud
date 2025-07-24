//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random fortune
char* generateFortune() {
    char* fortunes[] = {
        "You will win the lottery next week.",
        "Your future has already been determined.",
        "You will meet the love of your life tomorrow.",
        "A new opportunity is on the horizon for you.",
        "You will embark on a great adventure soon.",
        "You will face a great challenge, but you will overcome it.",
        "Your hard work will pay off in the end.",
        "Keep doing what you're doing, success is just around the corner.",
        "The best is yet to come.",
        "You will achieve greatness in the future."
    };
    int index = rand() % 10;
    return fortunes[index];
}

// function to display the fortune and ask if user wants another fortune
char askForFortune() {
    char answer;

    // generate and display the fortune
    char* fortune = generateFortune();
    printf("Your fortune for today is:\n\n%s\n\n", fortune);

    // ask if the user wants another fortune
    printf("Do you want another fortune? (Y/N)\n");
    while (1) {
        answer = getchar();
        if (answer == 'Y' || answer == 'N') {
            break;
        }
        printf("Invalid input, please enter Y or N.\n");
    }

    return answer;
}

// main program
int main() {
    // seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller!\n\n");

    char answer;
    do {
        answer = askForFortune();
    } while (answer == 'Y');

    printf("\nThank you for using the Automated Fortune Teller!\n");

    return 0;
}