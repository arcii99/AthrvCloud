//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct conspiracy {
    char *subject;
    char *verb;
    char *object;
};

int main()
{
    srand(time(NULL));
    struct conspiracy conspiracy_array[10] = {
        {"The Moon Landing", "was faked by", "the US government"},
        {"The Illuminati", "controls", "the world's governments"},
        {"9/11", "was an inside job by", "the US government"},
        {"Chemtrails", "are being used by", "the government to control our thoughts"},
        {"The Earth", "is actually flat and", "NASA is hiding the truth"},
        {"The New World Order", "is", "already in motion"},
        {"Vaccines", "are a tool for", "the government to poison us"},
        {"The Mandela Effect", "is a sign of", "alternate universes bleeding into our own"},
        {"An alien invasion", "is imminent and", "the government is covering it up"},
        {"Bigfoot", "is a government experiment created to", "observe us in the wilderness"}
    };
    int choice = rand() % 10;

    printf("Did you know that %s %s %s?\n", conspiracy_array[choice].subject,
           conspiracy_array[choice].verb, conspiracy_array[choice].object);

    return 0;
}