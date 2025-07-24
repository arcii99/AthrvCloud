//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pause() {
    printf("\nPress enter to continue...");
    getchar();
}

int main() {
    srand(time(NULL));

    char *conspiracyTheory[] = {
        "The moon landing was faked to hide the existence of extraterrestrial life",
        "Global warming is a hoax created by governments to control the population",
        "The Illuminati control the world's governments",
        "The cure for cancer has been found but is being hidden by pharmaceutical companies",
        "9/11 was an inside job orchestrated by the US government",
        "Area 51 is home to aliens and advanced technology",
        "The government is using chemtrails to control the weather and population",
        "Elvis Presley is still alive and living in hiding",
        "The earth is actually flat and governments are hiding the truth",
        "The pyramids were built by aliens and not by humans"
    };

    while (1) {
        printf("Random Conspiracy Theory Generator\n");
        printf("---------------------------------\n");

        printf("\nYour random conspiracy theory is:\n\n");
        printf("%s\n", conspiracyTheory[rand() % 10]);

        pause();
    }

    return 0;
}