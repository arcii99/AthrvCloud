//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char* subjects[] = {
        "The Government",
        "The Illuminati",
        "The Reptilians",
        "The Freemasons",
        "The Anunnaki",
        "The New World Order"
    };
    char* verbs[] = {
        "are controlling",
        "are manipulating",
        "are hiding information about",
        "are in league with",
        "are secretly funding",
        "are brainwashing the public about"
    };
    char* objects[] = {
        "climate change",
        "the moon landing",
        "911",
        "aliens",
        "vaccines",
        "the flat earth theory"
    };
    char* evidence[] = {
        "It's all in the documents they refuse to release",
        "There are too many coincidences to be mere chance",
        "Just look at the facts, they speak for themselves",
        "The truth is out there, if you know where to look",
        "You can't trust the mainstream media to tell you the truth"
    };
    printf("Random Conspiracy Theory Generator\n\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s %s %s. %s.\n", i+1, subjects[rand() % 6], verbs[rand() % 6], objects[rand() % 6], evidence[rand() % 5]);
    }
    return 0;
}