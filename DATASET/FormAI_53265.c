//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* conspiracies[10] = { "The moon landing was fake.",
                               "Bigfoot is real and the government is hiding it.",
                               "Chemtrails are being used to control our minds.",
                               "The Earth is actually flat.",
                               "The Illuminati controls everything.",
                               "Aliens built the pyramids.",
                               "The government is hiding the cure for cancer.",
                               "Lizard people are secretly ruling the world.",
                               "Cloning technology already exists and the government is using it to create super soldiers.",
                               "The Bermuda Triangle is a portal to another dimension." };

    char* evidence[10] = { "It's suspicious that there aren't any stars in the background of the moon landing photos.",
                           "People have reported seeing Bigfoot in various parts of the world for decades.",
                           "If you look closely at airplanes, you can see that they are releasing chemicals into the air.",
                           "If the Earth was really round, people on the other side wouldn't be upside down.",
                           "There are too many coincidences for the Illuminati not to be real.",
                           "There is no other explanation for how the pyramids were constructed.",
                           "It's fishy that there hasn't been a cure for cancer yet.",
                           "Some of the world's most powerful people have strange lizard-like features.",
                           "The military has been experimenting with genetically-modified organisms for years.",
                           "Dozens of ships and airplanes have disappeared in the Bermuda Triangle." };

    char* government[10] = { "The government is hiding the truth from us.",
                             "They want to keep us in the dark to maintain control.",
                             "The government has been lying to us for years.",
                             "They don't want us to know the truth.",
                             "They're afraid of what will happen if we find out what's really going on.",
                             "The government has too much power and they're afraid of losing it.",
                             "They're working with extraterrestrials to keep us in line.",
                             "The government wants to keep us dumb and dependent.",
                             "They're using these conspiracies to distract us from the real issues.",
                             "The government is the real enemy." };

    srand(time(NULL)); // Initialize the random number generator.

    printf("Random Conspiracy Theory Generator:\n\n");
    printf("\t%s\n\t%s\n\t%s\n\n", conspiracies[rand() % 10], evidence[rand() % 10], government[rand() % 10]);
    printf("Wake up, sheeple!");

    return 0;
}