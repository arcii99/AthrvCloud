//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    const char *nouns[] = {"government", "aliens", "Illuminati", "Big Pharma", "Freemasons", "media", "reptilians", "Nazis", "deep state", "New World Order", "Zionists", "bigfoot", "interdimensional beings", "lizard people", "time travelers", "vampires", "time travelers", "robots", "clones", "elves"};
    const char *verbs[] = {"control", "manipulate", "brainwash", "infiltrate", "enslave", "spy on", "program", "experiment on", "harvest", "extract", "clone", "teleport", "abduct", "mind control", "telepathically communicate with", "possess", "generously donate to", "turn against", "feed on", "obsess over"};
    const char *adjectives[] = {"secret", "unexplained", "supernatural", "mythical", "ancient", "advanced", "hidden", "occult", "magical", "forbidden", "dangerous", "man-made", "extra-terrestrial", "futuristic", "dimensional", "subliminal", "mysterious", "paranormal", "apocalyptic", "time-traveling"};

    int random_noun_index = rand() % (sizeof(nouns) / sizeof(nouns[0]));
    int random_verb_index = rand() % (sizeof(verbs) / sizeof(verbs[0]));
    int random_adjective_index = rand() % (sizeof(adjectives) / sizeof(adjectives[0]));

    printf("Did you know that the %s %s the %s?\n", adjectives[random_adjective_index], nouns[random_noun_index], verbs[random_verb_index]);

    return 0;
}