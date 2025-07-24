//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char *adverbs[] = {"secretly", "mysteriously", "covertly", "stealthily", "furtively", "clandestinely"};
    char *nouns[] = {"government", "Illuminati", "aliens", "Masons", "Deep State", "New World Order"};
    char *actions[] = {"control", "manipulate", "brainwash", "monopolize", "dominate", "enslave"};
    char *objects[] = {"population", "media", "economy", "technology", "health care", "education"};

    srand(time(NULL));

    int num = 0;
    while(num < 10)
    {
        int index1 = rand() % 6;
        int index2 = rand() % 6;
        int index3 = rand() % 6;
        int index4 = rand() % 6;

        printf("Did you know that %s the %s %s the %s?\n", adverbs[index1], nouns[index2], actions[index3], objects[index4]);

        num++;
    }

    return 0;
}