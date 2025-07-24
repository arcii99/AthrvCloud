//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THEORIES 10

int main(void) {
    char* theories[NUM_THEORIES] = {
        "The government is controlled by shape-shifting lizards.",
        "The moon landing was faked.",
        "The Illuminati controls the world.",
        "Chemtrails are being used for mind control.",
        "9/11 was an inside job.",
        "The earth is flat.",
        "The cure for cancer exists but is being suppressed.",
        "The apocalypse is coming in 2021.",
        "The Bermuda Triangle is a portal to another dimension.",
        "The Titanic was sunk on purpose for insurance money.",
    };
    
    srand(time(NULL));
    int theoryIndex = rand() % NUM_THEORIES;
    printf("Random conspiracy theory: %s\n", theories[theoryIndex]);
    
    return 0;
}