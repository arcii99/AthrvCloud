//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random conspiracy theories
char* generate_conspiracy() {
    // List of conspiracy theories
    char* theories[] = {
        "The moon landing was faked",
        "9/11 was an inside job",
        "Aliens are among us",
        "The government is controlling our minds with chemtrails",
        "Vaccines cause autism",
        "The earth is flat",
        "Elvis is still alive",
        "The Illuminati controls the world",
        "The Loch Ness monster is real",
        "The pyramids were built by aliens"
    };

    // Generate random index
    srand(time(NULL));
    int i = rand() % 10;

    // Return a conspiracy theory
    return theories[i];
}

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator\n");
    printf("-----------------------------------------------\n");

    // Keep generating conspiracy theories until user quits
    while (1) {
        printf("Press any key to generate a conspiracy theory or 'q' to quit: ");
        char choice = getchar();
        
        // Check if user wants to quit
        if (choice == 'q' || choice == 'Q') {
            break;
        }

        // Generate and print a conspiracy theory
        char* theory = generate_conspiracy();
        printf("\n%s\n\n", theory);
    }

    printf("Thanks for using the Random Conspiracy Theory Generator! Stay woke.\n");

    return 0;
}