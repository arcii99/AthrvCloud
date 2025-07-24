//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char *conspiracy1[] = {"The moon landing was fake", "The government controls the weather", "Aliens walk among us", "The Earth is flat", "Chemtrails are poisoning us", "Vaccines cause autism"};
    char *conspiracy2[] = {"the Illuminati", "the New World Order", "the Deep State", "the Reptilian Elite", "the Freemasons", "the Bilderberg Group"};

    srand(time(NULL));

    printf("Random Conspiracy Theory Generator:\n");

    // Generate 5 random conspiracy theories
    for (int i = 0; i < 5; i++) {
        int rand_index1 = rand() % 6;
        int rand_index2 = rand() % 6;

        printf("%d. %s is controlled by %s.\n", i+1, conspiracy1[rand_index1], conspiracy2[rand_index2]);
    }

    return 0;
}