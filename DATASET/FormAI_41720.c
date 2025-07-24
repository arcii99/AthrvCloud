//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int randNum = rand() % 10;

    char* theories[10] = {
        "The government is hiding the existence of aliens from us to maintain power.",
        "COVID-19 was man-made in a lab to control the population.",
        "The moon landing was faked to win the space race.",
        "The Illuminati controls the world's leaders.",
        "The Bermuda Triangle is a portal to another dimension.",
        "The Loch Ness Monster is a government experiment gone wrong.",
        "Bigfoot is actually an alien in disguise.",
        "The Titanic was sunk on purpose to eliminate certain passengers.",
        "The Earth is flat and the government is lying to us.",
        "The apocalypse is coming and the government is preparing themselves while keeping the public in the dark."
    };

    printf("Random Conspiracy Theory Generator:\n\n");
    printf("%s\n", theories[randNum]);
    printf("\nIs this true? Who knows! ");
    printf("But remember, always question what you're told.");

    return 0;
}