//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* topics[] = {"aliens", "chemtrails", "vaccines", "government surveillance", "Big Pharma", "climate change", "the Illuminati", "the New World Order", "the reptilian elite", "the Deep State"};
    char* actions[] = {"are controlling", "are manipulating", "are brainwashing", "are poisoning", "are hiding", "are planning", "are creating", "are testing", "are experimenting with", "are weaponizing"};
    char* objects[] = {"our minds", "the weather", "our food", "our water", "our DNA", "our emotions", "the media", "the economy", "the government", "the military"};

    srand(time(0));
    int index_topic = rand() % 10;
    int index_action = rand() % 10;
    int index_object = rand() % 10;

    printf("In this post-apocalyptic world, we must remain vigilant about the truth. The truth is that %s %s %s.\n", actions[index_action], objects[index_object], topics[index_topic]);

    return 0;
}