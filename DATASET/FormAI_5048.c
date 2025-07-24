//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void conspiracy1(char *s) {
    char *q = s;
    while (*q) *q++ -= 3;
}

void conspiracy2(char *s) {
    char *q = s;
    while (*q) *q++ += 5;
}

void conspiracy3(char *s) {
    char *q = s;
    while (*q) *q++ ^= 0x3F;
}

void conspiracy4(char *s) {
    char *q = s;
    while (*q) *q++ += 13;
}

void (*conspiracy_functions[])(char*) = {
    conspiracy1,
    conspiracy2,
    conspiracy3,
    conspiracy4,
    NULL
};

int main() {
    srand(time(NULL));

    char *conspiracy[] = {
        "The government is run by aliens",
        "The moon landing was fake",
        "The New World Order is real",
        "Chemtrails are in the air",
        "The Illuminati control everything",
        "The earth is flat",
        "The Rothschilds control the world's banks",
        "The JFK assassination was an inside job",
        "9/11 was an inside job",
        "The coronavirus is a hoax",
        "Vaccines cause autism",
        "The pyramids were built by aliens",
        "The Loch Ness Monster is real",
        "The Titanic never sank",
        "The Bermuda Triangle is a portal to another dimension",
        "Bigfoot exists",
        "Area 51 holds alien secrets",
        "Atlantis exists and was destroyed by a natural disaster",
        "Elvis Presley faked his own death",
        "Paul McCartney is dead",
        "Stanley Kubrick faked the moon landing",
        "Walt Disney was cryogenically frozen",
        "The Simpsons predict the future",
        "The lizard people control the world",
        "Time travel has already been invented",
        "The earth is hollow",
        "The government is hiding evidence of extraterrestrial life",
        "Ancient aliens visited earth in the past",
        "The government controls the weather",
        "The Illuminati killed Princess Diana",
        "The Illuminati killed Michael Jackson",
        "The Freemasons control the world",
        "The CIA killed Martin Luther King Jr.",
        "The CIA started the crack epidemic in the US",
        "The government is controlling our minds with chemicals",
        "The Black Dahlia murder was a government conspiracy",
        "The government created AIDS",
        "The Denver Airport is a secret underground base",
        "The government created the coronavirus",
        "The government is hiding the cure for cancer",
        "The government created 5G to control the population",
        "The government is hiding evidence of time travelers",
        "The government is hiding evidence of UFO sightings",
        "The government is hiding evidence of parallel universes",
        "The government created the internet as a tool for surveillance",
        "The government is hiding evidence of life on other planets",
        "The government is hiding evidence of the afterlife",
        "The government is controlling the media",
        "The government controls Hollywood",
        "The government is controlling the stock market",
        "The government is hiding evidence of a second sun in our solar system",
        "The government is hiding evidence of the Hollow Earth theory"
    };

    char *selected_conspiracy = conspiracy[rand() % (sizeof(conspiracy) / sizeof(char*))];

    int i = 0;
    while (conspiracy_functions[i]) {
        conspiracy_functions[i](selected_conspiracy);
        i++;
    }

    puts("\n*** RANDOM CONSPIRACY THEORY GENERATOR ***\n\n");
    puts(selected_conspiracy);
    puts("\n");

    return 0;
}