//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* conspiracy_theories[] = {
    "The earth is flat and the government is trying to hide it from us",
    "The moon landing was faked by the government to show their superiority to other countries",
    "The illuminati controls the world and is influencing major decisions",
    "The government is hiding evidence of extraterrestrial life",
    "The vaccine for COVID-19 was intentionally developed to control the population",
    "The JFK assassination was a planned attack orchestrated by the government",
    "The Bermuda triangle is a portal to another dimension used by the government for secret missions",
    "The world leaders are secretly members of a satanic cult practicing rituals behind closed doors"
};

void generate_conspiracy() {
    srand(time(NULL));
    int index = rand() % 8; // 8 conspiracy theories in array
    printf("%s\n", conspiracy_theories[index]);
}

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Are you ready to uncover the truth?\n");
    printf("Press enter to generate a conspiracy theory...\n");
    getchar();
    generate_conspiracy();

    return 0;
}