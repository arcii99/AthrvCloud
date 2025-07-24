//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL));

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    while (1) {
        printf("\nEnter any key to generate a new conspiracy theory or 'Q' to quit: ");
        char input = getchar();
        getchar(); // consume the newline character from the input buffer

        if (input == 'Q' || input == 'q') {
            printf("\nThank you for using the Random Conspiracy Theory Generator!\n");
            break;
        }

        int random_num = rand() % 10;

        if (random_num == 0) {
            printf("\nDid you know that the moon landing was faked? NASA staged the event to win the Space Race against the Soviet Union!");
        } else if (random_num == 1) {
            printf("\nIt's a well-known fact that the government is hiding evidence of alien encounters. Roswell was not a weather balloon but an extraterrestrial spacecraft!");
        } else if (random_num == 2) {
            printf("\nThe Illuminati controls the world's governments, financial systems, and media outlets. They are planning for a New World Order!");
        } else if (random_num == 3) {
            printf("\nHave you ever heard of Operation Northwoods? The US government planned false flag attacks to justify a war with Cuba!");
        } else if (random_num == 4) {
            printf("\nThe Twin Towers were not brought down by planes on 9/11. It was an inside job orchestrated by the US government!");
        } else if (random_num == 5) {
            printf("\nThe earth is flat and the government has been lying to us about the true shape of our planet for centuries!");
        } else if (random_num == 6) {
            printf("\nThe mafia assassinated JFK to prevent him from cracking down on organized crime!");
        } else if (random_num == 7) {
            printf("\nChemtrails from commercial airplanes are actually a government plot to control the population through mind control chemicals!");
        } else if (random_num == 8) {
            printf("\nThe Denver airport is the headquarters of the New World Order and it contains an underground bunker for the global elite!");
        } else {
            printf("\nPaul McCartney died in a car accident in 1966 and was replaced by a lookalike!");
        }
    }

    return 0;
}