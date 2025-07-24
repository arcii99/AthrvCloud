//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random conspiracy theory and print it
void generateConspiracyTheory() {
    char* theories[] = {
        "The moon landing was faked by the government!",
        "The Illuminati controls the world!",
        "Aliens have been visiting Earth for centuries!",
        "The earth is flat and the government is hiding it from us!",
        "Chemtrails are being used to control our minds!",
        "Vaccinations are causing autism!",
        "The government is controlling the weather with HAARP!",
        "9/11 was an inside job!",
        "The Bermuda Triangle is a portal to another dimension!",
        "The New World Order is coming!",
        "The Freemasons are behind everything!",
        "The government is hiding the cure for cancer!",
        "Elvis Presley is still alive and in hiding!",
        "The Loch Ness Monster is real and the government is hiding it from us!",
        "The Titanic was sunk on purpose!",
        "The CIA is behind the crack epidemic!",
        "Bigfoot is an alien!",
        "The government is hiding evidence of extraterrestrial life!",
        "The Denver Airport is a secret government base!",
        "The JFK assassination was a conspiracy!"
    };
    int numTheories = sizeof(theories) / sizeof(theories[0]);
    int randIndex = rand() % numTheories;
    printf("%s\n", theories[randIndex]);
}

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("--------------------------------------------------\n");
    printf("Press Enter to generate a conspiracy theory, q to quit\n");
    srand(time(NULL));
    while (1) {
        char c = getchar();
        if (c == 'q') {
            break;
        } else if (c == '\n') {
            generateConspiracyTheory();
        } else {
            printf("Invalid input, please try again.\n");
        }
    }
    return 0;
}