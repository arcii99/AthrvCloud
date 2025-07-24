//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char* conspiracy[] = {
        "The moon landing was faked by the US government.",
        "The Illuminati controls the world.",
        "9/11 was an inside job.",
        "Aliens have already made contact with the government.",
        "The Earth is flat.",
        "The government is hiding advanced technology from the public.",
        "The CIA assassinated JFK.",
        "Global warming is a hoax.",
        "Chemtrails are a form of population control.",
        "The government is controlling the weather with HAARP.",
        "The New World Order is coming.",
        "The Denver airport is a secret underground base.",
        "The world will end in 2012.",
        "Vaccines cause autism.",
        "The government is using mind control through the media.",
        "Bigfoot is real and being kept secret.",
        "The Loch Ness monster is real and being kept secret.",
        "The pyramids were built by aliens.",
        "The government is hiding the cure for cancer."
    };

    char* random_conspiracy = conspiracy[rand() % 19];

    printf("\n\n%s\n\n", random_conspiracy);
    printf("Oh, hark! What medley of theories come to mind,\n");
    printf("Enshrouding us in such a cloak of doubt?\n");
    printf("What artifice hath wove a tale, so blind,\n");
    printf("As to make us skeptical throughout?\n\n");
    printf("Forsooth, I hear the whispers in the wind,\n");
    printf("That speak of power held by hidden hands,\n");
    printf("Who steer the course of worlds as they rescind\n");
    printf("The truths we hold, and plunge us into sands\n\n");
    printf("Of doubt, and fear, and ignorance unfurled,\n");
    printf("And leave us lost, in search of something true,\n");
    printf("While they, behind the curtain, rule the world,\n");
    printf("And mock us as we struggle to construe\n\n");
    printf("The plot that they have woven, oh so sly,\n");
    printf("A web so tangled that we cannot see,\n");
    printf("The threads that bind us to a fate so high,\n");
    printf("A puppet show, where we're not truly free.\n");

    return 0;
}