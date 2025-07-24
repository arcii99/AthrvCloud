//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char *conspiracies[] = {
        "Aliens have taken over the government.",
        "The moon landing was faked by Kubrick.",
        "Elvis is still alive and in hiding.",
        "The Illuminati control the world's governments.",
        "The Earth is actually flat.",
        "Chemtrails are a way for the government to control us.",
        "The apocalypse is coming and only a select few will survive.",
        "The Roswell incident was actually a government cover-up.",
        "The government is hiding cures for diseases to maintain population control.",
        "The Titanic was actually sunk on purpose for financial gain.",
        "9/11 was an inside job.",
        "The Mandela Effect is evidence of alternate dimensions.",
        "Reptilian shape-shifters run the world.",
        "The Loch Ness Monster is actually a government experiment gone wrong.",
        "The Bermuda Triangle is a portal to another dimension.",
        "Bigfoot is real and has been secretly captured by the government.",
        "The government is hiding the existence of time travel technology.",
        "The Denver airport is home to a New World Order headquarters.",
        "Area 51 is actually a facility for housing extraterrestrial life forms.",
        "The Philadelphia Experiment was actually successful and led to the disappearance of an entire ship.",
    };
    
    int num_conspiracies = sizeof(conspiracies) / sizeof(conspiracies[0]);
    
    int random_num = rand() % num_conspiracies;
    
    printf("CONSPIRACY ALERT: %s\n", conspiracies[random_num]);
    
    return 0;
}