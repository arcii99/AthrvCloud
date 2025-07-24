//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));//initialize random seed

    char* nouns[] = {"government", "aliens", "Illuminati", "Big Pharma", "Masons", "Ivy League", "media", "New World Order", "reptilians", "Zionists", "the Deep State", "secret societies", "Freemasons", "NASA", "CIA", "FBI", "NSA", "MI6", "KGB"};

    char* verbs[] = {"control", "manipulate", "brainwash", "enslave", "dominate", "influence", "ensnare", "corrupt", "subjugate", "conquer"};

    char* adjectives[] = {"elite", "powerful", "corrupt", "sinister", "secretive", "manipulative", "hidden", "shadowy", "ruthless", "diabolical", "deceitful"};

    char* places[] = {"the shadows", "the backrooms", "boardrooms", "smoke-filled rooms", "high rise offices"};

    char* people[] = {"the Rothschilds", "the Rockefellers", "the 1%", "the Bilderberg Group", "the Bushes", "the Clintons"};

    //generating conspiracy theory
    printf("Did you know that %s is trying to %s the world? They are a part of the %s %s and have been working in %s to %s us all. It's all a part of their plan to gain %s. They are %s and %s, and %s. They are being controlled by %s, who are the real %s behind all this. Wake up, people!", 
        people[rand() % (sizeof(people) / sizeof(char*))],
        verbs[rand() % (sizeof(verbs) / sizeof(char*))],
        adjectives[rand() % (sizeof(adjectives) / sizeof(char*))],
        nouns[rand() % (sizeof(nouns) / sizeof(char*))],
        places[rand() % (sizeof(places) / sizeof(char*))],
        verbs[rand() % (sizeof(verbs) / sizeof(char*))],
        adjectives[rand() % (sizeof(adjectives) / sizeof(char*))],
        adjectives[rand() % (sizeof(adjectives) / sizeof(char*))],
        adjectives[rand() % (sizeof(adjectives) / sizeof(char*))],
        adjectives[rand() % (sizeof(adjectives) / sizeof(char*))],
        nouns[rand() % (sizeof(nouns) / sizeof(char*))],
        adjectives[rand() % (sizeof(adjectives) / sizeof(char*))]);

    return 0;
}