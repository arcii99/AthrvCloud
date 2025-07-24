//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Set up our arrays of conspiracy theories
    char *theories[] = {"The government is controlled by lizard people.",
                        "The moon landing was faked.",
                        "Chemtrails are a government cover-up for mind control experiments.",
                        "The Illuminati are behind everything.",
                        "9/11 was an inside job.",
                        "The Earth is actually flat.",
                        "Vaccines cause autism.",
                        "The Loch Ness Monster is real and being hidden from us.",
                        "Aliens have been visiting Earth for years and the government is hiding it.",
                        "The Bermuda Triangle is a portal to another dimension."};
    char *evidence[] = {"There are videos of lizard people shapeshifting on YouTube!",
                        "NASA has been caught doctoring photos and videos of the moon landing.",
                        "Airplanes spraying chemicals in the sky have been seen all around the world.",
                        "There are symbols and messages hidden in popular media that point to the Illuminati's existence.",
                        "The physics of the Twin Towers falling doesn't add up.",
                        "If the Earth was really round, there would be more curve visible from the ground.",
                        "Dozens of studies have linked vaccines to autism.",
                        "There have been countless sightings of a massive creature in Loch Ness.",
                        "Former government officials and military personnel have come forward with stories of alien encounters.",
                        "Numerous ships and planes have disappeared in the Bermuda Triangle without explanation."};
    char *people[] = {"The President",
                      "The CIA Director",
                      "Bill Gates",
                      "Mark Zuckerberg",
                      "The Pope",
                      "Elon Musk",
                      "George Soros",
                      "Barack Obama",
                      "Jeff Bezos",
                      "Tom Hanks"};

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number to select a theory, a piece of evidence, and a person
    int theory_index = rand() % 10;
    int evidence_index = rand() % 10;
    int person_index = rand() % 10;

    // Print out the randomly generated conspiracy theory
    printf("Did you know that %s\n\n", theories[theory_index]);

    // Print out the evidence
    printf("%s\n\n", evidence[evidence_index]);

    // Print out the person who is supposedly behind the conspiracy
    printf("And who is responsible for all this? It's none other than... %s!\n", people[person_index]);

    return 0;
}