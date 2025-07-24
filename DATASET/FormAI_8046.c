//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

const char *fortunes[] = {
    "Thou shalt be blessed with wealth and prosperity.",
    "Misfortune awaits thee at every turn. Beware!",
    "The stars foretell a great journey ahead.",
    "Thy future is bright, filled with love and happiness.",
    "Watch thy back, for there are jealous eyes upon thee.",
    "Thy efforts shall be rewarded beyond measure.",
    "The fates are in thy favor. Luck shall be thy companion.",
    "A great mystery shall soon be unveiled before thee.",
    "Thou shalt face many challenges, but victory shall be sweet.",
    "A dark shadow looms over thee. Tread carefully."
};

int main()
{
    printf("Welcome, adventurer! I am the Automated Fortune Teller. \n\n");

    // Seed the random number generator
    srand(time(NULL));

    // Select a random fortune
    int index = rand() % NUM_FORTUNES;
    const char *fortune = fortunes[index];

    // Print the fortune
    printf("Thy fortune, in the style of the medieval times, is:\n");
    printf("\n%s\n\n", fortune);

    // Farewell message
    printf("May thy fortune bring thee great success!\n");
    printf("Farewell, adventurer!\n");

    return 0;
}