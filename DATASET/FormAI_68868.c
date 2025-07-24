//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void print_conspiracy(void) {
    char *conspiracies[] = {
        "The moon landing was faked",
        "The government is controlling our minds with chemtrails",
        "9/11 was an inside job",
        "The earth is flat",
        "COVID-19 was created in a lab",
        "The Illuminati are controlling the world",
        "The Bermuda Triangle is a portal to another dimension",
        "Bigfoot is real and being covered up by the government",
        "The Loch Ness Monster is real and being covered up by the government",
        "The assassination of JFK was a government conspiracy"
    };
    int num_conspiracies = sizeof(conspiracies)/sizeof(char *);
    int rand_index = rand() % num_conspiracies;
    printf("%s\n", conspiracies[rand_index]);
}

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    int num_conspiracies = 10;
    for (int i = 0; i < num_conspiracies; i++) {
        print_conspiracy();
    }
    return 0;
}