//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned int)time(NULL)); // seed the random generator

    const char *conspiracy1[] = { "The moon landing was faked by the government.",
                                  "The Illuminati controls the world's governments.",
                                  "Global warming is a hoax created by the Chinese.",
                                  "The government is hiding evidence of extraterrestrial life.",
                                  "The CIA is behind almost every major world event.",
                                  "Chemtrails are a government conspiracy to control the population.",
                                  "Area 51 is hiding evidence of advanced technology from the public." };
    const char *conspiracy2[] = { "to distract us from the truth.",
                                  "to control the masses.",
                                  "to maintain their power and control.",
                                  "to create chaos and confusion.",
                                  "to hide their evil deeds from the public.",
                                  "to create a New World Order.",
                                  "to manipulate the stock market." };
    const char *conspiracy3[] = { "The evidence is clear if you know where to look.",
                                  "Wake up, sheeple!",
                                  "The truth is out there, you just need to open your eyes.",
                                  "Believe what you want, but the truth is undeniable.",
                                  "I have seen the evidence with my own eyes.",
                                  "Don't be fooled by the mainstream media.",
                                  "Trust no one, question everything." };
    
    int num_conspiracies = sizeof(conspiracy1) / sizeof(char *);
    int num_endings = sizeof(conspiracy2) / sizeof(char *);
    int num_exclamations = sizeof(conspiracy3) / sizeof(char *);

    for (int i = 1; i <= 10; i++) { // generate 10 conspiracy theories
        int rand1 = rand() % num_conspiracies;
        int rand2 = rand() % num_endings;
        int rand3 = rand() % num_exclamations;

        printf("%d. %s %s %s\n", i, conspiracy1[rand1], conspiracy2[rand2], conspiracy3[rand3]);
    }

    return 0;
}