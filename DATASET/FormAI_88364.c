//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char *topics[] = {
        "The moon landing was faked",
        "Aliens are real and the government is hiding them",
        "Chemtrails are being used to control the population",
        "The Illuminati are controlling everything",
        "9/11 was an inside job",
        "The earth is flat",
        "The government is using mind control",
        "Vaccines cause autism",
        "The apocalypse is coming",
        "The CIA killed JFK"};

    char *evidence[] = {
        "There are no stars in the photos of the moon landing",
        "People have reported seeing strange lights in the sky",
        "Chemicals have been found in the air and water",
        "There are hidden symbols in popular media",
        "Witnesses claim to have heard explosions before the towers fell",
        "The horizon always appears flat",
        "People have reported hearing strange voices in their heads",
        "Some children have been diagnosed with autism after receiving vaccines",
        "Natural disasters have been increasing in frequency and severity",
        "There are inconsistencies in the official story"};

    char *conclusions[] = {
        "Therefore, the moon landing was faked",
        "Therefore, the government is hiding aliens",
        "Therefore, the government is using chemtrails to control the population",
        "Therefore, the Illuminati are controlling everything",
        "Therefore, 9/11 was an inside job",
        "Therefore, the earth is flat",
        "Therefore, the government is using mind control",
        "Therefore, vaccines cause autism",
        "Therefore, the apocalypse is coming",
        "Therefore, the CIA killed JFK"};

    srand(time(NULL));
    int rand_num = rand() % 10;

    printf("Random Conspiracy Theory Generator:\n");
    printf("Topic: %s\n", topics[rand_num]);
    printf("Evidence: %s\n", evidence[rand_num]);
    printf("Conclusion: %s\n", conclusions[rand_num]);

    return 0;
}