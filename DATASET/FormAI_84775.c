//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 100

char* conspiracy_list[] = {
    "The earth is flat!",
    "Chemtrails are a government conspiracy!",
    "The moon landing was faked!",
    "9/11 was an inside job!",
    "The government is hiding evidence of UFOs!",
    "The Illuminati controls everything!",
    "The vaccine is killing people!",
    "The New World Order is coming!",
    "The Deep State is manipulating the world!",
    "The Bilderberg Group is running the show!",
    "The reptilians are among us!",
    "The Mandela Effect proves we're living in a parallel universe!",
    "Donald Trump is a time traveler!",
    "The Titanic didn't sink!",
    "MK-Ultra is still active!",
    "Area 51 is hiding alien technology!",
    "The apocalypse is nigh!",
    "Sasquatch is real and the government is hiding it from us!",
    "The government is hiding free energy technology!",
    "The moon is a hollowed-out spaceship!"
};

int main() {
    srand(time(NULL)); // Set random seed based on time

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    while(1) { // Loop indefinitely to generate new conspiracy theories
        printf("\nPress enter to generate a new conspiracy theory, or enter 'quit' to exit:\n");

        char input[MAX_CONSPIRACY_LENGTH];
        fgets(input, MAX_CONSPIRACY_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline character

        if(strcmp(input, "quit") == 0) {
            printf("Thanks for using the Random Conspiracy Theory Generator!\n");
            break;
        }

        int index = rand() % (sizeof(conspiracy_list) / sizeof(char*)); // Choose a random conspiracy

        printf("\nCONSPIRACY THEORY ALERT:\n%s\n", conspiracy_list[index]);
    }

    return 0;
}