//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* conspiracy(void) {
    srand(time(NULL));
    int num = rand() % 5;
    char* theory;

    switch(num) {
        case 0:
            theory = "The moon landing was faked to win the space race.";
            break;
        case 1:
            theory = "The government is hiding the existence of aliens because they pose a threat to our way of life.";
            break;
        case 2:
            theory = "The assassination of JFK was an inside job orchestrated by the CIA.";
            break;
        case 3:
            theory = "The Illuminati control the world's governments and economies for their own gain.";
            break;
        case 4:
            theory = "Hillary Clinton is secretly a reptilian alien who plans to take over the world.";
            break;
        default:
            theory = "There is no conspiracy, everything is just as it seems.";
    }
    return theory;
}

int main(void) {
    char* theory = conspiracy();
    printf("Welcome to the random conspiracy theory generator!\n");
    printf("Your conspiracy theory is: %s\n", theory);
    return 0;
}