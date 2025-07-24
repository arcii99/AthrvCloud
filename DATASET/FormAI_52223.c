//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* theories[] = {
            "The moon landing was faked by the government.",
            "9/11 was an inside job.",
            "The Earth is flat.",
            "Aliens are among us.",
            "The Illuminati control the world.",
            "The vaccine for COVID-19 is a plot to implant microchips in humans.",
            "The Bermuda Triangle swallows ships and planes due to a powerful electromagnetic field.",
            "The Denver International Airport is the secret headquarters of the New World Order.",
            "The world leaders are actually reptilian creatures in disguise.",
            "The Titanic didn't sink, it was actually its sister ship that met its fate.",
            "The government is hiding the cure for cancer to make money from treatments."
    };

    int num_theories = sizeof(theories) / sizeof(char*);
    srand(time(NULL)); // Seed the random generator with current time

    printf("Here's your random conspiracy theory of the day:\n");
    printf("%s\n", theories[rand() % num_theories]);

    return 0;
}